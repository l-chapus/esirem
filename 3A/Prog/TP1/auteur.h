#ifndef AUTEUR_H
#define AUTEUR_H


#include <iostream>
#include "date.h"

class Auteur{
private:
	std::string _identifiant_auteur;
	std::string _nom;
	std::string _prenom;
	Date _date_naissance;
public:
	Auteur(std::string identifiant_auteur, std::string nom, std::string prenom, Date date_naissance);
	std::string get_identifiant_auteur();
	std::string get_nom();
	std::string get_prenom();
	Date get_date_naissance();
};

#endif