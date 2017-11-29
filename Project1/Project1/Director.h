#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Person.h"

class Director : public Person
{
private:
	string guildAssosiation;
	int numberOfDirectorCredits;
public:
	//constructors
	Director();
	Director(const string &guildAssosiation, const int &numberOfDirectorCredits, const string &fname, const string &lname, const int &age);
	
	//destructor
	~Director();

	//operator
	bool operator==(const Director other);

	//get&set function
	string getGuildAssosiation() const;
	void setGuildAssosiation(const string guild);

	int getNumberOfDirectorCredits() const;
	void setNumberOfDirectorCredits(const int number);
};
#endif
