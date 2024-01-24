#include <iostream>
using namespace std;
#define MAX 10

struct Stack {
	int top;
	int bottom;
	int arr[MAX] = { 0 };
	Stack() {
		top = -1;
		bottom = -1;
	}
	bool isEmpty() const{
		if (top == -1) {
			return true;
		}
		return false;
	}
	bool isFull() const{
		if (bottom == MAX-1) {
			return true;
		}
		return false;
	}
	void push(int data) {
		if (isFull()) {
			cout << "stack is overFlow\n";
		}
		else if (isEmpty()) {
			bottom++;
			top++;
			arr[top] = data;
		}
		else {
			int i;
			bottom++;
			for (i = bottom; i > top; i--) {
				arr[i] = arr[i - 1];
			}
			arr[top] = data;
		}
	}
	void pop() {
		if (isEmpty()) {
			cout << "stack is underflow nothing to delete\n";
		}
		else if (top == bottom) {
			top = -1;
			bottom = -1;
		}
		else {
			top++;
		}
	}
	void showData() const{
		if (top == -1 && bottom == -1) {
			cout << "stack is empty\n";
			return;
		}
		for (int i = top; i <= bottom; i++) {
			cout << arr[i] << " ";	
		}
		cout << endl;
	}
	int peek() const{
		if (!isEmpty()) {
			return arr[top];
		}
		return -1;
	}
	int low() const{
		if (!isEmpty()) {
			return arr[bottom];
		}
		return -1;
	}
};

int main() {
	Stack stack1;
	stack1.pop();
	stack1.push(5);
	stack1.push(10);
	stack1.push(20);
	stack1.push(30);
	stack1.push(40);
	stack1.push(50);
	stack1.pop();
	stack1.showData();
	int Top = stack1.peek();
	cout << Top << endl;
	int Bottom = stack1.low();
	cout << Bottom << endl;
}

