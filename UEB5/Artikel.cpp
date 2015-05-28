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
* @brief Konstruktor
* @details Konstruktor zur Erzeugung eines Artikel Obj; Bestandsangabe optional
* @param artikelNr muss vierstellig sein!
* @param bezeichnung darf kein leerer String sein!
* @param artikelPreis darf nicht negativ sein!
* @param bestand (optional) darf nicht negativ sein!
*/

Artikel::Artikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand) throw(ArtikelException){
	if (artikelNr < LOWERBORDERARTIKELNUMMER || artikelNr > UPPERBORDERARTIKELNUMMER) {
		throw ArtikelException(THROWARTIKELNUMMERERROR);
	}
	if (bezeichnung.empty()){
		throw ArtikelException(THROWBEZEICHNUNGERROR);
	}
	if (bestand < 0){
		throw ArtikelException(THROWBESTANDERROR);
	}
	if(artikelPreis <= 0){
		throw ArtikelException(THROWPREISERROR);
	}
	this->artikelNr = artikelNr;
	this->bezeichnung = bezeichnung;
	this->bestand = bestand;
	this->artikelPreis = artikelPreis;
}

/**
* @brief bucheZugang
* @details Funktion zum erhoehen des Bestands
* @param menge muss positiv sein!
*/
void Artikel::bucheZugang(int menge) throw(ArtikelException){
	if(menge <= 0){
		throw ArtikelException(THROWONLYPOSITIVEALLOWEDERROR);
	}

	bestand += menge;
}
/**
* @brief bucheAbgang
* @details Funktion zum verringern des Bestands
* @param menge muss positiv sein!
*/
void Artikel::bucheAbgang(int menge)  throw(ArtikelException){
	if(menge <= 0){
		throw ArtikelException(THROWONLYPOSITIVEALLOWEDERROR);
	}
	if (bestand - menge < 0){
		throw ArtikelException(THROWBESTANDREDUCEERROR);
	}
	bestand -= menge;
}
/**
* @brief setBestand bei Inventur
* @details Funktion zum setzen des Bestands
* @param neuBestand darf nicht negativ sein!
*/
void Artikel::setBestand(int neuBestand)  throw(ArtikelException){
	if (neuBestand < 0){
		throw ArtikelException(THROWBESTANDERROR);
	}
	bestand = neuBestand;

}
/**
* @brief setBezeichnung
* @details Funktion zum setzen der Bezeichnung
* @param neuBezeichnung darf nicht leer sein!
*/
void Artikel::setBezeichnung(string neuBezeichnung)  throw(ArtikelException){
	if (neuBezeichnung.empty()){
		throw ArtikelException(THROWBEZEICHNUNGERROR);
	}
	bezeichnung = neuBezeichnung;
}
/**
* @brief Set neuer Preis
* @param neuPreis darf nicht negativ sein!
*/
void Artikel::setPreis(double neuPreis) throw(ArtikelException){
	if(neuPreis < 0){
		throw ArtikelException(THROWPREISERROR);
	}
	artikelPreis=round(neuPreis*100)/100.0; // auf zwei stellen runden
}
/**
 * @brief Preisaenderung
 * @param preisaenderung in Prozent (max. 99%)
 */
void Artikel::aenderePreis(double preisaenderung) throw(ArtikelException){
	if (abs(preisaenderung) > 100 ){
		throw ArtikelException(THROWCHARGETOODAMNHIGHERROR);
	}	if (abs(preisaenderung) == 0){
		throw ArtikelException(THROWZEROORNANERROR);
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
ostream& operator<<(ostream& o, const Artikel& artikel) {
	return o << artikel.toString();
}
