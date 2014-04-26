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

void FileOpener::leseDateiAus() {
	string zeile;
	while (getline(datei, zeile)) {
		datenSatz.push_back(zeile);
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
			if (*it == ";") {
				zwischenVector.push_back(zwischenString);
				zwischenString = "";
			}
			zwischenString += *it;
		}
		geteilterDatensatz.push_back(zwischenVector);
	}
}
