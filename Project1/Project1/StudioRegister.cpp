#include "StudioRegister.h"



StudioRegister::StudioRegister() {
	this->numberOf = 0;
	this->myLength = 1;
	this->studioArray = new Studio*[myLength];
}


StudioRegister::~StudioRegister(){
	for (int i = 0; i < this->numberOf; i++) {
		delete this->studioArray[i];
	}
	delete[] studioArray;
}

void StudioRegister::operator=(const StudioRegister & other) {
	if (this != &other) {
		for (int i = 0; i < this->numberOf; i++) {
			delete this->studioArray[i];
		}
		delete[] studioArray;

		this->numberOf = other.numberOf;
		this->myLength = other.myLength;

		studioArray = new Studio*[other.myLength];
		for (int i = 0; i < numberOf; i++) {
			this->studioArray[i] = new Studio(*other.studioArray[i]);
		}
	}
}

void StudioRegister::expand() {
	this->myLength = this->myLength + 5;
	Studio**tempArr = new Studio*[this->myLength];

	for (int i = 0; i < this->numberOf; i++) {
		tempArr[i] = this->studioArray[i];
	}

	delete[] this->studioArray;
	this->studioArray = tempArr;
	tempArr = NULL;
}

bool StudioRegister::addFilmToArrey(const string & conglomerate, const int & foundedYear, const string & name, const int & relaseYear, const int & directorID, const int & totalGrowth, const int & budget, const int & score) {
	bool check = false;
	int pos = findStudio(conglomerate, foundedYear);
	if (pos != -1) {
		check = this->studioArray[pos]->addFilmToArrey(name, relaseYear, directorID, totalGrowth, budget, score);
	}
	return check;
}

bool StudioRegister::addStudioToArrey(const string & conglomerate, const string & majorFilmStudioUnit, const int & foundedYear) {
	bool check = false;

	if (findStudio(conglomerate, foundedYear) == -1) {
		Studio *tempStudio = new Studio(conglomerate,majorFilmStudioUnit,foundedYear);
		if (this->numberOf == this->myLength) {
			expand();
		}
		studioArray[this->numberOf] = tempStudio;
		this->numberOf++;

		check = true;
		tempStudio = nullptr;
	}
	return check;
}

bool StudioRegister::removeStudio(const string & conglomerate, const int & foundedYear) {
	bool check = false;
	int pos = findStudio(conglomerate, foundedYear);
	if (pos != -1) {
		check = true;
	}
	if (check == true) {
		delete studioArray[pos];
		this->studioArray[pos] = this->studioArray[this->numberOf - 1];
		studioArray[numberOf - 1] = nullptr;
		this->numberOf--;
	}
	return check;
}

int StudioRegister::findStudio(const string & conglomerate, const int & foundedYear) const {
	int check = -1;
	for (int i = 0; i < this->numberOf; i++) {
		if (this->studioArray[i]->getConglomerate() == conglomerate && this->studioArray[i]->getFoundedYear() == foundedYear) {
			check = i;
			i = numberOf;
		}
	}
	return check;
}

bool StudioRegister::write2File(string name) const {
	bool check = false;
	ofstream outfile;
	outfile.open(name + ".txt");
	if (outfile.is_open() == true) {

		outfile << this->numberOf << endl;
		for (int i = 0; i < this->numberOf; i++) {
			this->studioArray[i]->write2File(outfile);
		}
		check = true;
		outfile.close();
	}
	return check;
}

bool StudioRegister::readFromFile(const string name) {
	bool check = false;
	ifstream inFile;
	inFile.open(name + ".txt");
	if (inFile.is_open() == true) {
		int fileNumber;

		inFile >> fileNumber;
		while (this->myLength <= fileNumber) {
			expand();
		}
		for (int i = 0; i < fileNumber; i++) {
			this->studioArray[i] = new Studio();
			this->studioArray[i]->readFromFile(inFile);
		}
		this->numberOf = fileNumber;
		check = true;
		inFile.close();
	}
	return check;
}

int StudioRegister::getNumberOf() const {
	return this->numberOf;
}
