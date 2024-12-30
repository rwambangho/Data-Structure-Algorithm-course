#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct TreeNode {
	struct TreeNode* left;
	element key;
	struct TreeNode* right;
}TreeNode;
#define max(a, b) ((a) > (b) ? (a) : (b))
TreeNode* search(TreeNode* node, int key){ //순환적인 탐색함수
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode)); //동적할당
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	//메모리할당, 노드구성
	if(node==NULL) return new_node(key); //(1) 100을 리턴받아서
	if (key < node->key) {
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert_node(node->right, key);
	}
	return node;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	if (key < root->key) { //키가 루트보다 작으면 왼쪽서브트리로
		root->left = delete_node(root->left, key);
	}
	else if (key > root->key) { //키가 루트보다 크면 오른쪽서브트리로
		root->right = delete_node(root->right, key);
	}
	else { //삭제할 key와 같은경우
		//case1) 차수가 0인 경우 10을 삭제 시
		//case2) 차수가 1인 경우 40을 삭제 시
		//case3? 차수가 2인 경우 30을 삭제 시
		if (root->left == NULL) { //차수가 0이거나 오른쪽노드를 갖고 있다면
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) { //차수가 0이거나 왼쪽노드를 갖고 있다면
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 왼쪽과 오른쪽 노드를 모두 갖고 있다면
		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key; // 루트노드를 교체한다
		root->right = delete_node(root->right, temp->key); // 기존의 루트노드를 삭제한다
	}
	return root;
}

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode* root){
	if (root != NULL) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

int calc_dir_size(TreeNode* root) { //디렉토리 용량 계산
	int left_size, right_size;
	if (root == NULL) return 0;

	left_size = calc_dir_size(root->left);
	right_size = calc_dir_size(root->right);
	return (root->key + left_size + right_size);
}

int get_node_count(TreeNode* node) { //노드의 개수
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

int get_height(TreeNode* node) { //노드의 높이
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}




int main() {
	TreeNode* root = NULL;


	root = insert_node(root, 30); //(2) 30에 저장한것
	root = insert_node(root, 20); 
	root = insert_node(root, 40);
	root = insert_node(root, 10);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	root = insert_node(root, 45);


	inorder(root);
	printf("\n");

	root = delete_node(root, 10);
	inorder(root);
	printf("\n");
	printf("디렉토리의 크기=%d\n", calc_dir_size(root));
	printf("노드의 수=%d\n", get_node_count(root));
	printf("노드의 높이=%d\n", get_height(root));

	return 0;
}
