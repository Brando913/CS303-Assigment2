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
		//get choice from user
		cin >> choice;
		//checks what choice and will run the chioce the user picked to run
		switch (choice) {
		//the add/push/insert function for the stack
		case '1': {
			int newInt;
			cout << "Enter new integer to add: ";
			cin >> newInt;
			intStack.push(newInt);
			break;
		}
		//remove/pop function for the stack
		case '2': {
			int remove = intStack.pop();
			cout << remove << " was removed" << endl;
			break;
		}
		//returns the top of the stack
		case '3': {
			int intTop = intStack.top();
			cout << "Top of stack is: " << intTop << endl;
			break;
		}
		//returns avg even when the avg is a 
		case '4': {
			float average = intStack.avg();
			cout << "Stack Average is: " << average << endl;
			break;
		}
		}
	}
}
