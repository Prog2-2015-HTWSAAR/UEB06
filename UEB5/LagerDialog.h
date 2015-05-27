#ifndef LAGERDIALOG_H_
#define LAGERDIALOG_H_
#include "BasisDialog.h"

class LagerDialog
{
public:
	const string SEPERATOR = "-L-----------------------------";
	const string DIALOGOPTIONONE = "(1) Automatischer Test";
	const string DIALOGOPTIONTWO = "(2) Manueller Test mit Bestandsangabe";
	const string DIALOGOPTIONTHREE = "(3) Manueller Test ohne Bestandsangabe";
	const string STANDARDEXITOPTION = "(0) -EXIT/BACK-";
	const string STANDARDCHOICEPHRASE = "Waehlen sie eine Option : ";
	const string INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
	const string ERRORPHRASE = "Fehler: ";
	LagerDialog();
	virtual ~LagerDialog();
	void dialog();
	void leereEingabe();
};

#endif