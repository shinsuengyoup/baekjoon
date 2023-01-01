#include <iostream>
using namespace std;

// Node
class Node {
    // 링크드 리스트에서 참조 private, proteced도 참조 가능하도록 frined 등록
    friend class LinkedList;
private:
    //생성자, 소멸자
    Node(){
        next = nullptr; // null 로 초기화
        prev = nullptr;
        data = 0;
    }
    ~Node(){}


private:
    int data;         // 변수저장
    Node* next;  // 다음 노드 주소 저장
    Node* prev;  // 이전 노드 주소 저장
};

//Linked List
class LinkedList {
public:
    LinkedList() {
        p_Begin = new NODE;
        p_End = new NODE;

        // 최초 생성 때는 추가된 노드가 없으니 시작과 끝을 연결한다.
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

    // 마지막 더미노드(p_End 노드)의 앞에 추가해야 하므로 p_End 노드의 바로 앞 노드를 가져온다.
    PNODE tmpPrev = p_End->prev;

    // 새로 추가한 노드와, 마지막 앞 노드와 연결
    tmpPrev->next = tmp;
    tmp->prev = tmpPrev;

    // 새로 추가한 노드와, 마지막 노드 연결
    tmp->next = p_End;
    p_End->prev = tmp;

    size++;
}
void LinkedList::push_front(int num) {
    PNODE tmp = new NODE;
    tmp->data = num;

    // 가장 앞 더미노드(p_begin 노드)의 뒤에 추가해야 하므로 p_begin 노드의 다음 노드를 가져온다.
    PNODE tmpNext = p_Begin->next;

    // 새로 추가한 노드와, 가장 앞 다음 노드와 연결
    tmpNext->prev = tmp;
    tmp->next = tmpNext;

    // 새로 추가한 노드와, 마지막 노드 연결
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
        cout << "ERROR : 데이터 삽입 실패, 삽입하고자 하는 인덱스가 리스트의 크기를 초과합니다." << endl;
    
        
}

void LinkedList::clear() {
    PNODE tmp = p_Begin->next;

    while (tmp != p_End) // 마지막이 아닐때 까지
    {
        PNODE next = tmp->next;

        delete tmp;

        tmp = next;
    }
    // 초기화
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
        cout << "ERROR : 데이터 삭제 실패, 리스트안에 데이터가 없습니다." << endl;
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
        cout << "ERROR : 데이터 삭제 실패, 삭제하고자 하는 인덱스가 리스트의 크기를 초과합니다." << endl;
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