#include <iostream>
#include <queue>

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

void mirrorOfBTree(BinaryTreeNode **head)
{
	if (*head == NULL)	return;

	if ((*head)->left == NULL && (*head)->right == NULL) return;

	BinaryTreeNode *p = (*head)->left;
	(*head)->left = (*head)->right;
	(*head)->right = p;

	mirrorOfBTree(&(*head)->left);
	mirrorOfBTree(&(*head)->right);
}

void printTree(BinaryTreeNode *head)
{
	if (head == NULL)	return;

	std::queue<BinaryTreeNode*>  q;
	q.push(head);
	while (!q.empty())
	{
		BinaryTreeNode *p = q.front();
		q.pop();

		std::cout << p->value << "\t";

		if (p->left != NULL) q.push(p->left);
		if (p->right != NULL) q.push(p->right);
	}
	std::cout << std::endl;
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
	p1->right = p4;
	p2->value = 3;
	p2->left = NULL;
	p2->right = NULL;
	p3->value = 4;
	p3->left = NULL;
	p3->right = NULL;
	p4->value = 5;
	p4->left = NULL;
	p4->right = NULL;

	std::cout << "Original Binary Tree:\t";
	printTree(head);
	mirrorOfBTree(&head);
	std::cout << "Mirror Of Binary Tree:\t";
	printTree(head);

	delete head;
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	return 0;
}
