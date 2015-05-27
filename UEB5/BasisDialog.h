#ifndef BASISDIALOG_H_
#define BASISDIALOG_H_
#include "Artikel.h"
#include "Artikeldialog.h"
#include "LagerDialog.h"
class BasisDialog
{
public:
	const string SEPERATOR = "-B-----------------------------";
	const string DIALOGOPTIONONE = "(1) Artikeldialog";
	const string DIALOGOPTIONTWO = "(2) Lagerdialog";
	const string STANDARDEXITOPTION = "(0) -EXIT/BACK-";
	const string STANDARDCHOICEPHRASE = "Waehlen sie eine Option : ";
	const string INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
	const string ERRORPHRASE = "Fehler: ";

	BasisDialog();
	~BasisDialog();
	void leereEingabe();
	void enterArtikelDialog();
	void enterLagerDialog();
	void dialog();

};

#endif 