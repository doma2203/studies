// sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "Sortpack.h"
#include <stdlib.h>

#define _SORTPACK_H_
//#define CONTROLPRINT 

using namespace std;

int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));

	double execTime;			//zmienna przechowuj¹ca czas wykonywania
					
	if (argc != 2){
		cout << "Error! Usage: sort.exe <tabsize>" << endl;
		return 1;
	}
	const int TabSize = atoi(argv[1]);
	
	if (TabSize < 0) {
		cout << "BLAD: Ujemny rozmiar tablicy! " << endl;
		return 2;
	}
	if (!TabSize) {
		cout << "BLAD: Zerowy rozmiar tablicy lub podano jako parametr ciag tekstowy!" << endl;
		return 3;
	}


	int* tabToSort = (int*)calloc(TabSize, sizeof(int));	//dynamiczna alokacja tablicy
	RandTab(tabToSort, TabSize); 
	printf("\n%s %i %s\n","******CZAS SORTOWANIA - TABLICA",TabSize,"ELEMENTOW******");
	printf("\n");
//----------------------------------------------------------------------------------------------
#ifdef CONTROLPRINT
	WriteTab(tabToSort, TabSize);
#endif
	int* tablica = (int*)calloc(TabSize, sizeof(int));
//----------------------------------------------------------------------------------------------
	CloneTab(tablica, tabToSort, TabSize);
	BubbleSort(tablica,TabSize,&execTime);
    printf("%.3f%s\t%s\n",execTime,"s","Bubble sort (sortowanie babelkowe)");
#ifdef CONTROLPRINT
	WriteTab(tablica, TabSize);
#endif
//----------------------------------------------------------------------------------------------
	CloneTab(tablica, tabToSort, TabSize);
	SelectionSort(tablica, TabSize, &execTime);
	printf("%.3f%s\t%s\n", execTime, "s","Selection sort (sortowanie przez wybieranie)");
#ifdef CONTROLPRINT
	WriteTab(tablica, TabSize);
#endif
//----------------------------------------------------------------------------------------------
	CloneTab(tablica, tabToSort, TabSize);
	InsertionSort(tablica, TabSize, &execTime);
	printf("%.3f%s\t%s\n", execTime, "s", "Insertion sort (sortowanie przez wstawianie)");
#ifdef CONTROLPRINT
	WriteTab(tablica, TabSize);
#endif
//----------------------------------------------------------------------------------------------
	CloneTab(tablica, tabToSort, TabSize);
	ShuttleSort(tablica, TabSize, &execTime);
	printf("%.3f%s\t%s\n", execTime, "s", "Shuttle sort (sortowanie mieszane)");
#ifdef CONTROLPRINT
	WriteTab(tablica, TabSize);
#endif
//----------------------------------------------------------------------------------------------
	CloneTab(tablica, tabToSort, TabSize);
	HalfSort(tablica, TabSize, &execTime);
	printf("%.3f%s\t%s\n", execTime, "s", "Half sort (sortowanie polowkowe)");
#ifdef CONTROLPRINT
	WriteTab(tablica, TabSize);
#endif
//----------------------------------------------------------------------------------------------*/
	CloneTab(tablica, tabToSort, TabSize);
	HeapSort(tablica, TabSize, &execTime);
	printf("%.3f%s\t%s\n", execTime, "s", "Heap sort (sortowanie stogowe)");
#ifdef CONTROLPRINT
	WriteTab(tablica, TabSize);
#endif
	execTime=NULL;
//----------------------------------------------------------------------------------------------
	CloneTab(tablica, tabToSort, TabSize);
	printf("%.3f%s\t%s\n", CountExecTime(QuickSort, tablica, 0, TabSize), "s", "Quick sort (sortowanie szybkie)");
#ifdef CONTROLPRINT
	WriteTab(tablica, TabSize);
#endif
//----------------------------------------------------------------------------------------------
	free(tablica);
	free(tabToSort);
	return 0;
}