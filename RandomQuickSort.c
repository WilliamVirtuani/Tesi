#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(int *A, int n);
int partition(int *A, int left, int right);
void swap(int *A, int i, int j);
void quickSort(int *A, int left, int right);
int count = 0;
int countComparison();
int scambi = 0;


int main()
{
  int n = 1000;
  int A[n];
        /*inizializzamo il generatore sull'ora attuale
        dell'elaboratore time(0), in questo modo si hanno
        valori diversi*/
	srand(time(0));

	for(int i=0;i<n;i++){
	   A[i]=1+rand()%1000; //numeri casuali tra 1 e 100
  }

  int left = 0;
  int right = n-1;
  clock_t start = clock();
  quickSort(A, left, right);
  clock_t end = clock();
  printf("TEMPO DI ESECUZIONE QUICKSORT =  %f secondi \n", ((double)(end - start)) / CLOCKS_PER_SEC);
  printArray(A,n);
  printf("\nNUMERO DI CONFRONTI QUICKSORT: %d \n ", count);
  return 0;
}



void printArray(int *A, int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%d\t", A[i]);
  }
}


void swap(int *A, int i, int j)
{
  int buffer = 0;
  buffer = A[i];
  A[i] = A[j];
  A[j] = buffer;
  ++scambi;
}


int partition(int *A, int left, int right)
{
  int m = left; // salvo la posizione del pivot (primo elemento dell'array)
  int pivot = A[m]; // salvo il valore del pivot
  while(left < right)
  {
    while(A[right] >= A[m] && left < right)
    {
      right --;
      ++count;
    }
    while(A[left] < A[m])
    {
      left ++;
      ++count;
    }
    if(left < right)
    {
      swap(A, left, right);
    }
  }
  swap(A, left, m);
  return left;
}

void quickSort(int *A, int left, int right)
{
  int m; // Salvo la posizione finale del pivot
  if(left < right)
  {
    m = partition(A, left, right);
    quickSort(A, left, m);
    quickSort(A, m+1, right);
  }
}

int countComparison()
{
  ++count;
  return 1;
}
