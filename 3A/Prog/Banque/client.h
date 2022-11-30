#include <iostream>
#include "date.h"
#include "adresse_postale.h"

class Client{
private:
	std::string _nom;
	std::string _prenom;
	Date _date_de_naissance;
	std::string _email;
	std::string _tel;
	Adresse_postale _adresse;
	Date _date_souscription;
	bool isClient(std::string tel);
public:
	Client(std::string nom, std::string prenom, Date date_de_naissance, std::string email, std::string tel, Adresse_postale adresse,Date date_souscription);
};