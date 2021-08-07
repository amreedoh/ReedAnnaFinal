/*
Anna Reed
8/5/2021
CIS 1202
Final Project
*/

#pragma once
#ifndef FEMALERAT_H
#define FEMALERAT_H

#include "Rat.h"
#include <string>

using namespace std;

class FemaleRat : public Rat {

private:
	int litters;
	bool spayed,
		children,
		tumors;

public:
	FemaleRat() : Rat() {
		litters = 0;
		spayed = children = tumors = false;
	}

	FemaleRat(double a, double wOz, char* nm, char* clr, bool alv, int li, bool sp, bool ch, bool tmr) : Rat(a, wOz, nm, clr, alv) {
		litters = li;
		spayed = sp;
		children = ch;
		tumors = tmr;
	};


	//litters
	void setLitters(int li);
	int getLitters();

	//spayed
	void setSpayed(bool sp);
	bool getSpayed();

	//children
	void setChildren(bool ch);
	bool getCildren();

	//tumors
	void setTumors(bool tmr);
	bool getTumors();

};
#endif // !FEMALERAT_H
