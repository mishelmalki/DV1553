#include "DirectorRegister.h"

//constructors
DirectorRegister::DirectorRegister() {
	this->myLength = 1;
	this->numberOf = 0;
	this->directorArrey = new Director*[myLength];
}

DirectorRegister::DirectorRegister(const DirectorRegister & other) {
	this->numberOf = other.numberOf;
	this->myLength = other.myLength;
	this->directorArrey = new Director*[myLength];
	for (int i = 0; i < numberOf; i++) {
		directorArrey[i] = new Director(*other.directorArrey[i]);
	}
}


//destructor
DirectorRegister::~DirectorRegister() {
	for (int i = 0; i < this->numberOf; i++) {
		delete this->directorArrey[i];
	}
	delete[] directorArrey;
}

//arrey expansion
void DirectorRegister::expand() {
	this->myLength = this->myLength + 5;
	Director**tempArr = new Director*[this->myLength];

	for (int i = 0; i < this->numberOf; i++) {
		tempArr[i] = this->directorArrey[i];
	}

	delete[] this->directorArrey;
	this->directorArrey = tempArr;
	tempArr = NULL;
}

//operator
void DirectorRegister::operator=(const DirectorRegister & other) {
	if (this != &other) {
		for (int i = 0; i < this->numberOf; i++) {
			delete directorArrey[i];
		}
		delete[] directorArrey;

		this->numberOf = other.numberOf;
		myLength = other.myLength;
		directorArrey = new Director*[other.myLength];
		for (int i = 0; i < numberOf; i++) {
			this->directorArrey[i] = new Director(*other.directorArrey[i]);
		}
	}
}

bool DirectorRegister::addDirectorToArrey(const int & numberOfDirectorCredits, const string & fname, const string & lname, const int & age) {
	bool check = false;

	if (findDirector(fname, lname) == -1) {
		Director *tempDirector = new Director(numberOfDirectorCredits, fname, lname, age);
		if (this->numberOf == this->myLength) {
			expand();
		}
		directorArrey[this->numberOf] = tempDirector;
		this->numberOf++;
		check = true;
		tempDirector = nullptr;
	}
	return check;
}

bool DirectorRegister::addDirectorToArreyWithID(const int MyID, const int & numberOfDirectorCredits, const string & fname, const string & lname, const int & age) {
	bool check = false;

	if (findDirector(fname, lname) == -1) {
		Director *tempDirector = new Director(MyID,numberOfDirectorCredits, fname, lname, age);
		if (this->numberOf == this->myLength) {
			expand();
		}
		directorArrey[this->numberOf] = tempDirector;
		this->numberOf++;
		check = true;
		tempDirector = nullptr;
	}
	return check;
}

bool DirectorRegister::removeDirector(const string fname, const string lname) {
	bool check = false;
	int pos = -1;
	for (int i = 0; i < this->numberOf; i++) {
		if (this->directorArrey[i]->getFirstName() == fname && this->directorArrey[i]->getLastName() == lname) {
			pos = i;
			check = true;
			i = numberOf;
		}
	}
	if (check == true) {
		delete directorArrey[pos];
		this->directorArrey[pos] = this->directorArrey[this->numberOf - 1];
		directorArrey[numberOf - 1] = nullptr;
		this->numberOf--;
	}
	return check;
}

int DirectorRegister::findDirector(const string fname, const string lname) const {
	int check = -1;
	for (int i = 0; i < this->numberOf; i++) {
		if (this->directorArrey[i]->getFirstName()==fname && this->directorArrey[i]->getLastName()==lname) {
			check = i;
			i = numberOf;
		}
	}
	return check;
}

bool DirectorRegister::write2File(string name) const {
	bool check = false;
	ofstream outfile;
	outfile.open(name + ".txt");
	if (outfile.is_open() == true) {
		outfile << this->numberOf << endl;
		for (int i = 0; i < this->numberOf; i++) {
			outfile << this->directorArrey[i]->getFirstName() << "\t"<< this->directorArrey[i]->getLastName() << endl;
			outfile << this->directorArrey[i]->getAge() << "\t" << this->directorArrey[i]->getNumberOfDirectorCredits() << "\t" << this->directorArrey[i]->getID() << endl;
		}
		check = true;
		outfile.close();
	}
	return check;
}

bool DirectorRegister::readFromFile(const string name) {
	bool check = false;
	ifstream inFile;
	inFile.open(name + ".txt");
	if (inFile.is_open() == true) {
		int age, numberOfDirectorCredits, ID, number;
		string FirstName, LastName;

		inFile >> number;
		while (this->myLength <= number) {
			expand();
		}
		for (int i = 0; i < number; i++) {
			inFile.ignore();
			
			getline(inFile, FirstName, '\t');
			getline(inFile, LastName);
			inFile >> age >> numberOfDirectorCredits >> ID;
			this->addDirectorToArreyWithID(ID,numberOfDirectorCredits, FirstName, LastName, age);
		}
		this->numberOf = number;
		check = true;
		inFile.close();
	}
	return check;
}
