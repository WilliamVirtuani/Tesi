#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *A, int i, int j);
void heapify(int *A, int root, int n);
void heapSort(int *A, int n);
void printArray(int *A, int n);
int cmp(int *A, int i, int j);
long unsigned int countComparisons = 0;
long unsigned int countMoves = 0;
#define N 100
long int c = 0;

int main()
{
  int n = 100000000;
  int *A = calloc(n,sizeof(int));
  int left = 0;
        /*inizializzamo il generatore sull'ora attuale
        dell'elaboratore time(0), in questo modo si hanno
        valori diversi*/
  while(c < N)
  {
    srand(time(0));
	   for(int i=0;i<n;i++)
     {
	      A[i]=1+rand()%n; //numeri casuali tra 1 ed n
      }
      heapSort(A,n);
      c++;
    }
    printf("\nNUMERO DI CONFRONTI HEAPSORT: %lu \n", countComparisons);
    printf("\nNUMERO DI CONFRONTI MEDI HEAPSORT: %lu \n", (countComparisons/N));
    printf("\nNUMERO (NORMALIZZATO) DI CONFRONTI MEDI HEAPSORT: %lu \n", (countComparisons/N)/n);
    printf("\nNUMERO DI SPOSTAMENTI HEAPSORT: %lu \n", countComparisons);
    printf("\nNUMERO DI SPOSTAMENTI MEDI HEAPSORT: %lu \n", (countMoves/N));
    printf("\nNUMERO (NORMALIZZATO) DI SPOSTAMENTI MEDI HEAPSORT: %lu \n", (countMoves/N)/n);
  return 0;
}


void swap(int *A, int i, int j)
{
  int buffer;
  buffer = A[i];
  A[i] = A[j];
  A[j] = buffer;
  ++countMoves;
}

void printArray(int *A, int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%d\t", A[i]);
  }
  printf("\n");
}

void heapify(int *A, int root, int n)
{
  int minimum = root;
  int l = 2*root+1;
  int r = 2*root+2;
  if(l < n && cmp(A, l, minimum))
  {
    minimum = l;
  }
  if(r < n && cmp(A, r, minimum))
  {
    minimum = r;
  }
  if(minimum != root)
  {
    swap(A, root, minimum);
    heapify(A, minimum, n);
  }
}

void heapSort(int *A, int n)
{
  for(int i = (n/2)-1; i >= 0; i--)
  {
    heapify(A, i, n);
  }
  for (int i = n-1; i > 0; i--)
  {
    swap(A, 0, i);
    heapify(A, 0, i);
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
