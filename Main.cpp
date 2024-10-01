//Brandon Alvarez De La Cruz
//CS-303 Assignment 2

#include <iostream>
//#include "Single_Link_List.h" // not needed to run program
#include "Stack.h"

int main() {
	stack intStack;
	for (int i = 1; i < 6; i++) {
		intStack.push(i);
	}
	char choice = '0';
	while (choice != 'q') {
		//shows the user the current before actions are made on it
		cout << "\nCurrent stack: ";
		intStack.printStack();

		//options for the user to make
		cout << "\n1. Add integer onto stack" << endl;
		cout << "2. Remove integer from stack" << endl;
		cout << "3. Get Top" << endl;
		cout << "4. Get Average in stack" << endl;
		cout << "q. Quit" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		switch (choice) {
		case '1': {
			int newInt;
			cout << "Enter new integer to add: ";
			cin >> newInt;
			intStack.push(newInt);
			break;
		}
		case '2': {
			int remove = intStack.pop();
			cout << remove << " was removed" << endl;
			break;
		}
		case '3': {
			int intTop = intStack.top();
			cout << "Top of stack is: " << intTop << endl;
			break;
		}
		case '4': {
			float average = intStack.avg();
			cout << "Stack Average is: " << average << endl;
			break;
		}
		}
	}
}
