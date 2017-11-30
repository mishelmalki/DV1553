#include "Studio.h"



Studio::Studio() {
	this->totalGrowth = 0;
	this->averageScore = 0;
	this->age = 0;
	this->myLength = 1;
	this->numberOfFilms = 0;
	this->filmArrey = new Film*[myLength];
}


Studio::~Studio()
{
}
