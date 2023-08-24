#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
	int data;
	struct Node *left, *right;
};
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
int findMax(struct Node* root)
{
	if (root == NULL)
		return INT_MIN;

	int res = root->data;
	int lres = findMax(root->left);
	int rres = findMax(root->right);
	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;
	return res;
}
int findMin(struct Node* root)
{
	if (root == NULL)
		return INT_MAX;
	int res = root->data;
	int lres = findMin(root->left);
	int rres = findMin(root->right);
	if (lres < res)
		res = lres;
	if (rres < res)
		res = rres;
	return res;
}
int main(void)
{
	struct Node* NewRoot = NULL;
	struct Node* root = newNode(12);
	root->left = newNode(72);
	root->right = newNode(32);
	root->left->right = newNode(94);
	root->left->right->left = newNode(30);
	root->left->right->right = newNode(45);
	root->right->right = newNode(34);
	root->right->right->left= newNode(1);
	printf("Maximum element is %d \n", findMax(root));
	printf("Minimum element is %d \n", findMin(root));
	return 0;
}

