#ifndef ACTOR_H
#define ACTOR_H

#include "Person.h"

class Actor : public Person
{
private:
	int numberOfActorCredits;
	int starMeter;
public:
	//constructors
	Actor();
	Actor(const int &numberOfActorCredits, const int &starMeter, const string &fname, const string &lname, const int &age);
	
	//destructor
	~Actor();

	//operator
	bool operator==(const Actor other);

	//get&set function
	void setNumberOfActorCredits(const int &number);
	int getNumberOfActorCredits() const;

	void setStarMeter(const int &meter);
	int getStarMeter() const;


};
#endif
