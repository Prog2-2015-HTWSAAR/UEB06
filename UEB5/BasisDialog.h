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
	* @details Konstruktor
	*/
	BasisDialog();
	/**
	* @brief Dekonstruktor
	* @details Dekonstruktor
	*/
	~BasisDialog();
	/**
	* @brief Eingabeleerung
	* @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
	*/
	void leereEingabe();
	void enterArtikelDialog();
	void enterLagerDialog();
	void dialog();

};

#endif 
