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
#include "BasisDialog.h"
/**
* @brief Main Function
*/
int main(){
	BasisDialog dia;
	dia.dialog();
	return 0;
}
