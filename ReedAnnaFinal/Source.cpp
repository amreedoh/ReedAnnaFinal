/*
Anna Reed
8/5/2021
CIS 1202
Final Project
*/

#include "Rat.h"
#include "MaleRat.h"
#include "FemaleRat.h"

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;


int menu();
void createFemRat(fstream& streamFem);
void createMalRat(fstream& streamMal);
void displayFemaleRat(fstream&  streamFem);
void displayMaleRat(fstream& streamMal);
void changeRat(fstream& streamFem, fstream& streamMal, int choice);
void checkCage(fstream& streamFem, fstream& streamMal, int choice);


int main() {
	fstream streamFem, streamMal;
	streamFem.open("FemaleRats.dat", ios::in | ios::out | ios::binary);
	streamMal.open("MaleRats.dat", ios::in | ios::out | ios::binary);

	//tests for files being open
	if (streamFem.fail()) {
		cout << "\nERROR: Female Rat file failed to open.";
		return 0;
	}
	if (streamMal.fail()) {
		cout << "\nERROR: Male Rat file failed to open.";
		return 0;
	}



	int choice;

	cout << "\nWelcome to Pet Rat Tracker!";
	cout << "\nWhat would you like to do?";

	do {
		cout << "\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n";
		choice = menu();
		cout << "\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n";

		switch (choice) {
		case 1: createFemRat(streamFem); break;
		case 2: displayFemaleRat(streamFem); break; 
		case 3: changeRat(streamFem, streamMal, choice); break;
		case 4: checkCage(streamFem, streamMal, choice); break;

		case 5: createMalRat(streamMal); break;
		case 6: displayMaleRat(streamMal); break;
		case 7: changeRat(streamFem, streamMal, choice); break;
		case 8: checkCage(streamFem, streamMal, choice); break;
		}
	} while (choice != 9);

	streamFem.close();
	streamMal.close();
	return 0;
}

int menu() {
	int choice;

	cout << "\n1) Add Female Rat\n2) View Female Rats\n3) Change Female Rat\n4) Female Cage Size Check"
		<< "\n\n5) Add Male Rat\n6) View Male Rat\n7) Change Male Rat\n8) Male Cage Size Check"
		<< "\n\n9) Exit\nChoice: ";
	cin >> choice;
	while (choice < 1 || choice > 9) {
		cout << "\nERROR: Invalid Choice.\nChoice: ";
		cin >> choice;
	} 

	return choice;
}

