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
/**
* @brief Konstruktor
* @param maxAnzArtikel (optional) muss positiv sein!
* @param name (optional) Name des Lagers darf nicht leer sein!
*/
Lager::Lager(int maxAnzArtikel, string name){
	if(maxAnzArtikel < 1){
		throw LagerException(meldungGroesse);
	}
	if(name.empty()){
		throw LagerException(meldungNameLeer);
	}
	anzArtikel = defaultArtikelAnzahl;
	this->maxAnzArtikel = maxAnzArtikel;
	this->name = name;
	this->artikelTab = new Artikel*[maxAnzArtikel];

}
/**
* @brief Destructor loescht alle Artikel
*/
Lager::~Lager() {
	loescheAlleArtikel();
	delete[] artikelTab;
}

/**
* @brief Eintragen eines neuen Artikels ohne Bestandsangabe
* @details Artikel wird am Ende ins ArtikelTab eingetragen, falls moeglich
* @param artikelNr
* @param bezeichnung
* @param artikelPreis
*/
void Lager::createArtikel(int artikelNr, string bezeichnung, double artikelPreis){
	int i = findeArtikel(artikelNr);
	if (i == -1){
		Artikel* ap = new Artikel(artikelNr, bezeichnung, artikelPreis);
		artikelTab[anzArtikel] = ap;
		anzArtikel++;
	}
}
/**
* @brief Eintragen eines neuen Artikels mit Bestandsangabe
* @details Artikel wird am Ende ins ArtikelTab eingetragen, falls moeglich
* @param artikelNr
* @param bezeichnung
* @param artikelPreis
* @param bestand
*/
void Lager::createArtikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand){
	int i = findeArtikel(artikelNr);
	if (i == -1){
		Artikel* ap = new Artikel(artikelNr, bezeichnung, artikelPreis, bestand);
		artikelTab[anzArtikel] = ap;
		anzArtikel++;
	}
}
/**
* @brief deleteArtikel Entfernen eines Artikels aus dem Lager
* @param artikelNr
*/
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
/**
* @brief bucheZugang erhoeht den bestand
* @param artikelNr
* @param menge
*/
void Lager::bucheAbgang(int artikelNr, int menge){
	int i = findeArtikel(artikelNr);
	if (i >= 0 ){
		int index = findeArtikel(artikelNr);
		artikelTab[index]->bucheAbgang(menge);
	}
}
/**
* @brief bucheAbgang verringert den bestand
* @param artikelNr
* @param menge
*/
void Lager::bucheZugang(int artikelNr, int menge){
	int i = findeArtikel(artikelNr);
	if (i >= 0 ){
		int index = findeArtikel(artikelNr);
		artikelTab[index]->bucheZugang(menge);
	}
}
/**
* @brief preiseAendern aendert alle preise prozentual
* @param preisaenderung
*/
void Lager::preiseAendern(double preisAenderung){
	for (int i = 0; i < anzArtikel; i++){
		artikelTab[i]->aenderePreis(preisAenderung);
	}

}
/**
* @brief findeArtikel Findet einen Artikel
* @param artikelNr
*/
int Lager::findeArtikel(int artikelNr){
	for(int i = 0; i < anzArtikel; i++){
	if (artikelNr == artikelTab[i]->getArtikelNr()){
			return i;
		}
	}
	return -1;
}
/**
* @brief loescheAlleArtikel loesche alle artikel
* @param artikelNr
*/
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
