/*
 * Linearlokation.h
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#ifndef LINEARLOKATION_H_
#define LINEARLOKATION_H_

#include"./Gebietslokation.h"
/**
 * Diese Klasse stellt eine Linearlocation dar.<br> In ihr sind alle Atribute enthalten,
 * die eine Linearlocation enth&auml;lt.
 */
//class Gebietslokation;
class Linearlokation : public Gebietslokation{
public:
	Linearlokation(vector<string> *zeile, Gebietslokation *areaReference, map<int, Gebietslokation*> *gebieteMap);
	virtual ~Linearlokation();

	const string& getAdminCounty() const;
	 Gebietslokation* getAreaReference() ;
	bool isInNegative() const;
	bool isInPositive() const;
	 Linearlokation* getInterruptsRoad() ;
	 Linearlokation* getIntersectioncode() ;
	 Linearlokation* getNegativeOffset() ;
	bool isOutNegative() const;
	bool isOutPositive() const;
	const string& getPoldir() const;
	 Linearlokation* getPositiveOffset() ;
	bool isPresentNegative() const;
	bool isPresentPositive() const;
	const string& getRoadName() const;
	const string& getRoadNumer() const;
	const string& getSecondName() const;
	bool isTern() const;
	bool isUrban() const;
	int getVeraendert() const;

private:
	/**
	 * Die Stra&szlig;ennummer. Sie besteht aus dem Bezeichner der Stra&szlig;e
	 * und der Nummer der Stra&szlig;e. <br>
	 * Bsp.: A620
	 */
	string roadNumer;

	/**
	 * Der Stra&szlig;enname.<br>
	 * Beispiel: B405 (Stra&szlig;ennummer), Metzer Stra&szlig;e (Stra&szlig;enname).
	 */
	string roadName;

	/**
	 * Ein zus&auml;tzlicher Name der Lokation.<br>
	 * Lt. Doku des Bundesamtes "Zweiter Name".
	 */
	string secondName;

	/**
	 * Area Verweis auf das Gebiet, in dem die Lokation liegt.<br>
	 * Dieses Attribut enth&auml;lt einen Pointer auf ein @link Gebietslokation @endlink
	 * Objekt.
	 */
	Gebietslokation *areaReference;

	/**
	 * Verweis auf die Vorg&auml;ngerlokation bezogen auf die Erfassungsrichtung.
	 * <br>Dieses Attribut enth&auml;lt einen Pointer auf die vorherige
	 * Lokation.
	 */
	Linearlokation *negativeOffset;

	/**
	 * Verweis auf die Nachfolgerlokation bezogen auf die Erfassungsrichtung.
	 * <br>Dieses Attribut enth&auml;lt einen Pointer auf die folgende
	 * Lokation.
	 */
	Linearlokation *positiveOffset;

	/**
	 * Flag, ob Verkehr st&auml;dtischen Characters vorliegt.<br>
	 * (1=ja, 0=nein)
	 */
	bool urban;

	/**
	 * Verweis auf die Loction, einer anderen Stra&szlig;e an gleicher Stelle.
	 * (zirkul&auml;re Verkettung)<br>
	 * Dieses Attribut enth&auml;lt einen Pointer auf die mit der Id verkn&uuml;pften
	 * Linearlokation.
	 */
	Linearlokation *intersectioncode;

	/**
	 * Verweis auf die n&auml;chste Lokation nach der Unterbrechung im
	 * Stra&szlig;enverlauf.<br>
	 * Dieses Attribut enth&auml;lt einen Pointer auf die mit der Id verkn&uuml;pften
	 * Linearlokation.
	 */
	Linearlokation *interruptsRoad;

	/**
	 *Flag, ob Lokation in Erfassungsrichtung zug&auml;nglich ist.<br>
	 *(1=ja, 0=nein)
	 */
	bool inPositive;

	/**
	 * Flag, ob Lokation in Erfassungsrichtung verlassen werden kann.<br>
	 * (1=ja, 0=nein)
	 */
	bool outPositive;

	/**
	 *Flag, ob Lokation entgegen Erfassungsrichtung zug&auml;nglich ist.<br>
	 *(1=ja, 0=nein)
	 */
	bool inNegative;

	/**
	 * Flag, ob Lokation entgegen Erfassungsrichtung verlassen werden kann.<br>
	 * (1=ja, 0=nein)
	 */
	bool outNegative;

	/**
	 * Flag, ob Lokation in Erfassungsrichtung vorhanden ist.<br>
	 * (1=ja, 0=nein)
	 */
	bool presentPositive;

	/**
	 * Flag, ob Lokation entgegen Erfassungsrichtung vorhanden ist.<br>
	 * (1=ja, 0=nein)
	 */
	bool presentNegative;

	/**
	 * Flag, ob Datensatz bei Aktualisierungsverlauf gegen&uuml;ber der Vorg&auml;ngerversion
	 * ver&auml;ndert wurde.<br>
	 * (Nur vor Release erkennbar 0=nein, 1=ja, 2=neu, 3=l&ouml;schen)
	 */
	int veraendert;

	/**
	 * Angabe, ob Lokation zum TERN-Netz geh&ouml;rt.<br>
	 * (1=ja, 0=nein)
	 */
	bool tern;

	/**
	 * Hinweis auf die zust&auml;ndige Polizeidienststelle.
	 */
	string poldir;

	/**
	 * Hinweis auf f&uuml;r die Bearbeitung zust&auml;ndiges Bundesand.
	 */
	string adminCounty;

};

#endif /* LINEARLOKATION_H_ */
