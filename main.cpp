#include <iostream> 
#include <fstream> 
#include "funcs.h"

int main() { 
    std::string line;
    int out_brace = 0;
    int in_brace = 0; 

    std::ifstream fin("bad-code.cpp"); 

    while(getline(fin, line)) { 
        std::cout << line << std::endl;
    }

    fin.close(); 
    fin.open("bad-code.cpp");

    while(getline(fin, line)) { 
        in_brace = countChar(line, '}') + in_brace;
        std::string unindented_line = removeLeadingSpaces(line);
        std::cout << indent(unindented_line, out_brace, in_brace) << std::endl;
        out_brace = countChar(line, '{') + out_brace;
    }

    fin.close();

    std::cout << "\n============================================\n";
    out_brace = 0;
    in_brace = 0;

    fin.open("badcode2.cpp");

    while(getline(fin, line)) { 
        std::cout << line << std::endl;
    }

    fin.close(); 
    fin.open("badcode2.cpp");

    while(getline(fin, line)) { 
        in_brace = countChar(line, '}') + in_brace;
        std::string unindented_line = removeLeadingSpaces(line);
        std::cout << indent(unindented_line, out_brace, in_brace) << std::endl;
        out_brace = countChar(line, '{') + out_brace;
    }

    fin.close();

    return 0; 
}