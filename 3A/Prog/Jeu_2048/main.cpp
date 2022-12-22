#include <iostream>
#include "grille.h"
#include <ctime>



int main(){
	srand(time(NULL));  //ou srand((unsigned int)time(0)); (trouver sur internet)
	
	Grille jeu;
	jeu.play();
	
	return 0;
}
