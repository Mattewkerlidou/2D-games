#ifndef Item_H
#define Item_H
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "Image.h" 
#include "Moteur.h" 

using namespace std;

class Item {
private:
    Image _sprite;
    int _itemx,_itemy,_spritex,_spritey;
    string _nom,_type;
public:
    Item();
    
    Item(string nom,int itemx,int itemy,Image sprite);
    Item(string nom,string type,int spritex,int spritey);
    Item(string nom,string type,int itemx,int itemy,int spritex,int spritey,Image sprite);



    //Item(int itemx,int itemy,int spritex,int spritey,Image sprite);

    void draw() const;

    void affichertous();

    int getitemx();

    int getitemy();

    int getspritex();

    int getspritey();

    string getnom();

    string gettype();
    
    Image getsprite ();



    
    


};
#endif
