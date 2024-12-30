#include <iostream>
#include <string>
using namespace std;
//이진트리 구현 = 한 노드에 왼쪽 노드와 오른쪽 노드가 존재하는 트리
class Tree {
    string data; //부모노드
    Tree* left, * right; //자식노드
public:
    Tree() { //받고 넣은 값은 초기화해줌
        data = ""; 
        left = NULL; 
        right = NULL; 
    }
    void setData(char data) { //입력받은 부모노드를 전달
        this->data = data; 
    }
    void setLeft(Tree* left) { //입력받은 왼쪽자식노드를 전달
        this->left = left; 
    }
    void setRight(Tree* right) { //입력받은 오른쪽자식노드를 전달
        this->right = right; 
    }
    void static preorder(Tree* root) { // 전위순회
        if (root) {
            cout << root->data; //루트노드 먼저방문
            preorder(root->left); //왼쪽노드 방문
            preorder(root->right); //오른쪽노드 방문
        }
    }
    void static inorder(Tree* root) { // 중위순회
        if (root) {
            inorder(root->left); //왼쪽노드 방문
            cout << root->data; //루트노드 방문
            inorder(root->right); //오른쪽 노드 방문
        }
    }
    void static postorder(Tree* root) { // 후위순회
        if (root) {
            postorder(root->left); //왼쪽노드 방문
            postorder(root->right); //오른쪽노드 방문
            cout << root->data; //루트노드 방문
        }
    }
};
int main() {
    int n;
    cin >> n; //트리의 노드 수를 입력받음
    Tree* tree = new Tree[n]; //노드 수 만큼 동적으로 트리 배열 할당
    for (int i = 0; i < n; ++i) {
        char data, left, right;
        cin >> data >> left >> right;
        if (data != '.') //부모노드를 넣고
            tree[(int)(data - 'A')].setData(data);
        //부모노드없인 자식노드는 없음
        if (left != '.') //왼쪽 자식이 있으면 왼쪽에 넣고
            tree[(int)(data - 'A')].setLeft(&tree[(int)(left - 'A')]); 

        else //.으로 입력받으면 NULL
            tree[(int)(data - 'A')].setLeft(NULL);

        if (right != '.') //오른쪽 자식이 있으면 오른쪽에 넣는다
            tree[(int)(data - 'A')].setRight(&tree[(int)(right - 'A')]);

        else //.으로 입력받으면 NULL
            tree[(int)(data - 'A')].setRight(NULL);
    }
    Tree* root = &tree[0]; //방문할 노드선언
   
    Tree::preorder(root);
    cout << endl;
    
    Tree::inorder(root);
    cout << endl;
    
    Tree::postorder(root);
    cout << endl;
}