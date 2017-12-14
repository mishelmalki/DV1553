#include "Studio.h"



Studio::Studio(){
	this->conglomerate = "";
	this->majorFilmStudioUnit = "";
	this->foundedYear = 0;
	this->totalGrowth = 0;
	this->averageScore = 0;
	this->numberOfFilms = 0;
	this->myLength = 1;
	this->filmArrey = new Film*[myLength];
}

Studio::Studio(const string &conglomerate, const string &majorFilmStudioUnit, const int &foundedYear) {
	this->conglomerate = conglomerate;
	this->majorFilmStudioUnit = majorFilmStudioUnit;
	this->foundedYear = foundedYear;

	this->totalGrowth = 0;
	this->averageScore = 0;
	this->myLength = 1;
	this->numberOfFilms = 0;
	this->filmArrey = new Film*[myLength];
}

Studio::Studio(const Studio & other) {
	this->conglomerate = other.conglomerate;
	this->majorFilmStudioUnit = other.majorFilmStudioUnit;
	this->foundedYear = other.foundedYear;
	this->totalGrowth = other.totalGrowth;
	this->averageScore = other.averageScore;
	this->numberOfFilms = other.numberOfFilms;
	this->myLength = other.myLength;
	this->filmArrey = new Film*[myLength];

	for (int i = 0; i < numberOfFilms; i++) {
		filmArrey[i] = new Film(*other.filmArrey[i]);
	}
}


Studio::~Studio() {
	for (int i = 0; i < this->numberOfFilms; i++) {
		delete this->filmArrey[i];
	}
	delete[] filmArrey;
}

void Studio::operator=(const Studio & other) {
	if (this != &other) {
		for (int i = 0; i < this->numberOfFilms; i++) {
			delete filmArrey[i];
		}
		delete[] filmArrey;

		this->numberOfFilms = other.numberOfFilms;
		this->myLength = other.myLength;

		this->conglomerate = other.conglomerate;
		this->majorFilmStudioUnit = other.majorFilmStudioUnit;
		this->foundedYear = other.foundedYear;
		this->totalGrowth = other.totalGrowth;
		this->averageScore = other.averageScore;

		filmArrey = new Film*[other.myLength];
		for (int i = 0; i < numberOfFilms; i++) {
			this->filmArrey[i] = new Film(*other.filmArrey[i]);
		}
	}
}

void Studio::expand() {
	this->myLength = this->myLength + 5;
	Film**tempArr = new Film*[this->myLength];

	for (int i = 0; i < this->numberOfFilms; i++) {
		tempArr[i] = this->filmArrey[i];
	}

	delete[] this->filmArrey;
	this->filmArrey = tempArr;
	tempArr = NULL;
}

void Studio::updateScore() {
	int mySum = 0;
	for (int i = 0; i < numberOfFilms; i++) {
		mySum = mySum + filmArrey[i]->getScore();
	}
	mySum = mySum / numberOfFilms;
	this->averageScore = mySum;
}


bool Studio::addFilmToArrey(const string & name, const int & relaseYear, const int & directorID, const int & totalGrowth, const int & budget, const int & score) {
	bool check = false;

	if (findFilm(name, relaseYear) == -1) {
		Film *tempFilm = new Film(name,relaseYear,directorID,totalGrowth,budget,score);
		if (this->numberOfFilms == this->myLength) {
			expand();
		}
		filmArrey[this->numberOfFilms] = tempFilm;
		this->numberOfFilms++;

		this->totalGrowth = this->totalGrowth + totalGrowth;
		updateScore();

		check = true;
		tempFilm = nullptr;
	}
	return check;
}

bool Studio::removeFilm(const string fname, const int rYear) {
	bool check = false;
	int pos = -1;
	for (int i = 0; i < this->numberOfFilms; i++) {
		if (this->filmArrey[i]->getName() == fname && this->filmArrey[i]->getRelaseYear() == rYear) {
			pos = i;
			check = true;
			i = numberOfFilms;
		}
	}
	if (check == true) {
		this->totalGrowth = this->totalGrowth - filmArrey[pos]->getTotalGrowth();
		delete filmArrey[pos];
		this->filmArrey[pos] = this->filmArrey[this->numberOfFilms - 1];
		filmArrey[numberOfFilms - 1] = nullptr;
		this->numberOfFilms--;
		updateScore();
	}
	return check;
}

int Studio::findFilm(const string fname, const int rYear) const {
	int check = -1;
	for (int i = 0; i < this->numberOfFilms; i++) {
		if (this->filmArrey[i]->getName() == fname && this->filmArrey[i]->getRelaseYear() == rYear) {
			check = i;
			i = numberOfFilms;
		}
	}
	return check;
}

bool Studio::write2File(ofstream &outfile) const {
	bool check = false;
	if (outfile.is_open() == true) {

		outfile << this->numberOfFilms << endl;
		outfile << this->foundedYear << endl;
		outfile << this->conglomerate << "\t" << this->majorFilmStudioUnit << endl;

		for (int i = 0; i < this->numberOfFilms; i++) {
			outfile << this->filmArrey[i]->getName() << "\t" << this->filmArrey[i]->getRelaseYear() << "\t" << this->filmArrey[i]->getDirectorID() << "\t" << this->filmArrey[i]->getTotalGrowth() << "\t" << this->filmArrey[i]->getBudget() << "\t" << this->filmArrey[i]->getScore() << endl;
		}
		check = true;
	}
	return check;
}

bool Studio::readFromFile(ifstream & inFile) {
	bool check = false;
	if (inFile.is_open() == true) {
		int releaseYear, directorID, totalGrowth, budget, score, numberOfFilmsInFile;
		string name;
		// very broken pointer, this -> corrupted
		inFile >> numberOfFilmsInFile;
		
		while (this->myLength <= numberOfFilmsInFile) {
			expand();
		}
		if (numberOfFilmsInFile == 0) {
			inFile.ignore();
		}
		for (int i = 0; i < numberOfFilmsInFile; i++) {
			inFile.ignore();
			getline(inFile, name);
			inFile >> releaseYear >> directorID >> totalGrowth >> budget >> score;
			this->addFilmToArrey(name, releaseYear, directorID, totalGrowth, budget, score);
		}
		inFile.ignore();
		this->numberOfFilms = numberOfFilmsInFile;
		check = true;
	}
	return check;
}


//get&set function
string Studio::getConglomerate() const {
	return this->conglomerate;
}

void Studio::setConglomerate(const string &congl) {
	this->conglomerate = congl;
}

string Studio::getMajorFilmStudioUnit() const {
	return this->majorFilmStudioUnit;
}

void Studio::setMajorFilmStudioUnit(const string & unit) {
	this->majorFilmStudioUnit = unit;
}

int Studio::getFoundedYear() const {
	return this->foundedYear;
}

void Studio::setFoundedYear(const int & foundedYear) {
	this->foundedYear = foundedYear;
}

int Studio::getNumberOfFilms() const {
	return this->numberOfFilms;
}
