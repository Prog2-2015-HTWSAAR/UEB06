/**
* @file Artikel.h
* @author Andreas Schreiner & Simon Bastian
* @date 16.05.2015
*
* Eingabe Funktionen
*/
#ifndef ARTIKEL_H_
#define ARTIKEL_H_
#include <string>
using namespace std;
/**
* @brief Artikel Klasse
*/
class Artikel {
public:
	/**
	* @brief Konstruktor mit 4 Parametern
	* @details Konstruktor zur Erzeugung eines Artikel Obj mit Bestandsangabe
	* @param artikelNr muss vierstellig sein!
	* @param bezeichnung darf kein leerer String sein!
	* @param artikelPreis darf nicht negativ sein!
	* @param bestand darf nicht negativ sein!
	*/
	Artikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand);
	/**
	* @brief Konstruktor mit 3 Parametern
	* @details Konstruktor zur Erzeugung eines Artikel Obj ohne Bestandsangabe
	* @param artikelNr muss vierstellig sein!
	* @param bezeichnung darf kein leerer String sein!
	* @param artikelPreis darf nicht negativ sein!
	*/
	Artikel(int artikelNr, string bezeichnung, double artikelPreis);
	virtual ~Artikel(){}
	/**
	* @brief bucheZugang
	* @details Funktion zum erhoehen des Bestands
	* @param menge muss positiv sein!
	*/
	void bucheZugang(int menge);
	/**
	* @brief bucheAbgang
	* @details Funktion zum verringern des Bestands
	* @param menge muss positiv sein!
	*/
	void bucheAbgang(int menge);
	/**
	* @brief setBezeichnung
	* @details Funktion zum setzen der Bezeichnung
	* @param neuBezeichnung darf nicht leer sein!
	*/
	void setBezeichnung(string neuBezeichnung);
	/**
	* @brief setBestand bei Inventur
	* @details Funktion zum setzen des Bestands
	* @param neuBestand darf nicht negativ sein!
	*/
	void setBestand(int neuBestand);
	/**
	* @brief Set neuer Preis
	* @param neuPreis darf nicht negativ sein!
	*/
	void setPreis(double neuPreis);
	/**
	 * @brief Preisaenderung
	 * @param preisaenderung in Prozent (max. 99%)
	 */
	void aenderePreis(double preisaenderung);
	/**
	* @brief get Artikelnummer
	* @return artikelNr
	*/
	int getArtikelNr() const {
		return artikelNr;
	}
	/**
	* @brief get Bezeichnung
	* @return bezeichnung
	*/
	string getBezeichnung() const {
		return bezeichnung;
	}
	/**
	* @brief get Bestand
	* @return bestand
	*/
	int getBestand() const {
		return bestand;
	}
	/**
	* @brief get ArtikelPreis
	* @return artikelPreis
	*/
	double getArtikelPreis() const{
		return artikelPreis;
	}
	virtual string toString() const;
private:
	int artikelNr; ///< Artikel Nummer
	string bezeichnung; ///< Artikel Bezeichnung
	int bestand; ///< Artikel Bestand
	double artikelPreis; ///< Artikel Preis
};


#endif 

