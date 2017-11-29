#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
private:
	string FirstName;
	string LastName;
	int age;
public:
	// ToDo make virtual!!!!!! (virtual & =0)

	//constructors
	Person();
	Person(const string &fname, const string &lname, const int &age);

	//destructor
	~Person();

	//get&set function
	void setFirstName(const string &fname);
	string getFirstName() const;

	void setLastName(const string &lname);
	string getLastName() const;

	void setAge(const int &age);
	int getAge() const;
};
#endif
