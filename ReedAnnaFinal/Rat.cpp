/*
Anna Reed
8/5/2021
CIS 1202
Final Project
*/

#include "Rat.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


//age
void Rat::setAge(double a) {
	age = a;
}
double Rat::getAge() {
	return age;
}

//weight
void Rat::setWeightOz(double wOz) {
	weightOz = wOz;
}
double Rat::getWeightOz() {
	return weightOz;
}

//name
void Rat::setName(char nm[]) {
	strcpy_s(name, (MAX - 1), nm);

}
char* Rat::getName() {
	return name;
}

//color
void Rat::setColor(char *clr) {
	strcpy_s(color, (MAX - 1), clr);
}
char* Rat::getColor() {
	return color;
}

//alive
void Rat::setAlive(bool al) {
	alive = al;
}
bool Rat::getAlive() {
	return alive;
}
