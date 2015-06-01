/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb05 *.o
* @file LagerDialog.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 01.06.2015
*
* LagerDialog implementation
*
*/
#include "LagerDialog.h"
const char* LagerDialog::LAGERWIRKLICHLOESCHEN = "Lager wirklich Loeschen (j)=Ja: ";
const char* LagerDialog::ARTIKELWIRKLICHLOESCHEN = "Artikel wirklich Loeschen (j)=Ja: ";
const char* LagerDialog::ARTIKELNUMMER = "Artikelnummer: ";
const char* LagerDialog::BEZEICHNUNG = "Bezeichnung: ";
const char* LagerDialog::ARTIKELPREIS = "Artikelpreis: ";
const char* LagerDialog::BESTAND = "Bestand: ";
const char* LagerDialog::ZUGANG = "Zugang: ";
const char* LagerDialog::ABGANG = "Abgang: ";
const char* LagerDialog::PRICECHANGEPHRASE = "Preisaenderung (%): ";
const char* LagerDialog::EDITDIALOGOPTIONONE = "(1) BUCHE - Zugang";
const char* LagerDialog::EDITDIALOGOPTIONTWO = "(2) BUCHE - Abgang";
const char* LagerDialog::EDITDIALOGOPTIONTHREE = "(3) Aendere Preis (%)";
const char* LagerDialog::SEPERATOR = "-L-----------------------------";
const char* LagerDialog::SEPERATORCREATELAGER = "-L-------CREATE-LAGER----------";
const char* LagerDialog::SEPERATORDELETELAGER = "-L-------DELETE-LAGER----------";
const char* LagerDialog::SEPERATORBUCHEZUGANG = "-L-------BUCHE-ZUGANG----------";
const char* LagerDialog::SEPERATORBUCHEABGANG = "-L-------BUCHE-ABGANG----------";
const char* LagerDialog::SEPERATORAENDEREPREIS = "-L-------AENDERE-PREIS---------";
const char* LagerDialog::SEPERATORDELETEARTIKEL = "-L-------DELETE-ARTIKEL--------";
const char* LagerDialog::SEPERATORCREATEARTIKEL = "-L-------CREATE-ARTIKEL--------";
const char* LagerDialog::DIALOGOPTIONONE = "(1) Groesse und Name festlegen";
const char* LagerDialog::DIALOGOPTIONTWO = "(2) Groesse festlegen";
const char* LagerDialog::DIALOGOPTIONTHREE = "(3) Standardlager";
const char* LagerDialog::STANDARDEXITOPTION = "(0) -EXIT/BACK-";
const char* LagerDialog::STANDARDBACKOPTION = "(0) -BACK-";
const char* LagerDialog::LAGERDIALOGOPTIONONE = "(1) Artikel Anlegen";
const char* LagerDialog::LAGERDIALOGOPTIONTWO = "(2) Artikel Anlegen ohne Bestand";
const char* LagerDialog::LAGERDIALOGOPTIONTHREE = "(3) Artikel Bearbeiten";
const char* LagerDialog::LAGERDIALOGOPTIONFOUR = "(4) Artikel Loeschen";
const char* LagerDialog::LAGERDIALOGOPTIONEXIT = "(0) Lager Loeschen";
const char* LagerDialog::STANDARDCHOICEPHRASE = "Waehlen sie eine Option : ";
const char* LagerDialog::INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
const char* LagerDialog::ERRORPHRASE = "Fehler: ";
const char* LagerDialog::STANDARDLAGERNAME = "Lager";
const char* LagerDialog::ENTERNAMEPHRASE = "Bitte geben sie den Lagernamen ein: ";
const char* LagerDialog::ENTERSIZEPHRASE = "Bitte geben sie die Lagergroesse ein: ";
/**
* @brief Konstructor
*/
LagerDialog::LagerDialog(){}
/**
* @brief Destructor
*/
LagerDialog::~LagerDialog(){}
/**
* @brief dialog Dialog
*/
void LagerDialog::dialog(){
	Lager* lager = NULL;
	int answer = -1;
	int anzahl = -1;
	string name = STANDARDLAGERNAME;
	do {
		cout << SEPERATOR << endl << DIALOGOPTIONONE << endl << DIALOGOPTIONTWO
			<< endl << DIALOGOPTIONTHREE << endl << STANDARDEXITOPTION << endl
			<< endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		leereEingabe();
		try {
			switch (answer){
			case 0:
				break;
			case 1:
				cout << SEPERATORCREATELAGER << endl << ENTERSIZEPHRASE;
				cin >> anzahl;
				leereEingabe();
				cout << ENTERNAMEPHRASE;
				cin >> name;
				leereEingabe();
				lager = new Lager(anzahl, name);
				startLagerDialog(lager);
				delete lager;
				break;
			case 2:
				cout << SEPERATORCREATELAGER << endl << ENTERSIZEPHRASE;
				cin >> anzahl;
				leereEingabe();
				lager = new Lager(anzahl);
				startLagerDialog(lager);
				delete lager;
				break;
			case 3:
				lager = new Lager();
				startLagerDialog(lager);
				delete lager;
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
			}
		}
		catch (LagerException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}

	} while (answer != 0);
}
/**
* @brief startLagerDialog Dialog Lagermanagementdialog
* @param lager
*/
void LagerDialog::startLagerDialog(Lager* lager) {
	int answer = -1;
	string wirklichLoeschen = "n";
	int artikelNr = 0000;
	int bestand = 0;
	double preis;
	string bezeichnung;
	do {
		cout << *lager << endl;
		cout << SEPERATOR << endl << LAGERDIALOGOPTIONONE << endl << LAGERDIALOGOPTIONTWO
			<< endl << LAGERDIALOGOPTIONTHREE << endl << LAGERDIALOGOPTIONFOUR
			<< endl << LAGERDIALOGOPTIONEXIT << endl << endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		leereEingabe();
		try {
			switch (answer){
			case 0:
				cout << SEPERATORDELETEARTIKEL << endl << LAGERWIRKLICHLOESCHEN;
				cin >> wirklichLoeschen;
				leereEingabe();
				if (wirklichLoeschen != "j"){
					answer = 9;
				}
				cout << endl;
				break;
			case 1:
				cout << SEPERATORCREATEARTIKEL << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				leereEingabe();
				cout << BEZEICHNUNG;
				cin >> bezeichnung;
				leereEingabe();
				cout << ARTIKELPREIS;
				cin >> preis;
				leereEingabe();
				cout << BESTAND;
				cin >> bestand;
				leereEingabe();
				cout << endl;
				lager->createArtikel(artikelNr, bezeichnung, preis, bestand);
				break;
			case 2:
				cout << SEPERATORCREATEARTIKEL << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				leereEingabe();
				cout << BEZEICHNUNG;
				cin >> bezeichnung;
				leereEingabe();
				cout << ARTIKELPREIS;
				cin >> preis;
				leereEingabe();
				cout << endl;
				lager->createArtikel(artikelNr, bezeichnung, preis);
				break;
			case 3:
				artikelEditDialog(lager);
				break;
			case 4:
				cout << SEPERATORDELETEARTIKEL << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				leereEingabe();
				cout << ARTIKELWIRKLICHLOESCHEN;
				cin >> wirklichLoeschen;
				leereEingabe();
				if (wirklichLoeschen == "j"){
					lager->deleteArtikel(artikelNr);
				}
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
			}

		}
		catch (LagerException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}
		catch (ArtikelException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}
	} while (answer != 0);

}
/**
* @brief artikelEditDialog Dialog zum Aendern von Artikeln
* @param lager
*/
void LagerDialog::artikelEditDialog(Lager* lager){
	int artikelNr = 0000;
	int bestandAenderung = 0;
	double preisAenderung = 0.0;
	int answer = -1;
	do {
		cout << endl << *lager << endl;
		cout << SEPERATOR << endl << EDITDIALOGOPTIONONE << endl << EDITDIALOGOPTIONTWO
			<< endl << EDITDIALOGOPTIONTHREE << endl << STANDARDBACKOPTION << endl
			<< endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		leereEingabe();
		try {
			switch (answer){
			case 0:
				break;
			case 1:
				cout << SEPERATORBUCHEZUGANG << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				leereEingabe();
				cout << ZUGANG;
				cin >> bestandAenderung;
				leereEingabe();
				lager->bucheZugang(artikelNr, bestandAenderung);
				break;
			case 2:
				cout << SEPERATORBUCHEABGANG << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				leereEingabe();
				cout << ABGANG;
				cin >> bestandAenderung;
				leereEingabe();
				lager->bucheAbgang(artikelNr, bestandAenderung);
				break;
			case 3:
				cout << SEPERATORAENDEREPREIS << endl << PRICECHANGEPHRASE;
				cin >> preisAenderung;
				leereEingabe();
				lager->preiseAendern(preisAenderung);
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
			}
		}
		catch (const char* e) {
			cout << ERRORPHRASE << e << endl;
		}
	} while (answer != 0);
}
/**
* @brief Eingabeleerung
* @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
*/
void LagerDialog::leereEingabe(){
	cin.clear();
	cin.ignore(BIGNUMBER, '\n');
}
