#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Image.h" 
#include "Moteur.h" 

class Personnage {
private:
    int _coox, _cooy,_skinx,_skiny;
    Image _sprite;

public:

    Personnage();

    Personnage(int coox,int cooy,int skin_x,int skin_y,Image sprite);

    void draw() const;

    void mouveright ();

    void mouveleft ();

    void mouveup ();

    void mouvedown ();
    
    int getcoox();
    
    int getcooy();


};

#endif