void createFemRat(fstream& streamFem) {
	const int MAX = 100;
	int litters;
	char fixed, babies, growth, alive;
	bool spayed, children, tumor, notAZombie;
	double age, weightOz;
	char name[MAX], color[MAX];

	//getting information

	cout << "\nName: "; //Name
	cin >> name;
	cout << "Age: "; //Age
	cin >> age;
	cout << "Color: "; //Color
	cin >> color;
	cout << "Weight(oz): "; //Weight
	cin >> weightOz;
	cout << "Are they alive? (T/F): "; //alive
	cin >> alive;
	while (alive != 't' && alive != 'T' && alive != 'f' && alive != 'F') {
		cout << "\nERROR: Invalid character. T/F : ";
		cin >> alive;
	}
	if (alive == 't' || alive == 'T') {
		notAZombie = true;
	}
	else if (alive == 'f' || alive == 'F') {
		notAZombie = false;
	}

	cout << "Spayed? (T/F): "; //spayed 
	cin >> fixed;
	while (fixed != 't' && fixed != 'T' && fixed != 'f' && fixed != 'F') {
		cout << "\nERROR: Invalid character. T/F : ";
		cin >> fixed;
	}
	if (fixed == 't' || fixed == 'T') {
		spayed = true;
	}
	else if (fixed == 'f' || fixed == 'F') {
		spayed = false;
	}

	cout << "Babies? (T/F): "; //asking if she has had babies 
	cin >> babies;
	while (babies != 't' && babies != 'T' && babies != 'f' && babies != 'F') {
		cout << "\nERROR: Invalid character. T/F : ";
		cin >> babies;
	}
	if (babies == 't' || babies == 'T') {
		children = true;
	}
	else if (babies == 'f' || babies == 'F') {
		children = false;
	}


	if (children) { //will ceck if there were pregnancies and if so how many litters
		cout << "Number of Litters: ";
		cin >> litters;
		while (litters <= 0); {
			cout << "\nERROR: Needs to be one or more litters: ";
			cin >> litters;
		}
	}
	else {
		litters = 0;
	}

	cout << "Evidence of tumors? (T/F): "; //tumors
	cin >> growth;
	while (growth != 't' && growth != 'T' && growth != 'f' && growth != 'F') {
		cout << "\nERROR: Invalid character. T/F : ";
		cin >> growth;
	}
	if (growth == 't' || growth == 'T') {
		tumor = true;
	}
	else if (growth == 'f' || growth == 'F') {
		tumor = false;
	}

	//creating a new female rat to put in file
	FemaleRat newbie(age, weightOz, name, color, alive, litters, spayed, children, tumor);

	//going to the end of the file to add to it
	streamFem.clear();
	streamFem.seekp(0L, ios::end);
	streamFem.write(reinterpret_cast<char*>(&newbie), sizeof(FemaleRat)); //writing to file

	return;
}
void createMalRat(fstream& streamMal) {
	
	const int MAX = 100;
	char fixed, alive, name[MAX], color[MAX];
	bool  notAZombie, nuetered;
	double age;
	double weightOz;

	//getting information

	cout << "\nName: ";//name
	cin >> name;
	cout << "Age: ";//age
	cin >> age;
	cout << "Color: ";//color
	cin >> color;
	cout << "Weight(oz): ";//weight
	cin >> weightOz;

	cout << "Are they alive? (T/F): ";//alive
	cin >> alive;
	while (alive != 't' && alive != 'T' && alive != 'f' && alive != 'F') {
		cout << "\nERROR: Invalid character. T/F : ";
		cin >> alive;
	}
	if (alive == 't' || alive == 'T') {
		notAZombie = true;
	}
	else if (alive == 'f' || alive == 'F') {
		notAZombie = false;
	}

	cout << "Nuetered? (T/F): ";//fixed 
	cin >> fixed;
	while (fixed != 't' && fixed != 'T' && fixed != 'f' && fixed != 'F') {
		cout << "\nERROR: Invalid character. T/F : ";
		cin >> fixed;

	}
	if (fixed == 't' || fixed == 'T') {
		nuetered = true;
	}
	else if (fixed == 'f' || fixed == 'F') {
		nuetered = false;
	}
	//creating a new male rat to put in file
	MaleRat newbie(age, weightOz, name, color, alive, nuetered);

	//going to the end of the file to add to it
	streamMal.clear();
	streamMal.seekp(0L, ios::end);
	streamMal.write(reinterpret_cast<char*>(&newbie), sizeof(MaleRat)); //writing to file
	return;
}

