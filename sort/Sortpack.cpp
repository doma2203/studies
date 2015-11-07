
#include <iostream>
#include <conio.h>
#include <time.h>
#include "Sortpack.h"
#include <stdlib.h>
#include <memory.h>

using namespace std;

//g³ówne funkcje sortowañ:
void BubbleSort(int* tab, int rozmiar, double* czasWykonania) { //OK!
	
	double initTime = clock();		
	for (int i = 1; i < rozmiar; i++)
		for (int j = rozmiar - 1; j >= i; j--)
			if (tab[j] < tab[j - 1]) {			//porównanie elementow i zamiana "l¿ejszego" z "ciê¿szym"
				int tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
			}
	double exitTime = clock();
	*czasWykonania = (exitTime - initTime)/(double)CLOCKS_PER_SEC;
}
void SelectionSort(int* tab,int rozmiar, double* czasWykonania) { //jest OK!
	double initTime = clock();
	for (int i = 0; i < rozmiar-1; i++)	
	{
		int ix = i;						
		int min = tab[ix];	
		for (int j = i + 1; j < rozmiar; j++) {
			if (tab[j] < min) { //wyszukiwanie minimum
				ix = j;
				min = tab[ix];
			}
		}
			tab[ix] = tab[i]; //zamiana elementów
			tab[i] =min;
		}
	double exitTime = clock();
	*czasWykonania = (exitTime - initTime) / (double)CLOCKS_PER_SEC;
}
void InsertionSort(int* tab, int rozmiar, double* czasWykonania) { //jest OK!
	
	double initTime = clock();
	for (int i = 1; i < rozmiar; i++) {
		int x = tab[i];
		int j = i;
		while ((j > 0) && (tab[j - 1]>x)) {
			tab[j] = tab[j - 1];
			j--;
			tab[j] = x;
		}
	}
	double exitTime = clock();
	*czasWykonania = (exitTime - initTime) / (double)CLOCKS_PER_SEC;
}
void ShuttleSort(int* tab, int rozmiar, double* czasWykonania) { //jest OK!	
	int left = 1;
	int right = rozmiar - 1;
	int k = rozmiar - 1;
	int tmp;
	double initTime = clock();
	do {
		for (int j = right; j >= left; j--) //"tradycyjne" sortowanie b¹belkowe
			if (tab[j - 1] > tab[j]) 
			{
				tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
				k = j;
			}
		left = k + 1;
		for (int j = left; j <= right; j++) //pêtla sortuj¹ca w drugim kierunku
			if (tab[j - 1] > tab[j])
			{
				tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
				k = j;
			}
		right = k - 1;
	} while (left <= right);
	double exitTime = clock();
	*czasWykonania = (exitTime - initTime) / (double)CLOCKS_PER_SEC;
}
void HalfSort(int* tab, int rozmiar, double* czasWykonania) { //OK, koñcówka wziêta z Wirth'a
	double initTime = clock();
	for (int i = 1; i < rozmiar; i++)
	{
		int klucz = tab[i];
		int left = 0;
		int right = i - 1;
		int m;
		while (left <= right) {
			m = (left + right) >> 1;
			(klucz < tab[m]) ? right = m - 1 : left = m + 1;
		}
		for (int j = i - 1; j >= m; j--)
			tab[j + 1] = tab[j];
			tab[left] = klucz;
	}
	double exitTime = clock();
	*czasWykonania = (exitTime - initTime) / (double)CLOCKS_PER_SEC;
	}
void HeapSort(int* tab, int rozmiar, double* czasWykonania) { //OK!
	int k;
	int tmp;
	int tSize = rozmiar;
	double initTime = clock();
	for (k = tSize>>1; k > 0; k--)
		HeapUpdate(tab, k, tSize); //przywrócenie warunku kopca
	for (int j = tSize; j > 1; j--) {
		tmp = tab[0];
		tab[0] = tab[j - 1];
		tab[j - 1] = tmp;
		HeapUpdate(tab, 1, j-1);
	}
	double exitTime = clock();
	*czasWykonania = (exitTime - initTime) / (double)CLOCKS_PER_SEC;
}
void QuickSort(int* tab,int poczatek, int rozmiar) { 
	int i = poczatek;
	int j = rozmiar;
	int x = tab[(poczatek + rozmiar) >> 1];
	while (i < j) {
		while ((i<=rozmiar)&&(tab[i] < x)) ++i;
		while ((j>=0)&&(tab[j] > x)) --j;
		if (i <= j) {
			if (i != j) {
				int temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
				++i;
				--j;
		}
	}
     if(poczatek<j)
		 QuickSort(tab,poczatek,j);
     if(i<rozmiar)
		 QuickSort(tab,i,rozmiar); 
}
//Funkcje pomocnicze:
void HeapUpdate(int *tab, int k, int n) {
	int i;
	int j;
	i = tab[k - 1];
	while (k <= (n>>1))
	{
		j = k<<1;
		if ((j < n) && (tab[j - 1] < tab[j]))
			j++;
		if (i >= tab[j - 1])
			break;
		else {
			tab[k - 1] = tab[j - 1];
			k = j;
		}
	}
	tab[k - 1] = i;

}
void RandTab(int *tab, int rozmiar){
for (int i = 0; i < rozmiar; i++)
	tab[i] = rand() % rozmiar + 1;
}
void CloneTab(int* cel, int* zrodlo, int rozmiar) {
	memcpy(cel, zrodlo, rozmiar*sizeof(int));
}
void WriteTab(int *tablica, int rozmiar) {
	for (int i = 0; i < rozmiar; i++)
		printf("%i ", tablica[i]);
	printf("\n");
}
//funkcja liczaca czas dla quicksorta, jako parametr przyjmuje funkcjê 
double CountExecTime(qSort pSort,int* tab, int poczatek, int rozmiar) {
	double initTime = clock();
	pSort(tab, poczatek, rozmiar-1);
	double exitTime = clock();
	return ((exitTime - initTime) / (double)CLOCKS_PER_SEC);
}