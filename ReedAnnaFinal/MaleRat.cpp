/*
Anna Reed
8/5/2021
CIS 1202
Final Project
*/

#include "Rat.h"
#include "MaleRat.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//nuetered
void MaleRat::setNuetered(bool nue) {
	nuetered = nue;
}
bool MaleRat::getNuetered() {
	return nuetered;
}