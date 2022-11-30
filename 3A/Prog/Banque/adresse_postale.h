#include <iostream>

class Adresse_postale{

private:
	int _numeroRue;
	int _codePostal;
	std::string _nomRue;
	std::string _nomVille;
	bool isAdresse(int numeroRue,int codePostal);
public:
	Adresse_postale(int numeroRue=0,std::string nomRue="",int codePostal=0,std::string nomVille="");
	std::string Adresse();
};