#ifndef LAGERDIALOG_H_
#define LAGERDIALOG_H_
#include "BasisDialog.h"
#include "Lager.h"
class LagerDialog
{
//	namespace Lager {
	//	enum FunktionsTyp { ANLEGEN, EINZAHLEN, ABHEBEN, UEBERWEISEN, LOESCHEN, ENDE = 9 };
public:
	const string ARTIKELNUMMER = "Artikelnummer: ";
	const string BEZEICHNUNG = "Bezeichnung: ";
	const string ARTIKELPREIS = "Artikelpreis: ";
	const string BESTAND = "Bestand: ";
	const string EDITDIALOGOPTIONONE = "(1) SET - Bezeichnung";
	const string EDITDIALOGOPTIONTWO = "(2) SET - ArtikelPreis";
	const string EDITDIALOGOPTIONTHREE = "(3) SET - Bestand";
	const string EDITDIALOGOPTIONFOUR = "(4) Aendere Preis (%)";
	const string EDITDIALOGOPTIONFIVE = "(5) BUCHE - Abgang";
	const string EDITDIALOGOPTIONSIX = "(6) BUCHE - Zugang";
	const string PRICECHANGEPHRASE = "Preisaenderung (%): ";
	const string SEPERATOR = "-L-----------------------------";
	const string SEPERATORCREATELAGER =	"-L-------CREATE-LAGER----------";
	const string SEPERATORDELETELAGER = "-L-------DELETE-LAGER----------";
	const string SEPERATORCREATEARTIKEL =	"-L-------CREATE-ARTIKEL--------";
	const string DIALOGOPTIONONE = "(1) Groesse und Name festlegen";
	const string DIALOGOPTIONTWO = "(2) Groesse festlegen";
	const string DIALOGOPTIONTHREE = "(3) Standardlager";
	const string STANDARDEXITOPTION = "(0) -EXIT/BACK-";
	const string STANDARDBACKOPTION = "(0) -BACK-";
	const string LAGERDIALOGOPTIONONE = "(1) Artikel Anlegen";
	const string LAGERDIALOGOPTIONTWO = "(2) Artikel Anlegen ohne Bestand";
	const string LAGERDIALOGOPTIONTHREE = "(3) Alle Artikel Ausgeben";
	const string LAGERDIALOGOPTIONFOUR = "(4) Bestimmten Artikel Ausgeben";
	const string LAGERDIALOGOPTIONFIVE = "(5) Artikel Bearbeiten";
	const string LAGERDIALOGOPTIONSIX = "(6) Artikel Loeschen";
	const string LAGERDIALOGOPTIONEXIT = "(0) Lager Loeschen";
	const string STANDARDCHOICEPHRASE = "Waehlen sie eine Option : ";
	const string INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
	const string ERRORPHRASE = "Fehler: ";
	const string STANDARDLAGERNAME = "Lager";
	const string ENTERNAMEPHRASE = "Bitte geben sie den Lagernamen ein: ";
	const string ENTERSIZEPHRASE = "Bitte geben sie die Lagergroesse ein: ";

	LagerDialog();
	virtual ~LagerDialog();
	void dialog();
	void leereEingabe();
	void startLagerDialog(Lager* lager);
	void artikelEditDialog();
private:
//	FunktionsTyp einlesenFunktion();
//	void ausfuehrenFunktion(FunktionsTyp);
	void legeKontoAnDialog();
	};
//}
#endif
