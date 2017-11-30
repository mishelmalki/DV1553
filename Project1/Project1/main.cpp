#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 
#include <iostream>

#include "DirectorRegister.h"
#include "StudioRegister.h"


int main(void) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	StudioRegister myReg;
	myReg.readFromFile("myStudios&Films");
	/*myReg.addStudioToArrey("WB", "mishelFilms", 1923);
	myReg.addStudioToArrey("My", "test", 2000);
	myReg.addFilmToArrey("WB", 1923, "batman v superman", 2016, 32525, 809555999, 300000000, 40);
	myReg.addFilmToArrey("WB", 1923, "Wonder W", 2017, 15551, 809555999, 300000000, 100);
	myReg.write2File("myStudios&Films");*/
	/*DirectorRegister reg;
	reg.readFromFile("myDirectors");*/
	
	/*Studio test("WB","mishelFilms",23);
	test.addFilmToArrey("batman v superman", 2016, 32525, 809555999, 300000000, 40);
	test.addFilmToArrey("MyBigTest", 2012, 12345, 809555999, 300000000, 60);
	test.write2File("myStudios&Films");*/

	
	
	
	//reg.write2File("myDirectors");
	//getchar();
};


/*reg.addDirectorToArrey(14, "Christopher", "Nolan", 47);
reg.addDirectorToArrey(20, "Quentin", "Tarantino", 54);
reg.addDirectorToArrey(61, "Martin", "Scorsese", 75);
reg.addDirectorToArrey(21, "Edgar", "Wright ", 43);*/

//added rand ID to director!!