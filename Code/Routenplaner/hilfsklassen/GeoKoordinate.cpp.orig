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
<<<<<<< HEAD
		unsigned long int lenght = zeichen.length();
		string nachkommastellen = zeichen.substr(lenght - NACHKOMMA_STELLEN,
		NACHKOMMA_STELLEN);
		string vorkommastellen = zeichen.substr(
				lenght - (NACHKOMMA_STELLEN + VORKOMMA_STELLEN),
				VORKOMMA_STELLEN);
		*angabe = stoi(vorkommastellen)
				+ (((stoi(nachkommastellen)) / (pow(10, NACHKOMMA_STELLEN))));
=======
	unsigned long int lenght = zeichen.length();
	string nachkommastellen = zeichen.substr(lenght-6, lenght-1);
	string vorkommastellen = zeichen.substr(lenght-8, lenght-6);
	*angabe=stoi(nachkommastellen)+(stoi(vorkommastellen)/100);
>>>>>>> dkadio

		//angabe->grad = stoi(zeichen.substr(BEGIN_GRAD, LAENGE_ANGABE));
		//angabe->minuten = stoi(zeichen.substr(BEGIN_MINUTE, LAENGE_ANGABE));
		//angabe->sekunden = stoi(zeichen.substr(BEGIN_SEKUNDE, LAENGE_ANGABE));
	} catch (const invalid_argument &e) {
		std::cerr << "\n" << e.what() << "\n";
	}
}

<<<<<<< HEAD
float GeoKoordinate::entfernungBerechnen(GeoKoordinate* ziel) {
=======
float GeoKoordinate::entfernungBerechnen(GeoKoordinate ziel) {
>>>>>>> dkadio
	float distance, dx, dy, lat;
	//lat = (ziel.breitenGrad + this->breitenGrad) / (2 * 0,01745);
	//dx = 111,3 * cos(lat) * (this->laengenGrad - ziel.laengenGrad);

<<<<<<< HEAD
	lat = (this->breitenGrad + ziel->breitenGrad) / 2 * 0.01745;
	dx = 111.3 * cos(lat) * (this->laengenGrad - ziel->laengenGrad);
	dy = 111.3 * (this->breitenGrad - ziel->getBreitenGrad());

	return (distance = sqrt(dx * dx + dy * dy));
=======
	lat = (this->breitenGrad + ziel.breitenGrad) / 2 * 0.01745;
	dx = 111.3 * cos(lat) * (this->laengenGrad - ziel.laengenGrad);
	dy = 111.3 * (this->breitenGrad - ziel.breitenGrad);

	return distance = sqrt(dx * dx + dy * dy);
>>>>>>> dkadio
}

string GeoKoordinate::toString() {
	stringstream s;

<<<<<<< HEAD
	s << "Breite: " << this->breitenGrad << "\nLaenge: " << this->laengenGrad << "\nCopy: " << this->breitenGrad << " " << this->laengenGrad;
	return (s.str());
}

float GeoKoordinate::getBreitenGrad() const {
	return (breitenGrad);
}

float GeoKoordinate::getLaengenGrad() const {
	return (laengenGrad);
}
=======
	s << "Breite: " << this->breitenGrad << "\nLaenge: " << this->laengenGrad;
	return (s.str());
}
>>>>>>> dkadio
