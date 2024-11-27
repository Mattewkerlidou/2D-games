#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
    // Initialisation du jeu
    Moteur moteur("Mon super jeu vidéo");

    // TODO: charger images, creer personnages, etc.

    bool quitter = false, chest=false;
    int x=0,y=0;
    Image fond, chest_close, chest_open;
    try
    {
        fond = Image(moteur, "assets/fond.png");
        chest_close = Image(moteur,"assets/coffre_ferme.png");
        chest_open = Image(moteur,"assets/coffre_ouvert.png");
    }
    catch (const invalid_argument& e )
    {
        cerr << "L'image spécifiée n'a pas été trouvé " << endl;
    }

    // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
    // (en general, 60 fois par seconde)
    while (!quitter)
    {
        // I. Gestion des evenements

        Evenement evenement = moteur.evenementRecu();
        while (evenement != AUCUN)
        {
            switch (evenement)
            {
            // QUITTER = croix de la fenetre ou Echap
            case QUITTER_APPUYE:
                quitter = true;
                break;
            // TODO: gerer les autres evenements
            case ESPACE_APPUYE:
                chest= true;
                break;
            case ESPACE_RELACHE:
                chest= false;
                break;
            case DROITE_APPUYE:
                x+=TAILLE_CASE;
                break;
            case HAUT_APPUYE:
                y-=TAILLE_CASE;
                break;
            case GAUCHE_APPUYE:
                x-=TAILLE_CASE;
                break;
            case BAS_APPUYE:
                y+=TAILLE_CASE;
                break;
            default:
                break;
            }

            evenement = moteur.evenementRecu();
        }

        // II. Mise à jour de l'état du jeu

        // TODO: faire bouger vos personnages, etc.

        // III. Generation de l'image à afficher

        moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

        // TODO: afficher vos personnages, objets, etc.
        fond.dessiner(0,0);

        if(chest){

            chest_open.dessiner(x,y);
        }
        else{
            chest_close.dessiner(x,y);
        }
        /*
          Affiche l'image en se cadencant sur la frequence de
          rafraichissement de l'ecran (donc va en general mettre le
          programme en pause jusqu'a ce que l'ecran soit rafraichi). En
          general, 60 images fois par seconde, mais ca peut dependre du
          materiel
        */
        moteur.finaliserRendu();
    }

    return 0;
}