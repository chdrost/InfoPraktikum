/*
 * Gebiet.h
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#ifndef GEBIET_H_
#define GEBIET_H_

#include <string>
using namespace std;


/**
 * Diese Klasse stellt ein Gebiet dar. Gebietslokationen sind laut der Dokumentation
 * des Bundesamtes mit einem "A" gekennzeichnet. Sie definieren grobe Gebiete,
 * wie beispielsweise Kontinente, L&auml;nder Ballungsr&auml;me oder Fl&uml;sse.
 */
class Gebiet {
public:
	Gebiet();
	virtual ~Gebiet();

private:
	/**
	 * Die Id einer Lokation erlaubt eine eindeutige Zuordnung dieser Lokation.
	 * In der Hierarchie folgende Lokationen verweisen auf diese Id.
	 */
	int id;
	/**
	 * Der Grob Typ einer Lokation gibt an, um weche Lokation es sich handelt.
	 * Er ist nur mit einem Buchstaben gekennzeichnet. Dieser Buchstabe ist im Fall
	 * der Gebietslokation immer A.
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
	 * verwendet.
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
	 * Dieses Attribut gibt an, welches Bundesland für die Bearbeitung zuständig ist.
	 * Dieses Attribut wird im aktuellen Release nicht genutzt, ist aber dennoch der
	 * Vollst&auml;ndigkeit halber enthalten.
	 */
	string adminBundesLand;


};

#endif /* GEBIET_H_ */
