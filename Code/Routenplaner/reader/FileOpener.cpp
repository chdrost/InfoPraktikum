/*
 * FileOpener.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "FileOpener.h"

FileOpener::FileOpener() {
}

FileOpener::~FileOpener() {
	if (datei != NULL) {
		datei.close();
	}
}

void FileOpener::oeffneDatei(const char* adresse) {
	datei.open(adresse, ifstream::in);
	if (!datei) {
		throw FileNotFoundException("Die Datei konnte nicht gefunden werden.");
	}
}
/**
 void FileOpener::leseDateiAus() {
 string zeile;
 while (getline(datei, zeile)) {
 datenSatz.push_back(zeile);
 }
 }*/

void FileOpener::leseDateiAus() {
	string zeile, spalte;
	vector<string> zeilenVector;
	while (getline(datei, zeile)) {
		istringstream stringStream(zeile);
		while (getline(stringStream, spalte, ';')) {
			zeilenVector.push_back(spalte);
		}
		geteilterDatensatz.push_back(zeilenVector);
		zeilenVector.clear();
	}
}
void FileOpener::spalteZeilen(void) {
	vector<string> zwischenVector;
	string zwischenString;
	string zeile;
	for (vector<string>::iterator it = datenSatz.begin(); it != datenSatz.end();
			it++) {
		zeile = *it;
		for (string::iterator sit = zeile.begin(); sit != zeile.end(); sit++) {
			if (*sit == ';') {
				zwischenVector.push_back(zwischenString);
				zwischenString = "";
			}
			zwischenString += *sit;
		}
		//cout<< "Zwischenstring: " <<zwischenString << "\n";
		geteilterDatensatz.push_back(zwischenVector);
	}
}
