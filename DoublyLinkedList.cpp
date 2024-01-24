#include <iostream>
using namespace std;

class DoublyLinkedNode {
public:
	int data;
	DoublyLinkedNode* next;
	DoublyLinkedNode* prev;
	DoublyLinkedNode(int data) {
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
};

class DoublyLinkedList {
public:
	DoublyLinkedNode* head;
	DoublyLinkedNode* tail;
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	void insertAtEnd(int data);
	void showData();
	void insertAtBegin(int data);
	void insertAtPosition(int position, int data);
	void deleteAtEnd();
	void deleteAtBegin();
	void deleteAtPosition(int position);
	void reverse();
};
void DoublyLinkedList::insertAtEnd(int data) {
	DoublyLinkedNode* node = new DoublyLinkedNode(data);
	if (head == nullptr) {
		head = node;
		tail = node;
		return;
	}
	tail->next = node;
	node->prev = tail;
	tail = node;
}
void DoublyLinkedList::insertAtBegin(int data) {
	DoublyLinkedNode* node = new DoublyLinkedNode(data);
	if (head == nullptr) {
		head = node;
		tail = node;
		return;
	}
	node->next = head;
	head->prev = node;
	head = node;
}
void DoublyLinkedList::insertAtPosition(int position, int data) {
	if (head == nullptr || position == 1) {
		insertAtBegin(data);
		return;
	}
	DoublyLinkedNode* temp = head;
	for (int i = 1; i < position - 1; i++) {
		if (temp->next == nullptr) {
			break;
		}
		temp = temp->next;
	}
	if (temp->next == nullptr) {
		insertAtEnd(data);
		return;
	}
	DoublyLinkedNode* node = new DoublyLinkedNode(data);
	node->next = temp->next;
	node->prev = temp;
	temp->next = node;
}
void DoublyLinkedList::showData() {
	DoublyLinkedNode* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void DoublyLinkedList::deleteAtEnd() {
	if (head == nullptr) {
		cout << "nothing to delete list is already empty\n";
		return;
	}
	DoublyLinkedNode* temp = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete temp;
}
void DoublyLinkedList::deleteAtBegin() {
	if (head == nullptr) {
		cout << "nothing to delete list is already empty\n";
		return;
	}
	DoublyLinkedNode* temp = head;
	if (temp->next == nullptr) {
		delete temp;
		head = nullptr;
		return;
	}
	head->prev = nullptr;
}

void DoublyLinkedList::deleteAtPosition(int position) {
	if (head == nullptr || position == 1) {
		deleteAtBegin();
		return;
	}
	DoublyLinkedNode* temp = head;
	for (int i = 1; i < position - 1; i++) {
		if (temp->next == nullptr) {
			break;
		}
		temp = temp->next;
	}
	if (temp->next == nullptr) {
		deleteAtEnd();
		return;
	}
	DoublyLinkedNode* temp1 = temp->next;
	if (temp1->next == nullptr) {
		delete temp1;
		temp->next = nullptr;
		tail = temp;
		return;
	}
	temp->next = temp1->next;
	delete temp1;
	temp1 = temp->next;
	temp1->prev = temp;
}
void DoublyLinkedList::reverse() {
	DoublyLinkedNode* temp1 = nullptr;
	DoublyLinkedNode* temp2 = head;
	tail = head;
	while (temp2 != nullptr) {
		temp2->prev = temp2->next;
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp2->prev;
	}
	head = temp1;
}
int main() {
	DoublyLinkedList list1;
	list1.insertAtPosition(1, 80);
	//list1.deleteAtPosition(1);
	//list1.deleteAtEnd();
	list1.insertAtPosition(3, 90);
	list1.insertAtPosition(2, 70);
	//list1.deleteAtBegin();
	//list1.deleteAtPosition(1);
	//list1.deleteAtPosition(3);
	list1.insertAtPosition(4, 100);
	list1.showData();
	list1.reverse();
	cout << endl;
	list1.showData();
}
