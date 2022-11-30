#include <assert.h>
#include <iostream>
#include "client.h"
#include <cstring>

Client::Client(std::string nom, std::string prenom, Date date_de_naissance, std::string email, std::string tel, Adresse_postale adresse,Date date_souscription){
	bool status = isClient(tel);
	assert(status && "Email ou numéro de téléphone non valide.");
	_nom = nom;
	_prenom = prenom;
	_date_de_naissance = date_de_naissance;
	_email = email;
	_tel = tel;
	_adresse = adresse;
	_date_souscription = date_souscription;
}

bool Client::isClient(std::string tel){
	int nb = std::stoi(tel);
	if(nb<0 || tel.length()!=10) {
		return false;
	}
//	int arrobase=0;
//	int point=0;
//	for(int k=0;k<email.length();++k){
//		
//		if(strcmp(email[k],"@")){
//			arrobase=k;
//		}
//		if(strcmp(email[k],".")){
//			point=k;
//		}
//	}
//	if(arrobase>point)
//		return false;
	return true;
}