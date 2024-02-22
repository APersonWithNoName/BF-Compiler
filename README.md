# BF-Compiler
## Instroduces
A simple bf compiler. VERSION 0.0.1
## How to use
Use include "translateBF2CPP.h".
## Functions Instroduces
- 
  Translating Operators from BF to C++.
- `String_translateBF2CPP(std::string input_string)`
  Translate strings composed in the BF language to C++.Depend on`Char_translateBF2CPP(char input_char)`.
- `File_translateBF2CPP(std::string infileName, std::string outfileName)`
  Translate BF source code files to .cpp files.Depend on`String_translateBF2CPP(std::string input_string)`.