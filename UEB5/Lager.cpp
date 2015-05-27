/*
 * Lager.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Simon
 */

#include "Lager.h"
Lager::Lager(int maxAnzArtikel) {
	this->anzArtikel = ARTIKELANZAHL;
	this->maxAnzArtikel = maxAnzArtikel;
	this->name = MUSTERLAGER;
	this->artikelTab = new Artikel*[maxAnzArtikel];
}
Lager::Lager(int maxAnzArtikel, string name){
	this->anzArtikel = ARTIKELANZAHL;
	this->maxAnzArtikel = maxAnzArtikel;
	this->name = name;
	this->artikelTab = new Artikel*[maxAnzArtikel];
}
Lager::~Lager() {
	// TODO Auto-generated destructor stub
}

void Lager::createArtikel(int artikelNr, string bezeichnung, double artikelPreis){
	Artikel* ap = new Artikel(artikelNr, bezeichnung, artikelPreis);
	artikelTab[anzArtikel] = ap;
	anzArtikel++;
}
void Lager::createArtikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand){
	Artikel* ap = new Artikel(artikelNr,bezeichnung,artikelPreis,bestand);
	artikelTab[anzArtikel] = ap;
	anzArtikel++;
}
void Lager::deleteArtikel(int artikelNr){
	int i = findeArtikel(artikelNr);
	if(i >= 0){
		delete artikelTab[i];
		// letztes Konto an die Stelle i setzen
		if(i != anzArtikel-1){
			artikelTab[i] = artikelTab[anzArtikel-1];
		}
		artikelTab[anzArtikel-1] = 0;
		anzArtikel--;
	}
}
void Lager::bucheAbgang(Artikel* artikel, int menge){
	artikel->bucheAbgang(menge);
}

void Lager::bucheZugang(Artikel* artikel, int menge){
	artikel->bucheZugang(menge);
}
void Lager::preiseAendern(double preisAenderung){
	for(int i = 0; i < anzArtikel; i++){
		artikelTab[i]->aenderePreis(preisAenderung);
	}
}
int Lager::findeArtikel(int artikelNr){
	for(int i = 0; i < anzArtikel; i++){
	if (artikelNr == artikelTab[i]->getArtikelNr()){
			return i;
		}
	}
	return -1;
}
void Lager::loescheAlleArtikel(){
	for(int i = 0; i < anzArtikel; i++){
		delete artikelTab[i];
	}
	anzArtikel = 0;
}

