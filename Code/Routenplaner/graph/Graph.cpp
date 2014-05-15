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
	verlinkeKnoten(konstruktionsMap, rohDaten);
	//TODO Pruefen, ob hier Destruktoren aufgerufen werden
	konstruktionsMap.clear();
}

Graph::~Graph() {
	for (auto it = knotenListe.begin(); it != knotenListe.end(); it++) {
		delete &*it;
	}
	knotenListe.clear();
}

void Graph::erstelleKnoten(map<int, Knoten*>& konstruktionsMap,
		const map<int, Gebietslokation*>& rohdaten) {
	//Alle Elemente durchlaufen
	for (auto it = rohdaten.begin(); it != rohdaten.end(); it++) {
		//Pruefen, ob Element eine Punklokation ist
		if (it->second->getType() == PUNKT) {
			//Pruefen, ob der Intersection Code des Elements schon enthalten ist
			if (konstruktionsMap.find(
					((Punktlokation*) it->second)->getIntersectioncode()->getId())
					== konstruktionsMap.end()) {
				Knoten *k = new Knoten((Punktlokation*) it->second);
				//In Arbeitsliste
				this->knotenListe.push_back(k);
				//In Map
				konstruktionsMap[k->getId()] = k;
			}
		}
	}
}

void Graph::verlinkeKnoten(map<int, Knoten*> konstruktionsMap,
		const map<int, Gebietslokation*> &rohdaten) {
	for (auto it = rohdaten.begin(); it != rohdaten.end(); it++) {
		//Pruefen, ob Element eine Punklokation ist
		if (it->second->getType() == PUNKT) {
			Punktlokation *pLok = (Punktlokation*) it->second;
			Knoten *knoten = konstruktionsMap[it->second->getId()];
			//POffset als Nachfolger eintragen
			if (pLok->getPositiveOffset() != NULL) {
				knoten->addNachfolger(konstruktionsMap[pLok->getId()]);
			}
			//NOffset als Nachfolger eintragen
			if (pLok->getNegativeOffset() != NULL) {
				knoten->addNachfolger(konstruktionsMap[pLok->getId()]);
			}
			//Die Offsets des Intersection Codes eintragen
			if (knoten->getEigenschaften()->getIntersectioncode() != NULL) {
				if (knoten->getEigenschaften()->getIntersectioncode()->getPositiveOffset() != NULL) {
					knoten->addNachfolger(
							konstruktionsMap[(knoten->getEigenschaften()->getIntersectioncode()->getPositiveOffset()->getId())]);
				}
				if (knoten->getEigenschaften()->getIntersectioncode()->getNegativeOffset() != NULL) {
					knoten->addNachfolger(
							konstruktionsMap[(knoten->getEigenschaften()->getIntersectioncode()->getNegativeOffset()->getId())]);
				}
			}

		}
	}
}
