//BUGS TO FIX
//Adding extra instructions/words sometimes (can't hard code number of bytes per line)
//Verilog addresses @XXXXXXXX not being changed from bytewise to wordwise for the backned (need to / by 4)

//Only parameter is the name of the file to reformat for memoryv4
//Also mit licenced like rest of project
//note that this is not meant to run on the cpu itself; c programs to be run on the cpu are in the c folder
#include <fstream>
#include <string>

//This is very hardcoded for objcopy output
//it adds a bunch of extra whitespace at the end for some reason, so in the future that should be removed

//borrowed from a cpp project I'm a dev in: https://gitlab.com/Blaziken_/checkers/-/blob/master/src/main.cpp
std::string splitFileName(std::string fileName)//todo error handling
{
    unsigned int dotIndex;
    
    for (int i = fileName.size() - 1; i >= 0; --i)
    {
        if (fileName[i] == '.')
            dotIndex = i;
    }//todo error handling if there is no .
    
    std::string name = fileName.substr(0, dotIndex);//before last . in file name
    //std::string ext = fileName.substr(dotIndex + 1);//after last . in file name//not used
    
    return name;
}

void reformat(std::string fileName)//todo error handling
{
    std::ifstream fileIn(fileName);
    std::ofstream fileOut(splitFileName(fileName));//todo error handling
    std::string temp;
    
    while (!fileIn.eof())//until the end of the file
    {
        switch (fileIn.peek())//look at first character of line (but don't remove)
        {
            case '\n'://empty line
            case '@'://verilog location operator thing
            case '/'://comment
            {
                std::getline(fileIn, temp);//get the entire line
                fileOut << temp << "\n";
                break;
            }
            default://data
            {
                for (int i = 0; i <= 3; ++i)//16 bytes on a given line
                {
                    for (int j = 0; j <= 3; ++j)//4 byte word
                    {
                        fileIn >> temp;//get a byte (discarding whitespace)
                        fileOut << temp;
                    }
                    fileOut << "\n";
                }
                std::getline(fileIn, temp);//skip to the next line and discard the \n
                break;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        reformat(argv[1]);//the file name
        return 0;
    }
    else
    {
        return 1;
    }
}
