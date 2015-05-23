/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb01 *.o
* @file ueb03.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 16.05.2015
*
* Main Funktion
*

*/
#include <iostream>

#include "Artikeldialog.h"
/**
* @brief Main Function
*/
int main(){
	Artikeldialog dia;
	dia.dialog();
	return 0;
}
