/*
 * Gebietslokation.cpp
 *
 *  Created on: 26.04.2014
 *      Author: christoph
 */

#include "Gebietslokation.h"

Gebietslokation::Gebietslokation(vector<string> *zeile) {
	this->id = stoi(zeile->at(LOCATIONCODE));
	this->typBuchstabe = zeile->at(TYPE).at(1);
	this->typZahl = (int) (zeile->at(TYPE).at(2));
	this->feinTyp = stoi(zeile->at(SUBTYPE));
	string str = zeile->at(FIRST_NAME);
	//Der Name ist mit "" angegeben. Diese muessen raus.
	//TODO mal sehen, ob das schneller geht
	str.erase(str.begin());
	str.erase(str.end()-1);
	this->firstName = str;
	this->adminBundesLand = zeile->at(ADMIN_County);
	this->aktualitaet = new Aktualitaet(zeile->at(ACTUALITY));
}

Gebietslokation::~Gebietslokation() {
	delete aktualitaet;
}

const string& Gebietslokation::getFirstName() const {
	return (firstName);
}

int Gebietslokation::getType() {
	return(GEBIET);
}

Gebietslokation::Gebietslokation() {
}

int Gebietslokation::getId() const {
	return (id);
}

void Gebietslokation::addLinLokation(Linearlokation* lokation) {
	this->linLocations.push_back(lokation);
}

string Gebietslokation::toString() {
	stringstream s;
	s<<"\nGebietslokation\nName:"<<this->firstName;

	//s <<"Id = " << this->id <<"\nTyp= "<<typBuchstabe<<typZahl<< "\nName= " << this->firstName<<"\n\n";
	return (s.str());
}
