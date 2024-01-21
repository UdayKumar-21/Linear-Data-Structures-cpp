// Author      : Uday Kumar Reddy
// Data        : 21-01-2024
// Description : Singly Linked List and its basic operations using c++
#include <iostream>
using namespace std;

class SinglyLinkedNode {  // to create a node for singlylinkedlist.
public:
	int data;
	SinglyLinkedNode* next;
	SinglyLinkedNode(int data) {
		this->data = data;
		next = nullptr;
	}
};


class SinglyLinkedList {   // we can create a multiple singlylinked lists using this class. 
						   // each list has its own properties .
public:
	SinglyLinkedNode* head;
	SinglyLinkedNode* tail;
	SinglyLinkedList() :head(nullptr), tail(nullptr) {}
	void insertAtEnd(int data);
	void insertAtBegin(int data);
	void insertAtPosition(int position, int data);
	void deleteAtEnd();
	void deleteAtBegin();
	void deleteAtPosition(int position);
	void Reverse();
	void showData() const;
	void Free();
};

//method to insert an element at the end of the Singly linked list.
void SinglyLinkedList::insertAtEnd(int data) {
	SinglyLinkedNode* node = new SinglyLinkedNode(data);
	if (head == nullptr) {
		head = node;
		tail = node;
		return;
	}
	tail->next = node;
	tail = node;
}

//method to insert an element at the begining of the singlylinked list.
void SinglyLinkedList::insertAtBegin(int data) {
	SinglyLinkedNode* node = new SinglyLinkedNode(data);
	if (head == nullptr) {
		head = node;
		tail = node;
		return;
	}
	node->next = head;
	head = node;
}


// method to insert an element at a specified position of the singly linked list.
void SinglyLinkedList::insertAtPosition(int position, int data) {
	if (position == 1) {
		insertAtBegin(data);
		return;
	}
	SinglyLinkedNode* temp = head;
	for (int i = 1; i < position - 1; i++) {
		temp = temp->next;
	}
	if (temp == tail) {
		insertAtEnd(data);
		return;
	}
	SinglyLinkedNode* node = new SinglyLinkedNode(data);
	node->next = temp->next;
	temp->next = node;
}


// method to delete the node at the end of the singlylinked list
void SinglyLinkedList::deleteAtEnd() {
	if (head == nullptr) {
		cout << "list is already empty nothing to delete\n";
		return;
	}
	SinglyLinkedNode* temp = head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	delete tail;
	tail = temp;
	tail->next = nullptr;
}


//method to delete the node at the begining of the singly linked list 
void SinglyLinkedList::deleteAtBegin() {
	if (head == nullptr) {
		cout << "list is already empty nothing to delete\n";
		return;
	}
	SinglyLinkedNode* temp = head;
	head = head->next;
	delete temp;
}


//method to delete the node at the specified position of the singly linked list
void SinglyLinkedList::deleteAtPosition(int position) {
	if (position == 1) {
		deleteAtBegin();
		return;
	}
	SinglyLinkedNode* temp = head;
	for (int i = 2; i < position - 1; i++) {
		temp = temp->next;
	}
	if (temp == tail) {
		deleteAtEnd();
		return;
	}
	SinglyLinkedNode* temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
}


// method to print the data of the entire singly linked list
void SinglyLinkedList::showData() const {
	SinglyLinkedNode* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


// method to reverse the entire singly linked list
void SinglyLinkedList::Reverse() {
	SinglyLinkedNode* temp1 = nullptr;
	SinglyLinkedNode* temp2 = nullptr;
	tail = head;
	while (head != nullptr) {
		temp2 = head->next;
		head->next = temp1;
		temp1 = head;
		head = temp2;
	}
	head = temp1;
}


// method to delete the entire singly linked list.
void SinglyLinkedList::Free() {
	while (head != nullptr) {
		SinglyLinkedNode* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
}


int main() {
	SinglyLinkedList list1;
	list1.insertAtEnd(20);
	list1.insertAtEnd(30);
	list1.insertAtEnd(40);
	list1.insertAtPosition(1, 50);
	list1.insertAtPosition(2, 70);
	list1.insertAtPosition(3, 40);
	list1.insertAtPosition(7, 80);
	list1.deleteAtBegin();
	list1.deleteAtPosition(1);
	list1.showData();
	list1.Reverse();
	list1.showData();
	list1.Free();  // delete the entire list.
	list1.showData(); // Since list was empty nothing to show the data inside the list
}
