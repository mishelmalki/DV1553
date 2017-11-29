#ifndef DIRECTOR_H
#define DIRECTOR_H
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Director 
{
private:
	string FirstName;
	string LastName;
	int age;
	int numberOfDirectorCredits;
public:
	//constructors
	Director();
	Director(const int &numberOfDirectorCredits, const string &fname, const string &lname, const int &age);
	
	//destructor
	~Director();

	//operator
	bool operator==(const Director &other);


	//get&set function
	void setFirstName(const string &fname);
	string getFirstName() const;

	void setLastName(const string &lname);
	string getLastName() const;

	void setAge(const int &age);
	int getAge() const;

	int getNumberOfDirectorCredits() const;
	void setNumberOfDirectorCredits(const int number);
};
#endif
