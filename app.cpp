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

	/*
	order - 1 -> ascending (visit left then right)
	order - 2 -> descending (visit right then left)

	source - 1 -> output to screen
	source - 2 -> output to file "student-info.txt"
	*/

	tree->display(1, 2);
	cout << endl << "-----------------" << endl;

	tree->display(2, 1);



	


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
		Student tempStudent = Student(); //Create new student object container
		Student* stuPointer = &tempStudent;

		getline(FileReader, scanLine);
        stringstream Cursor(scanLine); 
		Cursor >> studentID;

		getline(FileReader, labels, '=');
		getline(FileReader, scanLine);
		name = scanLine;

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

		//Assign the scanned data into the created Student object
		stuPointer->id = studentID;
		strcpy_s(stuPointer->name, name.c_str());
		strcpy_s(stuPointer->address, address.c_str());
		strcpy_s(stuPointer->DOB, dob.c_str());
		strcpy_s(stuPointer->phone_no, phoneNumber.c_str());
		strcpy_s(stuPointer->course, course.c_str());
		stuPointer->cgpa = cgpa;

		tree->insert(tempStudent);
    }
	



	FileReader.close();
	return true;
}

	