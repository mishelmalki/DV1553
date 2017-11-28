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
	Person();
	Person(const string &fname, const string &lname, const int &age);
	~Person();

	void setFirstName(const string &fname);
	string getFirstName();

	void setLastName(const string &lname);
	string getLastName();

	void setAge(const int &age);
	int getAge();
};
#endif
