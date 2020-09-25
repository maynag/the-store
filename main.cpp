#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

short int MainMenu(); // Function declaration
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
	int mainMenuOption = MainMenu();
	while (mainMenuOption != 3){
		if (mainMenuOption == 1){
			cout << "Selling" << endl;
		}else if (mainMenuOption == 2){
			cout << "Summary" << endl;
		}else if (mainMenuOption == 3){
			cout << "Not gonna happen!" << endl;
		}else{
			cerr << "This should never happen!" << endl;
		}
		mainMenuOption = MainMenu();
	}

	return 0;
}

short int MainMenu(){ //  Function definition
	short int option = 0;
	while (true){
		cout << "1. Sell" << endl
			 << "2. Day Summary" << endl
			 << "3. Exit" << endl;
		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Wrong input" << endl;
		}
		if (option < 1 || option > 3){
			cerr << "Not a menu option, input again" << endl;
		}else
			break;
	}
	return option;
}