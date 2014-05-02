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

void LokationsVerwaltung::objektErstellen(vector<string> *zeile,
		string pattern) {
	if (regex_match(zeile->at(TYPE), regex("\"A(.*)"))) {
		speichereGebietsLokation(new Gebietslokation(zeile));
	} else if (regex_match(zeile->at(TYPE), regex("\"L(.*)"))) {
		new Linearlokation(zeile, (Gebietslokation*) NULL);
	} else if (regex_match(zeile->at(TYPE), regex("\"P(.*)"))) {
		cout << "Spalte 32  " << zeile->at(31) << "\n";
	}
//TODO Nach dem gesamten Einlesen brauchen die LinLok noch einen Duchlauf um  die Referenzen zu verlinken
}

void LokationsVerwaltung::speichereGebietsLokation(Gebietslokation* lokation) {
	gebieteVector.push_back(lokation);
	insertMap(lokation);
}

void LokationsVerwaltung::speichereLinearLokation(vector<string>* zeile) {
	Gebietslokation *areaReference = gebieteMap.at(
			stoi(zeile->at(AREA_REFERENCE)));
	Linearlokation *linearLokation = new Linearlokation(zeile, areaReference);
	areaReference->addLinLokation(linearLokation);
	insertMap(linearLokation);

}

void LokationsVerwaltung::speicherePunkLokation(vector<string>* zeile) {
	Punktlokation *punkLokation;
	if (!zeile->at(LINEAR_REFERENCE).empty()) {
		Linearlokation *linearReference = (Linearlokation*) gebieteMap.at(
				stoi(zeile->at(LINEAR_REFERENCE)));
		punkLokation = new Punktlokation(zeile, linearReference);
		linearReference->addPktLokation(punkLokation);
	} else {
		punkLokation = new Punktlokation(zeile, NULL); //TODO Hier suchen wenn seltsame Fehler auftreten
	}
	insertMap(punkLokation);
}

void LokationsVerwaltung::objekteErstellen(vector<vector<string> >* datenSatz) {
//Erster Durchlauf, Erstellen der Gebietslokationen
	for (auto it = datenSatz->begin(); it != datenSatz->end(); it++) {
		if (regex_match(it->at(TYPE), regex("\"A(.*)"))) {
			speichereGebietsLokation(new Gebietslokation(&*it));
		}
	}
//Zeiter Durchlauf, Erstellen der Linearlokationen
	for (auto it = datenSatz->begin(); it != datenSatz->end(); it++) {
		if (regex_match(it->at(TYPE), regex("\"L(.*)"))) {
			speichereLinearLokation(&*it);
		}
	}
//Dritter Durchlauf, Erstellen der Punktlokationen
	for (auto it = datenSatz->begin(); it != datenSatz->end(); it++) {
		if (regex_match(it->at(TYPE), regex("\"P(.*)"))) {
			speicherePunkLokation(&*it);
		}
	}

//Vierter Durchlauf, Verknuepfung der Abhaengigleiten
//TODO Abhaengigkeiten verlinken
}

void LokationsVerwaltung::insertMap(Gebietslokation* lok) {
	gebieteMap.insert(pair<int, Gebietslokation*>(lok->getId(), lok));
	namenMap.insert(pair<string, Gebietslokation*>(lok->getFirstName(), lok));
}

Gebietslokation* LokationsVerwaltung::suchName(string name) {
	return ( namenMap.find(name)->second);
}

const multimap<string, Gebietslokation*>& LokationsVerwaltung::getNamenMap() const {
	return (namenMap);
}
