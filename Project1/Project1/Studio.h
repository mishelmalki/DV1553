#ifndef STUDIO_H
#define STUDIO_H
#include "Film.h"
#include <sstream>
#include <fstream>

class Studio
{
private:
	string conglomerate;
	string majorFilmStudioUnit;
	int foundedYear;
	int totalGrowth;
	int averageScore;
	int numberOfFilms;
	int myLength;
	Film**filmArrey;
	
public:
	//constructors
	Studio();
	Studio(const string &conglomerate, const string &majorFilmStudioUnit, const int &foundedYear);
	Studio(const Studio &other);

	//destructor
	~Studio();

	//operator
	void operator=(const Studio &other);

	//arrey expansion
	void expand();

	//Other functions
	void updateScore();

	//addToArrey
	bool addFilmToArrey(const string &name, const int &relaseYear, const int &directorID, const int &totalGrowth, const int &budget, const int &score);

	//remove from array
	bool removeFilm(const string fname, const int rYear);

	//findInArrey
	int findFilm(const string fname, const int rYear) const;

	//write&readToFile
	bool write2File(ofstream &outfile) const;
	bool readFromFile(ifstream &inFile);

	//get&set function
	string getConglomerate() const;
	void setConglomerate(const string &congl);


	string getMajorFilmStudioUnit() const;
	void setMajorFilmStudioUnit(const string &unit);

	int getFoundedYear() const;
	void setFoundedYear(const int &foundedYear);

	int getNumberOfFilms() const;

};
#endif
