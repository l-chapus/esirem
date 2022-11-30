#include "adresse_postale.h"
#include <assert.h>

Adresse_postale::Adresse_postale(int numeroRue,std::string nomRue,int codePostal,std::string nomVille){
	bool status = isAdresse(numeroRue,codePostal);
	assert(status && "L'adresse n'est pas valide.(numéro de rue ou code postale)");
	_numeroRue = numeroRue;
	_codePostal = codePostal;
	_nomRue = nomRue;
	_nomVille = nomVille;
}

bool Adresse_postale::isAdresse(int numeroRue, int codePostal){
	if(numeroRue<0)
		return false;
	if(codePostal<0)
		return false;
	return true;
}

std::string Adresse_postale::Adresse(){
	std::string adresse = std::to_string(_numeroRue) + " " + _nomRue + "   " + std::to_string(_codePostal) + " " + _nomVille;
	return adresse;
}