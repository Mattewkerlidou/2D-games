#include "Personnage.h"

Personnage::Personnage(){
    _coox=0;
    _cooy=0;
}
Personnage::Personnage(int coox,int cooy,int skin_x,int skin_y,Image sprite){
    _coox=coox;
    _cooy=cooy;
    _sprite=sprite;
    _skinx=skin_x;
    _skiny=skin_y;
    _sprite.selectionnerRectangle(_skinx,_skiny,16,16);
}

void Personnage::draw() const {
    _sprite.dessiner(_coox, _cooy);
}

    void Personnage::mouveright (){
        _coox+=TAILLE_CASE;
        _sprite.selectionnerRectangle(_skinx,_skiny+32,16,16);
    }

    void Personnage::mouveleft (){
        _coox-=TAILLE_CASE;
        _sprite.selectionnerRectangle(_skinx,_skiny+16,16,16);
        
    }
    void Personnage::mouveup (){
        _cooy-=TAILLE_CASE;
        _sprite.selectionnerRectangle(_skinx,_skiny+48,16,16);
    }

    void Personnage::mouvedown (){
        _cooy+=TAILLE_CASE;
        _sprite.selectionnerRectangle(_skinx,_skiny,16,16);
    }
    int Personnage::getcoox(){
        return _coox;
    }
    
    int Personnage::getcooy(){
        return _cooy;
    }
    
