/*
 * Graph.h
 *
 *  Created on: 13.05.2014
 *      Author: deniz
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>
#include "Knoten.h"
using namespace std;


class Graph {
public:
	Graph();
	virtual ~Graph();
private:
	list<Knoten> knoten;
};

	knoten.getitem().getnachfolger().getitem().getentfernung();

#endif /* GRAPH_H_ */
