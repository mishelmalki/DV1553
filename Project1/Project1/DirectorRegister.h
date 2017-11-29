#ifndef DIRECTORREGISTER_H
#define DIRECTORREGISTER_H
#include "Director.h"

class DirectorRegister
{
private:
	Director**directorArrey;
	int numberOf;
	int myLength;
public:
	//constructors
	DirectorRegister();

	//copyconstructor
	DirectorRegister(const DirectorRegister &other);

	//destructor
	~DirectorRegister();

	//get&set function
	
	//arrey expansion
	void expand();
	//operator
	void operator=(const DirectorRegister &other);

	//Other functions

	//addToArrey
	bool addDirectorToArrey(const int &numberOfDirectorCredits, const string &fname, const string &lname, const int &age);
	
	//remove from array
	bool removeDirector(const string fname,const string lname);
	//findInArrey
	int findDirector(const string fname, const string lname) const;
	
	//write&readToFile
	bool write2File(string name) const;
	bool readFromFile(const string name);

};
#endif
