#include "Dragon.h"
#include "Personnage.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <time.h>
using namespace std;

Dragon::Dragon() {
	x = -10;
	y = -10;
	hauteur = 4;
	salle = 0;
	phase = 1;
	base = 0;
	dir = 1 ;
	dirX = -1;
	vie = 6;
	vieTotale = 10;
	testVague = 0;
	testBouton = 0;
}

int Dragon::getX () const { return x; }

int Dragon::getY () const { return y; }

int Dragon::getPhase () const { return phase; }

int Dragon::getSalle () const { return salle; }

int Dragon::getBase () const { return base; }

int Dragon::getDir () const { return dir; }
	
int Dragon::getDirX () const { return dirX; }

int Dragon::getHitbox (const int n) const { return hitbox[n]; }

int Dragon::getVie () const { return vie; }

int Dragon::getVieTotale () const { return vieTotale; }

int Dragon::getTestVague () const { return testVague; }

int Dragon::getTestBouton () const { return testBouton; }

void Dragon::setTestVague (const int nvTestVague) { testVague = nvTestVague;}

void Dragon::setTestBouton (const int nvTestBouton) { testBouton = nvTestBouton;}

void Dragon::setVie (const int nvVie) { vie = nvVie;}

void Dragon::setVieTotale (const int nvVieTotale) { vieTotale = nvVieTotale;}

void Dragon::setHitbox (const int n, const int nvHitbox) { hitbox[n] = nvHitbox;}

void Dragon::setDir (const int posDir) { dir = posDir; }

void Dragon::setDirX (const int posDirX) { dirX = posDirX; }

void Dragon::setBase (const int nvBase) { base = nvBase; }

void Dragon::setX (const int posX) { x = posX; }

void Dragon::setY (const int posY) { y = posY; }

void Dragon::setSalle (const int numSalle) { salle = numSalle; }

void Dragon::setPhase (const int nvPhase) { phase = nvPhase; }

void Dragon::mortDragon (Terrain & t) {
		x=-10;
		y=-10;
		t.setXY(759,13,'^');
		t.setXY(759,12,'&');
		detruireHitbox(t);
}

void Dragon::creerHitbox(Terrain & t){
	for ( int k=-1;k<7;k++) {
		for ( int i=-2; i<6;i++) {
			if (t.getXY(x+k,y-i) == 'd' || t.getXY(x+k,y-i) == 'o') {
				t.setXY(x+k,y-i,' ');
			}
		}
	}

	for ( int k=0;k<6;k++){
		for (unsigned int i = 0; i <4; i++) {
			if ((k == 0 || k == 5) && t.getXY(x+k,y-i) == ' ') {
				t.setXY(x+k,y-i,'o');
			}
			else if (t.getXY(x+k,y-i) == ' ') {
				t.setXY(x+k,y-i,'d');
			}
		}
	}
}


void Dragon::bougeAuto ( Terrain & t) {
	if (dir == -1) {
		if (t.estPositionEnnemisValideVolant(x,y+dir+(dir*hauteur))) {
			y = y+dir;
		}
		else {
			dir = -dir;
		}
	}
	else {
		if (t.estPositionEnnemisValideVolant(x,y+dir)){
			y = y+dir;
		}
 		else {
			dir = -dir;
		}
	}
	creerHitbox(t);
}

void Dragon::detruireHitbox(Terrain & t){
	for ( int k=-1;k<7;k++) {
		for ( int i=-2; i<6;i++) {
			if (t.getXY(x+k,y-i) == 'd' || t.getXY(x+k,y-i) == 'o') t.setXY(x+k,y-i,' ');
		}
	}
}


void Dragon::mortPhase1(Terrain & t){
	unsigned int k=664;
	dirX = 1;
	while ((t.getXY(k,14) == '#') || (t.getXY(k,14) == '@')) {
		if(k<677) {
			k++;
		}
		else break;
	}
	t.setXY(k,14,'@');
	if (x < 680) {
		if (y > 5) {
			x++;
			y--;
		}
		else x++;
	}
	else {
		detruireHitbox(t);
		x = 710;
		y = 13;
		vie = 3;
		salle = 18; 
		phase = 2;
		testVague = 0;
		dirX = -1;
	}
	creerHitbox(t);
}



void Dragon::phase2(Terrain & t, unsigned int test) {
	int randomX = rand()%30 + 1;
	int randomType = rand()%3 + 1;
	if ((vie > 0) && (y > 5) && (testVague > 0)) y--; 
	if (y == 5 && test == 1 && testVague > 0) {
		if (randomType == 1) t.setXY(680+randomX,6,'Z');
		else if (randomType == 2) t.setXY(680+randomX,6,'B');
		else if (randomType == 3) t.setXY(683+randomX,6,'S');
		testVague--;
	}
	else if (testVague == 0 && y<13) y++;
	creerHitbox(t);
}


void Dragon::mortPhase2(Terrain & t) {
	unsigned int k=712;
	unsigned int m=13;
	dirX = 1;
	while (t.getXY(k,m) == '?') {
		if(k<720) {
			k++;
			m--;
		}
		else break;
	}
	for (unsigned int i = k; i < 719; i++) t.setXY(i,m,'?');
	if (x < 720) {
		if (y > 5) {
			y--;
		}
		else x++;
	}
	else {
		detruireHitbox(t);
		x = 753;
		y = 4;
		vie = 1;
		salle = 19; 
		phase = 3;
		dirX = -1;
	}
	creerHitbox(t);
}

void Dragon::phase3(Terrain & t, int xPerso, int yPerso) {
	unsigned int k = 721;
	unsigned int m = 14;
	unsigned int j = 4; 

	if (xPerso >= 728 && yPerso < 11 && testBouton != 1) {
		while (t.getXY(k,m) == '!') {
			m--;
		}
		for (unsigned int i = k; i < 759; i++) t.setXY(i,m,'!');
	}
	
	if (t.getXY(xPerso,yPerso) == ')') testBouton = 1;
	if (testBouton == 1) {
		while (t.getXY(k,j) == ' ') {
			j++;
		}
		for (unsigned int i = k; i < 759; i++) {
				if (t.getXY(i,j) != '#') t.setXY(i,j,' ');
		}
	}
	if (j == 14) {
		for (unsigned int i = k; i < 759; i++) {
				t.setXY(i,14,'#');
		}
		if (y < 13) y++;
	}
		
	creerHitbox(t);	
}





