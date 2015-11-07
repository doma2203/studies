#include "stack.h"
#include <iostream>
#include <stdlib.h> //do malloca
#include <memory.h>

#define MAXSTACK 50

using namespace std;
//----------------------------------------------------------------------------------------------------------
char tStack[MAXSTACK] = { 0 }; //stos w reprezentacji tablicowej
StackItem* pHead = NULL; //indeks pierwszego elementu na stosie, stos poczatkowy jest pusty
//----------------------------------------------------------------------------------------------------------
char push(StackItem** wskaznik, char c)
{
	StackItem* v = (StackItem*)malloc(sizeof(StackItem));
	if (v)
	{
		memset(v, 0, sizeof(StackItem));
		v->cKey = c;
		v->pNext = *wskaznik;
		*wskaznik = v;
	}
	if (*wskaznik)
		(*wskaznik)->cKey = c;
	else
		cout << "Stack overflow!!! :(" << endl;
	return c;
}
char pop(StackItem** wskaznik)
{
	char c;
	if (c = top(*wskaznik))
		del(wskaznik);
	else
		cout << "Stack underflow!!! :(" << endl;
	return c;
}


int isEmpty(StackItem* wskaznik)
{
	return (!wskaznik);
}

char top(StackItem *wskaznik)
{
	if (!isEmpty(wskaznik));
		return (wskaznik->cKey);
	return 0;
}

void del(StackItem **wskaznik)
{
	if (!isEmpty(*wskaznik))
	{
		StackItem* v = pHead;
		(*wskaznik) =(*wskaznik)->pNext; //v->pNext
		free(v);

	}
	else
		//obsluga bledu, stos pusty
		cout << "Stack underflow!!! :(";

}