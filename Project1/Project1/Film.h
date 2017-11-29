#ifndef FILM_H
#define FILM_H

#include"Director.h"
#include "Actor.h"
#include <string>

using namespace std;

class Film
{
private:
	string name;
	int relaseYear;
	Director director;
	Actor leadActor;
	int totalGrowth;
	int budget;
	int score;

public:
	//constructors
	Film();

	//destructor
	~Film();

	//operator

	//get&set function
	string getName() const;
	void setName(const string &name);
	int getRelaseYear() const;
	void setRelaseYear(const int &year);
	Director getDirector() const;
	//void setDirector(); unnecessary?
	Actor getLeadActor() const;
	//void setleadActor(); unnecessary??
	int getTotalGrowth() const;
	void setTotalGrowth(const int &growth);
	int getBudget() const;
	void setBudget(const int &budget);
	int getScore() const;
	void setScore(const int &score);

};
#endif

