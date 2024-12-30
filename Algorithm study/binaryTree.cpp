#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct TreeNode {
	struct TreeNode* left;
	element key;
	struct TreeNode* right;
}TreeNode;
#define max(a, b) ((a) > (b) ? (a) : (b))
TreeNode* search(TreeNode* node, int key){ //��ȯ���� Ž���Լ�
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode)); //�����Ҵ�
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	//�޸��Ҵ�, ��屸��
	if(node==NULL) return new_node(key); //(1) 100�� ���Ϲ޾Ƽ�
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
	if (key < root->key) { //Ű�� ��Ʈ���� ������ ���ʼ���Ʈ����
		root->left = delete_node(root->left, key);
	}
	else if (key > root->key) { //Ű�� ��Ʈ���� ũ�� �����ʼ���Ʈ����
		root->right = delete_node(root->right, key);
	}
	else { //������ key�� �������
		//case1) ������ 0�� ��� 10�� ���� ��
		//case2) ������ 1�� ��� 40�� ���� ��
		//case3? ������ 2�� ��� 30�� ���� ��
		if (root->left == NULL) { //������ 0�̰ų� �����ʳ�带 ���� �ִٸ�
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) { //������ 0�̰ų� ���ʳ�带 ���� �ִٸ�
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// ���ʰ� ������ ��带 ��� ���� �ִٸ�
		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key; // ��Ʈ��带 ��ü�Ѵ�
		root->right = delete_node(root->right, temp->key); // ������ ��Ʈ��带 �����Ѵ�
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

int calc_dir_size(TreeNode* root) { //���丮 �뷮 ���
	int left_size, right_size;
	if (root == NULL) return 0;

	left_size = calc_dir_size(root->left);
	right_size = calc_dir_size(root->right);
	return (root->key + left_size + right_size);
}

int get_node_count(TreeNode* node) { //����� ����
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

int get_height(TreeNode* node) { //����� ����
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}




int main() {
	TreeNode* root = NULL;


	root = insert_node(root, 30); //(2) 30�� �����Ѱ�
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
	printf("���丮�� ũ��=%d\n", calc_dir_size(root));
	printf("����� ��=%d\n", get_node_count(root));
	printf("����� ����=%d\n", get_height(root));

	return 0;
}
