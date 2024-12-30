#include <iostream>
#include <string>
using namespace std;
//����Ʈ�� ���� = �� ��忡 ���� ���� ������ ��尡 �����ϴ� Ʈ��
class Tree {
    string data; //�θ���
    Tree* left, * right; //�ڽĳ��
public:
    Tree() { //�ް� ���� ���� �ʱ�ȭ����
        data = ""; 
        left = NULL; 
        right = NULL; 
    }
    void setData(char data) { //�Է¹��� �θ��带 ����
        this->data = data; 
    }
    void setLeft(Tree* left) { //�Է¹��� �����ڽĳ�带 ����
        this->left = left; 
    }
    void setRight(Tree* right) { //�Է¹��� �������ڽĳ�带 ����
        this->right = right; 
    }
    void static preorder(Tree* root) { // ������ȸ
        if (root) {
            cout << root->data; //��Ʈ��� �����湮
            preorder(root->left); //���ʳ�� �湮
            preorder(root->right); //�����ʳ�� �湮
        }
    }
    void static inorder(Tree* root) { // ������ȸ
        if (root) {
            inorder(root->left); //���ʳ�� �湮
            cout << root->data; //��Ʈ��� �湮
            inorder(root->right); //������ ��� �湮
        }
    }
    void static postorder(Tree* root) { // ������ȸ
        if (root) {
            postorder(root->left); //���ʳ�� �湮
            postorder(root->right); //�����ʳ�� �湮
            cout << root->data; //��Ʈ��� �湮
        }
    }
};
int main() {
    int n;
    cin >> n; //Ʈ���� ��� ���� �Է¹���
    Tree* tree = new Tree[n]; //��� �� ��ŭ �������� Ʈ�� �迭 �Ҵ�
    for (int i = 0; i < n; ++i) {
        char data, left, right;
        cin >> data >> left >> right;
        if (data != '.') //�θ��带 �ְ�
            tree[(int)(data - 'A')].setData(data);
        //�θ������ �ڽĳ��� ����
        if (left != '.') //���� �ڽ��� ������ ���ʿ� �ְ�
            tree[(int)(data - 'A')].setLeft(&tree[(int)(left - 'A')]); 

        else //.���� �Է¹����� NULL
            tree[(int)(data - 'A')].setLeft(NULL);

        if (right != '.') //������ �ڽ��� ������ �����ʿ� �ִ´�
            tree[(int)(data - 'A')].setRight(&tree[(int)(right - 'A')]);

        else //.���� �Է¹����� NULL
            tree[(int)(data - 'A')].setRight(NULL);
    }
    Tree* root = &tree[0]; //�湮�� ��弱��
   
    Tree::preorder(root);
    cout << endl;
    
    Tree::inorder(root);
    cout << endl;
    
    Tree::postorder(root);
    cout << endl;
}