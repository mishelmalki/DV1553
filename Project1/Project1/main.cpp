#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 
#include "FranchiseRegister.h"
#include "DirectorRegister.h"
#include <iostream>


int main(void) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DirectorRegister reg;
	reg.readFromFile("myFile");

	

	reg.write2File("myFile");
	getchar();
}	



//reg.addDirectorToArrey(14, "Christopher", "Nolan", 47);
//reg.addDirectorToArrey(20, "Quentin", "Tarantino", 54);
//reg.addDirectorToArrey(61, "Martin", "Scorsese", 75);
//reg.addDirectorToArrey(21, "Edgar", "Wright ", 43);