#ifndef _STACK_H_
#define _STACK_H_
typedef struct StackItem
{
	char cKey;
	StackItem* pNext; //gwiazdki przy typie, nazwe moge uzyc jedna z dwoch

} StackItem, *LP_StackItem;

	char push(StackItem** wskaznik, char c);
	char pop(StackItem** wskaznik);
	char top(StackItem* wskaznik);
	void del(StackItem** wskaznik);
	int isEmpty(StackItem* wskaznik);
#endif
