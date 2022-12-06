#include <iostream>
#include <vector>
#include "livre.h"
#include "bibliotheque.h"

int main()
{
	Date vh(26,2,1802);
	Auteur a1("Vhugo","Hugo","Victor",vh);
	std::vector<std::string> emprunteur = {"lchapus","lpauzie"};
	Date d(17,5,1892);
	Livre l1("Les Misérables",a1,"Français","Roman",d,9780453009669,emprunteur);
	std::cout << l1.get_date_publication().get_annee() << std::endl;
	std::cout << l1.get_liste_emprunteur().at(0) << std::endl;
	std::cout << l1.get_auteur().get_nom() << std::endl;
	
	Bibliotheque  bu();

	return 0;
}