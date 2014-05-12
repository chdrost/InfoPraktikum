/*
 * Kante.h
 *
 *  Created on: 12.05.2014
 *      Author: christoph
 */

#ifndef KANTE_H_
#define KANTE_H_

#include "../geopunkte/Punktlokation.h"

/**
 * Diese Klasse repr&auml;sentiert eine Kante in einem Graphen.<br>
 * Eine Kante ist klar durch zwei Punktlokationen definiert und
 * hat als Zusatzinformation eine L&auml;nge.
 */
class Kante {
public:
	/**
	 * Der Konstruktor weist den Attributen ihre Referenzen zu und
	 * berechnet die L&auml;nge der Kante.
	 * @param start Der erste Punkt der Kante.
	 * @param ende Der andere Punkt der Kante.
	 */
	Kante(Punktlokation *start, Punktlokation *ende);
	virtual ~Kante();
private:
	Punktlokation *start;
	Punktlokation *ziel;
	float laenge;

	//evtl. Kante *nachfolger1;
	//evtl. Kante *nachfolger2;
	//evtl. Kante *nachfolger3;
	//Die Wertung ob Vorgaenger, Nachfolger oder sonstiges macht der Dijkstra

};

#endif /* KANTE_H_ */
