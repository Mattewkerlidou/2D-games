#include"Item.h"

Item::Item(){
    _itemx=0;
    _itemy=0;
    _spritex=0;
    _spritey=0;
}

Item::Item(int itemx,int itemy,int spritex,int spritey,Image sprite){
    _itemx=itemx;
    _itemy=itemy;
    _spritex=spritex;
    _spritey=spritey;
    _sprite=sprite;
    _sprite.selectionnerRectangle(_itemx,_itemy,TAILLE_CASE,TAILLE_CASE);

}

void Item::draw() const{
    _sprite.dessiner(_itemx,_itemy);
}
