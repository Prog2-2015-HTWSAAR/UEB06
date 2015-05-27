#include "BasisDialog.h"


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