void changeRat(fstream& streamFem, fstream& streamMal, int choice) {
	int change;
	cout << "\nWhat Rat would you like to change?: "; 
	cin >> change;
	change--; //gets correct "index" number

	const int MAX = 100;
	char fixed, alive, babies, growth, name[MAX], color[MAX];
	bool  spayed, children, tumor, notAZombie, nuetered;
	double age, weightOz;
	int litters;

	if (choice == 7) {
		//changing info on a male rat
		//getting information

		cout << "\nName: ";//name
		cin >> name;
		cout << "Age: ";//age
		cin >> age;
		cout << "Color: ";//color
		cin >> color;
		cout << "Weight(oz): ";//weight
		cin >> weightOz;

		cout << "Are they alive? (T/F): ";//alive
		cin >> alive;
		while (alive != 't' && alive != 'T' && alive != 'f' && alive != 'F') {
			cout << "\nERROR: Invalid character. T/F : ";
			cin >> alive;
		} 
		if (alive == 't' || alive == 'T') {
			notAZombie = true;
		}
		else if (alive == 'f' || alive == 'F') {
			notAZombie = false;
		}

		cout << "Nuetered? (T/F): ";//fixed 
		cin >> fixed;
		while (fixed != 't' && fixed != 'T' && fixed != 'f' && fixed != 'F') {
				cout << "\nERROR: Invalid character. T/F : ";
				cin >> fixed;
			
		} 
		if (fixed == 't' || fixed == 'T') {
			nuetered = true;
		}
		else if (fixed == 'f' || fixed == 'F') {
			nuetered = false;
		}

		//creating a new male rat to put in file
		MaleRat newbie(age, weightOz, name, color, alive, nuetered);

		//finding file location
		long size = (change * (sizeof(MaleRat)));

		//going to the end of the file to add to it
		streamMal.clear();
		streamMal.seekp(size, ios::beg);
		streamMal.write(reinterpret_cast<char*>(&newbie), sizeof(MaleRat)); //writing to file

	}
	else {
		//changing info on a female rat
		//getting information

		cout << "\nName: "; //Name
		cin >> name;
		cout << "Age: "; //Age
		cin >> age;
		cout << "Color: "; //Color
		cin >> color;
		cout << "Weight(oz): "; //Weight
		cin >> weightOz;
		cout << "Are they alive? (T/F): "; //alive
		cin >> alive;
		while (alive != 't' && alive != 'T' && alive != 'f' && alive != 'F') {
			cout << "\nERROR: Invalid character. T/F : ";
			cin >> alive;
		} 
		if (alive == 't' || alive == 'T') {
			notAZombie = true;
		}
		else if (alive == 'f' || alive == 'F') {
			notAZombie = false;
		}

		cout << "Spayed? (T/F): "; //spayed 
		cin >> fixed;
		while (fixed != 't' && fixed != 'T' && fixed != 'f' && fixed != 'F') {
			cout << "\nERROR: Invalid character. T/F : ";
			cin >> fixed;
		} 
		if (fixed == 't' || fixed == 'T') {
			spayed = true;
		}
		else if (fixed == 'f' || fixed == 'F') {
			spayed = false;
		}

		cout << "Babies? (T/F): "; //asking if she has had babies 
		cin >> babies;
		while (babies != 't' && babies != 'T' && babies != 'f' && babies != 'F') {
			cout << "\nERROR: Invalid character. T/F : ";
			cin >> babies;
		} 
		if (babies == 't' || babies == 'T') {
			children = true;
		}
		else if (babies == 'f' || babies == 'F') {
			children = false;
		}


		if (children) { //will ceck if there were pregnancies and if so how many litters
			cout << "Number of Litters: ";
			cin >> litters;
			while (litters <= 0); {
				cout << "\nERROR: Needs to be one or more litters: ";
				cin >> litters;
			}
		}
		else {
			litters = 0;
		}

		cout << "Evidence of tumors? (T/F): "; //tumors
		cin >> growth;
		while (growth != 't' && growth != 'T' && growth != 'f' && growth != 'F') {
			cout << "\nERROR: Invalid character. T/F : ";
			cin >> growth;
		} 
		if (growth == 't' || growth == 'T') {
			tumor = true;
		}
		else if (growth == 'f' || growth == 'F') {
			tumor = false;
		}

		//creating a new female rat to put in file
		FemaleRat newbie(age, weightOz, name, color, alive, litters, spayed, children, tumor);
		
		//finding file location
		long location = (change * (sizeof(FemaleRat)));

		//going to the end of the file to add to it
		streamFem.clear();
		streamFem.seekp(location, ios::beg);
		streamFem.write(reinterpret_cast<char*>(&newbie), sizeof(FemaleRat)); //writing to file

	}
}

