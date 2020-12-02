#include "ReplaceFile.hpp"

ReplaceFile::ReplaceFile(void) {}
ReplaceFile::~ReplaceFile(void) {}

void ReplaceFile::setNewFile(std::string srcFile, std::string s1, std::string s2)
{
    std::ifstream src(srcFile);
    std::string lign;
    int lenS1 = s1.size();

    if (src)
    {
        std::string fileReplace = srcFile + ".replace";
        std::ofstream newFile(fileReplace.c_str());
        if (newFile)
        {
            while (getline(src, lign))
            {
                size_t found = lign.find(s1);
                while (found != std::string::npos)
                {
                    lign.replace(found, lenS1, s2);
                    found = lign.find(s1, found + s2.size());
                }
                newFile << lign;
            }
        }
        else
        {
            std::cout << "An error occured, this file could not be created." << std::endl;
            return;
        }
        this->_newFile = srcFile + ".replace";
        std::cout << "new file exists : " << this->_newFile << std::endl;

        return;
    }
    else
    {
        std::cout << "An error occured, this file could not be opened." << std::endl;
        return;
    }
}

std::string ReplaceFile::getNameFile(void)
{
    return this->_newFile;
}