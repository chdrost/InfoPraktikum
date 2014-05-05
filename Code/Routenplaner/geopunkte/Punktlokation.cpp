/*
 * Punktlokation.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "Punktlokation.h"

Punktlokation::Punktlokation(vector<string> *zeile,
		Gebietslokation *areaReference, Linearlokation *linearReference) :
		Linearlokation(zeile, areaReference) {
	this->linearReference = linearReference;
	if (!zeile->at(NETZKNOTEN1_NR).empty()) {
		try {
			this->netzKontenNummerVor = stoi(zeile->at(NETZKNOTEN1_NR));
		} catch (const std::invalid_argument &e) {
			this->netzKontenNummerVor = 0;
		}
	}
	if (!zeile->at(NETZKNOTEN2_NR).empty()) {
		try {
			this->netzKontenNummerNach = stoi(zeile->at(NETZKNOTEN2_NR));
		} catch (const std::invalid_argument &e) {
			this->netzKontenNummerNach = 0;
		}
	}
	if (!zeile->at(STATION).empty()) {
		try {
			this->station = stoi(zeile->at(STATION));
		} catch (const std::invalid_argument &e) {
			this->station = 0;
		}
	}
	this->geoKoordinate = new GeoKoordinate(zeile->at(X_KOORDINATE),
			zeile->at(Y_KOORDINATE));
}

Punktlokation::~Punktlokation() {
	delete this->geoKoordinate;
}

string Punktlokation::toString() {
	return (Linearlokation::toString());
}
