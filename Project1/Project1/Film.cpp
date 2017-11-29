#include "Film.h"

//constructors
Film::Film() {

}


Film::~Film() {

}



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

Director Film::getDirector() const {
	return this->director;
}

Actor Film::getLeadActor() const {
	return this->leadActor;
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
