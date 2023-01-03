#include<iostream>
using namespace std;


// Node
class Node {
    // ���̳ʸ� Ʈ������ ���� private, proteced�� ���� �����ϵ��� frined ���
    friend class BinaryTree;
private:
    //������, �Ҹ���
    Node(int _data) {
        left = nullptr; // null �� �ʱ�ȭ
        right = nullptr;
        data = _data;
    }
    ~Node() {}


public:
    int data;         // ��������
    Node* left;  // ���� ���
    Node* right;  // ������ ���
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
        cout << "������ �� ã�Ҵ�.." << endl;
        return nullptr;
    }
    if (tree->data == _data) {
        cout << "������ ã�Ҵ� : " << tree->data<< endl;
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
    // �� ���� �ܸ� ��带 ã���� ������
    while (current->left != NULL)
        current = current->left;
    return current;
}
Node* BinaryTree::delete_node(Node* tree, int data) { // data ��� ���� �� ��Ʈ ��ȯ
    if (tree == NULL) return tree;
    if (data < tree->data) 			// Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� ����
        tree->left = delete_node(tree->left, data);
    else if (data > tree->data) 		// Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� ����
        tree->right = delete_node(tree->right, data);
    else {				// Ű�� ��Ʈ�� ������ �� ��带 ������
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
        tree->data = temp->data; 				// ���� Ű ����
        tree->right = delete_node(tree->right, temp->data); 	// ���� ��� ����
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