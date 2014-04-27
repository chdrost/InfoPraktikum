/*
 * LokationsVerwaltung.cpp
 *
 *  Created on: 26.04.2014
 *      Author: christoph
 */

#include "LokationsVerwaltung.h"

LokationsVerwaltung::LokationsVerwaltung() {
	// TODO Auto-generated constructor stub
}

LokationsVerwaltung::~LokationsVerwaltung() {
	/**
	 * Alle Daten l&ouml;schen.
	 */
	for (map<int, Gebietslokation*>::iterator it = gebieteMap.begin();
			it != gebieteMap.end(); it++) {
		delete it->second;
	}
}

void LokationsVerwaltung::objektErstellen(vector<string> *zeile) {
	if (regex_match(zeile->at(TYPE), regex("\"A(.*)"))) {
		//speichereGebietsLokation(new Gebietslokation(zeile));
	} else if (regex_match(zeile->at(TYPE), regex("\"L(.*)"))) {
		cout << "Spalte 32  "<<zeile->at(31) << "\n";
	} else if (regex_match(zeile->at(TYPE), regex("\"P(.*)"))) {
		//cout << "Punktlokation gefunden \n";
	}

}

void LokationsVerwaltung::speichereGebietsLokation(Gebietslokation* lokation) {
	gebieteVector.push_back(lokation);
	gebieteMap.insert(pair<int, Gebietslokation*>(lokation->getId(), lokation));
	namenMap.insert(
			pair<string, Gebietslokation*>(lokation->getFirstName(), lokation));
}
