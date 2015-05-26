/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb03 *.o
* @file Artikel.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 16.05.2015
*
* Artikel Funktionen
*
*/
#include <sstream>
#include "Artikel.h"
#include <cmath>
/**
* @brief Konstruktor mit 3 Parametern
* @details Konstruktor zur Erzeugung eines Artikel Obj ohne Bestandsangabe
* @param artikelNr muss vierstellig sein!
* @param bezeichnung darf kein leerer String sein!
* @param artikelPreis darf nicht negativ sein!
*/
Artikel::Artikel(int artikelNr, string bezeichnung, double artikelPreis){
	if (artikelNr < LOWERBORDERARTIKELNUMMER || artikelNr > UPPERBORDERARTIKELNUMMER) {
		throw THROWARTIKELNUMMERERROR;
	}
	if (bezeichnung.empty()){
		throw THROWBEZEICHNUNGERROR;
	}
	if(artikelPreis <= 0){
		throw THROWPREISERROR;
		}
	this->artikelNr = artikelNr;
	this->bezeichnung = bezeichnung;
	this->bestand = 0;
	this->artikelPreis=artikelPreis; //TODO EINGABE?
}
/**
* @brief Konstruktor mit 4 Parametern
* @details Konstruktor zur Erzeugung eines Artikel Obj mit Bestandsangabe
* @param artikelNr muss vierstellig sein!
* @param bezeichnung darf kein leerer String sein!
* @param artikelPreis darf nicht negativ sein!
* @param bestand darf nicht negativ sein!
*/

Artikel::Artikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand){
	if (artikelNr < LOWERBORDERARTIKELNUMMER || artikelNr > UPPERBORDERARTIKELNUMMER) {
		throw THROWARTIKELNUMMERERROR;
	}
	if (bezeichnung.empty()){
		throw THROWBEZEICHNUNGERROR;
	}
	if (bestand < 0){
		throw THROWBESTANDERROR;
	}
	if(artikelPreis <= 0){
		throw THROWPREISERROR;
	}
	this->artikelNr = artikelNr;
	this->bezeichnung = bezeichnung;
	this->bestand = bestand;
	this->artikelPreis=artikelPreis;
}


/**
* @brief bucheZugang
* @details Funktion zum erhoehen des Bestands
* @param menge muss positiv sein!
*/
void Artikel::bucheZugang(int menge){
	if(menge <= 0){
		throw THROWONLYPOSITIVEALLOWEDERROR;
	}

	bestand += menge;
}
/**
* @brief bucheAbgang
* @details Funktion zum verringern des Bestands
* @param menge muss positiv sein!
*/
void Artikel::bucheAbgang(int menge){
	if(menge <= 0){
		throw THROWONLYPOSITIVEALLOWEDERROR;
	}
	if (bestand - menge < 0){
		throw THROWBESTANDREDUCEERROR;
	}
	bestand -= menge;
}
/**
* @brief setBestand bei Inventur
* @details Funktion zum setzen des Bestands
* @param neuBestand darf nicht negativ sein!
*/
void Artikel::setBestand(int neuBestand){
	if (neuBestand < 0){
		throw THROWBESTANDERROR;
	}
	bestand = neuBestand;

}
/**
* @brief setBezeichnung
* @details Funktion zum setzen der Bezeichnung
* @param neuBezeichnung darf nicht leer sein!
*/
void Artikel::setBezeichnung(string neuBezeichnung){
	if (neuBezeichnung.empty()){
		throw THROWBEZEICHNUNGERROR;
	}
	bezeichnung = neuBezeichnung;
}
/**
* @brief Set neuer Preis
* @param neuPreis darf nicht negativ sein!
*/
void Artikel::setPreis(double neuPreis){
	if(neuPreis < 0){
		throw THROWPREISERROR;
	}
	artikelPreis=round(neuPreis*100)/100.0; // auf zwei stellen runden
}
/**
 * @brief Preisaenderung
 * @param preisaenderung in Prozent (max. 99%)
 */
void Artikel::aenderePreis(double preisaenderung){
	if (abs(preisaenderung) > 100 ){
		throw THROWCHARGETOODAMNHIGHERROR;
	}	if (abs(preisaenderung) == 0){
		throw THROWZEROORNANERROR;
	}
	artikelPreis*=(1+(preisaenderung/100));
	artikelPreis=round(artikelPreis*100)/100;
}

string Artikel::toString() const {
	ostringstream o;
	o << ARTIKELNUMMER << artikelNr << "\t"
	  << BEZEICHNUNG << bezeichnung << "\t "
	  << ARTIKELPREIS << artikelPreis << "\t"
	  << BESTAND << bestand;
	return o.str();
}