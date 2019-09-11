/**
@brief Module gérant le dragon
@file Dragon.h
@date 07/04/2017
*/

#ifndef _DRAGON_H
#define _DRAGON_H

#include "Terrain.h"
#include "Personnage.h"


class Dragon {

private :

	int x,y,hauteur;
	int dir;
	int dirX;
	int salle;
	int phase;
	int base;
	int hitbox[24];
	int vie;
	int vieTotale;
	int testVague;
	int testBouton;

public:

	/**
	@brief Constructeur par défaut du dragon
	*/
    	Dragon();

	/**
	@brief Accesseur à x
	*/
  	int getX () const;

	/**
	@brief Accesseur à salle
	*/
  	int getSalle () const;

	/**
	@brief Accesseur à y
	*/
   	int getY () const;

	/**
	@brief Accesseur à phase
	*/
   	int getPhase () const;


	/**
	@brief Accesseur à base
	*/
	int getBase () const;


	/**
	@brief Accesseur à dir
	*/
	int getDir () const;
	
	/**
	@brief Accesseur à dirX
	*/
	int getDirX () const;

	/**
	@brief Accesseur à hitbox[n]
	*/
	int getHitbox (const int n) const;

	/**
	@brief Accesseur à vie
	*/
	int getVie ()const;

	/**
	@brief Accesseur à vieTotale
	*/
	int getVieTotale ()const;

	/**
	@brief Accesseur à testVague
	*/
	int getTestVague ()const;

	/**
	@brief Accesseur à testBouton
	*/
	int getTestBouton ()const;

	/**
	@brief Mutateur de testVague
	*/
  	void setTestVague (const int nvTestVague);

	/**
	@brief Mutateur de vie
	*/
  	void setVie (const int nvVie);
	
	/**
	@brief Mutateur de testBouton
	*/
  	void setTestBouton (const int nvTestBouton);

	/**
	@brief Mutateur de vieTotale
	*/
  	void setVieTotale (const int nvVieTotale);

	/**
	@brief Mutateur de hitbox[n]
	*/
  	void setHitbox (const int n, const int nvHitbox);

	/**
	@brief Mutateur de dir
	*/
  	void setDir (const int posDir);

	/**
	@brief Mutateur de dirX
	*/
  	void setDirX (const int posDirX);

	/**
	@brief Mutateur de base
	*/
  	void setBase (const int nvBase);

	/**
	@brief Mutateur de x
	*/
  	void setX (const int posX);

	/**
	@brief Mutateur de salle
	*/
  	void setSalle (const int numSalle);

	/**
	@brief Mutateur de y
	*/
   	void setY (const int posY);

	/**
	@brief Mutateur de phase
	*/
   	void setPhase (const int nvPhase);

	/**
	@brief Mort du dragon
	*/
	void mortDragon (Terrain & t);

	/**
	@brief Mouvement automatique du dragon
	*/
    	void bougeAuto (Terrain & t);

	/**
	@brief creer la hitbox du dragon
	*/
	void creerHitbox(Terrain & t);

	/**
	@brief détruit la hitbox du dragon
	*/
	void detruireHitbox(Terrain & t);

	/**
	@brief Animations entre phase 1 et 2
	*/
	void mortPhase1(Terrain & t);

	/**
	@brief Animations entre phase 2 et 3
	*/
	void mortPhase2(Terrain & t);
	
	/**
	@brief Actions de la phase 2
	*/
	void phase2(Terrain & t, unsigned int test);
	
	/**
	@brief Actions de la phase 3
	*/
	void phase3(Terrain & t, int xPerso, int yPerso);	

};
#endif
