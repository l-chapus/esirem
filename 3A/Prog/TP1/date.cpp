#include "date.h"
#include <assert.h>


Date::Date(int jours,int mois,int annee): _jours(jours),_mois(mois),_annee(annee){
	bool status = date_valide(jours,mois,annee);
	assert(status && "Date non valide");
}

bool Date::date_valide(int jours,int mois,int annee){
	if((jours < 1) || (jours > 31)) return false;
	if((mois < 1) || (mois > 12)) return false;
	if((mois == 2) && (jours > 29)) return false;
	if(((mois == 4) || (mois == 6) || (mois == 9) || (mois == 11)) && (jours > 30)) return false;
	if((annee%4 == 0) && (mois == 2) && (jours > 28)) return false;
	return true;
}
int Date::get_annee(){
	return _annee;
}
int Date::get_mois(){
	return _mois;
}
int Date::get_jours(){
	return _jours;
}