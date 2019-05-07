#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



string readBinaryFile(string filename)
{
	ifstream file(filename.c_str(), ios::binary | ios::in);
    unsigned char tmp = 0;
    string ret = "";
	
	if (file) {
        while(!file.eof()) {
            file.read((char*)&tmp, sizeof(char));
            ret.push_back(tmp);
        }
	}
	else
		cerr << "ERROR : can't open file in reading mode" << endl;

	return ret;
}




//MAIN
int main(int argc, char *argv[])
{   
    string filename = argv[1];
    string message  = readBinaryFile(filename);

    cout << message << endl;

    cin.get();  //pause the terminal
    return 0;

}
