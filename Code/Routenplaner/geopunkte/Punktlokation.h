/*
 * Punktlokation.h
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#ifndef PUNKTLOKATION_H_
#define PUNKTLOKATION_H_

#include"Linearlokation.h"

class Punktlokation: public Linearlokation {
public:
	Punktlokation(vector<string> *zeile, Gebietslokation *areaReference);
	virtual ~Punktlokation();

private:
	/**
	 * Pointer auf die &uuml;bergeordnete Linearlokation.
	 */
	Linearlokation *linearReference;

	//exitNumber; TODO rausfinden, was man damit macht und was f&uuml;r ein Datentyp das ist

	//diversionPositive TODO rausfinden, was man damit macht und was f&uuml;r ein Datentyp das ist

	//diversionNegative TODO rausfinden, was man damit macht und was f&uuml;r ein Datentyp das ist

	/**
	 * Netzknotennummer der Lokation oder Netzknotennummer des vor der Lokation
	 * liegenden Netzknoten.
	 */
	int netzKontenNummerVor;

	/**
	 * Netzknotennummer des nach der Lokation liegenden Netzknoten.
	 */
	int netzKontenNummerNach;

	/**
	 * Entfernung der Lokation vor dem Netzknoten 1 in Richtung Netzknoten 2.<br>
	 * Die Angabe ist in Metern.
	 */
	int station;

	/**
	 * Der L&auml;ngengrad der Lokation.<br>
	 * Auch Ostkoordinate.<br>
	 * In der Dokumentation als X Koordinate bezeichnet.
	 */
	int laengenGrad;

	/**
	 * Der Breitengrad der Lokation.<br>
	 * Auch Nordkoordinate. <br>
	 * In der Dokumentation als Y-Koordinate bezeichnet.
	 */
	int breitenGrad;
};

#endif /* PUNKTLOKATION_H_ */
