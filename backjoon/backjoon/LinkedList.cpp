#include <iostream>
using namespace std;

// Node
class Node {
    // ��ũ�� ����Ʈ���� ���� private, proteced�� ���� �����ϵ��� frined ���
    friend class LinkedList;
private:
    //������, �Ҹ���
    Node(){
        next = nullptr; // null �� �ʱ�ȭ
        prev = nullptr;
        data = 0;
    }
    ~Node(){}


private:
    int data;         // ��������
    Node* next;  // ���� ��� �ּ� ����
    Node* prev;  // ���� ��� �ּ� ����
};

//Linked List
class LinkedList {
public:
    LinkedList() {
        p_Begin = new NODE;
        p_End = new NODE;

        // ���� ���� ���� �߰��� ��尡 ������ ���۰� ���� �����Ѵ�.
        p_Begin->next = p_End;  
        p_End->prev = p_Begin;
        size = 0;
    }
    ~LinkedList() {
        clear();
        delete p_Begin;
        delete p_End;
    }
private:
    typedef Node     NODE;
    typedef Node*    PNODE;
   
private:
    PNODE p_Begin;
    PNODE p_End;    
    int size;


    
public:
    void push_back(int);
    void push_front(int);
    void push(int, int);
    void clear();
    void pop_back();
    void pop(int);
    void printAll();
    int getSize();
};

void LinkedList::push_back(int num) {
    PNODE tmp = new NODE;
    tmp->data = num;

    // ������ ���̳��(p_End ���)�� �տ� �߰��ؾ� �ϹǷ� p_End ����� �ٷ� �� ��带 �����´�.
    PNODE tmpPrev = p_End->prev;

    // ���� �߰��� ����, ������ �� ���� ����
    tmpPrev->next = tmp;
    tmp->prev = tmpPrev;

    // ���� �߰��� ����, ������ ��� ����
    tmp->next = p_End;
    p_End->prev = tmp;

    size++;
}
void LinkedList::push_front(int num) {
    PNODE tmp = new NODE;
    tmp->data = num;

    // ���� �� ���̳��(p_begin ���)�� �ڿ� �߰��ؾ� �ϹǷ� p_begin ����� ���� ��带 �����´�.
    PNODE tmpNext = p_Begin->next;

    // ���� �߰��� ����, ���� �� ���� ���� ����
    tmpNext->prev = tmp;
    tmp->next = tmpNext;

    // ���� �߰��� ����, ������ ��� ����
    tmp->prev = p_Begin;
    p_Begin->next = tmp;

    size++;
}

void LinkedList::push(int num, int index) {

    PNODE tmpNext = p_Begin->next;
    PNODE tmp = new NODE;

    if (getSize() >= index) {
        for (int i = 0; i < index - 1; i++) {
            tmpNext = tmpNext->next;
        }
        tmp->data = num;
        tmp->prev = tmpNext->prev;
        tmp->next = tmpNext->prev->next;
        tmpNext->prev = tmp;
        tmp->prev->next = tmp;
        size++;
    }
    else
        cout << "ERROR : ������ ���� ����, �����ϰ��� �ϴ� �ε����� ����Ʈ�� ũ�⸦ �ʰ��մϴ�." << endl;
    
        
}

void LinkedList::clear() {
    PNODE tmp = p_Begin->next;

    while (tmp != p_End) // �������� �ƴҶ� ����
    {
        PNODE next = tmp->next;

        delete tmp;

        tmp = next;
    }
    // �ʱ�ȭ
    size = 0;
    p_Begin->next = p_End;
    p_End->prev = p_Begin;
}

void LinkedList::pop_back() {
    if (p_Begin->next != p_End) {
        PNODE tmp = p_End->prev;

        tmp->prev->next = p_End;
        p_End->prev = tmp->prev;

        delete tmp;
        size--;
    }
    else
        cout << "ERROR : ������ ���� ����, ����Ʈ�ȿ� �����Ͱ� �����ϴ�." << endl;
}

void LinkedList::pop(int index) {
    PNODE tmpNext = p_Begin->next;
    if (getSize() >= index) {
        for (int i = 0; i < index - 1; i++) {
            tmpNext = tmpNext->next;
        }
        tmpNext->prev->next = tmpNext->next;
        tmpNext->next->prev = tmpNext->prev;
        delete tmpNext;
        size--;
    }
    else
        cout << "ERROR : ������ ���� ����, �����ϰ��� �ϴ� �ε����� ����Ʈ�� ũ�⸦ �ʰ��մϴ�." << endl;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::printAll() {

    PNODE tmp = p_Begin->next;

    while (tmp != p_End) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
    cout << "size : " << size << endl;
}




int main()
{
    LinkedList list;
    list.pop_back();
    list.push_back(5);
    list.push_back(4);
    list.push_back(9);
    list.push_back(7);
    list.printAll();

    list.push(1, 2);
    list.printAll();

    list.pop_back();
    list.printAll();
    
    list.pop(2);
    list.printAll();
    return 0;
}