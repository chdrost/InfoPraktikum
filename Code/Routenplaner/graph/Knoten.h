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
#include "Child.h"
using namespace std;
class Knoten {
public:
	Knoten();
	virtual ~Knoten();
	void suchenachfolger();
private:
	void berechnelaenge();
	Punktlokation* eigenschaften; //getid ist die knotennummer
	list<Punktlokation*> nachfolgern;
	Punktlokation* interSectionCode;
};
#endif /* KNOTEN_H_ */