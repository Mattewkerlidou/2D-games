#ifndef MAPS_H
#define MAPS_H
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Image.h" 
#include "Moteur.h" 
#include"Item.h"


using namespace std;
class Maps {
private:
    vector <Item> _carte;
    int _nbElement;
    
public:
    
    void init(const string& namefiles,Image sprite);
    void init2(const string& namefiles);

    void afficher3();

    void recherchedico (Maps carte);
    void drawmaps();



};
#endif
