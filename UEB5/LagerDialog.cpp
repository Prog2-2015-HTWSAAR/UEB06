#include "LagerDialog.h"


LagerDialog::LagerDialog(){}
LagerDialog::~LagerDialog(){}

void LagerDialog::dialog(){
	Lager* lager;
	int answer = -1;
	int anzahl = -1;
	string name = STANDARDLAGERNAME;
	do {
		cout << SEPERATOR << endl << DIALOGOPTIONONE << endl << DIALOGOPTIONTWO
			<< endl << DIALOGOPTIONTHREE<< endl <<STANDARDEXITOPTION << endl
			<< endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		leereEingabe();
		try {
			switch (answer){
			case 0:
				cout << "exit is no option here" << endl;
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
				break;
			case 2:
				cout << SEPERATORCREATELAGER << endl << ENTERSIZEPHRASE;
				cin >> anzahl;
				leereEingabe();
				lager = new Lager(anzahl);
				startLagerDialog(lager);
				break;
			case 3:
				lager = new Lager();
				startLagerDialog(lager);

				break;
			default:
				cout << INPUTERRORPHRASE << endl;
			}
			delete lager;
		}catch (LagerException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}

	} while (answer != 0);
}
void LagerDialog::startLagerDialog(Lager* lager) {
	//TODO REST LAGERFUNKIONENEN IMPLEMENTIEREN!!!
	int answer = -1;
	int artikelNr = 0000;
	int bestand = 0;
	double preis;
	string bezeichnung;
	do {
		cout << *lager << endl;
		cout << SEPERATOR << endl << LAGERDIALOGOPTIONONE << endl << LAGERDIALOGOPTIONTWO
			<< endl << LAGERDIALOGOPTIONTHREE << endl << LAGERDIALOGOPTIONFOUR 
			<< endl << LAGERDIALOGOPTIONFIVE << endl << LAGERDIALOGOPTIONSIX << endl 
			<< LAGERDIALOGOPTIONEXIT << endl << endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		leereEingabe();
		try {
			switch (answer){
			case 0:
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
				lager->createArtikel(artikelNr, bezeichnung, preis);
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

		}catch (ArtikelException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}catch (LagerException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}
	} while (answer != 0);

}
void LagerDialog::artikelEditDialog(){
	int answer = -1;
	do {
		cout << SEPERATOR << endl << EDITDIALOGOPTIONONE << endl << EDITDIALOGOPTIONTWO
			<< endl << EDITDIALOGOPTIONTHREE << endl << EDITDIALOGOPTIONFOUR
			<< endl << EDITDIALOGOPTIONFIVE << endl << EDITDIALOGOPTIONSIX << endl
			<< STANDARDBACKOPTION << endl << endl << STANDARDCHOICEPHRASE;
		cin >> answer;
		leereEingabe();
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
