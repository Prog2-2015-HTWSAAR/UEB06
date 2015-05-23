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
	if (artikelNr < 1000  || artikelNr > 9999) {
		throw "Die Artikelnummer muss eine 4-stellige positive Zahl sein!";
	}

	if (bezeichnung.empty()){
		throw "Die Bezeichnung eines Artikels darf nicht leer sein!";
	}
	if(artikelPreis <= 0){
			throw "Der Preis darf nie null oder negativ sein!";
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
	if (artikelNr < 1000  || artikelNr > 9999) {
		throw "Die Artikelnummer muss eine 4-stellige positive Zahl sein!";
	}

	if (bezeichnung.empty()){
		throw "Die Bezeichnung eines Artikels darf nicht leer sein!";
	}
	if (bestand < 0){
		throw "Der Bestand darf nie negativ sein!";
	}
	if(artikelPreis <= 0){
		throw "Der Preis darf nie null oder negativ sein!";
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
		throw "Es duerfen nur positive Mengen gebucht werden!";
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
		throw "Es duerfen nur positive Mengen gebucht werden!";
	}
	if (bestand - menge < 0){
		throw "Es koennen nicht mehr Artikel abgebucht werden als vorhanden!";
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
		throw "Der Bestand darf nie negativ sein!";
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
		throw "Die Bezeichnung eines Artikels darf nicht leer sein!";
	}
	bezeichnung = neuBezeichnung;
}
/**
* @brief Set neuer Preis
* @param neuPreis darf nicht negativ sein!
*/
void Artikel::setPreis(double neuPreis){
	if(neuPreis < 0){
		throw "Der Preis darf nie negativ sein!";
	}
	artikelPreis=round(neuPreis*100)/100.0; // auf zwei stellen runden
}
/**
 * @brief Preisaenderung
 * @param preisaenderung in Prozent (max. 99%)
 */
void Artikel::aenderePreis(double preisaenderung){
	if (abs(preisaenderung) > 100 ){
		throw "This change is too damn High!";
	}	if (abs(preisaenderung) == 0){
		throw "0 or NaN Forbidden";
	}
	artikelPreis*=(1+(preisaenderung/100));
	artikelPreis=round(artikelPreis*100)/100;
}

