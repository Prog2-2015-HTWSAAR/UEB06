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
class Artikeldialog {
public:
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
	void testeBucheZugang(Artikel artikel);
	/**
	 * @brief Test der Abgangsbuchung eines Artikels
	 * @param artikel
	 */
	void testeBucheAbgang(Artikel artikel);
	/**
	* @brief Test des Setzens der Bezeichnung eines Artikels
	* @param artikel
	*/
	void testeSetBezeichnung(Artikel artikel);
	/**
	 * @brief Test des Setzens des Bestands eines Artikels
	 * @param artikel
	 */
	void testeSetBestand(Artikel artikel);
	/**
	 * @brief Test des Setzens des Preises eines Artikels
	 * @param artikel
	 */
	void testeSetPreis(Artikel artikel);
	/**
	 * @brief Test der Aenderung eines Preises
	 * @param artikel
	 */
	void testeAenderePreis(Artikel artikel);
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
};

#endif /* ARTIKELDIALOG_H_ */

