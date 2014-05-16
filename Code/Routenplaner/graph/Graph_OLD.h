/*
 * Graph.h
 *
 *  Created on: 13.05.2014
 *      Author: deniz
 */

/**
 * Diese Klasse stellt einen Graph dar. Die enth&auml;lt neben
 * einer geeigneten Datenstruktur auch Methoden um den Graph aufzubauen.
 */
#ifndef GRAPH_OLD_H_
#define GRAPH_OLD_H_

#include <map>
#include "Knoten.h"
//TODO stdlib wieder entfernen (War Nur zum Testen)
#include <stdlib.h>

using namespace std;

class Graph_OLD {
public:
	Graph_OLD(map<int, Gebietslokation*> rohDaten);
	virtual ~Graph_OLD();

	/**
	 * Diese Methode erstellt die erste Spalte der Adjazenzmatrix (n=0).<br>
	 * Dabei werden neue Knoten erstellt und in die Liste eingepflegt.
	 * @param konstruktionsMap Die Konstruktionsmap, dort sind die neuen
	 * Knoten zusammen mit einer Id gespeichert.
	 * @param rohdaten Eine Map mit den Rohdaten, also allen Lokationen.
	 */
	void erstelleKnoten(map<int, Knoten*> &konstruktionsMap,
			const map<int, Gebietslokation*> &rohdaten);

	/**
	 * Diese Methode baut die eigentloch Adjazenzliste auf. Hierzu werden die
	 * Spalten n>0 gef&uuml;llt.
	 * @param konstruktionsMap Die Kkonstruktionsmap erlaubt einen schnellen Zugriff
	 * auf ein Knotenobjekt.
	 */
	void verlinkeKnoten(map<int, Knoten*> konstruktionsMap,
			const map<int, Gebietslokation*> &rohdaten);

	/**
	 * Dient nur zum Validieren des Einlesens.
	 * @return Ein String mit allen enthaltenen Knoten.
	 */
	string toString();
private:
	/**
	 * Diese Liste enth&auml;lt den eigentlichen Graphen.
	 */
	list<Knoten*> knotenListe;
};

//knoten.getitem().getnachfolger().getitem().getentfernung();

#endif /* GRAPH_H_ */
