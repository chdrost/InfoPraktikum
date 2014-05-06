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
	stringstream s;

	s << "\nPunktlokation\nName:" << this->firstName;
	s << "\nUebergeordnete Strasse: ";
	if (this->linearReference != NULL) {
		s << this->linearReference->getRoadName();
	} else {
		s << "Keine Strasse uebergeordnet";
	}
	s << "\nKoordninate: " << this->geoKoordinate->toString();
	s << "\nDarin enthalten:\nNegative Offset: ";
	if (this->negativeOffset != NULL) {
		s << this->negativeOffset->getFirstName();
	} else {
		s << " Es ist kein Negative Offset hinterlegt.";
	}
	s << "\nPositive Offset: ";
	if (this->positiveOffset != NULL) {
		s << this->positiveOffset->getFirstName();
	} else {
		s << " Es ist kein positive Offset hinterlegt.";
	}
	s << "\nIntersection Code:";
	if (this->intersectioncode != NULL) {
		s << this->intersectioncode->getFirstName();
	} else {
		s << " Es ist kein Intersectioncode hinterlegt.";
	}
	s << "\nInterrupts Road";
	if (this->interruptsRoad != NULL) {
		s << this->interruptsRoad->getFirstName();
	} else {
		s << " Es ist kein Interrupts Road hinterlegt hinterlegt.";
	}
	return (s.str());
}

int Punktlokation::getType() {
	return (PUNKT);
}

GeoKoordinate * Punktlokation::getGeoKoordinate() const {
	return (geoKoordinate);
}

Linearlokation* Punktlokation::getLinearReference() const {
	return (linearReference);
}

int Punktlokation::getNetzKontenNummerNach() const {
	return (netzKontenNummerNach);
}

int Punktlokation::getNetzKontenNummerVor() const {
	return (netzKontenNummerVor);
}

int Punktlokation::getStation() const {
	return (station);
}
