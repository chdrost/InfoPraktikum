/*
 * SuchenKlasse.cpp
 *
 *  Created on: 07.05.2014
 *      Author: christoph
 */

#include "SuchenKlasse.h"

SuchenKlasse::SuchenKlasse(LokationsVerwaltung const *lokV) {
	this->lokalitaetsVerwaltung = lokV;

}

SuchenKlasse::~SuchenKlasse() {
	// TODO Auto-generated destructor stub
}

vector<Gebietslokation*> SuchenKlasse::suchId(int id) {
	static struct Equals {
		bool operator()(Gebietslokation* lok, int id) {
			if (lok->getId() == id) {
				return (true);
			} else {
				return (false);
			}
		}
	} vergleich; //inner ist die einzige Instanz
	vector<Gebietslokation*> vec = suche(vergleich, id);
	return (vec);
}

vector<Gebietslokation*> SuchenKlasse::suchTypBuchstabe(char buchstabe) {
}

vector<Gebietslokation*> SuchenKlasse::suchTypZahl(int zahl) {
}

vector<Gebietslokation*> SuchenKlasse::suchFeinTyp(int feinTyp) {
}

vector<Gebietslokation*> SuchenKlasse::suchFirstName(string firstName) {
}

vector<Gebietslokation*> SuchenKlasse::suchAdminBundesland(
		string adminBundesLand) {
}

vector<Gebietslokation*> SuchenKlasse::suchAktualitaet(
		Aktualitaet& aktualitaet) {
}

vector<Gebietslokation*> SuchenKlasse::suchRoadNumber(string roadNumber) {
}

vector<Gebietslokation*> SuchenKlasse::suchRoadName(string roadName) {
}

vector<Gebietslokation*> SuchenKlasse::suchSecondName(string secondName) {
}

vector<Gebietslokation*> SuchenKlasse::suchAreaReference(
		Gebietslokation& areaReference) {
}

vector<Gebietslokation*> SuchenKlasse::suchAreaReference(int id) {
}

vector<Gebietslokation*> SuchenKlasse::suchPositiveOffset(
		Linearlokation& positiveOffset) {
}

vector<Gebietslokation*> SuchenKlasse::suchPositiveOffset(int id) {
}

vector<Gebietslokation*> SuchenKlasse::suchNegativeOffset(
		Linearlokation& negativeOffset) {
}

vector<Gebietslokation*> SuchenKlasse::suchUrban(bool urban) {
}

vector<Gebietslokation*> SuchenKlasse::suchIntersectionCode(
		Linearlokation& intersectionCode) {
}

vector<Gebietslokation*> SuchenKlasse::suchIntersectionCode(int id) {
}

vector<Gebietslokation*> SuchenKlasse::suchInterruptsRoad(
		Linearlokation& interruptsroad) {
}

vector<Gebietslokation*> SuchenKlasse::suchInterruptsRoad(int id) {
}

vector<Gebietslokation*> SuchenKlasse::suchTern(bool tern) {
}

vector<Gebietslokation*> SuchenKlasse::suchPolDir(string polDir) {
}

vector<Gebietslokation*> SuchenKlasse::suchAdminCounty(string adminCounty) {
}

vector<Gebietslokation*> SuchenKlasse::suchNetzKnotenVor(
		unsigned int netzKnotenVor) {
}

vector<Gebietslokation*> SuchenKlasse::suchNetzknotenNach(
		unsigned int netzKnotenNach) {
}

vector<Gebietslokation*> SuchenKlasse::suchStation(int station) {
}

vector<Gebietslokation*> SuchenKlasse::suchGeokoordinate(
		GeoKoordinate& geoKoordinate) {
}
