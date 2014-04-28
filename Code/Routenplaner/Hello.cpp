/*
 * Hello.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "Hello.h"
using namespace std;
Hello::Hello() {
	// TODO Auto-generated constructor stub

}

Hello::~Hello() {
}

#include <iostream>                                     // Ein- und Ausgabebibliothek

int main() {                                             // Hauptfunktion
	//Jetzt mal die Datei auslesen
	FileOpener *datei = new FileOpener();
	datei->oeffneDatei(
			"/Users/christoph/Documents/HTW/SEM6/InfoPraktikum/Code/Routenplaner/testdatei.csv");
	datei->leseDateiAus();
	cout << "\n\n------------Einlesen abgeschlossen-----------\n\n";
	vector<vector<string> > erg = datei->getDatensatz();
	/*
	 vector<string> zwischen;
	 for(vector< vector<string> >::iterator it = erg.begin(); it != erg.end(); it++){
	 zwischen = *it;
	 for(vector<string>::iterator innerer = zwischen.begin(); innerer != zwischen.end(); innerer++){
	 cout<< *innerer<< "  ";
	 }
	 cout << "\n\n";
	 }*/

	LokationsVerwaltung *lokVerwaltung = new LokationsVerwaltung();
	lokVerwaltung->objekteErstellen(&erg);
	cout << "\nGroesse Vector: "<< lokVerwaltung->getGebieteVector().size();

	delete datei;
	delete lokVerwaltung;

	return (EXIT_SUCCESS);           // Optionale Rückgabe an das Betriebssystem
}

