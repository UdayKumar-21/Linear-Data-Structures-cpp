#include <iostream>
using namespace std;

class CircularSinglyLinkedNode {  // to create a node for Circular singly linked list.
public:
	int data;
	CircularSinglyLinkedNode* next;
	CircularSinglyLinkedNode(int data) {
		this->data = data;
		next = nullptr;
	}
};


class CircularSinglyLinkedList {   // we can create a multiple Circular singly linked lists using this class. 
						   // each list has its own properties .
public:
	CircularSinglyLinkedNode* head;
	CircularSinglyLinkedNode* tail;
	CircularSinglyLinkedList() :head(nullptr), tail(nullptr) {}
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

//method to insert an element at the end of the Circular Singly linked list.
void CircularSinglyLinkedList::insertAtEnd(int data) {
	CircularSinglyLinkedNode* node = new CircularSinglyLinkedNode(data);
	if (head == nullptr) {
		head = node;
		tail = node;
		tail->next = head;
		return;
	}
	tail->next = node;
	node->next = head;
	tail = node;
}

//method to insert an element at the begining of the Circular singly linked list.
void CircularSinglyLinkedList::insertAtBegin(int data) {
	CircularSinglyLinkedNode* node = new CircularSinglyLinkedNode(data);
	if (head == nullptr) {
		head = node;
		tail = node;
		return;
	}
	node->next = head;
	head = node;
	tail->next = head;
}


// method to insert an element at a specified position of the Circular singly linked list.
void CircularSinglyLinkedList::insertAtPosition(int position, int data) {
	if (position == 1) { // if the user enter the 1st position then it will effect to the head pointer
		insertAtBegin(data);
		return;
	}
	CircularSinglyLinkedNode* temp = head;
	for (int i = 1; i < position - 1; i++) {
		temp = temp->next;
	}
	if (temp == tail) {
		insertAtEnd(data);
		return;
	}
	CircularSinglyLinkedNode* node = new CircularSinglyLinkedNode(data);
	node->next = temp->next;
	temp->next = node;
}


// method to delete the node at the end of the Circular singly linked list
void CircularSinglyLinkedList::deleteAtEnd() {
	if (head == nullptr) {  // to check if the list is empty
		cout << "list is already empty nothing to delete\n";
		return;
	}
	CircularSinglyLinkedNode* temp = head;
	if(temp->next == head){  // if list has only one node after delete it ,list becomes empty.
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
	while (temp->next->next != head) {
		temp = temp->next;
	}
	delete tail;
	tail = temp;
	tail->next = head;
}


//method to delete the node at the begining of the Circular singly linked list 
void CircularSinglyLinkedList::deleteAtBegin() {
	if (head == nullptr) {
		cout << "list is already empty nothing to delete\n";
		return;
	}
	CircularSinglyLinkedNode* temp = head;
	head = head->next;
	delete temp;
	tail->next = head;
}


//method to delete the node at the specified position of the Circular singly linked list
void CircularSinglyLinkedList::deleteAtPosition(int position) {
	if (position == 1) {
		deleteAtBegin();
		return;
	}
	CircularSinglyLinkedNode* temp = head;
	for (int i = 2; i < position - 1; i++) {
		temp = temp->next;
	}
	if (temp == tail) {
		deleteAtEnd();
		return;
	}
	CircularSinglyLinkedNode* temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
}


// method to print the data of the entire Circular singly linked list
void CircularSinglyLinkedList::showData() const {
	if (head == nullptr) {
		cout << "list is empty nothing to show the data\n";
		return;
	}
	CircularSinglyLinkedNode* temp = head;
	do{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
	cout << endl;
}


// method to reverse the entire Circular singly linked list
void CircularSinglyLinkedList::Reverse() {
	CircularSinglyLinkedNode* temp1 = tail;
	CircularSinglyLinkedNode* temp2 = nullptr;
	tail = head;
	do{
		temp2 = head->next;
		head->next = temp1;
		temp1 = head;
		head = temp2;
	} while (head != tail && head != nullptr);
	head = temp1;
	tail->next = head;
}


// method to delete the entire Circular singly linked list.
void CircularSinglyLinkedList::Free() {
	tail->next = nullptr;
	while (head != nullptr) {
		CircularSinglyLinkedNode* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
}


int main() {
	CircularSinglyLinkedList list1;
	list1.insertAtEnd(20);
	list1.insertAtEnd(30);
	list1.insertAtEnd(40);
	list1.deleteAtEnd();
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
// If there are any mistakes in this code , please let me know
