#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include "date.h"
#include "auteur.h"
#include <vector>

class Livre{
private:
	std::string _titre;
	Auteur _auteur;
	std::string _langue;
	std::string _genre;
	Date _date_publication;
	long int _ISBN;
	std::vector<std::string> _liste_emprunteur;
public:
	Livre(std::string titre,Auteur auteur,std::string langue,std::string genre,Date date_publication,long int ISBN,std::vector<std::string> liste_emprunteur);
	std::string get_titre();
	Auteur get_auteur();
	std::string get_langue();
	std::string get_genre();
	Date get_date_publication();
	long int get_ISBN();
	std::vector<std::string> get_liste_emprunteur();
};

#endif