#include "Film.h"

//constructors
Film::Film() {}

Film::Film(const string & name, const int & relaseYear, const int & directorID, const int & totalGrowth, const int & budget, const int & score) {
	this->relaseYear = relaseYear;
	this->directorID = directorID;
	this->totalGrowth = totalGrowth;
	this->budget = budget;
	this->score = score;
}


Film::~Film() {}

//get&set function
string Film::getName() const {
	return this->name;
}

void Film::setName(const string & name) {
	this->name = name;
}

int Film::getRelaseYear() const {
	return this->relaseYear;
}

void Film::setRelaseYear(const int & year) {
	this->relaseYear = year;
}

int Film::getDirectorID() const {
	return this->directorID;
}

void Film::setDirectorID(const int & newID) {
	this->directorID = newID;
}

int Film::getTotalGrowth() const {
	return this->totalGrowth;
}

void Film::setTotalGrowth(const int & growth) {
	this->totalGrowth = growth;
}

int Film::getBudget() const {
	return this->budget;
}

void Film::setBudget(const int & budget) {
	this->budget = budget;
}

int Film::getScore() const {
	return this->score;
}

void Film::setScore(const int & score) {
	this->score = score;
}
