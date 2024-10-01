#include <iostream>
#include "Stack.h"

using namespace std;
//adds the new int onto the stack
void stack::push(int newVal) {
	elements.push_back(newVal);
}
//removed the top of the stack
int stack::pop() {
	if (!isEmpty()) {//check if stack is not empty to continue
		int store = elements.back();
		elements.pop_back();
		return store;
	}
	else
		throw runtime_error("Stack is empty. Cannot pop.");
}
//checks if stack is empty or not
bool stack::isEmpty() const {
	return elements.empty();
}
//retuns the top of the stack
int stack::top() const {
	if (!isEmpty()) {
		return elements.back();
	}
	else
		throw runtime_error("Stack is empty. No top element.");
}
//calculates the avg of ints even if the result is a decimal 
float stack::avg() const {
	if (!isEmpty()) {
		float sum = 0;
		for (int num : elements) {
			sum += num;
		}
		return sum / elements.size();
	}
	else
		throw runtime_error("Stack is empty. Cannot compute average.");
}
//able to print stack correctly to be visable to the user
void stack::printStack() const{
	if (!isEmpty()) {
		for (int i = elements.size() - 1; i >= 0; i--) {
			cout << elements[i] << ", ";
		}
		cout << endl;
	}
	else 
		cout << "Stack is empty." << endl;
}
