#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int value;
	struct ListNode *next;
};

struct ListNode* reverse(struct ListNode *head)
{
	if (head == NULL)
		return NULL;

	struct ListNode *ret = NULL;
	struct ListNode *p = head;
	struct ListNode *prev = NULL;
	while (p != NULL)
	{
		struct ListNode *next = p->next;
		if (next == NULL)
			ret = p;

		p->next = prev;
		prev = p;
		p = next;
	}
	return ret;
}

int main(int argc, char* argv[])
{
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p2 = (struct ListNode*)malloc(sizeof(struct ListNode));

	head->value = 1;
	head->next = p1;
	p1->value = 2;
	p1->next = p2;
	p2->value = 3;
	p2->next = NULL;

	printf("Before REVERSE:\t1\t2\t3\n");
	head = reverse(head);
	printf("After REVERSE:\t");
	while (head != NULL)
	{
		printf("%d\t", head->value);
		head = head->next;
	}
	printf("\n");

	free(head);
	free(p1);
	free(p2);

	return 0;
}
