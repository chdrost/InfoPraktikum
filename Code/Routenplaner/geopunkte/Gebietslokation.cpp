/*
 * Gebietslokation.cpp
 *
 *  Created on: 26.04.2014
 *      Author: christoph
 */

#include "Gebietslokation.h"

Gebietslokation::Gebietslokation() {
	// TODO Auto-generated constructor stub
}

Gebietslokation::Gebietslokation(vector<string> *zeile) {
	this->id = stoi(zeile->at(LOCATIONCODE));
	this->typBuchstabe = zeile->at(TYPE).at(1);
	this->typZahl = (int)(zeile->at(TYPE).at(2));
	this->feinTyp = stoi(zeile->at(SUBTYPE));
	this->firstName = zeile->at(FIRST_NAME);
	this->adminBundesLand = zeile->at(ADMIN_County);
	this->aktualitaet = new Aktualitaet(zeile->at(ACTUALITY));
}

Gebietslokation::~Gebietslokation() {
	delete aktualitaet;
}

const string& Gebietslokation::getFirstName() const {
	return firstName;
}

int Gebietslokation::getId() const {
	return id;
}
