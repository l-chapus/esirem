#pragma once
#include <array>
#include <iostream>
#include <vector>

class Grille{
private:
	std::vector<int> _board;
	int _mouvement;
	bool end=true;
	int _meilleur_score;
	int _taille_grille;
	int tmp;

	void ecran_fin();
	void sortie();
	int generateur_valeur() const ;
	void ajout_valeur();
	void droite();
	void gauche();
	void haut();
	void bas();
	void fusion_horizontale();
	void fusion_verticale();
	void mv_droite();
	void mv_gauche();
	void mv_haut();
	void mv_bas();
	void jeu_auto();
	void jeu_manuel();
	bool fin_jeu();  			//true si le jeu peut continuer et false si le jeu ne peut pas continuer
	void affichage();
	void init();
	void deplacement();
	int get_mouvement() const;
	int score();
	void deplacement_auto(std::string direction);
	void menu();
public:
	Grille();
	void play();
};
