/*
 * LokationsVerwaltung.h
 *
 *  Created on: 26.04.2014
 *      Author: christoph
 */

#ifndef LOKATIONSVERWALTUNG_H_
#define LOKATIONSVERWALTUNG_H_

#include <vector>
#include <set>
#include <string>
#include "Gebietslokation.h"
using namespace std;

/**
 * Diese Klasse verwaltet die verschiedenen Lokationen.<br>
 * Da aus verschiedenen Gründen und Gesichtspunkten auf die Lokalitionen
 * zugegriffen werden muss, werden die Lokationen in mehreren Speicherstrukturen
 * vorgehalten.
 */
class LokationsVerwaltung {
public:
	LokationsVerwaltung();
	virtual ~LokationsVerwaltung();
private:
	/**
	 * Dieses Attribut ist die prim&auml;re Datenstruktur f&uuml;r die Datens&auml;tze.
	 *Dort sind die Gebietslokationen organisiert, die wiederum rekrusiv Datens&auml;tze
	 *Dort mit Linearen Lokationen und Punktlokationen enthalten.
	 */
	vector<Gebietslokation> gebieteVector;

	/**
	 * Dieses Attribut erlaubt den schnellen Zugriff auf Objekte anhand ihrer Id.
	 * Der Schl&uuml;ssel ist der LOCATIONCODE einer Lokation, der Value ist der Pointer
	 * auf das Objekt selber.
	 */
	set<int, Gebietslokation*> gebieteSet;

	/**
	 * Dieses Attribut erlaubt das schnelle Suchen einer Lokation anhand eines Namens.<br>
	 * Da es nicht ausgeschlossen ist, dass ein Name mehrmals vorkommt, ist das Attribut als
	 * Multiset realisiert. Bei der Abfrage muss darauf geachtet werden, dass mehrere
	 * R&uuml;ckgabewerte auftreten k&ouml;nnen.
	 */
	multiset<string, Gebietslokation*> mySet;
};

#endif /* LOKATIONSVERWALTUNG_H_ */
