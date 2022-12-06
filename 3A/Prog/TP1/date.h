#ifndef DATE_H
#define DATE_H

class Date{
public:
	Date(int jours=1,int mois=1,int annee=2000);	
	int get_annee();
	int get_mois();
	int get_jours();
private:
	int _annee;
	int _mois;
	int _jours;
	bool date_valide(int jours,int mois,int annee);

};

#endif