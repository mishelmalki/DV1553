#include "Director.h"

//constructors
Director::Director() : Person(){}

Director::Director(const string & guildAssosiation, const int & numberOfDirectorCredits, const string & fname, const string & lname, const int & age) :Person(fname,lname,age){
	this->guildAssosiation = guildAssosiation;
	this->numberOfDirectorCredits = numberOfDirectorCredits;
}


//destructor
Director::~Director() {
	this->guildAssosiation = "";
	this->numberOfDirectorCredits = 0;
}

//operator
bool Director::operator==(const Director other) {
	bool test = false;
	if (this->getFirstName() == other.getFirstName() && this->getLastName() == other.getLastName()) {
		if (this->guildAssosiation == other.guildAssosiation) {
			test = true;
		}
	}
	return test;
}


//get&set function
string Director::getGuildAssosiation() const {
	return this->guildAssosiation;
}

void Director::setGuildAssosiation(string guild) {
	this->guildAssosiation = guild;
}

int Director::getNumberOfDirectorCredits() const {
	return this->numberOfDirectorCredits;
}

void Director::setNumberOfDirectorCredits(const int number) {
	this->numberOfDirectorCredits = number;
}

