#!/usr/bin/env bash
#MIT licensed
#Useful resources
#https://www.cyberciti.biz/faq/unix-howto-read-line-by-line-from-file/
#https://stackoverflow.com/questions/22546395/shell-bash-parsing-text-file
#Others that I forgot to document here

#Note: $1 contains the 1st command line argument (the file to convert)

#Convert elf to verilog hex (but addresses are incorrect)
riscv64-unknown-elf-objcopy $1 -O verilog --verilog-data-width=4

echo "//Processed Verilog Hex File For JZJCore" > "$1.hex"

#Read each line
while IFS= read -r line
do
    #Check for Verilog hex addresses
    if [[ ${line:0:1} == "@" ]]
    then
        #We need to divide the hexidecimal address by 4 to convert from word to byte-wise addresses
        
        #Objcopy always outputs 8 characters after the @
        originalAddressHex=${line:1:8}
        
        #Divide by 4 and convert back to hex
        newAddressDecimal=$((16#$originalAddressHex / 4))
        newAddressHex=$(echo "obase=16; $newAddressDecimal" | bc)
        
        #Write modified address to the file (it's ok that the value is not padded)
        echo "@$newAddressHex" >> "$1.hex"
    else
        #Pass through the line as is (contains data, a comment, or whitespace; not an address)
        echo "$line" >> "$1.hex"
    fi
done < "$1"
