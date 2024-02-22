#include "translateBF2CPP.h"

using namespace std;

int main()
{
    string infilename, outfilename;
    cout << "Input file Name and Output file Name.\n";
    cin >> infilename >> outfilename;
    File_translateBF2CPP(infilename, outfilename);
    return 0;
}
