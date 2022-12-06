#include "lecteur.h"

namespace lecteur{

Lecteur::Lecteur(std::string identifiant, std::string nom, std::string prenom, std::vector<long int> liste_ISBN) : _identifiant(identifiant), _nom(nom), _prenom(prenom), _liste_ISBN(liste_ISBN) {
}

std::string Lecteur::get_identifiant(){
	return _identifiant;
}

std::string Lecteur::get_nom(){
	return _nom;
}

std::string Lecteur::get_prenom(){
	return _prenom;
}

}	