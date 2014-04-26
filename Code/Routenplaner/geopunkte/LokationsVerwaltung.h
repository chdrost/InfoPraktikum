/*
 * LokationsVerwaltung.h
 *
 *  Created on: 26.04.2014
 *      Author: christoph
 */

#ifndef LOKATIONSVERWALTUNG_H_
#define LOKATIONSVERWALTUNG_H_

#include <vector>
#include <map>
#include <string>
#include "Gebietslokation.h"
#include "AttributDefines.h"
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
	/**
	 * Diese Methode entscheidet anhand des Types der Zeile, welches Objekt erstellt werden
	 * soll, erstellt es und l&auml;dt es in die Datenstrukturen.
	 * @param Ein Vector aus Strings, der einer Zeile unseres Datensatzes entspricht.
	 */
	void objektErstellen(vector<string> zeile);

	/**
	 * Diese Methode verteilt den Pointer auf die verschiedenen Datenstrukturen.
	 * @param lokation Ein Pointer auf eine Gebietslokation.
	 */
	void speichereGebietsLokation(Gebietslokation *lokation);
private:
	/**
	 * Dieses Attribut ist die prim&auml;re Datenstruktur f&uuml;r die Datens&auml;tze.
	 *Dort sind die Gebietslokationen organisiert, die wiederum rekrusiv Datens&auml;tze
	 *Dort mit Linearen Lokationen und Punktlokationen enthalten.
	 */
	vector<Gebietslokation*> gebieteVector;

	/**
	 * Dieses Attribut erlaubt den schnellen Zugriff auf Objekte anhand ihrer Id.
	 * Der Schl&uuml;ssel ist der LOCATIONCODE einer Lokation, der Value ist der Pointer
	 * auf das Objekt selber.
	 */
	map<int, Gebietslokation*> gebieteMap;

	/**
	 * Dieses Attribut erlaubt das schnelle Suchen einer Lokation anhand eines Namens.<br>
	 * Da es nicht ausgeschlossen ist, dass ein Name mehrmals vorkommt, ist das Attribut als
	 * Multiset realisiert. Bei der Abfrage muss darauf geachtet werden, dass mehrere
	 * R&uuml;ckgabewerte auftreten k&ouml;nnen.
	 */
	multimap<string, Gebietslokation*> namenMap;
};

#endif /* LOKATIONSVERWALTUNG_H_ */
