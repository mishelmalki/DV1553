#ifndef STUDIO_H
#define STUDIO_H
#include "Film.h"

class Studio
{
private:
	string conglomerate;
	string majorFilmStudioUnit;
	int age;
	int totalGrowth;
	int averageScore;
	int numberOfFilms;
	int myLength;
	Film**filmArrey;
	
public:
	//constructors
	Studio();
	//destructor
	~Studio();

	//operator
	//get&set function
	//arrey expansion
	//Other functions
	//update score and growth
	//addToArrey
	//remove from array
	//findInArrey
	//write&readToFile
};
#endif

