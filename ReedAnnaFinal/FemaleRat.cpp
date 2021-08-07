/*
Anna Reed
8/5/2021
CIS 1202
Final Project
*/

#include "Rat.h"
#include "FemaleRat.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;



//litters
void FemaleRat::setLitters(int li) {
	litters = li;
}
int FemaleRat::getLitters() {
	return litters;
}

//spayed
void FemaleRat::setSpayed(bool sp) {
	spayed = sp;
}
bool FemaleRat::getSpayed() {
	return spayed;
}

//children
void FemaleRat::setChildren(bool ch) {
	children = ch;
}
bool FemaleRat::getCildren() {
	return children;
}

//tumors
void FemaleRat::setTumors(bool tmr) {
	tumors = tmr;
}
bool FemaleRat::getTumors() {
	return tumors;
}