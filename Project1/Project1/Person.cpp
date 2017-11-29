#include "Person.h"

//constructors
Person::Person(){}

Person::Person(const string & fname, const string & lname, const int & age) {
	this->FirstName = fname;
	this->LastName = lname;
	this->age = age;
}

//destructor
Person::~Person() {
	this->FirstName = "";
	this->LastName = "";
	this->age = 0;
}

//get&set function
void Person::setFirstName(const string &fname) {
	this->FirstName = fname;
}

string Person::getFirstName() const {
	return this->FirstName;
}

void Person::setLastName(const string &lname) {
	this->LastName = lname;
}

string Person::getLastName() const {
	return this->LastName;
}

void Person::setAge(const int &age) {
	this->age = age;
}

int Person::getAge() const {
	return this->age;
}
