#ifndef REPLACE_FILE_HPP
# define REPLACE_FILE_HPP
# include <fstream>
# include <iostream>
# include <string>

class ReplaceFile
{
public:
    ReplaceFile(void);
    ~ReplaceFile(void);
    void        setNewFile(std::string srcFile, std::string s1, std::string s2);
    std::string getNameFile(void);
private:
    std::string _newFile;
};

#endif