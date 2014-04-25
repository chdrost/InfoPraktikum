/*
 * FileOpener.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "FileOpener.h"

FileOpener::FileOpener() {
	vector = new vector<string>();

}

FileOpener::~FileOpener() {
	delete vector;
}

