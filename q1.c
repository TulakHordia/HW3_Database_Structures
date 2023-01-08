#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int queueinfo;

typedef struct node
{
	queueinfo value;
	struct node* next;
} QueueNode;

QueueNode* createQueue(); //Creates an empty queue
int isEmptyQueue(QueueNode* Q); //Returns 1 if the queue is empty, 0 if not
void insert(QueueNode** Q, queueinfo x); //inserts item X at the rear of the queue Q
void delAfter(QueueNode* p, queueinfo* x); //deletes the node after node p from the list, and stores its contents in x.
void printQueue(QueueNode* Q); //prints the contents of the queue
void q2Pick(); //The picking procedure itself.
void main(); //Main.

QueueNode* createQueue()
{
	return NULL;
}

int isEmptyQueue(QueueNode* Q)
{
	if (!Q)
	{
		return 1;
	}
	return 0;
}

void insert(QueueNode** Q, queueinfo x)
{
	QueueNode* temp;
	temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (!temp)
	{
		return;
	}
	temp->value = x;
	if (isEmptyQueue((*Q)))
	{
		(*Q) = temp;
	}
	else
	{
		temp->next = (*Q)->next;
	}
	(*Q)->next = temp;
	(*Q) = temp;
}

void delAfter(QueueNode* p, queueinfo* x)
{
	QueueNode* q;
	if (p == NULL)
	{
		printf("ERROR\n"); //the list is empty
	}
	if (p == p->next)
	{
		printf("ERROR\n");
	}
	else {
		q = p->next;
		*x = q->value;
		p->next = q->next;
		free(q);
	}
}

void printQueue(QueueNode* Q)
{
	QueueNode* p = Q->next;
	while (p != Q)
	{
		printf("%d ", p->value);
		p = p->next;
	}
	printf("%d ", p->value);
}

void q2Pick() {

	//Variables init.
	int n, k, i, soldierNumber;
	QueueNode* theNode = NULL;

	//Input from user.
	printf("Enter amount of soldiers:\n");
	scanf("%d", &n);
	printf("Enter count value:\n");
	scanf("%d", &k);

	//Insert values
	for (i = 1; i <= n; i++)
	{
		insert(&theNode, i);
	}

	//Do the elimination proccess
	printf("Order of elimination:\n");
	while (theNode->next != theNode)
	{
		for (i = 1; i < k; i++)
		{
			theNode = theNode->next;
		}
		//Delete whats not necessary.
		delAfter(theNode, &soldierNumber);
		printf("%d ", soldierNumber);
	}

	//Print the last one standing.
	printf("\n");
	printf("The last one standing: %d.\n", theNode->value);

	//Free the memory.
	free(theNode);
}

void main()
{
	q2Pick();
}
