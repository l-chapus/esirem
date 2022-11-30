#include <iostream>
#include "grille.h"

int main(){
	srand(time(NULL));  //ou srand((unsigned int)time(0)); (trouver sur internet)
	Grille jeu;
	jeu.init();
	jeu.affichage();

	while(jeu.fin_jeu() && jeu.end){
		jeu.deplacement();
		jeu.affichage();
	}
	
	return 0;
}
