#Tests all JZJCore RV32IZifencei instructions as well as MMIO
#Assumes instructions are being fetched and decoded correctly (depends on immediate values as root of sanity)
#Outputs to x31; MMIO port 5 should have complete feedback
#Check the output at each prompt in the file to enusure it matches what is expected

lui x31, 0xabcde#Ensure x31 contains 0xabcde000
addi x31, x31, 0x765#Ensure x31 contains 0xabcde765
auipc x31, 0xedcba#Ensure x31 contains 0xedcba008
jal x31, .jalSkip#Ensure x31 contains 0x00000010
addi x31, x0, 0x123#Ensure that this is not executed on the first pass and x31 remains 0x000000c. On the second pass (the jalr instruction at the end), x31 should be set to 0x123
ecall#Ensure that this is not executed on the first pass; On the second pass this should halt the core
fence#This should do nothing; x31 should still contain 0x000000c
.jalSkip:
slli x1, x31, 0#x31 should still stay the same, just copied into x1
beq x31, x1, .beqSucess#Should branch
ebreak#Should not be executed
.beqSucess:

#todo more instructions



jalr x0, 0(x1)#should return to the instruction after first jal instruction for the second pass
