# BuildPlusPlus - Simplified C++ Build System
**BuildPlusPlus** is a basic build system implemented in C++, providing a simple way to compile and link C++ source files into executable programs. This class is designed for educational purposes and serves as a starting point for understanding the build process.

## Features

- Compile C++ source files into object files.
- Link object files into an executable program.
- Basic error handling for compilation and linking failures.

## Getting Started

1. Include the `build++.hpp` header file in your C++ application.
2. Create a list of source files and object files for your project.
3. Use the `BuildPlusPlus::AddIncludePath` method to add include directories to your program.
4. Use the `BuildPlusPlus::Compile` method to compile each source file into an object file.
5. Use the `BuildPlusPlus::Link` method to link the object files into an executable program.

## Example Usage

1. Create Build Script:

   1. ```cpp
      // build.cpp
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
      ```

2. Compile Build Script: `g++ build.cpp -o build`

3. Execute Build Script: `./build`

4. ???

5. Profit. 

## Customization

**BuildPlusPlus** provides a basic foundation for building C++ projects. You can extend and customize it to meet the specific requirements of your project, such as handling compiler flags, dependencies, and more advanced build scenarios.

## Limitations

- This build system is intended for educational purposes and is not a full-featured build tool like CMake or Make.
- Error handling is minimal and may not cover all possible failure scenarios.
- Platform-specific compilation and linking commands are not included. Modify the `BuildSystem` class to suit your platform's requirements.

## Contributing

Contributions to **BuildPlusPlus** are welcome! If you find issues or want to enhance its functionality, feel free to submit a pull request or open an issue.

## License

The `BuildSystem` class is provided under the [GPL3 License](LICENSE).
