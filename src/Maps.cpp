#include "Maps.h"
void Maps::init(const string& namefiles,Image sprite){
	ifstream read;
	string nom;
	int x,y;
	read.open(namefiles);
	if(!read.is_open()){
        throw string ("l'ouverture du fichier a echoue : " + namefiles);
	}
	read>>_nbElement;
	while (!read.eof()){
		read>>nom;
		read>>x;
		read>>y;
		_carte.push_back(Item(nom,x,y,sprite));
	}
	read.close();
}

void Maps::afficher3(){
	
	cout<<_nbElement;
	for (int i=0;i<_nbElement;i++){
		_carte[i].affichertous();
	}
}


void Maps::init2(const string& namefiles){
	ifstream read;
	string nom,type;
	int x,y;
	read.open(namefiles);
	if(!read.is_open()){
        throw string ("l'ouverture du fichier a echoue : " + namefiles);
	}
	read>>_nbElement;
	while (!read.eof()){
		read>>nom;
		read>>x;
		read>>y;
		read>>type;
		_carte.push_back(Item(nom,type,x,y));
	}
	read.close();

	
}

void Maps::recherchedico(Maps dico) {

    for (int i = 0; i < _nbElement; i++) {
        int debut = 0;
        int fin = dico._carte.size() - 1;
        bool trouve = false;
        int j = -1;

        while (debut <= fin && !trouve) {
            int milieu = (debut + fin) / 2;
            if (dico._carte[milieu].getnom() == _carte[i].getnom()) {
                trouve = true;
                j = milieu;
            } else if (_carte[i].getnom() < dico._carte[milieu].getnom()) {
                fin = milieu - 1;
            } else {
                debut = milieu + 1;
            }
        }

        // Mise à jour de _carte[i] si une correspondance est trouvée
        if (trouve && j != -1) {
            _carte[i] = Item(_carte[i].getnom(),dico._carte[j].gettype(),_carte[i].getitemx()*TAILLE_CASE,_carte[i].getitemy()*TAILLE_CASE,dico._carte[j].getspritex()*TAILLE_CASE,dico._carte[j].getspritey()*TAILLE_CASE,_carte[i].getsprite());
        }
    }
}
void Maps::drawmaps(){
	for (int i=0;i<_nbElement;i++){
		_carte[i].draw();
	}
}

