/*
 * Linearlokation.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "Linearlokation.h"

Linearlokation::Linearlokation(vector<string> *zeile,
		Gebietslokation *areaReference) :
		Gebietslokation(zeile) {
	this->areaReference = areaReference;
	leseWerteEin(zeile);

}

Linearlokation::~Linearlokation() {
	// TODO Auto-generated destructor stub
}

const string& Linearlokation::getAdminCounty() const {
	return adminCounty;
}

Gebietslokation* Linearlokation::getAreaReference() {
	return areaReference;
}

bool Linearlokation::isInNegative() const {
	return inNegative;
}

bool Linearlokation::isInPositive() const {
	return inPositive;
}

Linearlokation* Linearlokation::getInterruptsRoad() {
	return interruptsRoad;
}

Linearlokation* Linearlokation::getIntersectioncode() {
	return intersectioncode;
}

Linearlokation* Linearlokation::getNegativeOffset() {
	return negativeOffset;
}

bool Linearlokation::isOutNegative() const {
	return outNegative;
}

bool Linearlokation::isOutPositive() const {
	return outPositive;
}

const string& Linearlokation::getPoldir() const {
	return poldir;
}

Linearlokation* Linearlokation::getPositiveOffset() {
	return positiveOffset;
}

bool Linearlokation::isPresentNegative() const {
	return presentNegative;
}

bool Linearlokation::isPresentPositive() const {
	return presentPositive;
}

const string& Linearlokation::getRoadName() const {
	return roadName;
}

const string& Linearlokation::getRoadNumer() const {
	return roadNumer;
}

const string& Linearlokation::getSecondName() const {
	return secondName;
}

bool Linearlokation::isTern() const {
	return tern;
}

bool Linearlokation::isUrban() const {
	return urban;
}

int Linearlokation::getVeraendert() const {
	return veraendert;
}

void Linearlokation::setAreaReference( Gebietslokation* areaReference) {
	this->areaReference = areaReference;
}

void Linearlokation::leseWerteEin(vector<string>* zeile) {
//TODO Defaultwerte als Konstanten und cerr entfernen
	this->roadNumer = zeile->at(ROADNUMBER);
	this->roadName = zeile->at(ROADNAME);
	this->secondName = zeile->at(SECOND_NAME);
	try {
		this->urban = stoi(zeile->at(URBAN));
	} catch (const std::invalid_argument &e) {
		this->urban = 0;
		cerr<<"\n"<<zeile->at(URBAN)<<"  Cerr ausgeloest\n";
	}
	try {
		this->inPositive = stoi(zeile->at(IN_POSITIVE));
	} catch (const std::invalid_argument &e) {
		this->inPositive = 0;
		cerr<<"\n"<<zeile->at(IN_POSITIVE)<<"  Cerr ausgeloest\n";
	}
	try {
		this->outPositive = stoi(zeile->at(OUT_POSITIVE));
	} catch (const std::invalid_argument &e) {
		this->outPositive = false;
		cerr<<"\n"<<zeile->at(OUT_POSITIVE)<<"  Cerr ausgeloest\n";
	}
	try {
		this->inNegative = stoi(zeile->at(IN_NEGATIVE));
	} catch (const std::invalid_argument &e) {
		this->inNegative = false;
		cerr<<"\n"<<zeile->at(IN_NEGATIVE)<<"\n Cerr ausgeloest";
	}
	try {
		this->outNegative = stoi(zeile->at(OUT_NEGATIVE));
	} catch (const std::invalid_argument &e) {
		this->outNegative = false;
		cerr<<"\n"<<zeile->at(OUT_NEGATIVE)<<"  Cerr ausgeloest\n";
	}
	try {
		this->presentPositive = stoi(zeile->at(PRESENT_POSITIVE));
	} catch (const std::invalid_argument &e) {
		this->presentPositive = false;
		cerr<<"\n"<<zeile->at(PRESENT_POSITIVE)<<"  Cerr ausgeloest\n";
	}
	try {
		this->presentNegative = stoi(zeile->at(PRESENT_NEGATIVE));
	} catch (const std::invalid_argument &e) {
		this->presentNegative = false;
		cerr<<"\n"<<zeile->at(PRESENT_NEGATIVE)<<"  Cerr ausgeloest\n";
	}
	try {
		this->veraendert = stoi(zeile->at(VERAENDERT));
	} catch (const std::invalid_argument &e) {
		this->veraendert = false;
		cerr<<"\n"<<zeile->at(VERAENDERT)<<"  Cerr ausgeloest\n";
	}
	try {
		this->tern = stoi(zeile->at(TERN));
	} catch (const std::invalid_argument &e) {
		this->tern = false;
		cerr<<"\n"<<zeile->at(TERN)<<"  Cerr ausgeloest\n";
	}
	this->poldir = zeile->at(POLDIR);
	this->adminCounty = zeile->at(ADMIN_County);
}
