#include<iostream>
using namespace std;


// Node
class Node {
    // 바이너리 트리에서 참조 private, proteced도 참조 가능하도록 frined 등록
    friend class BinaryTree;
private:
    //생성자, 소멸자
    Node(int _data) {
        left = nullptr; // null 로 초기화
        right = nullptr;
        data = _data;
    }
    ~Node() {}


public:
    int data;         // 변수저장
    Node* left;  // 왼쪽 노드
    Node* right;  // 오른쪽 노드
};

class BinaryTree {
public:
    BinaryTree(int _data) {
        p_root = new NODE(_data);
        p_root->left = nullptr;
        p_root->right = nullptr;
        size = 0;
    }
    ~BinaryTree() {
        delete p_root;
    }
private:
    typedef Node     NODE;
    typedef Node*   PNODE;

public:
    PNODE p_root;
    int size;



public:
    Node* SearchData(Node* tree, int _data);
    Node* insertData(Node* tree, int data);
    Node* min_value_node(Node* tree);
    Node* delete_node(Node* tree, int key);
};

Node* BinaryTree::SearchData(Node* tree, int _data) {
    if (tree == nullptr) {
        cout << "데이터 못 찾았다.." << endl;
        return nullptr;
    }
    if (tree->data == _data) {
        cout << "데이터 찾았다 : " << tree->data<< endl;
        return tree;
    }
    else {
        if (tree->data > _data) {
            return SearchData(tree->left, _data);
        }
            
        else if (tree->data < _data) {
            return SearchData(tree->right, _data);
        }
            
    }
}
Node* BinaryTree::min_value_node(Node* node)
{
    Node* current = node;
    // 맨 왼쪽 단말 노드를 찾으러 내려감
    while (current->left != NULL)
        current = current->left;
    return current;
}
Node* BinaryTree::delete_node(Node* tree, int data) { // data 노드 삭제 후 루트 반환
    if (tree == NULL) return tree;
    if (data < tree->data) 			// 키가 루트보다 작으면 왼쪽 서브 트리에 있음
        tree->left = delete_node(tree->left, data);
    else if (data > tree->data) 		// 키가 루트보다 크면 오른쪽 서브 트리에 있음
        tree->right = delete_node(tree->right, data);
    else {				// 키가 루트와 같으면 이 노드를 삭제함
        if (tree->left == NULL) {	// (1) or (2)
            Node* temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL) {	// (1) or (2)
            Node* temp = tree->left;
            free(tree);
            return temp;
        }

        Node* temp = min_value_node(tree->right); 		// (3)
        tree->data = temp->data; 				// 직후 키 복사
        tree->right = delete_node(tree->right, temp->data); 	// 직후 노드 삭제
    }
    return tree;
}

Node* BinaryTree::insertData(Node* tree, int _data) {
    if (tree == nullptr) return new Node(_data);
    
    if (tree->data > _data) 
        tree->left = insertData(tree->left, _data);
    else if (tree->data < _data)
        tree->right = insertData(tree->right, _data);

    return tree;
}





int main() {
    BinaryTree bt(10);
    bt.insertData(bt.p_root,8);
    bt.insertData(bt.p_root, 6);
    bt.insertData(bt.p_root, 15);
    bt.insertData(bt.p_root, 7);
    bt.SearchData(bt.p_root, 7);
    bt.delete_node(bt.p_root,7);
    bt.SearchData(bt.p_root, 7);
    bt.SearchData(bt.p_root, 6);
    bt.SearchData(bt.p_root, 8);


}