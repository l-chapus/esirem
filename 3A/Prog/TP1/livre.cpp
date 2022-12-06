#include "livre.h"
#include "auteur.h"
#include <vector>

Livre::Livre(std::string titre,Auteur auteur,std::string langue,std::string genre,Date date_publication,long int ISBN,std::vector<std::string> liste_emprunteur) : _titre(titre), _auteur(auteur), _langue(langue), _genre(genre), _date_publication(date_publication), _ISBN(ISBN), _liste_emprunteur(liste_emprunteur){
}

std::string Livre::get_titre(){
	return _titre;
}
Auteur Livre::get_auteur(){
	return _auteur;
}
std::string Livre::get_langue(){
	return _langue;
}
std::string Livre::get_genre(){
	return _genre;
}
Date Livre::get_date_publication(){
	return _date_publication;
}
long int Livre::get_ISBN(){
	return _ISBN;
}
std::vector<std::string> Livre::get_liste_emprunteur(){
	return _liste_emprunteur;
}