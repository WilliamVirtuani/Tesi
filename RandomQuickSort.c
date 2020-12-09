#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(int *A, int n);
int partition(int *A, int left, int right);
void swap(int *A, int i, int j);
void quickSort(int *A, int left, int right);
long unsigned int countComparisons = 0;
int cmp(int *A, int i, int j);
int scambi = 0;
#define N 100
int c = 0;

int main()
{
  int n = 100;
  int A[n];
  int left = 0;
  int right = n-1;
        /*inizializzamo il generatore sull'ora attuale
        dell'elaboratore time(0), in questo modo si hanno
        valori diversi*/
  while(c < N)
  {
     ++c;
	   srand(time(0));

	    for(int i=0;i<n;i++){
	       A[i]=1+rand()%n; //numeri casuali tra 1 e 100
       }

       left = 0;
       right = n-1;
       clock_t start = clock();
       quickSort(A, left, right);
       clock_t end = clock();
     }
  printf("\nNUMERO DI CONFRONTI QUICKSORT: %lu \n ", countComparisons/N);
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
    while(cmp(A, right, m) && left < right)
    {
      right --;
    }
    while(!(cmp(A, left, m)))
    {
      left ++;
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

int cmp(int *A, int i, int j)
{
  ++countComparisons;
  if (A[i] >= A[j])
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
