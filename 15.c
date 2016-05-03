#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int value;
	struct ListNode* next;
};

struct ListNode* findKthToTail(struct ListNode* head, unsigned int k)
{
	if (head == NULL || k == 0)
		return NULL;

	struct ListNode *p1 = head;
	struct ListNode *p2 = head;
	
	for (int i = 0; i < k - 1; i++)
	{
		if (p2->next != NULL)
			p2 = p2->next;
		else
			return NULL;
	}

	while(p2->next != NULL)
	{
		p2 = p2->next;
		p1 = p1->next;
	}

	return p1;
}

int main(int argc, char* argv[])
{
	struct ListNode* head = (struct ListNode*)malloc(
			sizeof(struct ListNode));
	struct ListNode* p1 = (struct ListNode*)malloc(
			sizeof(struct ListNode));
	struct ListNode* p2 = (struct ListNode*)malloc(
			sizeof(struct ListNode));

	head->value = 1;
	head->next = p1;
	p1->value = 2;
	p1->next = p2;
	p2->value = 3;
	p2->next = NULL;

	struct ListNode *res = findKthToTail(head, 3);
	
	printf("List:            1\t2\t3\n");
	printf("The 3th to tail: %d\n", res->value);

	free(head);
	free(p1);
	free(p2);

	return 0;
}
