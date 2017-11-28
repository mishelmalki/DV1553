#ifndef ACTOR_H
#define ACTOR_H
#include "Person.h"
class Actor : public Person
{
private:
	int numberOfActorCredits;
	int starMeter;
public:
	Actor();
	Actor(const string &fname, const string &lname, const int &age);
	~Actor();


};
#endif
