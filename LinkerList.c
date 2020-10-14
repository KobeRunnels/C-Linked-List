#include "linklist.h"

int main()
{
	struct LinkedList gamer = {};
	
	addToList(&gamer,3);
	addToList(&gamer,2);
	addToList(&gamer,5);
	addToList(&gamer,6);
	addToList(&gamer,7);
	
	print(&gamer);
	removeAt(&gamer,2);
	printf("\n");
	print(&gamer);
	return 0;
}
