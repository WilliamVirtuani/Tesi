#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 1
int c = 0;
long unsigned int countComparisons = 0;
long unsigned int countMoves = 0;
void swap(int *A, int i, int j);
int cmp(int *A, int i, int j);
int partition(int *A, int low, int high);
void quicksort(int *A, int low, int high);
int main()
{
  int n = 10;
  int *A = calloc(n,sizeof(int));
  while(c < N)
  {
    ++c;
    srand(time(0));
    for(int i=0;i<n;i++)
    {
      A[i]=1+rand()%n; //numeri casuali tra 1 e 100
    }
  quicksort(A, 0, n-1);
}
  printf("\nNUMERO DI CONFRONTI QUICKSORT: %lu \n", countComparisons);
  printf("\nNUMERO DI CONFRONTI MEDI QUICKSORT: %lu \n", (countComparisons/N));
  printf("\nNUMERO (NORMALIZZATO) DI CONFRONTI MEDI QUICKSORT: %lu \n", (countComparisons/N)/n);
  printf("\nNUMERO DI SPOSTAMENTI QUICKSORT: %lu \n", countComparisons);
  printf("\nNUMERO DI SPOSTAMENTI MEDI QUICKSORT: %lu \n", (countMoves/N));
  printf("\nNUMERO (NORMALIZZATO) DI SPOSTAMENTI MEDI QUICKSORT: %lu \n", (countMoves/N)/n);
  for(int i = 0; i < n; i++)
  {
    printf("%d\t", A[i]);
  }
  return 0;

}
void quicksort(int *A, int low, int high)
{
  int pivot;
  if(low < high) {
    pivot = partition(A, low, high);
    quicksort(A, low, pivot-1);
    quicksort(A, pivot+1, high);
  }
}

int cmp(int *A, int i, int j)
{
  ++countComparisons;
  if (A[i] <= A[j])
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void swap(int *A, int i, int j)
{
  int buffer;
  buffer = A[i];
  A[i] = A[j];
  A[j] = buffer;
  ++countMoves;
}

int partition(int *A, int low, int high)
{
  int pivot, i, j;
  if(low < high) {
    pivot = low;
    i = low;
    j = high;
    while(i < j) {

      while(cmp(A,i,pivot) && i <= high)
        i++;

      while(!(cmp(A,j,pivot) && j >= low))
        j--;

      if(i < j) {
        swap(A, i, j);
      }
    }
    swap(A, j, pivot);
  }
    return j;
  }
