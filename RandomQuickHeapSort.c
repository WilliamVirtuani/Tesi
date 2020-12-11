#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *A, int i, int j); // swap due elementi dell'array
int reversePartition(int *A, int left, int right); // Effettua la ripartizione dell'array e ritorna la posizione finale del pivot
void buildMaxHeap(int *A, int root, int right, int scale); // Costruisce una struttura (MAX)Heap a partire da un albero binario completo o quasi completo
void buildMinHeap(int *A, int root, int right, int scale); // Costruisce una struttura (MIN)Heap a partire da un albero binario completo o quasi completo
void fixMaxHeap(int *A, int root, int right, int scale); // Risistema una struttura (MAX)Heap che non rispetta la condizione di heap sulla radice
void fixMinHeap(int *A, int root, int right, int scale); // Risistema una struttura (MIN)Heap che non rispetta la condizione di heap sulla radice
int specialMaxLeaf(int *A,int left, int right, int scale); // Ritorna la posizione della foglia più piccola in una struttura (MAX)heap
int specialMinLeaf(int *A,int left, int right, int scale); // Ritorna la posizione della foglia più piccola in una struttura (MIN)heap
void printArray(int *A, int left, int n); // Stampa Array
int cmp(int *A, int i, int j);
long unsigned int countComparisons = 0;
long unsigned int countMoves = 0;
#define N 100
long int c = 0;

int main()
{
  int n = 0;
  printf("INSERIRE DIMENSIONE ARRAY: ");
  scanf("%d", &n);
  int *A = calloc(n,sizeof(n));
  int l = 0;
  int left = 0;
  int right = n-1;
  int m = 0; // Variabile che memorizza la posizione iniziale del pivot
  int pivot = 0; // Variabile che memorizza la posizione finale del pivot
  int pivotEntry = 0; // Variabile che memorizza il pivot
  clock_t start = clock();
  while(c < N){
    c++;
    srand(time(0));
    for(int i=0; i<n; i++)
    {
      A[i]=1+rand()%n; //numeri casuali tra 1 ed n
    }
  right = n-1;
  left = 0;
  while(left < right)
  {
  pivot = reversePartition(A, left, right);
  pivotEntry = A[pivot];
  if(right+left > 2*pivot)
  {
    buildMaxHeap(A, left, pivot-1, left);
    A[pivot] = A[right];
    for(int j = 0; j <= pivot-left-1; j++)
    {
      A[right-j] = A[left];
      l = specialMaxLeaf(A, left, pivot-1,left);
      A[l]=A[right-j-1];
    }
    right = right-(pivot-left)-1;
    A[right+1] = pivotEntry;
  }
  else
  {
    buildMinHeap(A, pivot+1, right, pivot+1);
    A[pivot] = A[left];
    for(int j = 0; j <= right-pivot-1; j++)
    {
      A[left+j] = A[pivot+1];
      l = specialMinLeaf(A, pivot+1,right,pivot+1);
      A[l] = A[left+j+1];
    }
    left = left+(right-pivot)+1;
    A[left - 1] = pivotEntry;
  }
 }
}
  clock_t end = clock();
  printf("\nNUMERO DI CONFRONTI QUICKHEAPSORT: %lu \n", countComparisons);
  printf("\nNUMERO DI CONFRONTI MEDIO QUICKHEAPSORT: %lu \n", (countComparisons/N));
  printf("\nNUMERO (NORMALIZZATO) DI CONFRONTI MEDIO QUICKHEAPSORT: %lu \n", (countComparisons/N)/n);
  printf("\nNUMERO DI SPOSTAMENTI QUICKHEAPSORT: %lu \n", countComparisons);
  printf("\nNUMERO DI SPOSTAMENTI MEDIO QUICKHEAPSORT: %lu \n", (countMoves/N));
  printf("\nNUMERO (NORMALIZZATO) DI SPOSTAMENTI MEDIO QUICKHEAPSORT: %lu \n", (countMoves/N)/n);
  printf("\nTEMPO DI ESECUZIONE QUICKHEAPSORT =  %f secondi \n\n", ((double)(end - start)) / CLOCKS_PER_SEC);
  return 0;
}


void swap(int *A, int i, int j)
{
  int buffer = 0;
  buffer = A[i];
  A[i] = A[j];
  A[j] = buffer;
  ++countMoves;
}


void printArray (int *A, int left, int n)
{
  for(int i = left; i < n; i++)
  {
    printf("%d\t",A[i]);
  }
}


int reversePartition(int *A, int left, int right)
{
  int pivot, i, j;
  if(left < right)
  {
    pivot = left;
    i = left;
    j = right;
    while(i < j) {

      while(cmp(A,i,pivot) && i <= right)
        i++;

      while(!(cmp(A,j,pivot)) && j >= left)
        j--;

      if(i < j) {
        swap(A, i, j);
      }
    }
    swap(A, j, pivot);
  }
    return j;
}


void fixMaxHeap(int *A, int root, int right, int scale)
{
  int max = 0;
  int sx = 0;
  int dx = 0;
  int pos = 0;
  while(root <= right-1)
  {
    dx = ((root*2)+2)-scale;
    sx = ((root*2)+1)-scale;
    max = root;
    if(dx <= right && cmp(A, dx, max))
    {
      max = dx;
    }
   if(sx <= right && cmp(A, sx, max))
    {
      max = sx;
    }
    if(max != root)
    {
      swap(A, root, max);
      root = max;
    }
    else break;
  }
}


void fixMinHeap(int *A, int root, int right, int scale)
{
  int max = 0;
  int sx = 0;
  int dx = 0;
  int pos = 0;
  while(root <= right-1)
  {
    dx = ((root*2)+2)-scale;
    sx = ((root*2)+1)-scale;
    max = root;
    if(dx <= right && !(cmp(A, dx, max)))
    {
      max = dx;
    }
   if(sx <= right && !(cmp(A, sx, max)))
    {
      max = sx;
    }
    if(max != root)
    {
      swap(A, root, max);
      root = max;
    }
    else break;
  }
}


void buildMaxHeap(int *A, int root, int right, int scale)
{
  int dim =(right-root)+1;
  int start =((dim/2)-1)+root;
  for(int i = start; i >= root; i--)
  {
    fixMaxHeap(A, i, right, scale);
  }
}


void buildMinHeap(int *A, int root, int right, int scale)
{
  int dim =(right-root)+1;
  int start =((dim/2)-1)+root;
  for(int i = start; i >= root; i--)
  {
    fixMinHeap(A, i, right, scale);
  }
}


int specialMaxLeaf(int *A,int left, int right, int scale)
{
  int i = left+1;
  if(i > right)
  {
    return i-1;
  }

  while(i < right)
  {
    if(!(cmp(A, i, i+1)))
    {
      i = i+1;

    }
    swap(A,i,(i+scale-1)/2);

    i = (2*i+1)-scale;
  }
  if(i == right)
  {
    swap(A, (i+scale-1)/2,i);
    i = (2*i+1)-scale;
  }
  return (i+scale-1)/2;
}


int specialMinLeaf(int *A,int left, int right, int scale)
{
  int i = left+1;
  if(i > right)
  {
    return i-1;
  }
  while(i < right)
  {
    if(cmp(A, i, i+1))
    {
      i = i+1;
    }
    swap(A, i, (i+scale-1)/2);
    i = (2*i+1)-scale;
  }
  if(i == right)
  {
    swap(A, i, (i+scale-1)/2);
    i = (2*i+1)-scale;
  }

  return (i+scale-1)/2;
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
