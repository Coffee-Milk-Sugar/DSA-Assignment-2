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
void clearCinBuffer(istream &);


int main() {
	BST* tree = new BST();
	BST* subTree = new BST();

	bool EXIT = false;
	do {
		system("cls");

		int choice = menu();
		if (choice == 1) { //readFile()
			readFile("student.txt", tree);
			continue;
		} 
		else if (choice == 2) { //print deepest node
			tree->deepestNodes();

			system("pause");
			continue;
		}
		else if (choice == 3) { //display student
			int order = 0;
			int source = 0;

			while (true) { //Loop for validity check
				cout << "Where do you want to display the output (1 - Screen / 2 - File): ";
				cin >> source;
				if (source >= 1 && source <= 2) break;
				clearCinBuffer(cin);

			}
			while (true) { //Loop for validity check
				cout << "Which order of display? (1 - Ascending/ 2 - Descending): ";
				cin >> order;
				cout << endl;
				if (order >= 1 && order <= 2) break;
				clearCinBuffer(cin);
			}
			tree->display(order, source);

			system("pause");
			continue;
		}
		else if (choice == 4) { //clone subtree

			continue;
		}
		else if (choice == 5) { //print level nodes
			tree->printLevelNodes();

			system("pause");
			continue;
		}
		else if (choice == 6) { //print path

			continue;
		}
		else if (choice == 7) {
			EXIT = true;

			cout << "See you again." << endl;
		}
		else {

			cout << "Invalid input! Please enter numerals as choice!" << endl;
			system("PAUSE");
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clear all the invalid input
			system("cls");
			continue;
		}

	} while (!EXIT);

	/*
	order - 1 -> ascending (visit left then right)
	order - 2 -> descending (visit right then left)

	source - 1 -> output to screen
	source - 2 -> output to file "student-info.txt"
	*/

	//tree->display(1, 2);
	//cout << endl << "-----------------" << endl;

	//tree->display(2, 1);
	//tree->deepestNodes();


	


	system("pause");
	return 0;
}

//(a)
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

		//Check for redundancy 
		bool notUnique = false;
		if (!tree->findGrandsons(tempStudent)) {
			tree->insert(tempStudent);
		}
    }
	
	cout << endl << endl << "Read File Successful." << endl;
	system("pause");
	FileReader.close();
	return true;
}

//(b)
int menu() {
	int selection = 0;
	cout << "Menu" << endl << endl;
	cout << "(1) Read data BST" << endl;
	cout << "(2) Print deepest nodes" << endl;
	cout << "(3) Display student" << endl;
	cout << "(4) Clone Subtree" << endl;
	cout << "(5) Print Level Nodes" << endl;
	cout << "(6) Print Path" << endl;
	cout << "(7) Exit" << endl;
	cout << endl;
	cout << "Selection: ";
	cin >> selection;
	return selection;
}


//helper function
void clearCinBuffer(istream& in) {
	cout << endl;
	cout << "Invalid input! Please enter numerals as choice!" << endl;
	system("PAUSE");
	in.clear();
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear all the invalid input
	system("cls");
}