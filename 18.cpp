#include <iostream>

struct BinaryTreeNode
{
	int 	value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

bool hasSubTreeCore(BinaryTreeNode *tree1, BinaryTreeNode *tree2)
{
	if (tree2 == NULL)	return true;
	if (tree1 == NULL)	return false;
	
	bool result = false;
	if (tree1->value == tree2->value)
	{
		result = hasSubTreeCore(tree1->left, tree2->left);
		if (result)
			result = hasSubTreeCore(tree1->right, tree2->right);
	}

	return result;
}

bool hasSubTree(BinaryTreeNode *tree1, BinaryTreeNode *tree2)
{
	if (tree1 == NULL)
		return false;
	if (tree2 == NULL)
		return true;

	bool result = false;
	if (tree1->value == tree2->value)
	{
		result = hasSubTreeCore(tree1, tree2);
	}
	if (!result)
		result = hasSubTree(tree1->left, tree2);
	if (!result)
		result = hasSubTree(tree1->right, tree2);

	return result;
};

int main(int argc, char* argv[])
{
	BinaryTreeNode *tree1 = new BinaryTreeNode;
	BinaryTreeNode *p1 = new BinaryTreeNode;
	BinaryTreeNode *p2 = new BinaryTreeNode;
	BinaryTreeNode *p3 = new BinaryTreeNode;
	BinaryTreeNode *p4 = new BinaryTreeNode;

	tree1->value = 1;
	tree1->left = p1;
	tree1->right = NULL;
	p1->value = 2;
	p1->left = p2;
	p1->right = p3;
	p2->value = 3;
	p2->left = NULL;
	p2->right = p4;
	p3->value = 4;
	p3->left = NULL;
	p3->right = NULL;
	p4->value = 5;
	p4->left = NULL;
	p4->right = NULL;

	BinaryTreeNode *tree2 = new BinaryTreeNode;
	BinaryTreeNode *q1 = new BinaryTreeNode;
	BinaryTreeNode *q2 = new BinaryTreeNode;

	tree2->value = 2;
	tree2->left = q1;
	tree2->right = q2;
	q1->value = 3;
	q1->left = NULL;
	q1->right = NULL;
	q2->value = 4;
	q2->left = NULL;
	q2->right = NULL;

	std::cout << hasSubTree(tree1, tree2) << std::endl;

	return 0;
}
