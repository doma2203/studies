#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include "Stack.h"

#define MAXSTACK 50

using namespace std;

double tStack[MAXSTACK] = { 0 }; //stos w reprezentacji tablicowej
StackItem* pHead = NULL; //indeks pierwszego elementu na stosie, stos poczatkowy jest pusty

double push(StackItem** wskaznik, double c)
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

double pop(StackItem** wskaznik)
{
	double c;
	if (c = top(*wskaznik))
		del(wskaznik);
	else
		cout << "Stack underflow!!! :(" << endl;
	return c;
}

double top(StackItem *wskaznik)
{
	if (!isEmpty(wskaznik))
		return (wskaznik->cKey);
//?	cout << "Stack underflow :(" << endl;
}

void del(StackItem **wskaznik)
{
	if (!isEmpty(*wskaznik))
	{
		StackItem* v = pHead;
		(*wskaznik) = (*wskaznik)->pNext; //v->pNext
		free(v);
	}
	else
		cout << "Stack underflow!!! :(";
}

int isEmpty(StackItem* wskaznik)
{
	return (!wskaznik);
}



