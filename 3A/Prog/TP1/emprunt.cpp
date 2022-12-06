#include <iostream>
#include "emprunt.h"
#include "date.h"

Emprunt::Emprunt(Date date_emprunt, long int ISBN, std::string identifiant) : _date_emprunt(date_emprunt), _ISBN(ISBN), _identifiant(identifiant){

}