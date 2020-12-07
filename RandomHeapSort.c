#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *A, int i, int j);
void heapify(int *A, int root, int n);
void heapSort(int *A, int n);
void printArray(int *A, int n);
long int count = 0;
int countComparison();
#define N 100
long int c = 0;

int main()
{
  int n = 1000;
  int A[n];
  int left = 0;
        /*inizializzamo il generatore sull'ora attuale
        dell'elaboratore time(0), in questo modo si hanno
        valori diversi*/
  while(c < N)
  {
    srand(time(0));
	   for(int i=0;i<n;i++)
     {
	      A[i]=1+rand()%100000; //numeri casuali tra 1 e 100
      }


      heapSort(A,n);
      c++;
    }

  printf("\nNUMERO DI CONFRONTI MEDI HEAPSORT: %ld \n", (count/N)/n);
  return 0;
}


void swap(int *A, int i, int j)
{
  int buffer;
  buffer = A[i];
  A[i] = A[j];
  A[j] = buffer;
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
  if(l < n && A[l] > A[minimum])
  {
    minimum = l;
    ++count;
  }
  if(r < n && A[r] > A[minimum])
  {
    minimum = r;
    ++count;
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

int countComparison()
{
  ++count;
  return 1;
}
