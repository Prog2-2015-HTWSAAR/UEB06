/*
 * Lager.h
 *
 *  Created on: 23.05.2015
 *      Author: Simon
 */

#ifndef LAGER_H_
#define LAGER_H_
#include "Artikel.h"

class Lager {
public:
	Lager(int maxAnzArtikel);
	Lager(int maxAnzArtikel, string name);
	virtual ~Lager();
	void createArtikel(int artikelNr, string bezeichnung, double artikelPreis);
	void createArtikel(int artikelNr, string bezeichnung, double artikelPreis, int bestand);
	void deleteArtikel(int artikelNr);
	void bucheZugang(Artikel artikel);
	void bucheAbgang(Artikel artikel);
	void preiseAendern(double prozent);

private:
	int findeArtikel(int artikelNr);
	string name;
	Artikel** sortiment;
	int anzArtikel;
	int maxAnzArtikel;
};

#endif /* LAGER_H_ */
