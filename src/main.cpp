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

	bool quitter = false/*,win=false,lose=false /*chest=false*/;
	int x=0,y=0;
	Image fond, chest_close, chest_open,mcharac,spritenemie,spritenemie2,gameover;
	try
	{
		fond = Image(moteur, "assets/fond.png");
		//chest_close = Image(moteur,"assets/coffre_ferme.png");
		//chest_open = Image(moteur,"assets/coffre_ouvert.png");
		mcharac = Image(moteur,"assets/personnages.png");
		spritenemie= Image(moteur,"assets/personnages.png");
		spritenemie= Image(moteur,"assets/personnages.png");
		gameover= Image(moteur,"assets/gameover.png");


	}
	catch (const invalid_argument& e )
	{
		cerr << "L'image spécifiée n'a pas été trouvé " << endl;
	}
	Personnage hero , enemie, enemie2;
	hero = Personnage(x,y,4*TAILLE_CASE,0*TAILLE_CASE,2,mcharac);
	enemie = Personnage( 5*TAILLE_CASE , TAILLE_CASE, 10*TAILLE_CASE,0*TAILLE_CASE,1,spritenemie);
	enemie2 = Personnage( TAILLE_CASE ,5*TAILLE_CASE, 1*TAILLE_CASE,0*TAILLE_CASE,3,spritenemie);


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
				//chest= true;
				break;
			case ESPACE_RELACHE:
				//chest= false;
				break;
			case DROITE_APPUYE:
				if(hero.getcoox()!=LARGEUR_FENETRE-TAILLE_CASE){
					hero.mouveright();
				}
				break;
			case HAUT_APPUYE:
				if (hero.getcooy()!=0){
					hero.mouveup();
				}		
				break;
			case GAUCHE_APPUYE:
				if (hero.getcoox()!=0){
					hero.mouveleft();
				}
				break;
			case BAS_APPUYE:
				if (hero.getcooy()!=HAUTEUR_FENETRE-TAILLE_CASE){
					hero.mouvedown();
				}
				break;
			default:
				break;
			}

			evenement = moteur.evenementRecu();
		}

		// II. Mise à jour de l'état du jeu

		// TODO: faire bouger vos personnages, etc.
		if(moteur.animationsAmettreAjour()){
			enemie2.avancer(enemie2.getdirection());
			enemie.avancer(enemie.getdirection());
		}
		// III. Generation de l'image à afficher

		moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

		// TODO: afficher vos personnages, objets, etc.
		fond.dessiner(0,0);
		/*if(chest){
			chest_open.dessiner(16,16);
		}
		else{
			chest_close.dessiner(16,16);
		}*/
		enemie.draw();
		enemie2.draw();
		hero.draw();
		/*if (lose=((enemie.getcoox()==hero.getcoox() && enemie.getcooy()==hero.getcooy())||(enemie2.getcoox()==hero.getcoox() && enemie2.getcooy()==hero.getcooy()) )){
			quitter = true;
			moteur.initialiserRendu();
			gameover.dessiner(LARGEUR_FENETRE/4,HAUTEUR_FENETRE/2);
			moteur.attendre(2);
		}*/
		
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