void displayFemaleRat(fstream& streamFem) {

	FemaleRat tempFem;
	int ratAmt = 0;
	
	cout << "\n~*~*~Girls~*~*~";


	streamFem.clear();
	streamFem.seekg(0L, ios::beg);
	streamFem.read(reinterpret_cast<char*>(&tempFem), sizeof(FemaleRat));

	while (!streamFem.eof()) {
		ratAmt++;
		cout << "\n\nRat #" << ratAmt
			<< "\n  Name: " << tempFem.getName()
			<< "\n  Age: " << tempFem.getAge()
			<< "\n  Color: " << tempFem.getColor()
			<< "\n  Weight: " << tempFem.getWeightOz()
			<< "\n  Alive: ";
		if (tempFem.getAlive()) cout << "True";
		else cout << "False";

		cout << "\n  Children: ";
		if (tempFem.getCildren()) cout << "True";
		else cout << "False";

		cout << "\n  Litters: " << tempFem.getLitters();

		cout << "\n  Fixed: ";
		if (tempFem.getSpayed()) cout << "True";
		else cout << "False";

		cout << "\n  Tumor: ";
		if (tempFem.getTumors()) cout << "True\n";
		else cout << "False\n"; 
		
		streamFem.read(reinterpret_cast<char*>(&tempFem), sizeof(FemaleRat));
	}

	if (ratAmt == 0)
		cout << "\nYou don't have any girl rats yet!\n";

	return;

}
void displayMaleRat(fstream& streamMal) {

	MaleRat tempMal;
	int ratAmt = 0;

	cout << "\n~*~*~Boys~*~*~";

	streamMal.clear();
	streamMal.seekg(0L, ios::beg);
	streamMal.read(reinterpret_cast<char*>(&tempMal), sizeof(MaleRat));

	while (!streamMal.eof()) {
		ratAmt++;
		cout << "\n\nRat #" << ratAmt 
			<< "\n  Name: " << tempMal.getName()
			<< "\n  Age: " << tempMal.getAge()
			<< "\n  Color: " << tempMal.getColor()
			<< "\n  Weight: " << tempMal.getWeightOz()
			<< "\n  Alive: ";
		if (tempMal.getAlive()) cout << "True";
		else cout << "False";

		cout	<< "\n  Fixed: ";
		if (tempMal.getNuetered()) cout << "True\n";
		else cout << "False\n";
		
		streamMal.read(reinterpret_cast<char*>(&tempMal), sizeof(MaleRat));
	}

	if (ratAmt == 0)
		cout << "\nYou don't have any boy rats yet!\n";

	return;

}

void checkCage(fstream& streamFem, fstream& streamMal, int choice) {
	MaleRat tempMal;
	FemaleRat tempFem;

	double height, width, length, cubic;
	int ratAmt = 0;

	cout << "\nCage Height (ft): ";
	cin >> height;
	cout << "Cage Width (ft): ";
	cin >> width;
	cout << "Cage Length (ft): ";
	cin >> length;

	cubic = height * width * length;

	if (choice == 8) {
		//counts male rats
		streamMal.clear();
		streamMal.seekg(0L, ios::beg);
		streamMal.read(reinterpret_cast<char*>(&tempMal), sizeof(MaleRat));
		while (!streamMal.eof()) {
			if (tempMal.getAlive()) {
				ratAmt++;
			}
			streamMal.read(reinterpret_cast<char*>(&tempMal), sizeof(MaleRat));
		}
	}
	else {
		//counts Female rats
		streamFem.clear();
		streamFem.seekg(0L, ios::beg);
		streamFem.read(reinterpret_cast<char*>(&tempFem), sizeof(FemaleRat));
		while (!streamFem.eof()) {
			if (tempFem.getAlive()) {
				ratAmt++;
			}
			streamFem.read(reinterpret_cast<char*>(&tempFem), sizeof(FemaleRat));
		}
	}

	if (ratAmt > (cubic / 2)) {
		cout << "You need a bigger cage!\n";
	}
	else if (ratAmt == (cubic / 2)) {
		cout << "You have enough space but just barely!\n";
	}
	else {
		cout << "You have enough space!\n";
	}
	return;
}


//Code for checking if change happened correctly
/*
//checks female rat file
		FemaleRat tempFem;
		streamFem.seekg(location, ios::beg);
		streamFem.read(reinterpret_cast<char*>(&tempFem), sizeof(FemaleRat));
		cout << "\n  Name: " << tempFem.getName()
			<< "\n  Age: " << tempFem.getAge()
			<< "\n  Color: " << tempFem.getColor()
			<< "\n  Weight: " << tempFem.getWeightOz()
			<< "\n  Alive: " << tempFem.getAlive()
			<< "\n  Children: " << tempFem.getCildren();
		if (tempFem.getCildren()) {
			cout << "\n  Litters: " << tempFem.getLitters();
		}
		cout << "\n  Fixed: " << tempFem.getSpayed()
			<< "\n  Tumor: " << tempFem.getTumors() << endl;
		system("pause");

//checks male rat file
		MaleRat tempMal;
		streamFem.seekg(location, ios::beg);
		streamFem.read(reinterpret_cast<char*>(&tempMal), sizeof(MaleRat));
		//testing
		cout << "\n  Name: " << tempMal.getName()
			<< "\n  Age: " << tempMal.getAge()
			<< "\n  Color: " << tempMal.getColor()
			<< "\n  Weight: " << tempMal.getWeightOz()
			<< "\n  Alive: " << tempMal.getAlive()
			<< "\n  Fixed: " << tempMal.getNuetered() << endl;
		system("pause");
*/