/*
 * Hello.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "Hello.h"

Hello::Hello() {
	// TODO Auto-generated constructor stub

}

Hello::~Hello() {
	// TODO Auto-generated destructor stub
}

#include <iostream>                                     // Ein- und Ausgabebibliothek

int main(){                                             // Hauptfunktion
    std::cout << "Hallo, du schöne Welt!" << std::endl; // Ausgabe

    return 0;                                           // Optionale Rückgabe an das Betriebssystem
}

