#include <iostream>
using namespace std;

// Node
class Node {

    friend class Stack;
private:
    //생성자, 소멸자
    Node() {
        next = nullptr; // null 로 초기화
        data = 0;
    }
    ~Node() {}


private:
    int data;         // 변수저장
    Node* next;  // 다음 노드 주소 저장
};


class Stack {
public:
    Stack() {
        p_End = new NODE;
        top = new NODE;

        top->next = p_End;
        size = 0;
    }
    ~Stack() {
        clear();
        delete p_End;
    }
private:
    typedef Node     NODE;
    typedef Node*    PNODE;

private:
    PNODE p_End;
    PNODE top;
    int size;

public:
    void push(int);
    void pop();
    void clear();
    void printAll();

};

void Stack::push(int num) {
    PNODE newNode = new NODE;
    newNode->next = top->next;
    newNode->data = num;
    top->next = newNode;
    size++;
}
void Stack::pop() {
    PNODE tmp = new NODE;
    tmp = top->next;
    top->next = tmp->next;
    delete tmp;
    size--;
}
void Stack::printAll() {
    PNODE tmp = top->next;

    while (tmp != p_End) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
    cout << "size : " << size << endl;
}

void Stack::clear() {
    PNODE tmp = top->next;

    while (tmp != p_End) // 마지막이 아닐때 까지
    {
        PNODE next = tmp->next;

        delete tmp;

        tmp = next;
    }
    // 초기화
    size = 0;
    top->next = p_End;
}

int main() {
    Stack stack;
    stack.push(5);
    stack.push(5);
    stack.push(3);
    stack.push(4);
    stack.push(7);
    stack.push(9);
    stack.push(15);
    stack.printAll();

    stack.pop();
    stack.pop();
    stack.printAll();
}