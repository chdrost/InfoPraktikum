/*
 * GeoKoordinate.cpp
 *
 *  Created on: 28.04.2014
 *      Author: christoph
 */

#include "GeoKoordinate.h"

GeoKoordinate::GeoKoordinate(string xKoordinate, string yKoordinate) {
	this->laengenGrad = new gradAngabe();
	gradEinlesen(xKoordinate, this->laengenGrad);

	this->breitenGrad = new gradAngabe();
	gradEinlesen(yKoordinate, this->breitenGrad);
}

GeoKoordinate::~GeoKoordinate() {
	delete this->breitenGrad;
	delete this->laengenGrad;
}

void GeoKoordinate::gradEinlesen(string zeichen, gradAngabe* angabe) {
	try {
		angabe->grad = stoi(zeichen.substr(BEGIN_GRAD, LAENGE_ANGABE));
		angabe->minuten = stoi(zeichen.substr(BEGIN_MINUTE, LAENGE_ANGABE));
		angabe->sekunden = stoi(zeichen.substr(BEGIN_SEKUNDE, LAENGE_ANGABE));
	} catch (const invalid_argument &e) {
		std::cerr << "\n" << e.what() << "\n";
	}
}