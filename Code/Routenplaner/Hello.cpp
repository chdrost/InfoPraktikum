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
	// TODO Auto-generated destructor stub
}

#include <iostream>                                     // Ein- und Ausgabebibliothek

int main() {                                             // Hauptfunktion
	std::cout << "Hallo, du schöne Welt!" << std::endl; // Ausgabe

	Aktualitaet akt = Aktualitaet();
	cout << "Mit Null: " << akt.toString() << "\n";
	Aktualitaet akkt = Aktualitaet("01.11.04 16:37:00");
	cout << "Mit 01.11.04 16:37:00 : " << akkt.toString();

	//Jetzt mal die Datei auslesen
	FileOpener *datei = new FileOpener();
	datei->oeffneDatei(
			"/Users/christoph/Documents/HTW/SEM6/InfoPraktikum/Code/Routenplaner/testdatei.csv");
	datei->leseDateiAus();
	vector<string> vec = datei->getDatenSatz();
	cout << "\n" << "Die Groesse des Vectors: " << vec.size() << "\n";

	for (vector<string>::iterator i = vec.begin(); i != vec.end(); i++) {
		cout << *i << "\n";
	}

	cout << "\n------------Teilen der Zeilen--------------\n";
	datei->spalteZeilen();

	cout << "ende";
	return 0;                        // Optionale Rückgabe an das Betriebssystem
}

