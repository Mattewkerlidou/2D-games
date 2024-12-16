#include"Item.h"

Item::Item(){
	_itemx=0;
	_itemy=0;
}

Item::Item(string nom,int itemx,int itemy,Image sprite){
	_nom=nom;
	_itemx=itemx;
	_itemy=itemy;
	_sprite=sprite;
}
Item::Item(string nom,string type,int spritex,int spritey){
	_nom=nom;
	_type=type;
	_spritex=spritex;
	_spritey=spritey;
}
Item::Item(string nom,string type,int itemx,int itemy,int spritex,int spritey,Image sprite){
	_nom=nom;
	_type=type;
	_itemx=itemx;
	_itemy=itemy;
	_spritex=spritex;
	_spritey=spritey;
	_sprite=sprite;
	_sprite.selectionnerRectangle(_spritex,_spritey,TAILLE_CASE,TAILLE_CASE);
}


void Item::draw() const{
	_sprite.dessiner(_itemx,_itemy);
}
void Item::affichertous(){
	cout<<"Ton items est :"<<_nom <<" au position x : "<<_itemx<<" et y : "<<_itemy<<" sont sprite est aux position spritex : "<<_spritex<<" et spritey : "<<_spritey<<" et est de type :"<<_type<<endl;
}

    int Item::getitemx(){
		return _itemx;
	}

    int Item::getitemy(){
		return _itemy;
	}

    int Item::getspritex(){
		return _spritex;
	}

    int Item::getspritey(){
		return _spritey;
	}

    string Item::getnom(){
		return _nom;
	}

    string Item::gettype(){
		return _type;
	}
    Image Item::getsprite (){
		return _sprite;
	}

