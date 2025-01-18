#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) (a)

typedef struct AVLNode {
	int key;
	struct AVLNode* left;
	struct AVLNode* right;

}AVLNode;

AVLNode* create_node(int key) {
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

AVLNode* insert(AVLNode* node, int key) {
	if (node == NULL) {
		return (create_node(key));
	}
	if (key == node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}
	else
		return node;
}

void preorder(AVLNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	AVLNode* root = NULL;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 60);
	root = insert(root, 70);

	printf("전위순회결과 \n");
	preorder(root);

	return 0;
}