#pragma once

#include<iostream>
#include<string>
#include<fstream>

std::string Char_translateBF2CPP(char input_char) {
	switch (input_char) {
	case '>':
		return "p++";
	case '<':
		return "p--";
	case '+':
		return "*p=*p+1";
	case '-':
		return "*p=*p-1";
	case '.':
		return "cout<<char(*p)";
	case ',':
		return "*p =getch()";
	case '[':
		return "while(*p){";
	case ']':
		return "}";
	default:
		return "";
	}
}

std::string String_translateBF2CPP(std::string input_string) {
	std::string output_string;
	for (char c : input_string) {
		output_string += Char_translateBF2CPP(c);
		if (c != '[')
			output_string += ";\n";
		if (c == '[')
			output_string += "\n";
	}
	return output_string;
}

void File_translateBF2CPP(std::string infileName, std::string outfileName) {
	std::ifstream infile(infileName);
	if (infile.is_open()) {
		std::string lineData;
		std::string Data;
		while (std::getline(infile, lineData)) {
			Data += lineData;
		}
		infile.close();
		std::string translated_string = String_translateBF2CPP(Data);
		std::ofstream outfile(outfileName);
		if (outfile.is_open()) {
			outfile << "\#include\<iostream\>\n";
			outfile << "using namespace std;\n";
			outfile << "void run\(\) \{\n";
			outfile << "char arr\[1000\] = \{0\};\n";
			outfile << "char\* p = arr+500;\n";
			outfile << translated_string << std::endl;
			outfile << "\}\n\n";
			outfile << "int main\(\) \{\n";
			outfile << "run\(\);\n";
			outfile << "return 0;\n";
			outfile << "\}";
			outfile.close();
		}
		else {
			std::cout << "Something wrong, I cannot open the output file. Please try again." << std::endl;
		}
	}
	else {
		std::cout << "Something wrong, I cannot open the file named" << infileName <<"." << std::endl;
		std::cout << "Please check the input file and try again." << std::endl;
	}
}