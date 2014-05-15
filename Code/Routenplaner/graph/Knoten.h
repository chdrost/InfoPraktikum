/*
 * Knoten.h
 *
 *  Created on: 13.05.2014
 *      Author: deniz
 */

#ifndef KNOTEN_H_
#define KNOTEN_H_
#include <list>
#include "../geopunkte/Punktlokation.h"

/**
 * Diese Klasse repr&auml;sentiert einen Knotenpunkt im Graph.<br>
 * Sie hat Informationen &uuml;ber ihre Nachbarn und den Abstand zu ihrem
 * aufrufenden Nachbarn.<br>
 */
using namespace std;
class Knoten {
public:
	Knoten(Punktlokation* punktLokation);
	virtual ~Knoten();
	void addNachfolger(Knoten *nachfolger);
	float berechneLaenge(Knoten * derAnnere);
	int getId();

	string toString();
	Punktlokation* getEigenschaften() {
		return (eigenschaften);
	}

private:
	Punktlokation* eigenschaften; //getid ist die knotennummer
	list<Knoten*> nachfolger;
};
#endif /* KNOTEN_H_ */
