/*
 * BenutzerInterface.cpp
 *
 *  Created on: 06.05.2014
 *      Author: christoph
 */

#include "BenutzerInterface.h"

BenutzerInterface::BenutzerInterface(LokationsVerwaltung* lokVerwaltung) {
	this->lokVerwaltung = lokVerwaltung;

}

BenutzerInterface::~BenutzerInterface() {
	delete lokVerwaltung;
}
//TODO Eingaben Typsicher machen
void BenutzerInterface::zeigeHauptMenue() {
	unsigned int auswahl = ENDE;
	do {
		cout << "\nWas wollen Sie tun?";
		cout << "\nEnde durch - " << ENDE;
		cout << "\n" << NAMEN_SUCHEN << " - oeffnet die Suche nach einem Namen";
		cout << "\n" << ID_SUCHEN << " - oeffnet die Suche nach einer Id";
		cout << "\n" << ALLE_LOKS << " - gibt alle Lokationen aus\nAuswahl: ";
		cin >> auswahl;
		switch (auswahl) {
		case NAMEN_SUCHEN:
			zeigeSuche();
			break;
		case ID_SUCHEN:
			zeigeIdSuche();
			break;
		case ALLE_LOKS:
			zeigeAlle();
			break;
		default:
			cout << "\nFalsche Auswahl!\n";

		}
	} while (auswahl != ENDE);
}

void BenutzerInterface::zeigeSuche() {
	cout << "Geben Sie den Namen der gesuchten Lokation ein: ";
	string suchString = "";
	cin >> suchString;
	vector<Gebietslokation*> treffer = lokVerwaltung->suchen(suchString);
	for (int i = 0; i < treffer.size(); i++) {
		cout << "\n\n Stelle: " << i;
		cout << treffer.at(i)->toString();
	}
	if (treffer.empty()) {
		return;
	}
	cout << "\nWelche Lokation moechten Sie sich weiter betrachten?"
			<< " Waehlen Sie bitte die entsprechende Nummer:";
	unsigned int nummer = 0;
	cin >> nummer;
	zeigeFeinMenue(treffer.at(nummer));
}

void BenutzerInterface::zeigeIdSuche() {
}

void BenutzerInterface::zeigeFeinMenue(Gebietslokation* lok) {
	int klassenTyp = lok->getType();
	int eingabe = 0;
	do {
		cout << "\nWas moechten Sie mit der Lokation tuen?";
		cout << "\nEnde durch -" << ENDE;
		if (klassenTyp >= GEBIET) {
			cout << "\nName anzeigen - " << NAME_ANZEIGEN;
		}
		if (klassenTyp > GEBIET) {
			cout << "\nUebergeordnete Lokation anzeigen - "
					<< UEBERGEORDNETE_LOKATION_ANZEIGEN;
		}
		if (klassenTyp > LINEAR) {
			cout << "\nUebergeordnete Strasse anzeigen - "
					<< UEBERGEORDNETE_STRASSE_ANZEIGEN;
		}
		if (klassenTyp >= GEBIET) {
			cout << "\nPositive Offeset anzeigen - " << POFFSET_ANZEIGEN;
		}
		if (klassenTyp >= GEBIET) {
			cout << "\nNegative Offeset anzeigen - " << NOFFSET_ANZEIGEN;
		}
		cout << "\nId anzeigen - " << ID_ANZEIGEN;
		if (klassenTyp > 1) {
			cout << "\nKoordinaten anzegen - " << KOORDINATE_ANZEIGEN;
		}
		cout << "\nJetzt waehlen: ";
		cin >> eingabe;

		//TODO evtl. noch Pruefung vor dem casten
		switch (eingabe) {
		case NAME_ANZEIGEN:
			cout << "\n" << lok->getFirstName();
			break;
		case UEBERGEORDNETE_LOKATION_ANZEIGEN:
			cout << "\n";
			if (((Linearlokation*) lok)->getAreaReference() != NULL) {
				cout << ((Linearlokation*) lok)->getAreaReference()->toString()<<"\n";
			} else {
				cout << "Keine Area Reference gefunden";
			}
			break;
		case UEBERGEORDNETE_STRASSE_ANZEIGEN:
			cout << "\n";
			if (((Punktlokation*) lok)->getLinearReference() != NULL) {
				cout
						<< ((Punktlokation*) lok)->getLinearReference()->toString()<<"\n";
			} else {
				cout << "Keine Linear Reference gefunden";
			}
			break;
		case POFFSET_ANZEIGEN:
			cout << "\n";
			if (((Linearlokation*) lok)->getPositiveOffset() != NULL) {
				cout
						<< ((Linearlokation*) lok)->getPositiveOffset()->toString()<<"\n";
			} else {
				cout << "Kein Positive Offeset gefunden";
			}
			break;

		case NOFFSET_ANZEIGEN:
			cout << "\n";
			if (((Linearlokation*) lok)->getNegativeOffset() != NULL) {
				cout
						<< ((Linearlokation*) lok)->getNegativeOffset()->toString()<<"\n";
			} else {
				cout << "Kein Negative Offeset gefunden";
			}
			break;
		case KOORDINATE_ANZEIGEN:
			cout << "\n";
			if (((Punktlokation*) lok)->getGeoKoordinate() != NULL) {
				cout << ((Punktlokation*) lok)->getGeoKoordinate()->toString()<<"\n";
			} else {
				cout << "Keine Geo Koordinate gefunden";
			}
			break;
		default:
			cout << "\nDu kannst gar nichts.";
		}
	} while (eingabe != ENDE);
}

void BenutzerInterface::zeigeAlle() {
	for (auto it = lokVerwaltung->getNamenMap().begin();
			it != lokVerwaltung->getNamenMap().end(); it++) {
		cout << "\nName: " << it->first << "Value: " << it->second->toString();
	}
}
