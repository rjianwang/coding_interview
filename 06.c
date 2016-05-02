#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode
{
    int m_value;
    struct BinaryTreeNode* m_left;
    struct BinaryTreeNode* m_right;
};

struct BinaryTreeNode* constructCore(
    int *startPreorder, int *endPreorder,
    int *startInorder, int *endInorder)
{
	// 前序遍历，构造根结点
    struct BinaryTreeNode* root = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    root->m_value = startPreorder[0];
	root->m_left = NULL;
	root->m_right = NULL;

	// 迭代结束
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
		{
			printf("Invalid input.\n");
			return NULL;
		}
	}

	// 中序遍历找到根结点的值
	int *rootInorder = startInorder;
	while (rootInorder <= endInorder
			&& *rootInorder != root->m_value)
		++rootInorder;

	// 如在中序遍历中未找到前序遍历中的结点，退出
	if (rootInorder == endInorder && *rootInorder != root->m_value)
	{
		printf("Invalid input.\n");
		return NULL;
	}

	// 构建左子树
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		root->m_left = constructCore(startPreorder + 1,
				leftPreorderEnd, startInorder, rootInorder - 1);
	}

	// 构建右子树
	if (leftLength < endPreorder - startPreorder)
	{
		root->m_right  = constructCore(leftPreorderEnd + 1,
				endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

struct BinaryTreeNode* construct (int* preorder, int* inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0)
    {
        return NULL;
    }

    return constructCore(preorder, preorder + length - 1, inorder, inorder + length -1);
}

int main(int argc, char* argv[])
{
	//int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
	//int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
	int preorder[] = {1};
	int inorder[] = {1};
	construct(preorder, inorder, 1);

	return 0;
}
