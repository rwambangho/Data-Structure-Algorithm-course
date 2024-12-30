#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int value) : data(value), leftChild(nullptr), rightChild(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree(int number) {
        root = nullptr;
        createNodes(number);
        linkNodes(number);
    }

    void createNodes(int number) {
        for (int i = 1; i <= number; i++) {
            TreeNode* newNode = new TreeNode(i);
            nodes[i] = newNode;
        }
    }

    void linkNodes(int number) {
        for (int i = 1; i <= number; i++) {
            if (i % 2 == 0) {
                nodes[i / 2]->leftChild = nodes[i];
            }
            else {
                nodes[i / 2]->rightChild = nodes[i];
            }
        }
    }

    void inorderTraversal(TreeNode* ptr) {
        if (ptr) {
            inorderTraversal(ptr->leftChild);
            std::cout << ptr->data << ' ';
            inorderTraversal(ptr->rightChild);
        }
    }

    void performInorderTraversal() {
        inorderTraversal(root);
    }

private:
    TreeNode* nodes[100]; // Assuming a maximum of 100 nodes
};

int main() {
    int number;
    std::cin >> number;

    BinaryTree tree(number);
    tree.performInorderTraversal();

    return 0;
}