#ifndef _SORTPACK_H_
#define _SORTPACK_H_

typedef void (*qSort) (int*,int, int); //tworzenie wskaünika do funkcji

//Funkcje pomocnicze:
void HeapUpdate(int *tab, int k, int n);
void RandTab(int *tab, int rozmiar);
void CloneTab(int* cel, int* zrodlo, int rozmiar);
void WriteTab(int *tablica, int rozmiar);
double CountExecTime(qSort pSort,int* tab, int poczatek, int rozmiar); //Quicksort jest rekurencyjny, nie moge przekazywac czasu przez wskaünik

//G≥Ûwne funkcje sortowaÒ:
void BubbleSort(int* tab, int rozmiar, double* czasWykonania); 
void SelectionSort(int* tab, int rozmiar, double* czasWykonania);
void InsertionSort(int* tab, int rozmiar, double* czasWykonania);
void ShuttleSort(int* tab, int rozmiar, double* czasWykonania); //sortowanie mieszane, takøe: "cocktail sort"
void HalfSort(int* tab, int rozmiar, double* czasWykonania);
void HeapSort(int *tab, int rozmiar, double* czasWykonania);
void QuickSort(int *tab, int poczatek, int rozmiar);

#endif
