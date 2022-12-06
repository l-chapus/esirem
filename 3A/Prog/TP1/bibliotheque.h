#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include "livre.h"
#include "auteur.h"
#include "lecteur.h"
#include <vector>
#include <iostream>

class Bibliotheque{
private:
	std::std::vector<Livre> _livres;
	std::std::vector<Auteur> _auteurs;
	std::std::vector<Lecteur> _lecteurs;
public:
	Bibliotheque(std::vector<Livre> livres, std::vector<Auteur> auteurs, std::vector<Lecteur> lecteurs);
	std::vector<Livre> get_livres();
	std::vector<Auteur> get_auteurs();
	std::vector<Lecteur> get_lecteurs();
};

#endif