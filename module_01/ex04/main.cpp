#include <iostream>
#include <fstream> 
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Error!!! Usage: ./sed <file> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string text;
    size_t  idx = 0;
    size_t  pos = 0;

    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "s1 can't be empty" << std::endl;
        return (1);
    }

    std::ifstream read_file(argv[1]);
    if (read_file.is_open())
    {
        if (getline(read_file, text, '\0'))
        {
            std::ofstream out_file((std::string(argv[1]) + ".replace").c_str());
            if (!out_file)
            {
                std::cerr << "Error: failed to create output file" << std::endl;
                return (1);
            }
            pos = text.find(s1, idx);
            while (pos != std::string::npos)
            {
                std::string part = text.substr(idx, pos - idx);
                out_file.write(part.c_str(), part.length());
                out_file.write(s2.c_str(), s2.length());
                idx = pos + s1.length();
                pos = text.find(s1, pos + 1);
            }
            std::string part = text.substr(idx);
            out_file.write(part.c_str(), part.length());
            out_file.close();
        }   
    }
    else
    {
        std::cerr << "Error: failed to open file" << std::endl;
        return (1);
    }
    read_file.close();
    return (0);
}