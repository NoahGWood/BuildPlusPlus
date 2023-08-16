#include "build++.hpp"
#include <vector>
#include <string>

int main()
{
    BuildPlusPlus::AddIncludePath("include");

    std::vector<std::string> sourceFiles = {"src/main.cpp", "src/foo.cpp", "src/bar.cpp"};
    std::vector<std::string> objectFiles;
    
    for (const auto& sourceFile : sourceFiles) {
        std::string objectFile = sourceFile.substr(0, sourceFile.rfind('.')) + ".o";
        BuildPlusPlus::Compile(sourceFile, objectFile);
        objectFiles.push_back(objectFile);
    }
    BuildPlusPlus::Link("MyApp", objectFiles);
// Alternatively, if you want to add libs:
//    std::vector<std::string> libraries = {"boost_system", "boost_thread"};
//    BuildPlusPlus::Link("MyApp", objectFiles, libraries);
    return 0;
}