#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Image.h" 
#include "Moteur.h" 


class Personnage {
private:
    int _coox, _cooy,_skinx,_skiny,_direction;
    Image _sprite;
    bool _anime=false,milieu=false;

public:
    Personnage();

    Personnage(int coox,int cooy,int skin_x,int skin_y,int direction,Image sprite);

    void draw() const;

    void mouveright ();

    void mouveleft ();

    void mouveup ();

    void mouvedown ();
    
    int getcoox() const;
    
    int getcooy()const;

    void updatedirection(int a);

    void IAmouvetoleft();

    void IAmouvetoright();

    void IAmouvetoup();

    void IAmouvetodown();

    void avancer (int way) ;
    
    int getdirection() const;

    bool touch (Personnage people) const;

};
#endif
