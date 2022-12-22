#pragma once
#include <array>
#include <iostream>

class Grille{
private:
	std::array<int,16> _board;
	int _mouvement;
	bool end=true;
	int _meilleur_score;

	void ecran_fin();
	void sortie();
	int generateur_valeur();
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
	int score() const;
	void deplacement_auto(std::string direction);
public:
	Grille();
	void play();
};
