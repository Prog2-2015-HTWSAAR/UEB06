/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb03 *.o
* @file Artikeldialog.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 16.05.2015
*
* Artikeldialog Funktionen
*

*/
#include "Artikeldialog.h"
#include "Artikel.h"
#include <iostream>


Artikeldialog::Artikeldialog(){
	// Nothing to do here
}

Artikeldialog::~Artikeldialog(){
	// Nothing to do here
}

void Artikeldialog::ausgeben(const Artikel& artikel){
	cout << ARTIKELNUMMER << artikel.getArtikelNr()
		 << BEZEICHNUNG << artikel.getBezeichnung()
		 << ARTIKELPREIS << artikel.getArtikelPreis()
		 << BESTAND << artikel.getBestand() << endl;
}

/**
* @brief testeConstructor1 mit 2 Parameter(Artikelnummer. Bezeichnung)
* @param artikelNr Artikelnummer des neuen Obj
* @param bezeichnung Bezeichnung des neuen Obj
* @param artikelpreis
*/

void Artikeldialog::testeConstructor1(int artikelNr, string bezeichnung, double artikelpreis){
	cout << endl << RUNTESTCONSTRUCTORPHRASE << WITHOUTPHRASE << endl;
	cout << USEVALUESPHRASE << endl;
	cout << ARTIKELNUMMER << artikelNr << endl;
	cout << BEZEICHNUNG << bezeichnung << endl;
	cout << ARTIKELPREIS << artikelpreis << endl;
	try{
		Artikel artikel(artikelNr,bezeichnung,artikelpreis);
		cout << endl << CREATEARTIKELPHRASE << endl;
		ausgeben(artikel);
	} catch (const char* e) {
		cout << ERRORPHRASE << e << endl;
	}

}
/**
* @brief testeConstructor2 mit 3 Parameter(Artikelnummer.Bezeichnung, Bestand)
* @param artikelNr Artikelnummer
* @param bezeichnung Bezeichnung
* @param bestand Lagerbestand
*/
void Artikeldialog::testeConstructor2(int artikelNr, string bezeichnung, double artikelpreis, int bestand){

	cout << endl << RUNTESTCONSTRUCTORPHRASE << endl;
	cout << USEVALUESPHRASE << endl;
	cout << ARTIKELNUMMER << artikelNr << endl;
	cout << BEZEICHNUNG << bezeichnung << endl;
	cout << ARTIKELPREIS << artikelpreis << endl;
	cout << BESTAND << bestand << endl;

	try {
		Artikel artikel(artikelNr,bezeichnung,artikelpreis,bestand);
		cout << endl << CREATEARTIKELPHRASE << endl;
		ausgeben(artikel);
	} catch (const char* e) {
		cout << ERRORPHRASE << e << endl;
	}

}
/**
* @brief testeBucheAbgang
* @details Autom Test Buche Abgang Bestand
* @param artikel Artikel obj
*/
void Artikeldialog::testeBucheAbgang(Artikel *artikel){
	int menge = TESTABGANG;

	cout << endl << "Starte Test zur Buchung eines Abgangs..." << endl;

	cout << "Der Abgang umfasst "<< menge << " Artikel!" << endl;

	cout << "Artikel vor Abgang:" << endl;
	ausgeben(*artikel);

	try {
		artikel->bucheAbgang(menge);
		cout << endl << "Artikel nach Abgang:" << endl;
		ausgeben(*artikel);
	} catch (const char* e) {
		cout << ERRORPHRASE << e << endl;
	}
}

/**
* @brief testeBucheZugang
* @details Autom Test Buche Zugang Bestand
* @param artikel Artikel obj
*/
void Artikeldialog::testeBucheZugang(Artikel *artikel){
	int menge=TESTZUGANG;

	cout << endl << "Starte Test zur Buchung eines Zugangs..." << endl;

	cout << "Der Zugang umfasst " << menge << " Artikel!" << endl;

	cout << "Artikel vor Zugang:" << endl;
	ausgeben(*artikel);

	try {
		artikel->bucheZugang(menge);
		cout << endl << "Artikel nach Zugang:" << endl;
		ausgeben(*artikel);
	} catch (const char* e) {
		cout << ERRORPHRASE << e << endl;
	}

}

