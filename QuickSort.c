#include <stdio.h>
#include <time.h>

void printArray(int *A, int n);
int partition(int *A, int left, int right);
void swap(int *A, int i, int j);
void quickSort(int *A, int left, int right);
int count = 0;
int countComparison();


int main()
{
  int n = 0; // Dimensione array
  printf("Inserire dimensione array: ");
  scanf("%d", &n);
  int A[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  int left = 0;
  int right = n-1;
  clock_t start = clock();
  quickSort(A, left, right);
  clock_t end = clock();
  printf("Tempo di esecuzione =  %f secondi \n", ((double)(end - start)) / CLOCKS_PER_SEC);
  printArray(A,n);
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
    }
    while(A[left] < A[m])
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
    quickSort(A, left, m-1);
    quickSort(A, m+1, right);
  }
}
