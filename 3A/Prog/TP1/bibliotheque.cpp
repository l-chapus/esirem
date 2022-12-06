#include "bibliotheque.h"

Bibliotheque::Bibliotheque(std::vector<Livre> livres, std::vector<Auteur> auteurs, std::vector<Lecteur> lecteurs): _livres(livres), _auteurs(auteurs), _lecteurs(lecteurs){

}
std::vector<Livre> Bibliotheque::get_livres(){
	return _livres;
}
std::vector<Auteur> Bibliotheque::get_auteurs(){
	return _auteurs;
}
std::vector<Lecteur> Bibliotheque::get_lecteurs(){
	return _lecteurs;
}
