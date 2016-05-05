#include <iostream>

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

int depthOfTree(BinaryTreeNode *head)
{
	if (head == NULL)
		return 0;
	int d_left = 0, d_right = 0;

	d_left = depthOfTree(head->left) + 1;
	d_right = depthOfTree(head->right) + 1;

	return d_left > d_right ? d_left : d_right;
}

int main(int argc, char* argv[])
{
	BinaryTreeNode *head = new BinaryTreeNode;
	BinaryTreeNode *p1 = new BinaryTreeNode;
	BinaryTreeNode *p2 = new BinaryTreeNode;
	BinaryTreeNode *p3 = new BinaryTreeNode;
	BinaryTreeNode *p4 = new BinaryTreeNode;

	head->value = 1;
	head->left = p1;
	head->right = p2;
	p1->value = 2;
	p1->left = p3;
	p1->right = NULL;
	p2->value = 3;
	p2->left = NULL;
	p2->right = NULL;
	p3->value = 4;
	p3->left = p4;
	p3->right = NULL;
	p4->value = 5;
	p4->left = NULL;
	p4->right = NULL;

	std::cout << depthOfTree(head) << std::endl;

	return 0;
}
