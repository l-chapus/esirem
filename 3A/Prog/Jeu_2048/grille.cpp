#include "grille.h"
#include <iostream>
#include <array>
#include <ctime>
#include <unistd.h>

Grille::Grille() {
	_mouvement = 0;
	_board = {0};
}

void Grille::affichage() {
	int tmp=0;
	system("clear");
	std::cout << "Le score est de : " << score() << std::endl;
	std::cout << "Le nombre de mouvements est : " << _mouvement << std::endl;
	std::cout << "-----------------------------" << std::endl;
	for(int x=0;x<4;x++){
		for(int y=0;y<4;y++){
			if(_board.at(4*x+y)==0)
				std::cout << "|      ";
			if(_board.at(4*x+y)==2)
				std::cout << "|   2  ";
			if(_board.at(4*x+y)==4)
				std::cout << "|   4  ";
			if(_board.at(4*x+y)==8)
				std::cout << "|   8  ";
			if(_board.at(4*x+y)==16)
				std::cout << "|  16  ";
			if(_board.at(4*x+y)==32)
				std::cout << "|  32  ";
			if(_board.at(4*x+y)==64)
				std::cout << "|  64  ";
			if(_board.at(4*x+y)==128)
				std::cout << "|  128 ";
			if(_board.at(4*x+y)==256)
				std::cout << "|  256 ";
			if(_board.at(4*x+y)==512)
				std::cout << "|  512 ";
			if(_board.at(4*x+y)==1024)
				std::cout << "| 1024 ";
			if(_board.at(4*x+y)==2048){
				std::cout << "| 2048 ";
				tmp=1;
			}
		}
		std::cout << "|" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	}
	std::cout << "z = haut, s = bas, d = droite, q = gauche et e = exit" << std::endl;
	std::cout << "Appuyer sur une touche :" << std::endl;
	if(tmp){
		ecran_fin();
	}	
}

void Grille::ecran_fin(){
	system("clear");
	std::cout << "   ██████  ██████  ███    ██  ██████  ██████   █████  ████████ ███████     ██ " << std::endl;
	std::cout << "  ██      ██    ██ ████   ██ ██       ██   ██ ██   ██    ██    ██          ██ " << std::endl;
	std::cout << "  ██      ██    ██ ██ ██  ██ ██   ███ ██████  ███████    ██    ███████     ██ " << std::endl;
	std::cout << "  ██      ██    ██ ██  ██ ██ ██    ██ ██   ██ ██   ██    ██         ██        " << std::endl;
	std::cout << "   ██████  ██████  ██   ████  ██████  ██   ██ ██   ██    ██    ███████     ██ " << std::endl << std::endl;
	std::cout << "score : " << score() << std::endl;
	std::cout << "nombre de mouvements : " << _mouvement << std::endl;
	sortie();
}

int Grille::score() const {
	int S=0;
	int n=_board.size();
	for(int k=0;k<n;++k){
		S=S+_board.at(k);
	}
	return S;
}
int Grille::get_mouvement() const {
	return _mouvement;
}

int Grille::generateur_valeur(){
	int valeur[4] = {2,2,2,4};
	return valeur[rand() % 4];
}

void Grille::init(){
	_mouvement=0;
	_board = {0};
	int nb=rand()%2 + 1;
	for(int k=0;k<nb;++k){
		int emplacement=rand()%15;
		_board.at(emplacement)=generateur_valeur();
	}
}

void Grille::fusion_horizontale(){
	for(int k=0;k<4;++k){
		for(int j=0;j<3;++j){
			if(_board.at(4*k+j) ==_board.at(4*k+j+1)){
				_board.at(4*k+j) = _board.at(4*k+j)*2;
				_board.at(4*k+j+1) = 0; 
			}
		}
	}	
}
void Grille::mv_droite(){
	int S=0;
	for(int k=0;k<4;++k){
		for(int j=3;j>0;j--){
			for(int i=j;i>0;--i){
				if(_board.at(4*k+i)==0){
					S = _board.at(4*k+i);
					_board.at(4*k+i) = _board.at(4*k+i-1);
					_board.at(4*k+i-1) = S;
				}
			}
		}
	}
}
void Grille::droite(){
	mv_droite();
	fusion_horizontale();
	mv_droite();
}

void Grille::mv_gauche(){
	int S=0;
	for(int k=0;k<4;++k){
		for(int j=0;j<3;j++){
			for(int i=j;i<3;++i){
				if(_board.at(4*k+i)==0){
					S = _board.at(4*k+i);
					_board.at(4*k+i) = _board.at(4*k+i+1);
					_board.at(4*k+i+1) = S;
				}
			}
		}
	}
}
void Grille::gauche(){
	mv_gauche();
	fusion_horizontale();
	mv_gauche();
}


