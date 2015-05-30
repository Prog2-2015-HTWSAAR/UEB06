#include "BasisDialog.h"

const char* BasisDialog::SEPERATOR = "-B-----------------------------";
const char* BasisDialog::DIALOGOPTIONONE = "(1) Artikeldialog";
const char* BasisDialog::DIALOGOPTIONTWO = "(2) Lagerdialog";
const char* BasisDialog::STANDARDEXITOPTION = "(0) -EXIT/BACK-";
const char* BasisDialog::STANDARDCHOICEPHRASE = "Waehlen sie eine Option : ";
const char* BasisDialog::INPUTERRORPHRASE = "-> FEHLERHAFTE EINGABE <-";
const char* BasisDialog::ERRORPHRASE = "Fehler: ";
BasisDialog::BasisDialog(){}
BasisDialog::~BasisDialog(){}

void BasisDialog::dialog(){
	int answer = -1;
	do {
		try {
			cout << endl << SEPERATOR << endl << DIALOGOPTIONONE << endl
				<< DIALOGOPTIONTWO << endl << STANDARDEXITOPTION << endl
				<< endl << STANDARDCHOICEPHRASE;
			cin >> answer;
			switch (answer) {
			case 0:
				break;
			case 1:
				enterArtikelDialog();
				break;
			case 2:
				enterLagerDialog();
				break;
			default:
				cout << INPUTERRORPHRASE << endl;
				break;
			}
		}
		catch (const char* e) {
			cout << ERRORPHRASE << e << endl;
		}
		leereEingabe();
	} while (answer != 0);
}
void BasisDialog::leereEingabe(){
	cin.clear();
	cin.ignore(BIGNUMBER, '\n');
}
void BasisDialog::enterArtikelDialog(){
	Artikeldialog dia;
	dia.dialog();
}
void BasisDialog::enterLagerDialog(){
	LagerDialog dia;
	dia.dialog();
}