/**
* @brief testeSetBezeichnung
* @details Autom Test Setze Bezeichnung
* @param artikel Artikel obj
*/
void Artikeldialog::testeSetBezeichnung(Artikel *artikel){
	string bezeichnung = NEUBEZ;
	cout << endl << "Starte Test zum Setzen der Bezeichnung eines Artikels..." << endl;

	cout << "Die neue Bezeichnung soll " << bezeichnung << " sein!" << endl;

	cout << "Artikel vorher:" << endl;
	ausgeben(*artikel);

	try {
		artikel->setBezeichnung(bezeichnung);
		cout << endl << "Artikel nachher:" << endl;
		ausgeben(*artikel);
	} catch (const char* e) {
		cout << ERRORPHRASE << e << endl;
	}

}

/**
* @brief testeSetBestand
* @details Autom Test Setze Bestand
* @param artikel Artikel obj
*/
void Artikeldialog::testeSetBestand(Artikel *artikel){
	int bestand = NEUBESTAND;
	cout << endl << "Starte Test zum Setzen des Bestands eines Artikels..." << endl;

	cout << "Der neue Bestand soll " << bestand << " sein!" << endl;

	cout << "Artikel vorher:" << endl;
	ausgeben(*artikel);

	try {
		artikel->setBestand(bestand);
		cout << endl << "Artikel nachher:" << endl;
		ausgeben(*artikel);
	} catch (const char* e) {
		cout << ERRORPHRASE << e << endl;
	}

}
/**
 * @brief Test des Setzens des Preises eines Artikels
 * @param artikel
 */
void Artikeldialog::testeSetPreis(Artikel *artikel){
	double preis = NEUPREIS;
	cout << endl << "Starte Test zum Setzen des Preises eines Artikels..." << endl;

	cout << "Der neue Preis soll " << preis << " sein!" << endl;

	cout << "Artikel vorher:" << endl;
	ausgeben(*artikel);

	try {
		artikel->setPreis(preis);
		cout << endl << "Artikel nachher:" << endl;
		ausgeben(*artikel);
	} catch (const char* e) {
		cout << ERRORPHRASE << e << endl;
	}

}
/**
 * @brief Test der Aenderung eines Preises
 * @param artikel
 */
void Artikeldialog::testeAenderePreis(Artikel *artikel){
	double preisaenderung=TESTAENDERUNG;

	cout << endl << "Starte Test zur Aenderung des Preises..." << endl;

	cout << "Der Preis aendert sich um " << preisaenderung << " Prozent!" << endl;

	cout << "Artikel vor Zugang:" << endl;
	ausgeben(*artikel);

	try {
		artikel->aenderePreis(preisaenderung);
		cout << endl << "Artikel nach Zugang:" << endl;
		ausgeben(*artikel);
	} catch (const char* e) {
		cout << ERRORPHRASE << e << endl;
	}
}
/**
* @brief testeAlles
* @details Autom Test Fkt
*/
void Artikeldialog::testeAlles(){
	int artikelNr= TESTNR;
	string beschreibung = TESTBEZ;
	int bestand = TESTBESTAND;
	double preis= TESTPREIS;
	Artikel* artikel(artikelNr,beschreibung,bestand);

	cout << endl << "Starte alle Tests..." << endl;
	testeConstructor1(artikelNr, beschreibung, preis);
	testeConstructor2(artikelNr, beschreibung, preis, bestand);
	testeBucheAbgang(artikel);
	testeBucheZugang(artikel);
	testeSetBezeichnung(artikel);
	testeSetBestand(artikel);
	testeSetPreis(artikel);
	testeAenderePreis(artikel);
}
/**
* @brief Benutzerdialog
* @details Dialog zur Auswahl zwischen automatischen Tests und manuellem Testen
*/
void Artikeldialog::dialog(){
	int answer;
	do {
		cout << SEPERATOR << endl;
		cout << DIALOGOPTIONONE << endl;
		cout << DIALOGOPTIONTWO << endl;
		cout << DIALOGOPTIONTHREE << endl;
		cout << STANDARDEXITOPTION << endl << endl;
		cout << STANDARDCHOICEPHRASE;
		cin >> answer;
		try {
			switch (answer){
				case 0:
					break;
				case 1:
					testeAlles();
					break;
				case 2:
					createArtikelMitBestand();
					break;
				case 3:
					createArtikelOhneBestand();
					break;
				default:
					cout << INPUTERRORPHRASE << endl;
			}
		} catch (const char* e) {
			cout << ERRORPHRASE << e << endl;
		}
	} while (answer != 0);
}

