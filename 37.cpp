#include <iostream>

struct ListNode
{
	int value;
	ListNode *next;
};

ListNode* firstCommonNode(ListNode *head1, ListNode *head2)
{
	if (head1 == NULL || head2 == NULL)
		return NULL;

	int length1 = 0, length2 = 0;
	ListNode *p = head1, *q = head2;
	while (p != NULL)
	{
		p = p->next;
		length1++;
	}
	while (q != NULL)
	{
		q = q->next;
		length2++;
	}

	int diff = length1 - length2;
	p = head1;
	q = head2;
	if (length2 > length1)
	{
		p = head2;
		q = head1;
		diff = length2 - length1;
	}

	for (int i = 0; i < diff; i++)
		p = p->next;

	while (p != NULL && q != NULL)
	{
		if (p->value == q->value)
			return p;
		p = p->next;
		q = q->next;
	}

	return NULL;
}

int main(int argc, char* argv[])
{
	ListNode *head1 = new ListNode;
	ListNode *p1 = new ListNode;
	ListNode *p2 = new ListNode;
	ListNode *p3 = new ListNode;

	head1->value = 1;
	head1->next = p1;
	p1->value = 2;
	p1->next = p2;
	p2->value = 3;
	p2->next = p3;
	p3->value = 4;
	p3->next = NULL;

	ListNode *head2 = new ListNode;
	head2->value = -1;
	head2->next = p2;

	std::cout << firstCommonNode(head1, head2)->value << std::endl;

	return 0;
}
