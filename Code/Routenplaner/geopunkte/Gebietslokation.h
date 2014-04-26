/*
 * Gebietslokation.h
 *
 *  Created on: 26.04.2014
 *      Author: christoph
 */

#ifndef GEBIETSLOKATION_H_
#define GEBIETSLOKATION_H_

#include <string>
#include <vector>
#include "AttributDefines.h"

using namespace std;
/**
 * Diese Klasse stellt ein Gebiet dar. Gebietslokationen sind laut der Dokumentation
 * des Bundesamtes mit einem "A" gekennzeichnet. Sie definieren grobe Gebiete,
 * wie beispielsweise Kontinente, L&auml;nder Ballungsr&auml;me oder Fl&uml;sse.
 */
class Gebietslokation {
public:
	Gebietslokation();
	/**
	 * Dieser Konstruktor soll als Standardkonstruktor genutzt werden. <br>
	 * Aus dem Vector werden die entsprechenden Attribute der Zeile ausgelesen.
	 * @param Ein Vector, der einer Zeile aus dem Datensatz entspricht.
	 */
	Gebietslokation(vector<string> zeile);
	virtual ~Gebietslokation();

	string getFirstName() const {
		return firstName;
	}

	int getId() const {
		return id;
	}

private:
	/**
	 * Die Id einer Lokation erlaubt eine eindeutige Zuordnung dieser Lokation.
	 * In der Hierarchie folgende Lokationen verweisen auf diese Id.<br>
	 * Die ID entspricht dem "LOCATIONCODE" der Dokumentation.
	 */
	int id;

	/**
	 * Der Grob Typ einer Lokation gibt an, um weche Lokation es sich handelt.
	 * Er ist nur mit einem Buchstaben gekennzeichnet. Dieser Buchstabe ist im Fall
	 * der Gebietslokation immer A.
	 * Das Feld "TYPE" in der Dokumentation des Bundesamtes setzt sich aus @link typBuchstabe
	 * @endlink und @link typZahl @endlink zusammen.
	 */
	char typBuchstabe;

	/**
	 * Zur Beschriebung der Lokation geh&ouml;rt eine Zahl. Die Zahl beschreit, um welche
	 * Lokation es sich handelt.<br>
	 * M&ouml;glich sind:<br>
	 * <ol>
	 * 		<li>Kontinent</li>
	 * 		<li>L&auml;ndergruppe</li>
	 * 		<li>Land</li>
	 * 		<li><i>Nicht definiert</i></li>
	 * 		<li>Gew&auml;sser</li>
	 * 		<li>Allgemeines Gebiet</li>
	 * 		<li>Bundesland</li>
	 * 		<li>regierungsbezirk</li>
	 * 		<li>Gemeinde / Stadt</li>
	 * 		<li>Gemeindeteil</li>
	 * 		<li>Teilgebiet</li>
	 * </ol>
	 * F&uml;r die Benennung wurde jeweils die Beschreibung des ersten @link feinTyp @endLink
	 * verwendet.<br>
	 * Das Feld "TYPE" in der Dokumentation des Bundesamtes setzt sich aus @link typBuchstabe
	 * @endlink und @link typZahl @endlink zusammen.
	 */
	int typZahl;

	/**
	 * Der feinTyp beschreibt den Typ einer Lokation genauer. <br>
	 * Der Typ A5 beispielsweise steht f&uuml;r ein Gew&auml;sser. Wird das Gew&auml;sser
	 * durch den Feintyp 2 genauer spezifiziert, wird das allgemeine Ge&auml;sser zu einem
	 * Binnensee.
	 */
	int feinTyp;

	/**
	 * Der Name der Location.<br>
	 * Bsp.:Deutschland
	 */
	string firstName;

	/**
	 * Dieses Attribut gibt an, welches Bundesland für die Bearbeitung zuständig ist.
	 * Dieses Attribut wird im aktuellen Release nicht genutzt, ist aber dennoch der
	 * Vollst&auml;ndigkeit halber enthalten.
	 */
	string adminBundesLand;
};

#endif /* GEBIETSLOKATION_H_ */
