#ifndef Item_H
#define Item_H
#include <vector>
#include <iostream>
#include  <string>
#include <fstream>

#include "Image.h" 
#include "Moteur.h" 


class Item {
private:
    Image _sprite;
    int _itemx,_itemy,_spritex,_spritey;
public:
    Item();
    
    Item(int itemx,int itemy,int spritex,int spritey,Image sprite);

    void draw() const;


};
#endif
