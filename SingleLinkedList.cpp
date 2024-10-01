#include "SingleLinkList.h"

Single_Linked_List::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}
//constructor
//destructor
Single_Linked_List::~Single_Linked_List() {
	while (!empty()) {
		pop_front();
	}
}
//adds a new int into the list the adjusts acordingly when added to the front
void Single_Linked_List::push_front(int item) {
	Node* newNode = new Node(item);
	if (empty()) {
		head = tail = newNode;
	}
	else {
		newNode->Next = head;
		head = newNode;
	}
	num_items++;
}

void Single_Linked_List::push_back(int item) {
	Node* newNode = new Node(item);
	if (empty()) {
		head = tail = newNode;
	}
	else {
		tail->Next = newNode;
		tail = newNode;
	}
	num_items++;
}
//removes the front node int and changes the head acordingly along with nunber of items
void Single_Linked_List::pop_front() {
	if (!empty()) {
		Node* temp = head;
		head = head->Next;
		delete temp;
		num_items--;
		if (empty()) {
			tail = nullptr;
		}
	}
}
//removes the back and changes the tail acordingly with num of items
void Single_Linked_List::pop_back() {
	if (!empty()) {
		if (head == tail) {
			delete head;
			head = tail = nullptr;
		}
		else {
			Node* current = head;
			while (current->Next != tail) {
				current = current->Next;
			}
			delete tail;
			tail = current;
			tail->Next = nullptr;
		}
		num_items--;
	}
}
//returns the first number in the list not not thows an error
int Single_Linked_List::front() const {
	if (!empty()) return head->data;
	throw std::out_of_range("List is empty");
}
//returns the back number in list, else it will throw an error
int Single_Linked_List::back() const {
	if (!empty()) return tail->data;
	throw std::out_of_range("List is empty");
}
//checks if the linked list is empty or not
bool Single_Linked_List::empty() const {
	return num_items == 0;
}
//puts the number in place with specific index location
void Single_Linked_List::insert(size_t index, int item) {
	if (index == 0) {
		push_front(item);
	}
	else if (index >= num_items) {
		push_back(item);
	}
	else {
		Node* newNode = new Node(item);
		Node* current = head;
		for (size_t i = 0; i < index - 1; i++) {
			current = current->Next;
		}
		newNode->Next = current->Next;
		current->Next = newNode;
		num_items++;
	}
}
//removed the number at specific index and fixed head and tail acordingly
bool Single_Linked_List::remove(size_t index) {
	if (index >= num_items) return false;
	if (index == 0) {
		pop_front();
	}
	else {
		Node* current = head;
		for (size_t i = 0; i < index - 1; i++) {
			current = current->Next;
		}
		Node* toDelete = current->Next;
		current->Next = toDelete->Next;
		if (toDelete == tail) {
			tail = current;
		}
		delete toDelete;
		num_items--;
	}
	return true;
}
//returns the index of the number being looked after
size_t Single_Linked_List::find(int item) const {
	Node* current = head;
	size_t index = 0;
	while (current) {
		if (current->data == item) return index;
		current = current->Next;
		index++;
	}
	return num_items;
}
