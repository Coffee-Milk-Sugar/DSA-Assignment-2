#include	<iostream>
#include	<fstream>
#include	<sstream> 

#include	<string>
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
	readFile("student.txt", tree);

	system("pause");
	return 0;
}
bool readFile(const char* filename, BST* tree) {
	ifstream FileReader(filename);

	if (!FileReader) { //Case [1]: File not found
		cout << "File reading not sucessful " << endl;
		return false;
	}


	string labels;
	string scanLine;
	//Initiation of student attributes

	int studentID;
	string name;
	string address;
	string dob;
	string phoneNumber;
	string course;
	double cgpa;
	string dummy;
    while (getline(FileReader, labels, '=')) {
		getline(FileReader, scanLine);
        stringstream Cursor(scanLine); 
		Cursor >> studentID;
		Cursor.clear();

		getline(FileReader, labels, '=');
		getline(FileReader, scanLine);
		Cursor.str(scanLine);
		Cursor >> name;

		Cursor.clear();
		getline(FileReader, labels, '=');
		getline(FileReader, scanLine);
		address = scanLine;

		Cursor.clear();
		getline(FileReader, labels, '=');
		getline(FileReader, scanLine);
		Cursor.str(scanLine);
		Cursor >> dob;

		Cursor.clear();
		getline(FileReader, labels, '=');
		getline(FileReader, scanLine);
		Cursor.str(scanLine);
		Cursor >> phoneNumber;

		Cursor.clear();
		getline(FileReader, labels, '=');
		getline(FileReader, scanLine);
		Cursor.str(scanLine);
		Cursor >> course;

		Cursor.clear();
		getline(FileReader, labels, '=');
		getline(FileReader, scanLine);
		Cursor.str(scanLine);
		Cursor >> cgpa;

		
    }
	



	FileReader.close();
	return true;
}

	