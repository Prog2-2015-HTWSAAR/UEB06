/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb05 *.o
* @file LagerDialog.h
* @author Andreas Schreiner & Simon Bastian
*
* @date 01.06.2015
*
* LagerDialog-Header
*
*/
#ifndef LAGERDIALOG_H_
#define LAGERDIALOG_H_
#include "BasisDialog.h"
#include "Lager.h"
/**
 * @brief Klasse zum Testen der Lager-Klasse
 */
class LagerDialog {
public:
	static const char* LAGERWIRKLICHLOESCHEN;
	static const char* ARTIKELWIRKLICHLOESCHEN;
	static const char* ARTIKELNUMMER;
	static const char* BEZEICHNUNG;
	static const char* ARTIKELPREIS;
	static const char* BESTAND;
	static const char* ZUGANG;
	static const char* ABGANG;
	static const char* PRICECHANGEPHRASE;
	static const char* EDITDIALOGOPTIONONE;
	static const char* EDITDIALOGOPTIONTWO;
	static const char* EDITDIALOGOPTIONTHREE;
	static const char* SEPERATOR;
	static const char* SEPERATORCREATELAGER;
	static const char* SEPERATORDELETELAGER;
	static const char* SEPERATORBUCHEZUGANG;
	static const char* SEPERATORBUCHEABGANG;
	static const char* SEPERATORAENDEREPREIS;
	static const char* SEPERATORDELETEARTIKEL;
	static const char* SEPERATORCREATEARTIKEL;
	static const char* DIALOGOPTIONONE;
	static const char* DIALOGOPTIONTWO;
	static const char* DIALOGOPTIONTHREE;
	static const char* STANDARDEXITOPTION;
	static const char* STANDARDBACKOPTION;
	static const char* LAGERDIALOGOPTIONONE;
	static const char* LAGERDIALOGOPTIONTWO;
	static const char* LAGERDIALOGOPTIONTHREE;
	static const char* LAGERDIALOGOPTIONFOUR;
	static const char* LAGERDIALOGOPTIONEXIT;
	static const char* STANDARDCHOICEPHRASE;
	static const char* INPUTERRORPHRASE;
	static const char* ERRORPHRASE;
	static const char* STANDARDLAGERNAME;
	static const char* ENTERNAMEPHRASE;
	static const char* ENTERSIZEPHRASE;
	/**
	* @brief Konstructor
	*/
	LagerDialog();
	/**
	* @brief Destructor 
	*/
	virtual ~LagerDialog();
	/**
	* @brief dialog Dialog
	*/
	void dialog();
	/**
	* @brief Eingabeleerung
	* @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
	*/
	void leereEingabe();
	/**
	* @brief startLagerDialog Dialog Lagermanagementdialog
	* @param lager
	*/
	void startLagerDialog(Lager* lager);
	/**
	* @brief artikelEditDialog Dialog zum Aendern von Artikeln
	* @param lager
	*/
	void artikelEditDialog(Lager* lager);
	};
#endif
