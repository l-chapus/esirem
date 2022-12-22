#include <iostream>
#include "grille.h"
#include <unistd.h>

void solveur(int nb)
{
	Grille jeu;
	int meilleur_score=0;
	int iteration=0;
	int score_tmp=0;
	std::array<std::string,4> direction = {"q","s","d","z"};

	for(int k=1; k<(nb+1);k++)
	{
		jeu.init();
		jeu.affichage();
		while(jeu.fin_jeu() && jeu.end)
		{
			sleep(1);
			

			jeu.deplacement_auto(direction.at(rand() % 4));
			jeu.affichage();
		}
		
		score_tmp = jeu.score();
		if(score_tmp>meilleur_score)
		{
			meilleur_score=jeu.score();
			iteration=k;
		}
	}
	std::cout << "Meilleur score : " << meilleur_score << std::endl;
	std::cout << "Le meilleur score a été obtenu à l'itération : " << iteration << std::endl;
}

int main(){
	srand(time(NULL));  //ou srand((unsigned int)time(0)); (trouver sur internet)
	
//Jeu à la main
	//Grille jeu;
	//jeu.init();
	//jeu.affichage();
	//while(jeu.fin_jeu() && jeu.end){
	//	jeu.deplacement();
	//	jeu.affichage();
	//}

//Jeu automatisé

	int nb_essaies = 6;
	solveur(nb_essaies);

	return 0;
}
