/*
Anna Reed
8/5/2021
CIS 1202
Final Project
*/

#pragma once
#ifndef RAT_H
#define RAT_H

#include <string>

using namespace std;

class Rat {

private:
	static const int MAX = 100;
	double weightOz, age;
	char name[MAX], color[MAX];
	bool alive;

public:

	Rat() {
		age = 0;
		weightOz = 0;
		strcpy_s(name, (MAX-1), "");
		strcpy_s(color, (MAX - 1), "");
		alive = false;
	}

	Rat(double a, double wOz, char* nm, char* clr, bool alv) {
		age = a;
		weightOz = wOz;
		strcpy_s(name, (MAX - 1), nm);
		strcpy_s(color, (MAX - 1), clr);
		alive = alv;
	}
	
	//age
	void setAge(double a);
	double getAge();
	
	//weight
	void setWeightOz(double wOz);
	double getWeightOz();
	
	//name
	void setName(char *nm);
	char* getName();
	
	//color
	void setColor(char *clr);
	char* getColor();
	
	//alive
	void setAlive(bool al);
	bool getAlive();

};
#endif // !RAT_H
