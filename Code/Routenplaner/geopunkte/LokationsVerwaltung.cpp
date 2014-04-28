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

void LokationsVerwaltung::objektErstellen(vector<string> *zeile, string pattern) {
	if (regex_match(zeile->at(TYPE), regex("\"A(.*)"))) {
		speichereGebietsLokation(new Gebietslokation(zeile));
	} else if (regex_match(zeile->at(TYPE), regex("\"L(.*)"))) {
		new Linearlokation(zeile, (Gebietslokation*)NULL);
	} else if (regex_match(zeile->at(TYPE), regex("\"P(.*)"))) {
		cout << "Spalte 32  "<<zeile->at(31) << "\n";
	}
//TODO Nach dem gesamten Einlesen brauchen die LinLok noch einen Duchlauf um  die Referenzen zu verlinken
}

void LokationsVerwaltung::speichereGebietsLokation(Gebietslokation* lokation) {
	gebieteVector.push_back(lokation);
	gebieteMap.insert(pair<int, Gebietslokation*>(lokation->getId(), lokation));
	namenMap.insert(
			pair<string, Gebietslokation*>(lokation->getFirstName(), lokation));
}

void LokationsVerwaltung::speichereLinearLokation(vector<string>* zeile) {
	Gebietslokation *areaReference = gebieteMap.at(stoi(zeile->at(AREA_REFERENCE)));
	Linearlokation *linearLokation = new Linearlokation(zeile, areaReference);
	areaReference->addLinLokation(linearLokation);
	gebieteMap.insert(pair<int, Gebietslokation*>(linearLokation->getId(), linearLokation));
	namenMap.insert(
				pair<string, Gebietslokation*>(linearLokation->getFirstName(), linearLokation));


}

void LokationsVerwaltung::objekteErstellen(vector<vector<string> >* datenSatz) {
	//Erster Durchlauf, Erstellen der Gebietslokationen
	for(auto it = datenSatz->begin(); it != datenSatz->end(); it++){
		if (regex_match(it->at(TYPE), regex("\"A(.*)"))) {
				speichereGebietsLokation(new Gebietslokation(&*it));
			}
	}
	//Zeiter Durchlauf, Erstellen der Linearlokationen
	for(auto it = datenSatz->begin(); it != datenSatz->end(); it++){
		if (regex_match(it->at(TYPE), regex("\"L(.*)"))) {
					speichereLinearLokation(&*it);
				}
		}
	//Dritter Durchlauf, Erstellen der Punktlokationen
	//TODO Punktlokationen einlesen

	//Vierter Durchlauf, Verknuepfung der Abhaengigleiten
	//TODO Abhaengigkeiten verlinken
}
