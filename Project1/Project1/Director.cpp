#include "Director.h"

//constructors
Director::Director(){}

Director::Director( const int & numberOfDirectorCredits, const string & fname, const string & lname, const int & age) {
	this->FirstName = fname;
	this->LastName = lname;
	this->age = age;
	this->numberOfDirectorCredits = numberOfDirectorCredits;
}


//destructor
Director::~Director() {

}

//operator

bool Director::operator==(const Director & other)
{
	return (this->getFirstName() == other.getFirstName() && this->getLastName() == other.getLastName());
}


//get&set function
void Director::setFirstName(const string &fname) {
	this->FirstName = fname;
}

string Director::getFirstName() const {
	return this->FirstName;
}

void Director::setLastName(const string &lname) {
	this->LastName = lname;
}

string Director::getLastName() const {
	return this->LastName;
}

void Director::setAge(const int &age) {
	this->age = age;
}

int Director::getAge() const {
	return this->age;
}

int Director::getNumberOfDirectorCredits() const {
	return this->numberOfDirectorCredits;
}

void Director::setNumberOfDirectorCredits(const int number) {
	this->numberOfDirectorCredits = number;
}

