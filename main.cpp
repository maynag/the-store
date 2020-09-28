#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::flush;

using std::string;

short int MainMenu(); // Function declaration
void SellMenu(int&, int&, int&);
void PrintSummary(int, int, int);

int PromptForNumber(string);

/*
 * Naming standards !!!!
 *  CamelCase
 *  Snake_Case
 *  This class:
 *  ALL_CAPS --> constants
 *  CamelCase --> Functions, Methods, Classes
 *  camelCase --> Variables
 */

int main() {
	cout << "Welcome to my Store" << endl << endl;

	int apples = 0;
	int pears = 0;
	int grapes = 0;


	while (true) {
		
		int mainMenuOption = MainMenu();

		if (mainMenuOption == 1) {
			cout << endl << "Selling..." << endl;
			SellMenu(apples, pears, grapes);
		}
		else if (mainMenuOption == 2) {
			cout << endl << "Summary" << endl << endl;
			PrintSummary(apples, pears, grapes);
		}
		else if (mainMenuOption == 3) {
			cout << endl << "Goodbye!" << endl;
			break;
		}
		else {
			cerr << "This should never happen!" << endl;
		}
	}

	return 0;
}

short int MainMenu(){ //  Function definition
	short int option = 0;
	while (true) {

		cout	<< "1. Sell" << endl
				<< "2. Day Summary" << endl
				<< "3. Exit" << endl;
		
		cout << endl;
		option = option = PromptForNumber("Option: ");

		if (option < 1 || option > 3) {
			cerr << "Not a menu option, input again" << endl;
		}
		else
			break;
	}
	return option;
}

void SellMenu(int& applesRef, int& pearsRef, int& grapesRef) { //  Function definition

	while (true) {
		
		short option = 0;
		int quantity = 0;

		cout << endl;
		cout	<< "1. Apple" << endl
				<< "2. Pear" << endl
				<< "3. Grapes" << endl
				<< "4. Exit" << endl;


		cout << endl;
		option = PromptForNumber("Option: ");

		if (option == 4){
			cout << "Finished Selling..." << endl << endl;
			break;	// EXIT SELL MENU - EARLY OUT
		}

		if (option < 1 || option > 4) {
			cerr << "Not a menu option, input again" << endl;
			continue; // - - CONTINUE - -
		}
		
		quantity = PromptForNumber("Quantity to buy: ");

		if (option == 1) {
			applesRef += quantity;
			cout << "Added " << quantity << " apples" << endl;
		}
		else if (option == 2) {
			pearsRef += quantity;
			cout << "Added " << quantity << " pears" << endl;
		}
		else if (option == 3) {
			grapesRef += quantity;
			cout << "Added " << quantity << " grapes" << endl;
		}
	}
}

int PromptForNumber(string prompt) {
	int n = 0;
	cout << prompt << flush;
	cin >> n;

	while (cin.fail()) {
		cerr << "ERROR: Non-Numerical Value" << endl;
		cerr << "I did not detect a number when it was expected." << endl;

		// Clear input stream
		cin.clear();

		// Discard previous input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << endl;
		cout << "Please try again." << endl;
		cout << prompt << flush;
		cin >> n;
	}

	return n;
}

void PrintSummary(int apples, int pears, int grapes) {

	cout << "SALE TOTALS" << endl;
	cout << "Apples:\t" << apples << endl;
	cout << "Pears:\t" << pears << endl;
	cout << "Grapes:\t" << grapes << endl;
	cout << endl;
}