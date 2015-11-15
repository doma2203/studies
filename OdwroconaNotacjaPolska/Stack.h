#ifndef _STACK_H_
#define _STACK_H_

typedef struct StackItem
{
	double cKey;
	StackItem* pNext; //gwiazdki przy typie, nazwe moge uzyc jedna z dwoch

} StackItem, *LP_StackItem;

double push(StackItem** wskaznik, double c);
double pop(StackItem** wskaznik);
double top(StackItem* wskaznik);
void del(StackItem** wskaznik);
int isEmpty(StackItem* wskaznik);
#endif

