#include <iostream>
#include <fstream>
#include "FoodList.h"

/*
* prompts user, gets input, and validates
* returns 's', 'o', 'h', or 'q', depending on user choice
*/
char menu() {
	char choice;

	// repeat until valid input found
	while (true) {
		cout << "+----------------+" << endl;
		cout << "| s - search     |" << endl;
		cout << "| o - output all |" << endl;
		cout << "| h - histogram  |" << endl;
		cout << "| q - quit       |" << endl;
		cout << "+----------------+" << endl;

		try {
			cin >> choice;
			if (cin.bad()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw "bad input";
			}
			if (
				choice == 's' ||
				choice == 'o' ||
				choice == 'h' ||
				choice == 'q'
				) {
				return choice;
			}
			else {
				throw "bad input";
			}
		}
		catch (...) {
			cout << "Invalid input" << endl;
			cout << "Please enter one of the characters indicated by the menu" << endl << endl;
		}
	}
}

/*
* prompts the user for a food name, then outputs the quantity
* @param searchList is the Foodlist to search for the data
*/
void search(FoodList& searchList) {
	string searchStr;

	// repeat until valid input found
	while (true) {
		cout << "Enter the name of the food to search for: ";
		cin >> searchStr;
		if (cin.bad()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please try again" << endl;
		}
		else {
			break;
		}
	}

	// search for matching food
	FoodNode* result = searchList.find(searchStr);

	// if result found output number, else output 'none found'
	if (result) {
		cout << "Quantity: " << result->getQuantity() << endl;
	}
	else {
		cout << "None found" << endl;
	}
}

int main() {
		// parsing
	
	// read data from input file
	ifstream infile("CS210_Project_Three_Input_File.txt");
	FoodList list;
	list.read(infile);

	// write data to frequencies.dat
	ofstream outfile("frequencies.dat");
	list.outputAll(outfile);
	cout << "Data written to ./frequencies.dat" << endl;

	// cleanup
	infile.close();
	outfile.close();


		// user interaction
	
	// get user choice
	char choice = menu();

	// repeat until user quits
	while (choice != 'q') {
		switch (choice) {
		case 's':
			// search
			search(list);
			break;
		case 'o':
			// output
			list.outputAll(cout);
			break;
		case 'h':
			// histogram
			list.histogramAll(cout);
		}
		// get user's next choice
		choice = menu();
	}
}

