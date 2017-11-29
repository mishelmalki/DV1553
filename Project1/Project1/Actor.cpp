#include "Actor.h"

//constructors
Actor::Actor() :Person(){}

Actor::Actor(const int &numberOfActorCredits, const int &starMeter, const string &fname, const string & lname, const int & age) :Person(fname, lname, age) {
	this->numberOfActorCredits = numberOfActorCredits;
	this->starMeter = starMeter;
}

//destructor
Actor::~Actor() {
	this->numberOfActorCredits = 0;
	this->starMeter = 0;
}

//operator
bool Actor::operator==(const Actor other) {
	bool test = false;
	if (this->getFirstName() == other.getFirstName() && this->getLastName() == other.getLastName()) {
		if (this->starMeter == other.starMeter) {
			test = true;
		}
	}
	return test;
}

//get&set function
void Actor::setNumberOfActorCredits(const int & number) {
	this->numberOfActorCredits = number;
}

int Actor::getNumberOfActorCredits() const {
	return this->numberOfActorCredits;
}

void Actor::setStarMeter(const int & meter) {
	this->starMeter = meter;
}

int Actor::getStarMeter() const {
	return this->starMeter;
}
