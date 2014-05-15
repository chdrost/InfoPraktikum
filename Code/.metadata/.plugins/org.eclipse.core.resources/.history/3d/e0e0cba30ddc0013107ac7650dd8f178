/*
 * Graph.cpp
 *
 *  Created on: 13.05.2014
 *      Author: deniz
 */

#include "Graph.h"

Graph::Graph(map<int, Gebietslokation*> rohDaten) {
	map<int, Knoten*> konstruktionsMap;
	erstelleKnoten(konstruktionsMap, rohDaten);
	verlinkeKnoten(konstruktionsMap);
	konstruktionsMap.clear();
}

Graph::~Graph() {
	for (auto it = knotenListe.begin(); it != knotenListe.end(); it++) {
		delete &*it;
	}
	knotenListe.clear();
}

void Graph::erstelleKnoten(const map<int, Knoten*>& konstruktionsMap,
		const map<int, Gebietslokation*>& rohdaten) {
}

void Graph::verlinkeKnoten(const map<int, Knoten*>& konstruktionsMap) {
}
