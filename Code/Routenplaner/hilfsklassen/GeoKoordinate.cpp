/*
 * GeoKoordinate.cpp
 *
 *  Created on: 28.04.2014
 *      Author: christoph
 */

#include "GeoKoordinate.h"

GeoKoordinate::GeoKoordinate(string xKoordinate, string yKoordinate) {
	this->laengenGrad = 0;
	gradEinlesen(xKoordinate, &this->laengenGrad);

	this->breitenGrad = 0;
	gradEinlesen(yKoordinate, &this->breitenGrad);
}

GeoKoordinate::~GeoKoordinate() {

}

void GeoKoordinate::gradEinlesen(string zeichen, float* angabe) {
	try {
	unsigned long int lenght = zeichen.length();
	string nachkommastellen = zeichen.substr(lenght-6, lenght-1);
	string vorkommastellen = zeichen.substr(lenght-8, lenght-6);
	*angabe=stoi(nachkommastellen)+(stoi(vorkommastellen)/100);

		//angabe->grad = stoi(zeichen.substr(BEGIN_GRAD, LAENGE_ANGABE));
		//angabe->minuten = stoi(zeichen.substr(BEGIN_MINUTE, LAENGE_ANGABE));
		//angabe->sekunden = stoi(zeichen.substr(BEGIN_SEKUNDE, LAENGE_ANGABE));
	} catch (const invalid_argument &e) {
		std::cerr << "\n" << e.what() << "\n";
	}
}

float GeoKoordinate::entfernungBerechnen(GeoKoordinate ziel) {
	float distance, dx, dy, lat;
	//lat = (ziel.breitenGrad + this->breitenGrad) / (2 * 0,01745);
	//dx = 111,3 * cos(lat) * (this->laengenGrad - ziel.laengenGrad);

	lat = (this->breitenGrad + ziel.breitenGrad) / 2 * 0.01745;
	dx = 111.3 * cos(lat) * (this->laengenGrad - ziel.laengenGrad);
	dy = 111.3 * (this->breitenGrad - ziel.breitenGrad);

	return distance = sqrt(dx * dx + dy * dy);
}

string GeoKoordinate::toString() {
	stringstream s;

	s << "Breite: " << this->breitenGrad << "\nLaenge: " << this->laengenGrad;
	return (s.str());
}
