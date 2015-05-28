/**
* @file Artikel.h
* @author Andreas Schreiner & Simon Bastian
* @date 16.05.2015
*
* Artikel Klasse und zugehoerige Ausnahmen
*/
#ifndef ARTIKEL_H_
#define ARTIKEL_H_
#include <string>
#include <iostream>
#include <stdexcept>


using namespace std;


/**
 * Standardausnahme fuer logische Fehler in der Artikelklasse
 */
class ArtikelException : public logic_error {
public:
    ArtikelException(const string& msg = "") : logic_error(msg) {}
};

/**
* @brief Artikel Klasse
*/
class Artikel {
public:
	const int LOWERBORDERARTIKELNUMMER = 1000;
	const int UPPERBORDERARTIKELNUMMER = 9999;
	const string ARTIKELNUMMER = "ArtikelNr: ";
	const string BEZEICHNUNG = "Bez.: ";
	const string ARTIKELPREIS = "Preis: ";
	const string BESTAND = "Bestand: ";
	const char* THROWARTIKELNUMMERERROR = "Die Artikelnummer muss eine 4-stellige positive Zahl sein!";
	const char* THROWBEZEICHNUNGERROR = "Die Bezeichnung eines Artikels darf nicht leer sein!";
	const char* THROWBESTANDERROR = "Der Bestand darf nie negativ sein!";
	const char* THROWPREISERROR = "Der Preis darf nie null oder negativ sein!";
	const char* THROWONLYPOSITIVEALLOWEDERROR = "Es duerfen nur positive Mengen gebucht werden!";
	const char* THROWBESTANDREDUCEERROR = "Es koennen nicht mehr Artikel abgebucht werden als vorhanden!";
	const char* THROWCHARGETOODAMNHIGHERROR = "This change is too damn High!";
	const char* THROWZEROORNANERROR = "0 or NaN Forbidden";

	/**
	* @brief Konstruktor
	* @details Konstruktor zur Erzeugung eines Artikel Obj mit Bestandsangabe
	* @param artikelNr muss vierstellig sein!
	* @param bezeichnung darf kein leerer String sein!
	* @param artikelPreis darf nicht negativ sein!
	* @param bestand (optional) darf nicht negativ sein!
	* @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	*/
	Artikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand = 0)
			throw (ArtikelException);

	virtual ~Artikel(){}
	/**
	* @brief bucheZugang
	* @details Funktion zum erhoehen des Bestands
	* @param menge muss positiv sein!
	* @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	*/
	void bucheZugang(int menge) throw (ArtikelException);
	/**
	* @brief bucheAbgang
	* @details Funktion zum verringern des Bestands
	* @param menge muss positiv sein!
	* @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	*/
	void bucheAbgang(int menge) throw (ArtikelException);
	/**
	* @brief setBezeichnung
	* @details Funktion zum setzen der Bezeichnung
	* @param neuBezeichnung darf nicht leer sein!
	* @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	*/
	void setBezeichnung(string neuBezeichnung) throw (ArtikelException);
	/**
	* @brief setBestand bei Inventur
	* @details Funktion zum setzen des Bestands
	* @param neuBestand darf nicht negativ sein!
	* @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	*/
	void setBestand(int neuBestand) throw (ArtikelException);
	/**
	* @brief Set neuer Preis
	* @param neuPreis darf nicht negativ sein!
	* @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	*/
	void setPreis(double neuPreis) throw (ArtikelException);
	/**
	 * @brief Preisaenderung
	 * @param preisaenderung in Prozent (0% < preisaenderung < 100%)
	 * @throw ArtikelException Falls Vorbedingungen nicht erfuellt sind!
	 */
	void aenderePreis(double preisaenderung) throw (ArtikelException);
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
	friend ostream& operator<<(ostream&, const Artikel&);
private:
	int artikelNr; ///< Artikel Nummer
	string bezeichnung; ///< Artikel Bezeichnung
	int bestand; ///< Artikel Bestand
	double artikelPreis; ///< Artikel Preis
};


#endif 

