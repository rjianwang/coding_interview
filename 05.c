#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int value;
	struct ListNode* next;
};

void reverse_print(struct ListNode* head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
	{
		reverse_print(head->next);
	}
	printf("%d\n", head->value);
}

int main(int argc, char* argv[])
{
	struct ListNode *head = NULL;

	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));;
	p1->value = 1;
	p2->value = 2;
	p3->value = 3;

	head = p1;
	p1->next = p2;
	p2->next = p3;
	
	reverse_print(head);

	return 0;
}
