#ifndef FILM_H
#define FILM_H

#include <string>

using namespace std;

class Film
{
private:
	string name;
	int relaseYear;
	int directorID;
	int totalGrowth;
	int budget;
	int score;

public:
	//constructors
	Film();
	Film(const string &name, const int &relaseYear, const int &directorID, const int &totalGrowth, const int &budget, const int &score);

	//destructor
	~Film();

	//operator

	//get&set function
	string getName() const;
	void setName(const string &name);

	int getRelaseYear() const;
	void setRelaseYear(const int &year);
	
	int getDirectorID() const;
	void setDirectorID(const int &newID);

	int getTotalGrowth() const;
	void setTotalGrowth(const int &growth);

	int getBudget() const;
	void setBudget(const int &budget);

	int getScore() const;
	void setScore(const int &score);

};
#endif

