#pragma once

#ifndef BUILD_PLUSPLUS
#define BUILD_PLUSPLUS

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For calling system()

std::string m_IncludePaths = "";
class BuildPlusPlus {
public:
    static void AddIncludePath(const std::string& path)
    {
        m_IncludePaths += " -I" + path;
    }
    static void Compile(const std::string& sourceFile, const std::string& objectFile) {
        std::string compileCommand = "g++ -c -o " + objectFile + m_IncludePaths + " " + sourceFile;
        std::cout << "Compiling: " << sourceFile << std::endl;
        int compileResult = system(compileCommand.c_str());
        if (compileResult != 0) {
            std::cerr << "Compilation failed for: " << sourceFile << std::endl;
            exit(1);
        }
    }

    static void Link(const std::string& outputFile, const std::vector<std::string>& objectFiles) {
        std::string linkCommand = "g++ -o " + outputFile;
        for (const auto& objFile : objectFiles)
        {
            linkCommand += " " + objFile;
        }
        std::cout << "Linking: " << outputFile << std::endl;
        int linkResult = system(linkCommand.c_str());
        if(linkResult != 0)
        {
            std::cerr << "Linking failed for: " << outputFile << std::endl;
            exit(1);
        }
    }

    static void Link(const std::string& outputFile, const std::vector<std::string>& objectFiles, const std::vector<std::string>& libraries)
    {
        std::string linkCommand = "g++ -o " + outputFile;
        for (const auto& objFile : objectFiles)
        {
            linkCommand += " " + objFile;
        }
        for(const auto& library : libraries)
        {
            linkCommand += " -l" + library;
        }
        std::cout << "Linking: " << outputFile << std::endl;
        int linkResult = system(linkCommand.c_str());
        if(linkResult != 0)
        {
            std::cerr << "Linking failed for: " << outputFile << std::endl;
            exit(1);
        }
    }
};

#endif // BUILD_PLUSPLUS
