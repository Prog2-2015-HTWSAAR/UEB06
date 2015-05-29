/*
 * Lager.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Simon
 */

#include "Lager.h"
#include <sstream>
#include <cmath>
const char* Lager::defaultName = "Musterlager";
const char* Lager::meldungGroesse = "Lagergroesse muss positiv sein!";
const char* Lager::meldungNameLeer = "Lagername darf nicht leer sein!";
Lager::Lager(int maxAnzArtikel, string name){
	if(maxAnzArtikel < 1){
		throw LagerException(meldungGroesse);
	}
	if(name.empty()){
		throw LagerException(meldungNameLeer);
	}
	anzArtikel = ARTIKELANZAHL;
	this->maxAnzArtikel = maxAnzArtikel;
	this->name = name;
	this->artikelTab = new Artikel*[maxAnzArtikel];

}

Lager::~Lager() {
	loescheAlleArtikel();
	delete[] artikelTab;
}


void Lager::createArtikel(int artikelNr, string bezeichnung, double artikelPreis){
	int i = findeArtikel(artikelNr);
	if (i == -1){
		Artikel* ap = new Artikel(artikelNr, bezeichnung, artikelPreis);
		artikelTab[anzArtikel] = ap;
		anzArtikel++;
	}
}
void Lager::createArtikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand){
	int i = findeArtikel(artikelNr);
	if (i == -1){
		Artikel* ap = new Artikel(artikelNr, bezeichnung, artikelPreis, bestand);
		artikelTab[anzArtikel] = ap;
		anzArtikel++;
	}
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
void Lager::bucheAbgang(int artikelNr, int menge){
	int i = findeArtikel(artikelNr);
	if (i != -1 && menge > NULL){
		int index = findeArtikel(artikelNr);
		artikelTab[index]->bucheAbgang(menge);
	}
}

void Lager::bucheZugang(int artikelNr, int menge){
	int i = findeArtikel(artikelNr);
	if (i != -1 && menge > NULL){
		int index = findeArtikel(artikelNr);
		artikelTab[index]->bucheZugang(menge);
	}
}
void Lager::preiseAendern(double preisAenderung){
	for (int i = 0; i < anzArtikel; i++){
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
string Lager::toString() const {
	ostringstream o;
	o << "Lager: " << name << '\n';
	for (int i = 0; i < anzArtikel; i++) {
		o << artikelTab[i]->toString() << '\n';
	}
	o << endl;
	return o.str();
}
ostream& operator<<(ostream& o, const Lager& lager) {
	o << "Lager: " << lager.name << " ";
	o << lager.anzArtikel << "/" << lager.maxAnzArtikel <<'\n';
	for (int i = 0; i < lager.anzArtikel; i++) {
		o << *lager.artikelTab[i] << endl;
	}
	return o;
}