/**
* @brief createArtikelComplete
* @details Artikel Erstellung mit 4 parametern
*/
void Artikeldialog::createArtikelMitBestand(){
	int artikelNr=0;
	string bezeichnung="";
	double artikelPreis=0.0;
	int bestand = 0;
	cout << CREATEARTIKELPHRASE << endl << ARTIKELNUMMER;
	cin >> artikelNr;
	leereEingabe();
	cout << BEZEICHNUNG;
	cin >> bezeichnung;
	cout << ARTIKELPREIS;
	cin >> artikelPreis;
	leereEingabe();
	cout << BESTAND;
	cin >> bestand;
	leereEingabe();
	Artikel artikel(artikelNr, bezeichnung, artikelPreis, bestand);
	manuell(artikel);

}
/**
* @brief createArtikelTwoParam
* @details Artikel Erstellung mit 3 parametern wobei bestand=0
*/
void Artikeldialog::createArtikelOhneBestand(){
	int artikelNr=0;
	string bezeichnung="";
	int artikelPreis=0;
	cout << CREATEARTIKELPHRASE << endl << ARTIKELNUMMER;
	cin >> artikelNr;
	leereEingabe();
	cout << BEZEICHNUNG;
	cin >> bezeichnung;
	cout << ARTIKELPREIS;
	cin >> artikelPreis;
	leereEingabe();
	Artikel artikel(artikelNr, bezeichnung,artikelPreis);
	manuell(artikel);
}
/**
* @brief manuell
* @details manuell Fkt untere ebene des Dialogs
* @param artikel Artikel obj
*/
void Artikeldialog::manuell(Artikel artikel){
	int answer=-1;
	double preis=0.0;
	int menge=0;
	string bezeichnung;
	do {
		cout << SEPERATOR << endl;
		cout << ARTIKELNUMMER << artikel.getArtikelNr() << endl;
		cout << BEZEICHNUNG << artikel.getBezeichnung() << endl;
		cout << ARTIKELPREIS << artikel.getArtikelPreis() << endl;
		cout << BESTAND << artikel.getBestand() << endl;
		cout << SEPERATOR << endl;
		cout << MANUELLDIALOGOPTIONONE << endl;
		cout << MANUELLDIALOGOPTIONTHREE << endl;
		cout << MANUELLDIALOGOPTIONTHREE << endl << endl;
		cout << MANUELLDIALOGOPTIONFOUR << endl;
		cout << MANUELLDIALOGOPTIONFIVE << endl;
		cout << MANUELLDIALOGOPTIONSIX << endl << endl;
		cout << STANDARDEXITOPTION << endl << endl;
		cout << STANDARDCHOICEPHRASE;
		cin >> answer;
		try {
			switch (answer){
				case 0:
					break;
				case 1:
					cout << BEZEICHNUNG;
					cin >> bezeichnung;
					artikel.setBezeichnung(bezeichnung);
					break;
				case 2:
					cout << NEWPHRASE << ARTIKELPREIS;
					cin >> preis;
					artikel.setPreis(preis);
					break;
				case 3:
					cout << NEWPHRASE << BESTAND;
					cin >> menge;
					artikel.setBestand(menge);
					break;
				case 4:
					cout << PRICECHANGEPHRASE;
					cin >> preis;
					artikel.aenderePreis(preis);
					break;
				case 5:
					cout << VALUEPHRASE;
					cin >> menge;
					artikel.bucheAbgang(menge);
					break;
				case 6:
					cout << VALUEPHRASE;
					cin >> menge;
					artikel.bucheZugang(menge);
					break;
				default: cout << INPUTERRORPHRASE << endl;
			}
		} catch (const char* e) {
			cout << endl << ERRORPHRASE << e << endl << endl;
		}
		leereEingabe();
	} while (answer != 0);
}

/**
 * @brief Eingabeleerung
 * @details Im Falle einer falschen eingabe leer dies den Eingabepuffer.
 */
void Artikeldialog::leereEingabe(){
	cin.clear();
	cin.ignore(BIGNUMBER, '\n');
}

