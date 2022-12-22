#include "grille.h"
#include <iostream>
#include <array>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <chrono>
#include <thread>

Grille::Grille() {
	_mouvement = 0;
	_board = {0};
	_taille_grille=4;
}

void Grille::affichage() {
	int tmp=0;
	system("clear");
	std::cout << "Le meilleur score est de : " << _meilleur_score << std::endl;
	std::cout << "Le score de la parti en cour est de : " << score() << std::endl;
	std::cout << "Le nombre de mouvements est : " << _mouvement << std::endl;
	std::string ligne="-";
	for(int k=0;k<_taille_grille;++k){
		ligne+="-------";
	}

	std::cout << ligne << std::endl;
	for(int x=0;x<_taille_grille;x++){
		for(int y=0;y<_taille_grille;y++){
			if(_board.at(_taille_grille*x+y)==0)
				std::cout << "|      ";
			if(_board.at(_taille_grille*x+y)==2)
				std::cout << "|   2  ";
			if(_board.at(_taille_grille*x+y)==4)
				std::cout << "|   4  ";
			if(_board.at(_taille_grille*x+y)==8)
				std::cout << "|   8  ";
			if(_board.at(_taille_grille*x+y)==16)
				std::cout << "|  16  ";
			if(_board.at(_taille_grille*x+y)==32)
				std::cout << "|  32  ";
			if(_board.at(_taille_grille*x+y)==64)
				std::cout << "|  64  ";
			if(_board.at(_taille_grille*x+y)==128)
				std::cout << "|  128 ";
			if(_board.at(_taille_grille*x+y)==256)
				std::cout << "|  256 ";
			if(_board.at(_taille_grille*x+y)==512)
				std::cout << "|  512 ";
			if(_board.at(_taille_grille*x+y)==1024)
				std::cout << "| 1024 ";
			if(_board.at(_taille_grille*x+y)==2048){
				std::cout << "| 2048 ";
				tmp=1;
			}
		}
		std::cout << "|" << std::endl;
	std::cout << ligne << std::endl;
	}

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
	for(int k=0;k<(_taille_grille*_taille_grille);k++){
		_board.push_back(0);
	}
	for(int k=0;k<(_taille_grille*_taille_grille);k++){
		_board.at(k)=0;
	}
	int nb=rand()%2 + 1;
	for(int k=0;k<nb;++k){
		int emplacement=rand()%(_taille_grille*_taille_grille-1);
		_board.at(emplacement)=generateur_valeur();
	}
}

void Grille::fusion_horizontale(){
	for(int k=0;k<_taille_grille;++k){
		for(int j=0;j<(_taille_grille-1);++j){
			if(_board.at(_taille_grille*k+j) ==_board.at(_taille_grille*k+j+1)){
				_board.at(_taille_grille*k+j) = _board.at(_taille_grille*k+j)*2;
				_board.at(_taille_grille*k+j+1) = 0; 
			}
		}
	}	
}
void Grille::mv_droite(){
	int S=0;
	for(int k=0;k<_taille_grille;++k){
		for(int j=(_taille_grille-1);j>0;j--){
			for(int i=j;i>0;--i){
				if(_board.at(_taille_grille*k+i)==0){
					S = _board.at(_taille_grille*k+i);
					_board.at(_taille_grille*k+i) = _board.at(_taille_grille*k+i-1);
					_board.at(_taille_grille*k+i-1) = S;
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
	for(int k=0;k<_taille_grille;++k){
		for(int j=0;j<(_taille_grille-1);j++){
			for(int i=j;i<(_taille_grille-1);++i){
				if(_board.at(_taille_grille*k+i)==0){
					S = _board.at(_taille_grille*k+i);
					_board.at(_taille_grille*k+i) = _board.at(_taille_grille*k+i+1);
					_board.at(_taille_grille*k+i+1) = S;
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
	for(int k=0;k<_taille_grille;++k){
		for(int i=0;i<(_taille_grille-1);++i){
			if(_board.at(_taille_grille*i+k) == _board.at(_taille_grille*(i+1)+k)){
				_board.at(_taille_grille*i+k) =_board.at(_taille_grille*i+k)*2;
				_board.at(_taille_grille*(i+1)+k) = 0;
			}
		}
	}
}
void Grille::mv_haut(){
	int S=0;
	for(int k=0;k<_taille_grille;++k){
		for(int j=0;j<(_taille_grille-1);++j){
			for(int i=j;i<(_taille_grille-1);++i){
				if(_board.at(_taille_grille*i+k)==0){
					S = _board.at(_taille_grille*i+k);
					_board.at(_taille_grille*i+k) = _board.at(_taille_grille*(i+1)+k);
					_board.at(_taille_grille*(i+1)+k) = S;
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
	for(int k=0;k<_taille_grille;++k){
		for(int j=(_taille_grille-1);j>0;--j){
			for(int i=j;i>0;--i){
				if(_board.at(_taille_grille*i+k)==0){
					S = _board.at(_taille_grille*(i-1)+k);
					_board.at(_taille_grille*(i-1)+k) = _board.at(_taille_grille*i+k);
					_board.at(_taille_grille*i+k) = S;
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
	std::vector<int> tmp2 = _board;
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
	int emplacement=rand()%(_taille_grille*_taille_grille-1);
	while (_board.at(emplacement) != 0){
		emplacement=rand()%(_taille_grille*_taille_grille-1);
	}
	_board.at(emplacement)=nb;
}

void Grille::deplacement(){
	std::cout << "z = haut, s = bas, d = droite, q = gauche et m = menu" << std::endl;
	std::cout << "Appuyer sur une touche :" << std::endl;
	bool fin = fin_jeu();
	std::string move = "";
	std::cin >> move;
	std::vector<int> tmp = {0};
	
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

		if(move == "m"){
			play();
		}
	}
}
void Grille::deplacement_auto(std::string direction){
	bool fin = fin_jeu();
	std::vector<int> tmp = {0};
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
	std::cout << "Choisissez une taille de grille :" << std::endl;
	std::cin >> _taille_grille;
	std::cout << "Il y a 2 modes de jeu : soit automatique, soit manuel. Veuillez séléctionner le mode qui vous intérresse :" << std::endl;
	std::cout << "m = manuel , a = automatique et e = exit" << std::endl;
	std::cin >> mode;
	init();
	if(mode=="m" || mode=="M"){
		jeu_manuel();
	}
	if(mode=="a" || mode=="A"){
		jeu_auto();
	}
	if(mode=="e" || mode=="E"){
		sortie();
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
	std::vector<int> tmp = {0};

	init();
	affichage();		
	while(fin_jeu() && end)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
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