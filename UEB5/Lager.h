/**
 * @file Lager.h
 *
 * @date 23.05.2015
 * @author Andreas Schreiner & Simon Bastian
 */

#ifndef LAGER_H_
#define LAGER_H_
#include "Artikel.h"
/**
 * @brief Eine Lagerklasse
 */
class Lager {
public:
	/**
	 * @brief Konstruktor ohne Namensangabe
	 *
	 * @param maxAnzArtikel muss positiv sein!
	 */
	Lager(int maxAnzArtikel);
	/**
	 * @brief Konstruktor mit Namensangabe
	 * @param maxAnzArtikel muss positiv sein!
	 * @param name Name des Lagers
	 */
	Lager(int maxAnzArtikel, string name);
	/**
	 * @brief Destructor löscht alle Artikel
	 */
	virtual ~Lager();
	/**
	 * @brief Eintragen eines neuen Artikels ohne Bestandsangabe
	 * @details Artikel wird am Ende ins ArtikelTab eingetragen, falls moeglich
	 * @param artikelNr
	 * @param bezeichnung
	 * @param artikelPreis
	 */
	void createArtikel(int artikelNr, string bezeichnung, double artikelPreis);
	/**
	 * @brief Eintragen eines neuen Artikels mit Bestandsangabe
	 * @details Artikel wird am Ende ins ArtikelTab eingetragen, falls moeglich
	 * @param artikelNr
	 * @param bezeichnung
	 * @param artikelPreis
	 * @param bestand
	 */
	void createArtikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand);
	/**
	 * @brief Entfernen eines Artikels aus dem Lager
	 * @param artikelNr
	 */
	void deleteArtikel(int artikelNr);
	/**
	 *
	 */
	void bucheZugang(Artikel *artikel, int menge);
	/**
	 *
	 */
	void bucheAbgang(Artikel *artikel, int menge);
	/**
	 *
	 */
	void preiseAendern(double preisaenderung);

private:
	int findeArtikel(int artikelNr);
	void loescheAlleArtikel();
	string name;
	Artikel** artikelTab;
	int anzArtikel;
	int maxAnzArtikel;
};

#endif /* LAGER_H_ */
