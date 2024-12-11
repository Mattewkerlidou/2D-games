#include "Personnage.h"

Personnage::Personnage(){
	_coox=0;
	_cooy=0;
	_skinx=0;
	_skiny=0;
	_direction=0;
}
Personnage::Personnage(int coox,int cooy,int skin_x,int skin_y,int direction,Image sprite){
	_coox=coox;
	_cooy=cooy;
	_sprite=sprite;
	_skinx=skin_x;
	_skiny=skin_y;
	_direction=direction;
	_sprite.selectionnerRectangle(_skinx,_skiny+(_direction*16),TAILLE_CASE,TAILLE_CASE);
}

void Personnage::draw() const {
	_sprite.dessiner(_coox, _cooy);
}

	void Personnage::mouveright (){
		_coox+=2;
		updatedirection(2);
		
	}

	void Personnage::mouveleft (){
		_coox-=2;
		updatedirection(1);
		
		
	}
	void Personnage::mouveup (){
		_cooy-=2;
		updatedirection(3);
		

	}

	void Personnage::mouvedown (){
		_cooy+=2;
		updatedirection(0);
		

	}
	int Personnage::getcoox() const {
		return _coox;
	}
	
	int Personnage::getcooy() const{
		return _cooy;
	}

	void Personnage::updatedirection(int a){
		if(_anime){
			if(milieu){
				_sprite.selectionnerRectangle(_skinx,_skiny+(a*16),TAILLE_CASE,TAILLE_CASE);
				milieu=false;
			}
			else{
				_sprite.selectionnerRectangle(_skinx-16,_skiny+(a*16),TAILLE_CASE,TAILLE_CASE);
				_anime=false;
				milieu=true;
			}
		}
		else{
			if(milieu){
				_sprite.selectionnerRectangle(_skinx,_skiny+(a*16),TAILLE_CASE,TAILLE_CASE);
				milieu=false;

			}
			else{
				_sprite.selectionnerRectangle(_skinx+16,_skiny+(a*16),TAILLE_CASE,TAILLE_CASE);
				_anime=true;
				milieu=true;
			}

		}
		
	}


void Personnage::IAmouvetoleft(){
	if(_coox!=0){
		
		updatedirection(_direction);
		_coox-=2;
	}else{
		_direction=2;
		updatedirection(_direction);
	}
}

void Personnage::IAmouvetoright(){
	if(_coox!=LARGEUR_FENETRE-TAILLE_CASE){
		
		updatedirection(_direction);

		_coox+=2;
	}else{
		_direction=1;
		updatedirection(_direction);
	}
}

void Personnage::IAmouvetoup(){
	if(_cooy!=0){
		
		updatedirection(_direction);
		
		_cooy-=2;
	}else{
		_direction=0;
		updatedirection(_direction);
	}
}

void Personnage::IAmouvetodown(){
	if (_cooy!=HAUTEUR_FENETRE-TAILLE_CASE){
		
		updatedirection(_direction);
		_cooy+=2;
	}else{
		_direction=3;
		updatedirection(_direction);
	}
}
void Personnage::avancer (int way) {
	switch (way)
	{
	case 0:
		IAmouvetodown();
		break;
	case 1:
		IAmouvetoleft();
		break;
	case 2:
		IAmouvetoright();
		break;
	case 3:
		IAmouvetoup();
		break;
	default:
		break;
	}
}

int Personnage::getdirection() const{
	return _direction;
}

bool Personnage::touch (Personnage people) const{

	return (people.getcoox()==_coox && people.getcooy()==_cooy);
}
