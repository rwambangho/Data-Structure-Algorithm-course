#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) (a)

typedef struct AVLNode {
	int key;
	struct AVLNode* left;
	struct AVLNode* right;

}AVLNode;

int get_height(AVLNode* node) { //트리의 높이 반환
	int height = 0;
	if (node != NULL)
		height = 1 + MAX(get_height(node->left), get_height(node->right));

	return height;
}

int get_balance(AVLNode* node) { //노드의 균형인수를 반환
	if (node == NULL) return 0;

	return get_height(node->left) - get_height(node->right);
}

AVLNode* create_node(int key) { //노드를 동적으로 생성
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

AVLNode* rotate_right(AVLNode* parent) { //오른쪽으로 회전
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	return child;
}

AVLNode* rotate_left(AVLNode* parent) { //왼쪽으로 회전
	AVLNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;

	return child;
}



AVLNode* insert(AVLNode* node, int key) {
	if (node == NULL) {
		return (create_node(key));
	}
	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}
	else
		return node;

	int balance = get_balance(node);

	if (balance > 1 && key < node->left->key) { //LL타입 처리
		return rotate_right(node);
	}
	if (balance < -1 && key > node->right->key) { //RR타입 처리
		return rotate_left(node);
	}
	if (balance > 1 && key > node->left->key) { //LR타입처리
		node->left = rotate_right(node->left);
		return rotate_right(node);
	}
	if (balance < -1 && key < node->right->key) { //RL타입 처리
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
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
	root = insert(root, 29);


	printf("전위순회결과 \n");
	preorder(root);

	return 0;
}