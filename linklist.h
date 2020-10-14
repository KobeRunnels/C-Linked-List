#include <stdio.h>
#include <stdlib.h>

// array with elements holding a value and a pointer to another element

struct Node
{
	int element;
	struct Node * next;
} Node_default = {0,NULL};

struct LinkedList
{
	int length;
	struct Node holder;
} LinkedList_default = {0,(struct Node){0,NULL}};

void addToList(struct LinkedList * input, int value)
{
	int x;
	struct Node * lhand;	
	struct Node * rhand;

	if(input->length == 0)
	{
		input->holder.element = value;	
	}
	else if(input->length == 1)
	{
		input->holder.next = (struct Node*)malloc(sizeof(struct Node));
		input->holder.next->element = value;
		input->holder.next->next = (struct Node*)malloc(sizeof(struct Node));
	}
	else
	{
		for(x=0;x<input->length;x++)
		{
			if(x==0)
			{
				lhand = &input->holder;
			}
			else
			{
				rhand = lhand->next;
				lhand = rhand;
			}		
		}	
		lhand->next = (struct Node*)malloc(sizeof(struct Node));
		*lhand->next = (struct Node){value,NULL};
	}
	input->length++;
}

int removeAt(struct LinkedList * input, int pos)
{
	struct LinkedList * copy;
	struct Node * hand;
	struct Node *grab = &input->holder;
	struct Node *nextGrab;
	int x;
	for(x=0;x<input->length;x++)
	{
		if(x==pos)
		{
			hand = grab;
		}
		else
		{
			addToList(copy,grab->element);
			nextGrab = hand->next;
			hand = nextGrab;
		}
	}
	return hand->element;
}

void print(struct LinkedList * input)
{
	int x;
	struct Node * hand;	
	struct Node * lhand;	
	hand = &input->holder;
	for(x=0;x<input->length;x++)
	{
		printf("\n%d",hand->element);
		lhand = hand->next;
		hand = lhand;
	}
}

int get(struct LinkedList * input,int pos)
{
	int x;
	struct Node * hand = &input->holder;	
	struct Node * lhand;
	if(pos < input->length)
	{
		for(x=0;x<pos;x++)
		{
			lhand = hand->next;
			hand = lhand;
		}
	}
	return hand->element;
}

