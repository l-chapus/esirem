#include <array>


class Grille{
private:
	std::array<int,16> _board;
	int _mouvement;
	
	void ecran_fin();
	void sortie();
	int score();
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
public:
	bool end=true;
	Grille();
	bool fin_jeu();  			//true si le jeu peut continuer et false si le jeu ne peut pas continuer
	void affichage();
	void init();
	void deplacement();
};
