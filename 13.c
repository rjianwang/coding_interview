#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int value;
	struct ListNode* next;
};

// delete the node in the list
void delete_node(struct ListNode** head, struct ListNode* node)
{
	if (head == NULL || node == NULL)
		return;

	if (node->next != NULL)
	{
		struct ListNode* p = node->next;

		node->value = p->value;
		node->next = p->next;

		free(p);
		p = NULL;
	}
	else if (*head == node)
	{
		free(node);
		head = NULL;
		node = NULL;
	}
	else
	{
		struct ListNode *p = *head;
		while (p->next != node)
		{
			p = p->next;
		}

		p->next = NULL;
		free(node);
		node = NULL;
	}
}

int main(int argc, char* argv[])
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(
				struct ListNode));
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(
				struct ListNode));
	struct ListNode* p2 = (struct ListNode*)malloc(sizeof(
				struct ListNode));
	head->value = 1;
	head->next = p1;
	p1->value = 2;
	p1->next = p2;
	p2->value = 3;
	p2->next = NULL;

	//delete_node(&head, p1);	
	//delete_node(&head, p2);	
	delete_node(&head, head);	
	printf("delete_node p1: ");
	while (head != NULL)
	{
		printf("%d\t", head->value);
		head = head->next;
	}

	printf("\n");

	return 0;
}
