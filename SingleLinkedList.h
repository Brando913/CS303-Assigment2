#pragma once
#include <iostream>
//class to be able to access the linked list and its functions
class Single_Linked_List {
	private:
        //node to be abel to connect the list of integers
		struct Node {
			int data;
			Node* Next;
			Node(int item) : data(item), Next(nullptr) {}
		};
		Node* head;
		Node* tail;
		size_t num_items;

    public:
        //functions with contructer and destructer 
        Single_Linked_List();
        ~Single_Linked_List();
        void push_front(int item);
        void push_back(int item);
        void pop_front();
        void pop_back();
        int front() const;
        int back() const;
        bool empty() const;
        void insert(size_t index, int item);
        bool remove(size_t index);
        size_t find(int item) const;
        size_t size() const { return num_items; }
};
