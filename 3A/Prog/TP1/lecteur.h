#include <iostream>
#include <vector>

namespace lecteur{

class Lecteur{
public:
	Lecteur(std::string identifiant, std::string nom, std::string prenom, std::vector<long int> liste_ISBN);
	std::string get_identifiant();
	std::string get_nom();
	std::string get_prenom();

private: 
	std::string _identifiant;
	std::string _nom;
	std::string _prenom;
	std::vector<long int> _liste_ISBN;
};

}