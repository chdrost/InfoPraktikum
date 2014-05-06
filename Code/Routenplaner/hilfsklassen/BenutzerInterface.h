/*
 * BenutzerInterface.h
 *
 *  Created on: 06.05.2014
 *      Author: christoph
 */

#ifndef BENUTZERINTERFACE_H_
#define BENUTZERINTERFACE_H_
#define ENDE 0
#define NAMEN_SUCHEN 1
#define ID_SUCHEN 2
#define ALLE_LOKS 3

#define NAME_ANZEIGEN 1
#define UEBERGEORDNETE_LOKATION_ANZEIGEN 2
#define UEBERGEORDNETE_STRASSE_ANZEIGEN 3
#define POFFSET_ANZEIGEN 4
#define NOFFSET_ANZEIGEN 5
#define ID_ANZEIGEN 6
#define KOORDINATE_ANZEIGEN 7

#include "../geopunkte/LokationsVerwaltung.h"
#include  <iostream>

/**
 * Erste Klasse f&uuml;r ein Benutzerinterface.<br>
 * Sie erlaubt das genaue Betrachten von Lokationen und
 * bietet hierf&uuml;r eine Men&uuml;f&uuml;hrung an.
 */
class BenutzerInterface {
public:
	BenutzerInterface(LokationsVerwaltung* lokVerwaltung);
	virtual ~BenutzerInterface();
	/**
	 * Diese Methode gibt das Hauptmenue auf der Konsole aus.
	 */
	void zeigeHauptMenue();

	/**
	 * Diese Methode enth&auml;lt die Darstellung d&uuml;r die Suche nach einer
	 * Lokation und gibt diese auf der Konsole aus.
	 */
	void zeigeSuche();

	/**
	 * Diese Methode erlaubt die Suche nach einer Id.
	 */
	void zeigeIdSuche();

	/**
	 * Das Feinmenue wird von der Suchfunktion aufgerufen.<br>
	 * Dort k&ouml;nnen Methoden aufgerufen werden um sich Werte
	 * einer Lokation anzeigen zu lassen.
	 * @param lok Der Pointer auf die Lokation, die angezeigt werden soll.
	 */
	void zeigeFeinMenue(Gebietslokation * lok);

	/**
	 * Diese Methode gibt alle Lokationen aus.
	 */
	void zeigeAlle();

private:
	LokationsVerwaltung* lokVerwaltung;
};

#endif /* BENUTZERINTERFACE_H_ */