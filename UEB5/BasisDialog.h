/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb05 *.o
* @file Artikeldialog.h
* @author Andreas Schreiner & Simon Bastian
*
* @date 01.06.2015
*
* BasisDialog Implementation
*
*/
#ifndef BASISDIALOG_H_
#define BASISDIALOG_H_
#include "Artikel.h"
#include "Artikeldialog.h"
#include "LagerDialog.h"
#include "Lager.h"
#include <sstream>
#include <cmath>
class BasisDialog
{
public:
	static const char* SEPERATOR;
	static const char* DIALOGOPTIONONE;
	static const char* DIALOGOPTIONTWO;
	static const char* STANDARDEXITOPTION;
	static const char* STANDARDCHOICEPHRASE;
	static const char* INPUTERRORPHRASE;
	static const char* ERRORPHRASE;

	/**
	 * @brief Konstruktor
	 */
	BasisDialog();
	/**
	 * @brief Dekonstruktor
	 */
	~BasisDialog();
	/**
	 * @brief Eingabeleerung
	 * @details Im Falle einer falschen eingabe leert dies den Eingabepuffer.
	 */
	void leereEingabe();
	/**
	 * @brief Initiiert den ArtikelDialog
	 */
	void enterArtikelDialog();
	/**
	 * @brief Initiiert den LagerDialog
	 */
	void enterLagerDialog();
	/**
	 * @brief Initiiert den StartDialog
	 * @details Auswahl zwischen Artikel- und Lagerdialog
	 */
	void startDialog();

};

#endif 
