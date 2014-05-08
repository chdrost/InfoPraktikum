/*
 * SuchenKlasse.h
 *
 *  Created on: 07.05.2014
 *      Author: christoph
 */

#ifndef SUCHENKLASSE_H_
#define SUCHENKLASSE_H_

#include "../geopunkte/LokationsVerwaltung.h"

/**
 * Diese Klasse ist ein Container f&uuml;r alle m&ouml;glichen
 * Suchen, die man auf die Lokationsobjekte ansetzen kann.<br>
 */
class SuchenKlasse {
public:
	SuchenKlasse(LokationsVerwaltung const *lokV);
	virtual ~SuchenKlasse();

	/**
	 * Diese Methode sucht Lokationen anhand ihrer Id.
	 * @param id Die Id, die gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchId(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihrers Typs.
	 * @param id Der char Typ, nach dem gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchTypBuchstabe(char buchstabe);

	/**
	 * Diese Methode sucht Lokationen anhand ihrers Zahlentyps.
	 * @param id Der Zahlentyp, der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchTypZahl(int zahl);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Feintyps.
	 * @param feinTyp Der Feintyp, anhand dem gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchFeinTyp(int feinTyp);

	/**
	 * Diese Methode sucht Lokationen anhand ihres First Names.
	 * @param firstName Der First Name, anhand dem gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchFirstName(string firstName);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Admin Bundeslands.
	 * @param adminBundesland Das administrative Bundesland, anhand dessen
	 *  gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchAdminBundesland(string adminBundesLand);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer Aktualit&auml;t.
	 * @param aktualitart Die Aktualit&auml;t, anhand der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchAktualitaet(Aktualitaet *aktualitaet);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer Road Number.
	 * @param roadNumber Die Road Number, anhand der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchRoadNumber(string roadNumber);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Road Names.
	 * @param roadName Der Road Name, anhand dem gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchRoadName(string roadName);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Second Names.
	 * @param feinTyp Der Feintyp, anhand dem gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchSecondName(string secondName);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer Area Reference.
	 * @param areaReference Die Area Reference, anhand der gesucht werden soll,
	 * bzw. ein Pointer darauf.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchAreaReference(Gebietslokation *areaReference);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer Area Reference.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchAreaReference(Gebietslokation &areaReference)@endlink vorzuziehen.
	 * @param areaReference Die Area Reference, anhand der gesucht werden soll,
	 * bzw. ihre Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchAreaReference(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Positive Offset.
	 * @param positiveOffset Der Positive Offset, anhand der gesucht werden soll,
	 * bzw. ein Pointer darauf.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchPositiveOffset(Linearlokation *positiveOffset);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Positive Offset.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchPositiveOffset(Gebietslokation &positiveOffset)@endlink vorzuziehen.
	 * @param positiveOffset Der Positive Offset, anhand der gesucht werden soll,
	 * bzw. seine Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchPositiveOffset(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Negative Offset.
	 * @param negativeOffset Der Negative Offset, anhand der gesucht werden soll,
	 * bzw. ein Pointer darauf.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchNegativeOffset(Linearlokation *negativeOffset);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Negative Offset.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchNegativeOffset(Gebietslokation &negativeOffset)@endlink vorzuziehen.
	 * @param id Der Positive Offset, anhand der gesucht werden soll,
	 * bzw. seine Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchNegativeOffset(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Negative Offset.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchNegative(Gebietslokation &negativeOffset)@endlink vorzuziehen.
	 * @param id Der Positive Offset, anhand der gesucht werden soll,
	 * bzw. seine Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchUrban(bool urban);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Intersection Codes.
	 * @param intersectionCode Der Intersection Code, anhand dem gesucht werden soll,
	 * bzw. ein Pointer darauf.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchIntersectionCode(
			Linearlokation *intersectionCode);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Intersection Codes.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchIntersectionCode(Gebietslokation &intersectionCode)@endlink
	 * vorzuziehen.
	 * @param id Der Positive Offset, anhand der gesucht werden soll,
	 * bzw. seine Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchIntersectionCode(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Intersection Codes.
	 * @param intersectionCode Der Intersection Code, anhand dem gesucht werden soll,
	 * bzw. ein Pointer darauf.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchInterruptsRoad(Linearlokation *interruptsroad);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Interrupts Road.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchInterruptsRoad(Linearlokation &interruptsroad@endlink
	 * vorzuziehen.
	 * @param id Die Id des Interrupts Road, anhand der gesucht werden soll,
	 * bzw. seine Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchInterruptsRoad(int id);

	//TODO evtl. Suchfkt. fuer Flags schreiben

	/**
	 * Diese Methode sucht Lokationen anhand ihrers TERN Flags.
	 * @param tern Das Flag, das gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchTern(bool tern);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer zust&auml;ndigen Polizei
	 * Dienststelle.
	 * @param polDir Die Dienststelle, ddie gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchPolDir(string polDir);

	/**
	 * Diese Methode sucht Lokationen anhand ihreres zust&auml;ndigen Bundeslands.
	 * @param adminCounty Das Bundesland, das gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchAdminCounty(string adminCounty);

	/**
	 * Diese Methode sucht Lokationen anhand ihreres Netzknoten Vor.
	 * @param netzKnotenVor Der Netzknoten vor, der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchNetzKnotenVor(unsigned int netzKnotenVor);

	/**
	 * Diese Methode sucht Lokationen anhand ihreres Netzknoten Nach.
	 * @param netzKnotenNach Der Netzknoten nach, der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchNetzknotenNach(unsigned int netzKnotenNach);

	/**
	 * Diese Methode sucht Lokationen anhand ihrerer Station.
	 * @param station Der Netzknoten vor, die gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchStation(int station);

	/**
	 * Diese Methode sucht Lokationen anhand ihrerer Geokoordinate.
	 * @param geoKoordinate Die Geokoordinate, nach der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchGeokoordinate(GeoKoordinate *geoKoordinate);

	/**
	 * Diese Methode &uuml;bernimmt die eigentliche Suche.<br>
	 * Die f&uuml;r den Vergleich zust&auml;ndige Methode ist der () Operator.<br>
	 * Jede Suchmethode muss diesen in einem Struct implementiert haben.
	 * @note Optimierungen der Suche k&ouml;nnen hier vorgenommen werden.
	 * @param Funktion Die Methode, die als Vergleichsmethode genutzt werden soll.<br>
	 * Sie muss ich jeder such* Methode implementiert sein.
	 * @param suchWert Der Wert, nach dem gesucht werden soll.
	 * @return Ein Vector mit den gesuchten Datens&auml;tzen.
	 */
	template<class Funktion, typename suchWert>
	inline vector<Gebietslokation*> suche(Funktion f, suchWert wert);

private:
	/**
	 * Ein Pointer auf ein Lokalit&auml;tsverwaltungsobjekt.<b>
	 * Dort sind die Datens&auml;tze enthalten, die durchsucht werden
	 * sollen.
	 */
	const LokationsVerwaltung *lokalitaetsVerwaltung;
};

template<class Funktion, typename suchWert>
inline vector<Gebietslokation*> SuchenKlasse::suche(Funktion f, suchWert wert) {
	auto first = lokalitaetsVerwaltung->getGebieteMap().begin();
	auto last = lokalitaetsVerwaltung->getGebieteMap().end();
	vector<Gebietslokation*> vec;
	while (first != last) {
		if (f(first->second, wert)) {
			vec.push_back((Gebietslokation*) &*first);
		}
		++first;
	}
	return (vec);
}

#endif /* SUCHENKLASSE_H_ */
