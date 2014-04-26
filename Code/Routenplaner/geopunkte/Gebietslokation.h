/*
 * Gebietslokation.h
 *
 *  Created on: 26.04.2014
 *      Author: christoph
 */

/*
 * Die folgenden Defines entsprechen der Doku des Bundesamtes. Sie erleichtern den Zugriff
 * auf die Daten innerhalb des eingelesenen und zerlegten Datensatzes.
 */
#define LOCATIONCODE 0
#define TYPE 1
#define SUBTYPE 2
#define ROADNUMBER 3
#define ROADNAME 4
#define FIRST_NAME 5
#define SECOND_NAME 6
#define AREA_REFERENCE 7
#define LINEAR_REFERENCE 8
#define NEGATIVE_OFFSET 9
#define POSITIVE_OFFSET 10
#define URBAN 11
#define INTERSECTIONSCODE 12
#define INTERRUPTS_ROAD 13
#define IN_POSITIVE 14
#define OUT_POSITIVE 15
#define IN_NEGATIVE 16
#define OUT_NEGATIVE 17
#define PRESENT_POSITIVE 18
#define PRESENT_NEGATIVE 19
#define EXIT_NUMBER 20
#define DIVERSION_POSITIVE 21
#define DIVERSION_NEGATIVE 22
#define VERAENDERT 23
#define TERN 24
#define NETZKNOTEN1_NR 25
#define NETZKNOTEN2_NR 26
#define STATION 27
#define X_KOORDINATE 28
#define Y_KOORDINATE 29
#define POLDIR 30
#define ADMIN_County 31
#define ACTUALITY 32
#define ACTIVATED 33
#define TESTED 34
#define SPECIAL1 35
#define SPECIAL2 36
#define SPECIAL3 37
#define SPECIAL4 38
#define SPECIAL5 39
#define SPECIAL6 40
#define SPECIAL7 41
#define SPECIAL8 42
#define SPECIAL9 43
#define SPECIAL10 44

#ifndef GEBIETSLOKATION_H_
#define GEBIETSLOKATION_H_

#include <string>
#include <vector>

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
	Gebietslokation(vector<string>);
	virtual ~Gebietslokation();

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
