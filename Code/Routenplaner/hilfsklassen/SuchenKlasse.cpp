/*
 * SuchenKlasse.cpp
 *
 *  Created on: 07.05.2014
 *      Author: christoph
 */

#include "SuchenKlasse.h"

SuchenKlasse::SuchenKlasse(LokationsVerwaltung const *lokV) {
	// TODO Auto-generated constructor stub

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
	return (suche(vergleich, id));
}
