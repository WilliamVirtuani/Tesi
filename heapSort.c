#include <stdio.h>
#include <time.h>

void swap(int *A, int i, int j);
void heapify(int *A, int root, int n);
void heapSort(int *A, int n);
void printArray(int *A, int n);



int main()
{
  int n = 0;
  printf("Inserire dimensione array: ");
  scanf("%d", &n);
  int A[n];
  int left = 0;
  printf("Inserire elementi: ");
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  clock_t start = clock();
  heapSort(A,n);
  clock_t end = clock();
  printf("\nTempo di esecuzione =  %f secondi \n", ((double)(end - start)) / CLOCKS_PER_SEC);
  printArray(A,n);
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
  }
  if(r < n && A[r] > A[minimum])
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
