/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb06 *.o
* @file ueb05.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 26.05.2015
*
* Main Funktion
*

*/
#include <iostream>

#include "../UEB06/BasisDialog.h"
/**
* @brief Main Function
*/
int main(){
	BasisDialog basisDialog;
	basisDialog.startDialog();
	return 0;
}
