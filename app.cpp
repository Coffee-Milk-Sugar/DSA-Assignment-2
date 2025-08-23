#include	<iostream>
#include	<fstream>
#include	<cstdlib>
#include	<cstdio>
#include	<ctime>
#include	"BST.h"
#include    "Student.h"

using namespace std;

bool readFile(const char *, BST *);
int menu();

int main() {
	BST* tree = new BST();
	
	system("pause");
	return 0;
}
bool readFile(const char* filename, BST* tree) {
	ifstream FileReader(filename);

	if (!FileReader) { //Case [1]: File not found
		cout << "File reading not sucessful " << endl;
		return false;
	}

	

}

	