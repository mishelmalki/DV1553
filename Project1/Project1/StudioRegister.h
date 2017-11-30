#ifndef STUDIOREGISTER_H
#define STUDIOREGISTER_H
#include "Studio.h"

class StudioRegister
{
private:
	int numberOf;
	int myLength;
	Studio**studioArray;
public:
	//constructors
	StudioRegister();
	//destructor
	~StudioRegister();
	//operator
	void operator=(const StudioRegister &other);

	//arrey expansion
	void expand();

	//Other functions
	//addFilmHelp
	bool addFilmToArrey(const string &conglomerate, const int &foundedYear, const string &name, const int &relaseYear, const int &directorID, const int &totalGrowth, const int &budget, const int &score);

	//addStudioToArrey
	bool addStudioToArrey(const string &conglomerate, const string &majorFilmStudioUnit, const int &foundedYear);

	//remove from array
	bool removeStudio(const string &conglomerate, const int &foundedYear);

	//findInArrey
	int findStudio(const string &conglomerate, const int &foundedYear) const;

	//write&readToFile
	bool write2File(string name) const;
	bool readFromFile(const string name);

	//get&set function
	int getNumberOf()const;
};
#endif

