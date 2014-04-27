/*
 * Linearlokation.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "Linearlokation.h"

Linearlokation::Linearlokation(vector<string> *zeile,
		Gebietslokation *areaReference, map<int, Gebietslokation*> *gebieteMap) :
		Gebietslokation(zeile) {
	this->roadNumer = zeile->at(ROADNUMBER);
	this->roadName = zeile->at(ROADNAME);
	this->secondName = zeile->at(SECOND_NAME);
	this->areaReference = gebieteMap->at(stoi(zeile->at(AREA_REFERENCE)));
	this->negativeOffset = (Linearlokation*) gebieteMap->at(
			stoi(zeile->at(NEGATIVE_OFFSET)));
	this->positiveOffset = (Linearlokation*) gebieteMap->at(
			stoi(zeile->at(POSITIVE_OFFSET)));
	this->urban = stoi(zeile->at(URBAN));
	this->intersectioncode = (Linearlokation*) gebieteMap->at(
			stoi(zeile->at(INTERSECTIONSCODE)));
	this->interruptsRoad = (Linearlokation*) gebieteMap->at(
			stoi(zeile->at(INTERRUPTS_ROAD)));
	this->inPositive = stoi(zeile->at(IN_POSITIVE));
	this->outPositive = stoi(zeile->at(OUT_POSITIVE));
	this->inNegative = stoi(zeile->at(IN_NEGATIVE));
	this->outNegative = stoi(zeile->at(OUT_NEGATIVE));
	this->presentPositive = stoi(zeile->at(PRESENT_POSITIVE));
	this->presentNegative = stoi(zeile->at(PRESENT_NEGATIVE));
	this->veraendert = stoi(zeile->at(VERAENDERT));
	this->tern = stoi(zeile->at(TERN));
	this->poldir = zeile->at(POLDIR);
	this->adminCounty = zeile->at(ADMIN_County);
}

Linearlokation::~Linearlokation() {
	// TODO Auto-generated destructor stub
}

const string& Linearlokation::getAdminCounty() const {
	return adminCounty;
}

 Gebietslokation* Linearlokation::getAreaReference()  {
	return areaReference;
}

bool Linearlokation::isInNegative() const {
	return inNegative;
}

bool Linearlokation::isInPositive() const {
	return inPositive;
}

 Linearlokation* Linearlokation::getInterruptsRoad()  {
	return interruptsRoad;
}

 Linearlokation* Linearlokation::getIntersectioncode()  {
	return intersectioncode;
}

 Linearlokation* Linearlokation::getNegativeOffset()  {
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

 Linearlokation* Linearlokation::getPositiveOffset()  {
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
