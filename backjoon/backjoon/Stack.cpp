#include<iostream>
using namespace std;

#define MaxSize 100
#define TopDefalt -1

// 정적 Stack
class Stack {
private:
	int top;
	int stack[MaxSize] = {0,};
public:
	Stack() {
		top = TopDefalt;
	}
	~Stack() {
	}
	void push(int);
	void pop();
	void printAll();
	void Clear();
	bool isEmpty();
};

bool Stack::isEmpty() {
	return top >= MaxSize ? true : false;
}
void Stack::push(int num) {
	if (isEmpty() == false) {
		top++;
		stack[top] = num;
	}
	else
		cout << "Stack의 size가 최대치 입니다.";
}
void Stack::pop() {
	if (top > TopDefalt)
		top--;
	else
		cout << "Stack의 size가 0입니다.";
}
void Stack::printAll() {
	if (top > TopDefalt) {
		for (int i = 0; i < top + 1; i++) {
			cout << stack[i] << " ";
		}
		cout << endl;
	}
	else
		cout << "Stack의 size가 0입니다.";
	
}
void Stack::Clear() {
	top = TopDefalt;
}



int main()
{
	Stack stack;
	stack.push(5);
	stack.push(15);
	stack.push(74);
	stack.push(92);
	stack.push(8);
	stack.push(97);
	stack.printAll();
	stack.pop();
	stack.printAll();
	stack.Clear();
	stack.printAll();







	return 0;
}