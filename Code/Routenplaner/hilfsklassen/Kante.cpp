/*
 * Kante.cpp
 *
 *  Created on: 12.05.2014
 *      Author: christoph
 */

#include "Kante.h"

Kante::Kante(Punktlokation *start, Punktlokation *ende) {
	this->start = start;
	this->ziel = ende;
	this->laenge = this->start->getGeoKoordinate()->entfernungBerechnen(
			this->ziel->getGeoKoordinate());

}

Kante::~Kante() {
	/* Hier nichts destruieren, da die Pointer von der Klasse
	 Lokationsverwaltung destruiert werden.
	 */
}
