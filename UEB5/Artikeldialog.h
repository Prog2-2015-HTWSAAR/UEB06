/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb03 *.o
* @file Artikeldialog.h
* @author Andreas Schreiner & Simon Bastian
*
* @date 08.05.2015
*
* H file
*
*/
#ifndef ARTIKELDIALOG_H_
#define ARTIKELDIALOG_H_
#include "Artikel.h"
#include <iostream>
#define TESTNR 4711
#define TESTBEZ "Wasser"
#define NEUBEZ "Koelsch-Wasser"
#define TESTBESTAND 42
#define NEUBESTAND 40
#define TESTPREIS 13.37
#define NEUPREIS 137.70
#define TESTAENDERUNG 5
#define TESTABGANG 23
#define TESTZUGANG 21
#define BIGNUMBER 10000
class Artikeldialog {
public:
	const string ARTIKELNUMMER = "Artikelnummer: ";
	const string BEZEICHNUNG = "\nBezeichnung: ";
	const string ARTIKELPREIS = "\nArtikelpreis: ";
	const string BESTAND = "\naktl. Bestand: ";
	const string SEPERATOR = "-------------------------------";
	const string NEWPHRASE = "Neuer";
	const string DIALOGOPTIONONE = "(1) Automatischer Test";
	const string DIALOGOPTIONTWO = "(2) Manueller Test mit Bestandsangabe";
	const string DIALOGOPTIONTHREE = "(3) Manueller Test ohne Bestandsangabe";
	const string STANDARDEXITOPTION = "(0) -EXIT/BACK-";
	const string STANDARDCHOICEPHRASE = "Waehlen sie eine Option : ";
	const string MANUELLDIALOGOPTIONONE = "(1) SET - Bezeichnung";
	const string MANUELLDIALOGOPTIONTWO = "(2) SET - ArtikelPreis";
	const string MANUELLDIALOGOPTIONTHREE = "(3) SET - Bestand";
	const string MANUELLDIALOGOPTIONFOUR = "(4) Aendere Preis (%)";
	const string MANUELLDIALOGOPTIONFIVE = "(5) BUCHE - Abgang";
	const string MANUELLDIALOGOPTIONSIX = "(6) BUCHE - Zugang";
	const string PRICECHANGEPHRASE = "Preisaenderung (%): ";
	const string INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
	const string WITHOUTPHRASE = "ohne Bestand...";
	const string RUNTESTCONSTRUCTORPHRASE = "Starte Test zum Erstellen eines Artikels";
	const string USEVALUESPHRASE = "Nutze folgende Werte : ";
	const string VALUEPHRASE = "Wert: ";
	const string CREATEARTIKELPHRASE = "Erstellter Artikel:";
	const string ERRORPHRASE = "Fehler: ";
	Artikeldialog();
	virtual ~Artikeldialog();
	/**
	 * @brief Ausgeben eines Artikels
	 * @param artikel
	 */
	void ausgeben(const Artikel& artikel);
	/**
	 * @brief Test des Konstruktors mit zwei Argumenten
	 * @param artikelNr
	 * @param bezeichnung
	 * @param artikelpreis
	 */
	void testeConstructor1(int artikelNr, string bezeichnung, double artikelpreis);
	/**
	 * @brief Test des Konstruktors mit drei Argumenten
	 * @param artikelNr
	 * @param bezeichnung
	 * @param artikelpreis
	 * @param bestand
	 */
	void testeConstructor2(int artikelNr, string bezeichnung, double artikelpreis, int bestand);
	/**
	 * @brief Test der Zugangsbuchung eines Artikels
	 * @param artikel
	 */
	void testeBucheZugang(Artikel *artikel);
	/**
	 * @brief Test der Abgangsbuchung eines Artikels
	 * @param artikel
	 */
	void testeBucheAbgang(Artikel *artikel);
	/**
	* @brief Test des Setzens der Bezeichnung eines Artikels
	* @param artikel
	*/
	void testeSetBezeichnung(Artikel *artikel);
	/**
	 * @brief Test des Setzens des Bestands eines Artikels
	 * @param artikel
	 */
	void testeSetBestand(Artikel *artikel);
	/**
	 * @brief Test des Setzens des Preises eines Artikels
	 * @param artikel
	 */
	void testeSetPreis(Artikel *artikel);
	/**
	 * @brief Test der Aenderung eines Preises
	 * @param artikel
	 */
	void testeAenderePreis(Artikel *artikel);
	/**
	 * @brief Ausfuehrung aller Tests
	 */
	void testeAlles();
	/**
	 * @brief Benutzerdialog
	 * @details Dialog zur Auswahl zwischen automatischen Tests und manuellem Testen
	 */
	void dialog();
	/**
	 * @brief Interaktiver Test eines Artikels
	 * @param artikel
	 */
	void manuell(Artikel artikel);
	/**
	 * @brief Interaktives Erstellen eines Testartikels mit Bestand
	 * @details ruft manuell() auf
	 */
	void createArtikelMitBestand();
	/**
	 * @brief Interaktives Erstellen eines Testartikels ohne Bestand
	 * @details ruft manuell() auf
	 */
	void createArtikelOhneBestand();
	/**
	 * @brief Eingabeleerung
	 * @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
	 */
	void leereEingabe();
};
#endif /* ARTIKELDIALOG_H_ */

