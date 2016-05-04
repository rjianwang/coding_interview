#include <iostream>
#include <queue>

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void printTree(BinaryTreeNode *head)
{
	if (head == NULL)
		return;

	std::queue<BinaryTreeNode*> q;
	q.push(head);

	while (q.size() != 0)
	{
		BinaryTreeNode *temp = q.front();
		q.pop();
		
		std::cout << temp->value << "\t";

		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
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
	BinaryTreeNode *p5 = new BinaryTreeNode;

	head->value = 1;
	head->left = p1;
	head->right = p2;
	p1->value = 2;
	p1->left = p3;
	p1->right = p4;
	p2->value = 3;
	p2->left = NULL;
	p2->right = p5;
	p3->value = 4;
	p3->left = NULL;
	p3->right = NULL;
	p4->value = 5;
	p4->left = NULL;
	p4->right = NULL;
	p5->value = 6;
	p5->left = NULL;
	p5->right = NULL;

	printTree(head);

	return 0;
}
