// calc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include "Stack.h"
#define _STACK_H_
#define DOT '.'

using namespace std;
//----------------------------------------
void calc();
double GetNum();
int IsOper(char c);
char GetOper();
void SkipSpaces(); 
int IsDigit(char c);
int prior(char pOper);
double Count(int Oper, double arg1, double arg2);
//-----------------------------------------------------
void calc() {
	LP_StackItem liczby = NULL;
	LP_StackItem operatory = NULL;
	char c;

	while ((IsDigit(c = GetOper())) || (IsOper(c))) {
		if (IsDigit(c)) {
			ungetc(c, stdin);
			push(&liczby, GetNum());
		}
		
		else{
			//ungetc(c, stdin);
			if (prior(c) > prior(top(operatory)))
				push(&liczby, Count(c, pop(&liczby), pop(&liczby)));
			else push(&operatory, c);
		}
			//ungetc(c, stdin);
	}
	cout << pop(&liczby);
}
//----------------------------------------------------
double GetNum() {
	double res = 0;
	SkipSpaces();
	char c;
	while (IsDigit(c = getchar())) {
		res = res * 10 + (c - '0');
	}
	if (c == DOT)
	{
		double coef = 0.1;
		while (IsDigit(c = getchar()))
		{
			res += (c - '0')*coef;
			coef *= 0.1;
		}
	}
	ungetc(c, stdin);
	return res;
}
//------------------------------------------------
void SkipSpaces() {
	char c;
	while (c = getchar() == ' ')
		ungetc(c, stdin);
}
//------------------------------------------------
int IsOper(char c) {
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '^':return 1;
	default: return 0;
	}
}
//------------------------------------------------
int IsDigit(char c) {
	return (c >= '0') && (c <= '9');
}
//------------------------------------------------
int prior(char pOper) {
	//to swich'em
	switch (pOper) {
	case '+':
	case '-': return 1;
	case '/':
	case '*': return 2;
	case '^': return 3;
	}
	return 0;
}
//------------------------------------------------
char GetOper() {
	SkipSpaces();
	return getchar();
}
//------------------------------------------------
double Count(int Oper, double arg1, double arg2) {
	if (IsOper(Oper)) {
		switch (Oper) {
		case '+': return arg1 + arg2;
		case '-': return arg2 - arg1;
		case '*': return arg1 * arg2;
		case '/':
			if (!arg1)
				printf("Pamiêtaj chole... Ekhem, niedozwolona operacja dzielenia przez 0!\n");
			break;
			return arg2 / arg1;
		case '^': return pow(arg2, arg1);
		}
	}
	return 0;
}
int main()
{
	printf("Podaj wyrazenie symboliczne: ");
	calc();
	printf("\n");
	return 0;
}