void Grille::fusion_verticale(){
	for(int k=0;k<4;++k){
		for(int i=0;i<3;++i){
			if(_board.at(4*i+k) == _board.at(4*(i+1)+k)){
				_board.at(4*i+k) =_board.at(4*i+k)*2;
				_board.at(4*(i+1)+k) = 0;
			}
		}
	}
}
void Grille::mv_haut(){
	int S=0;
	for(int k=0;k<4;++k){
		for(int j=0;j<3;++j){
			for(int i=j;i<3;++i){
				if(_board.at(4*i+k)==0){
					S = _board.at(4*i+k);
					_board.at(4*i+k) = _board.at(4*(i+1)+k);
					_board.at(4*(i+1)+k) = S;
				}
			}
		}
	}
}
void Grille::haut(){
	mv_haut();
	fusion_verticale();
	mv_haut();
}

void Grille::mv_bas(){
	int S=0;
	for(int k=0;k<4;++k){
		for(int j=3;j>0;--j){
			for(int i=j;i>0;--i){
				if(_board.at(4*i+k)==0){
					S = _board.at(4*(i-1)+k);
					_board.at(4*(i-1)+k) = _board.at(4*i+k);
					_board.at(4*i+k) = S;
				}
			}
		}
	}
}
void Grille::bas(){
	mv_bas();
	fusion_verticale();
	mv_bas();
}


bool Grille::fin_jeu(){
	bool tmp=false;
	std::array<int,16> tmp2 = _board;
	int n = _board.size();
	for(int k=0;k<n;++k){
		if(_board.at(k)==0){
			tmp=true;
		}
	}
	fusion_verticale();
	if(tmp2!=_board){
		tmp=true;
	}
	_board=tmp2;
	fusion_horizontale();
	if(tmp2!=_board){
		tmp=true;
	}
	_board=tmp2;
	return tmp;
}

void Grille::sortie(){
	end = false;
}

void Grille::ajout_valeur(){
	int nb=generateur_valeur();
	int emplacement=rand()%15;
	while (_board.at(emplacement) != 0){
		emplacement=rand()%15;
	}
	_board.at(emplacement)=nb;
}

void Grille::deplacement(){
	bool fin = fin_jeu();
	std::string move = "";
	std::cin >> move;
	std::array<int,16> tmp = {0};
	
	if(fin){
		if(move == "z"){
			tmp = _board;
			haut();
			if(tmp != _board){
				ajout_valeur();
				_mouvement++;
			}
		}
		if(move == "s"){
			tmp = _board;
			bas();
			if(tmp != _board){
				ajout_valeur();
				_mouvement++;
			}
		}
		if(move == "q"){
			tmp = _board;
			gauche();
			if(tmp != _board){
				ajout_valeur();
				_mouvement++;
			}
		}
		if(move == "d"){
			tmp = _board;
			droite();
			if(tmp != _board){
				ajout_valeur();
				_mouvement++;
			}
		}

		if(move == "e"){
			sortie();
		}
	}
}
void Grille::deplacement_auto(std::string direction){
	bool fin = fin_jeu();
	std::array<int,16> tmp = {0};
	if(fin){
		if(direction == "z"){
			tmp = _board;
			haut();
			if(tmp != _board){
				ajout_valeur();
				_mouvement++;
			}
		}
		if(direction == "s"){
			tmp = _board;
			bas();
			if(tmp != _board){
				ajout_valeur();
				_mouvement++;
			}
		}
		if(direction == "q"){
			tmp = _board;
			gauche();
			if(tmp != _board){
				ajout_valeur();
				_mouvement++;
			}
		}
		if(direction == "d"){
			tmp = _board;
			droite();
			if(tmp != _board){
				ajout_valeur();
				_mouvement++;
			}
		}

		if(direction == "e"){
			sortie();
		}
	}
}

void Grille::play(){
	std::string mode="";
	std::cout << "Bienvue dans le jeu 2048." << std::endl;
	std::cout << "Il y a 2 modes de jeu : soit automatique, soit manuel. Veuillez séléctionner le mode qui vous intérresse :" << std::endl;
	std::cout << "m pour manuel et a pour automatique" << std::endl;
	std::cin >> mode;
	if(mode=="m" || mode=="M"){
		jeu_manuel();
	}
	if(mode=="a" || mode=="A"){
		jeu_auto();
	}
}

void Grille::jeu_manuel() {
	init();
	affichage();
	while(fin_jeu() && end){
		deplacement();
		affichage();
	}
}

void Grille::jeu_auto(){

	int score_tmp=0;
	std::array<int,16> tmp = {0};

	init();
	affichage();		
	while(fin_jeu() && end)
	{
		sleep(1);
		tmp = _board;
		deplacement_auto("s");
		if(tmp==_board){
			deplacement_auto("q");
			if(tmp==_board){
				deplacement_auto("d");
				if(tmp==_board){
					deplacement_auto("z");
				}
			}
		}
		affichage();
	}
		
	score_tmp = score();
	if(score_tmp>_meilleur_score)
	{
		_meilleur_score=score();
	}

	std::string reponse="";
	std::cout << "Le jeu est terminé." << std::endl;
	std::cout << "Voulez-vous relancer une partie ?" << std::endl;
	std::cout << "r pour relancer et e pour revenir au menu" << std::endl;
	std::cin >> reponse;
	if(reponse == "r" || reponse == "R"){
		jeu_auto();
	}
	else{
		play();
	}
}