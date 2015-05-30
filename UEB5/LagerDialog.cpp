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
	int answer = -1;
	string wirklichLoeschen ="n";
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
				cout << SEPERATORDELETEARTIKEL << endl <<LAGERWIRKLICHLOESCHEN;
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

		}catch (LagerException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}catch (ArtikelException& e) {
			cout << ERRORPHRASE << e.what() << endl;
		}
	} while (answer != 0);

}
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

void LagerDialog::leereEingabe(){
	cin.clear();
	cin.ignore(BIGNUMBER, '\n');
}
