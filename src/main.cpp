#include"translateBF2C.h"

using namespace std;

int main() {
	string infilename, outfilename;
	cout << "输入文件名\n";
	cin >> infilename >> outfilename;
	File_translateBF2CPP(infilename, outfilename);
	return 0;
}