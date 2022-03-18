#include <iostream>
#include <cctype>
#include "funcs.h"
#include <fstream>

std::string removeLeadingSpaces(std::string line){
    std::string result;
    int i = 0;
    if(isspace(line[i])){
        while (isspace(line[i])){
            i++;
        }
    }
    result = line.substr(i);
    return result;    
}

int countChar(std::string line, char c){
    int result = 0;
    for (int i = 0; i < line.length(); i++){
        if(line[i] == c)
            result++;
    }
    return result;
}

std::string indent(std::string line, int out, int in) { 
    std::string result = ""; 
    for(int i = 0; i < out - in; i++) { 
        result += "\t"; 
    }
    return result + line; 
}