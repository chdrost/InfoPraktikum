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
	while (getline(datei, zeile))
	{
	    datenSatz.push_back(zeile);
	}
}
