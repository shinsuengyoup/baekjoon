#include<iostream>
using namespace std;

#define max_Size 100



class Queue {
public:	
	int front;
	int rear;
	int size;
	int* data;

public:
	Queue() {
		size = max_Size;
		data = new int[size];
		front = 0;
		rear = 0;
	}
	~Queue() {
		delete[] data;
	}

	void push(int _data);
	void pop();
	bool isEmpty();
	bool isFull();
	void printAll();

};

void Queue::push(int _data) {
	if (isFull()) {
		cout << "Queue에 데이터가 꽉 찼습니다." << endl;
	}
	else {
		data[rear] = _data;
		rear = (rear + 1) % size;
	}
	
}
void Queue::pop() {
	if (isEmpty()) {
		cout << "Queue에 데이터가 없습니다." << endl;
	}
	else
		front = (front + 1) % size;
}

bool Queue::isEmpty() {
	if (rear == front)
		return true;
	else
		return false;
}

bool Queue::isFull() {
	if (((rear + 1) % size) == front)
		return true;
	else
		return false;
}

void Queue::printAll() {

	int i = front;
	while (i != rear) {
		cout << data[i] << " ";
		i = (i + 1) % size;
	}
	cout << endl;
}

int main() {
	Queue que;
	que.pop();
	que.push(10);
	que.push(12);
	que.push(14);
	que.push(16);
	que.push(18);
	que.push(20);
	que.push(22);
	que.printAll();
	que.pop();
	que.pop();
	que.pop();
	que.printAll();
	

}


