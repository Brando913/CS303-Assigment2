#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
//class to easier acess the functions for the stack using vector
class stack {
private:
	vector<int> elements;
public:
	//functions used to change and acsess the variable
	void push(int newVal);
	int pop();
	bool isEmpty() const;
	int top() const;
	float avg() const;
	void printStack() const;
};
