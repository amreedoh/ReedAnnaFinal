/*
Anna Reed
8/5/2021
CIS 1202
Final Project
*/

#pragma once
#ifndef MALERAT_H
#define MALERAT_H

#include "Rat.h"
#include <string>

using namespace std;

class MaleRat : public Rat {

private:
	bool nuetered;


public:
	MaleRat() : Rat() {
		nuetered = false;
	}

	MaleRat(double a, double wOz, char* nm, char* clr, bool alv, bool nue) : Rat(a, wOz, nm, clr, alv) {
		nuetered = nue;
	};

	void setNuetered(bool nue);
	bool getNuetered();
};
#endif // !MALERAT_H



