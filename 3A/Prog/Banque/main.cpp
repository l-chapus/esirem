#include <iostream>
#include "client.h"

int main()
{
	Date date_client1(14,1,2016);
	Date dncl1(12,5,1992);
	Adresse_postale maisoncl1(45,"Rue du bonheur",21000,"Dijon");
	Client client1("Toto","Dupont",dncl1,"toto.dupont@gmail.com","0754206595",maisoncl1,date_client1);
	std::cout << " " << std::endl;
	return 0;
}