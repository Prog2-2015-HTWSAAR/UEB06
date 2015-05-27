#include "LagerDialog.h"


LagerDialog::LagerDialog(){}
LagerDialog::~LagerDialog(){}

void LagerDialog::dialog(){
	int answer;
	int anzahl;
	string name = STANDARDLAGERNAME;
	do {
		cout << SEPERATOR << endl << DIALOGOPTIONONE << endl << DIALOGOPTIONTWO
			<< endl << STANDARDEXITOPTION << endl
			<< endl << STANDARDCHOICEPHRASE;
		cin >> answer;
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
				startLagerDialog(anzahl, name);
				break;
			case 2:
				cout << SEPERATORCREATELAGER << endl << ENTERSIZEPHRASE;
				cin >> anzahl;
				leereEingabe();
				startLagerDialog(anzahl, name);
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
			}
		}
		catch (const char* e) {
			cout << ERRORPHRASE << e << endl;
		}
		leereEingabe();
	} while (answer != 0);
}
void LagerDialog::startLagerDialog(int size, string name) {
	Lager* lager1 = new Lager(size, name);
	int answer;
	int artikelNr;
	int bestand;
	double preis;
	string bezeichnung;
	do {
		cout << SEPERATOR << endl << LAGERDIALOGOPTIONONE << endl << LAGERDIALOGOPTIONTWO
			<< endl << LAGERDIALOGOPTIONTHREE << endl << LAGERDIALOGOPTIONFOUR 
			<< endl << LAGERDIALOGOPTIONFIVE << endl << LAGERDIALOGOPTIONSIX << endl 
			<< LAGERDIALOGOPTIONEXIT << endl << endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		try {
			switch (answer){
			case 0:
				break;
			case 1:
				cout << SEPERATORCREATEARTIKEL << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				cout << BEZEICHNUNG;
				cin >> bezeichnung;
				cout << ARTIKELPREIS;
				cin >> preis;
				cout << BESTAND;
				cin >> bestand;
				lager1->createArtikel(artikelNr, bezeichnung, preis, bestand);
				break;
			case 2:
				cout << SEPERATORCREATEARTIKEL << endl << ARTIKELNUMMER;
				cin >> artikelNr;
				cout << BEZEICHNUNG;
				cin >> bezeichnung;
				cout << ARTIKELPREIS;
				cin >> preis;
				cout << BESTAND;
				cin >> bestand;
				lager1->createArtikel(artikelNr, bezeichnung, preis);
				break;
			case 3:
				break;
			case 4:
				artikelEditDialog();
				break;
			case 5:
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
			}
			cout << *lager1 << endl;
		}
		catch (const char* e) {
			cout << ERRORPHRASE << e << endl;
		}
		leereEingabe();
	} while (answer != 0);
}
void LagerDialog::artikelEditDialog(){
	int answer;
	do {
		cout << SEPERATOR << endl << EDITDIALOGOPTIONONE << endl << EDITDIALOGOPTIONTWO
			<< endl << EDITDIALOGOPTIONTHREE << endl << EDITDIALOGOPTIONFOUR
			<< endl << EDITDIALOGOPTIONFIVE << endl << EDITDIALOGOPTIONSIX << endl
			<< STANDARDBACKOPTION << endl << endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		try {
			switch (answer){
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
			}
		}
		catch (const char* e) {
			cout << ERRORPHRASE << e << endl;
		}
		leereEingabe();
	} while (answer != 0);
}

void LagerDialog::leereEingabe(){
	cin.clear();
	cin.ignore(BIGNUMBER, '\n');
}