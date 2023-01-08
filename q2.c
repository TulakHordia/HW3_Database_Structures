#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node* next;
}NODE;

NODE* Reorder(NODE* head);
void ReorderAgain(NODE** head);
void printLists(NODE* headNode);

int main();

NODE* Reorder(NODE* head)
{
    NODE* oddNumbersListNode = NULL;
    NODE* oddNumbersList = NULL;

    NODE* evenNumbersListNode = NULL;
    NODE* evenNumbersList = NULL;

    while (head != NULL)
    {
        if (head->key % 2 != 0) // Check if odd
        {
            if (!oddNumbersListNode) //Create the list
            {
                oddNumbersListNode = (NODE*)malloc(sizeof(NODE)); //allocate mem
                oddNumbersListNode->key = head->key; //put the odd key into the list
                oddNumbersListNode->next = NULL; // set the next one as NULL
                oddNumbersList = oddNumbersListNode; // add the whole Node to the oddNumbersList
            }
            else //If list has already been created
            {
                oddNumbersList->next = (NODE*)malloc(sizeof(NODE)); //Allocate next node
                oddNumbersList = oddNumbersList->next; //Set next node as current node
                oddNumbersList->key = head->key; //place the odd number into oddNumbersList
                oddNumbersList->next = NULL; //set next node as NULL
            }
        }
        else //if even
        {
            if (!evenNumbersListNode) //Create the list, same process as odd numbers
            {
                evenNumbersListNode = (NODE*)malloc(sizeof(NODE));
                evenNumbersListNode->key = head->key;
                evenNumbersListNode->next = NULL;
                evenNumbersList = evenNumbersListNode;
            }
            else
            {
                evenNumbersList->next = (NODE*)malloc(sizeof(NODE));
                evenNumbersList = evenNumbersList->next;
                evenNumbersList->key = head->key;
                evenNumbersList->next = NULL;
            }
        }
        head = head->next;
    }

    oddNumbersList->next = evenNumbersListNode; //add the even numbers after the odd ones
    return oddNumbersListNode; //return the initial list back
}



void printLists(NODE* headNode)
{
    while (headNode != NULL)
    {
        printf("%d, ",headNode->key);
        headNode = headNode->next;
    }
    printf("\n");
}

int main()
{
    NODE* oldListNode = NULL;
    NODE* newListNode;

    for (int i = 9; i >= 1; i--) {
        newListNode = (NODE*)malloc(sizeof(NODE));
        if (!newListNode) {
            free(newListNode);
        }
        newListNode->key = i;
        newListNode->next = oldListNode;
        oldListNode = newListNode;
    }

    printLists(oldListNode);
    newListNode = Reorder(oldListNode);
    printLists(newListNode);

    ReorderAgain(&oldListNode);
    printLists(&oldListNode);
}

void ReorderAgain(NODE** head)
{
    int currentKey;
    NODE* headPointer = *head;
    NODE* previousNode;
    NODE* evenHead = NULL;
    NODE* evenTail = NULL;
    NODE* oddHead = NULL;
    NODE* oddTail = NULL;
    if (headPointer == NULL)
    {
        return;
    }
    while (headPointer != NULL)
    {
        currentKey = headPointer->key; //store current i
        previousNode = headPointer; //set prevNode as current node
        headPointer = headPointer->next; //forward current node

        if (currentKey % 2 != 0) //odd
        {
            if (oddTail == NULL) //first time, if no odd values set
            {
                oddTail = previousNode; //set the tail as current node
                oddHead = oddTail; //set head to tail
            }
            else //if theres already a tail
            {
                oddTail->next = previousNode; //set next tail as current node
                oddTail = oddTail->next; //forward tail
            }
        }
        else //even
        {
            if (evenTail == NULL) //first time, if no even values set
            {
                evenTail = previousNode; //set tail as current node
                evenHead = evenTail; //set head to tail
            }
            else
            {
                evenTail->next = previousNode; //set next tail as current node
                evenTail = evenTail->next; //forward tail
            }
        }
    }
    //now unite the nodes
    if (oddTail != NULL) //if there are odd values
    {
        oddTail->next = evenHead;
        *head = evenHead;
        if (evenTail != NULL) //if there are even values
        {
            evenTail->next = NULL;
        }
    }
    else //if there are no odd values, just put the even values in
    {
        *head = evenHead;
    }
}