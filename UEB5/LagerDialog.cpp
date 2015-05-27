#include "LagerDialog.h"


LagerDialog::LagerDialog(){}
LagerDialog::~LagerDialog(){}

void LagerDialog::dialog(){
	int answer;
	do {
		cout << SEPERATOR << endl << DIALOGOPTIONONE << endl << DIALOGOPTIONTWO
			<< endl << DIALOGOPTIONTHREE << endl << STANDARDEXITOPTION << endl
			<< endl << STANDARDCHOICEPHRASE;
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