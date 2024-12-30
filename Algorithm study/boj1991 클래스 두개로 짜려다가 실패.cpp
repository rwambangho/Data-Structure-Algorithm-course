#include<iostream>
using namespace std;

class TreeNode { //�����������
public:
    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int value) : data(value), leftChild(NULL), rightChild(NULL) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree(int number) {
        root = nullptr;
    }

    //������ȸ
    void preorder(TreeNode* ptr) {
        cout << ptr->data;

        if (ptr->leftChild != NULL) {
            preorder(ptr->leftChild);
        }
        if (ptr->rightChild != NULL) {
            preorder(ptr->rightChild);
        }
    }
    //������ȸ
    void inorder(TreeNode* ptr) {
        if (ptr->leftChild != NULL) {
            inorder(ptr->leftChild);
        }

        cout << ptr->data;

        if (ptr->rightChild != NULL) {
            inorder(ptr->rightChild);
        }
    }

    //������ȸ
    void postorder(TreeNode* ptr) {
        if (ptr->leftChild != NULL) {
            postorder(ptr->leftChild);
        }
        if (ptr->rightChild != NULL) {
            inorder(ptr->rightChild);
        }
        cout << ptr->data;
    }
    void performPreorder() {
        preorder(root);
    }

    void performInorder() {
        inorder(root);
    }
    void performPostorder() {
        postorder(root);
    }
private:
    TreeNode* nodes[100];

};

int main() {
    int number;
    cin >> number;
    BinaryTree tree(number);

    TreeNode* nodes = new TreeNode[number + 1];

    for (int i = 0; i < number; i++) {
        char parent, left, right;

        cin >> parent >> left >> right; //�θ���, �����ڽĳ��, �������ڽĳ��
        nodes[(int)(parent - 'A')].data = parent;

        if (left != '.') { //�����ڽ��� ������ 
            nodes[(int)(parent - 'A')].leftChild = &nodes[(int)left - 'A'];
        }
        if (right != '.') { //�������ڽ��� ������
            nodes[(int)(parent - 'A')].rightChild = &nodes[(int)right - 'A'];
        }
    }
    //TreeNode* root = &nodes[0];


    tree.performPreorder();
    cout << endl;
    tree.performInorder();
    cout << endl;
    tree.performPostorder();
    cout << endl;


    return 0;
}