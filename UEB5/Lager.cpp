/*
 * Lager.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Simon
 */

#include "Lager.h"

Lager::Lager(int maxAnzArtikel) {
	this->anzArtikel = 0;
	this->maxAnzArtikel = maxAnzArtikel;
	this->name = "Musterlager";
	this->sortiment = new Artikel*[maxAnzArtikel];
}
Lager::Lager(int maxAnzArtikel, string name){
	this->anzArtikel = 0;
	this->maxAnzArtikel = maxAnzArtikel;
	this->name = name;
	this->sortiment = new Artikel*[maxAnzArtikel];
}
Lager::~Lager() {
	// TODO Auto-generated destructor stub
}

void Lager::createArtikel(int artikelNr, string bezeichnung, double artikelPreis){
	Artikel* ap = new Artikel(artikelNr,bezeichnung,artikelPreis);
	sortiment[anzArtikel++]=ap;
}
void Lager::createArtikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand){
	Artikel* ap = new Artikel(artikelNr,bezeichnung,artikelPreis,bestand);
	sortiment[anzArtikel++]=ap;
}
void Lager::deleteArtikel(int artikelNr){
	int i = findeArtikel(artikelNr);
	if(i >= 0){
		delete sortiment[i];
		// letztes Konto an die Stelle i setzen
		if(i != anzArtikel-1){
			sortiment[i] = sortiment[anzArtikel-1];
		}
		sortiment[--anzArtikel] = 0;
	}
}

