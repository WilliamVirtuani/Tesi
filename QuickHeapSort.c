#include <stdio.h>

void Scambia(int *A, int i, int j); // Scambia due elementi dell'array
int ChoosePivot(int *A, int left, int right); // Ritorna la posizione iniziale del pivot
int ReversePartition(int *A, int left, int right, int m); // Effettua la ripartizione dell'array e ritorna la posizione finale del pivot
void BuildMaxHeap(int *A, int root, int right, int scale); // Costruisce una struttura (MAX)Heap a partire da un albero binario completo o quasi completo
void BuildMinHeap(int *A, int root, int right, int scale); // Costruisce una struttura (MIN)Heap a partire da un albero binario completo o quasi completo
void FixMaxHeap(int *A, int root, int right, int scale); // Risistema una struttura (MAX)Heap che non rispetta la condizione di heap sulla radice
void FixMinHeap(int *A, int root, int right, int scale); // Risistema una struttura (MIN)Heap che non rispetta la condizione di heap sulla radice
int SpecialMaxLeaf(int *A,int left, int right, int scale); // Ritorna la posizione della foglia più piccola in una struttura (MAX)heap
int SpecialMinLeaf(int *A,int left, int right, int scale); // Ritorna la posizione della foglia più piccola in una struttura (MIN)heap
void StampaArray(int *A, int left, int n); // Stampa Array

int main()
{
  int n = 0;
  int l = 0;
  printf("Inserire dimensione dell'array: ");
  scanf("%d", &n);
  int A[n];
  printf("Inserire elementi dell'array: ");
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  int left = 0;
  int right = n-1;
  int m = 0; // Variabile che memorizza la posizione iniziale del pivot
  int pivot = 0; // Variabile che memorizza la posizione finale del pivot
  int pivotEntry = 0; // Variabile che memorizza il pivot
  while(left < right)
  {
  m = ChoosePivot(A, left, right);
  pivot = ReversePartition(A, left, right, m);
  pivotEntry = A[pivot];
  if(right+left > 2*pivot)
  {
    BuildMaxHeap(A, left, pivot-1, left);
    Scambia(A,pivot,right);
    for(int j = 0; j <= pivot-left-1; j++)
    {
      Scambia(A, right-j, left);
      l = SpecialMaxLeaf(A, left, pivot-1,left);
      Scambia(A, l, right-j-1);
    }
    right = right-(pivot-left)-1;
  }
  else
  {
    BuildMinHeap(A, pivot+1, right, pivot+1);
    Scambia(A,pivot,left);
    for(int j = 0; j <= right-pivot-1; j++)
    {
      Scambia(A, left+j, pivot+1);
      l = SpecialMinLeaf(A, pivot+1,right,pivot+1);
      Scambia(A, l, left+j+1);
    }
    left = left+(right-pivot)+1;
  }
}
StampaArray(A,0,n);
  return 0;
}


void Scambia(int *A, int i, int j)
{
  int buffer = 0;
  buffer = A[i];
  A[i] = A[j];
  A[j] = buffer;
}


int ChoosePivot(int *A, int left, int right)
{
  return left;
}


void StampaArray (int *A, int left, int n)
{
  for(int i = left; i < n; i++)
  {
    printf("%d\t",A[i]);
  }
}


int ReversePartition(int *A, int left, int right, int m)
{
  while (left < right)
  {
    while(A[right] <= A[m])
    {
      right--;
    }
    while(A[left] >= A[m] && left < right)
    {
      left++;
    }
    if(left < right)
    {
      Scambia(A, left, right);
    }
  }
  Scambia(A, left, m);
  return left;
}


void FixMaxHeap(int *A, int root, int right, int scale)
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
    if(dx <= right && A[dx] > A[max])
    {
      max = dx;
    }
   if(sx <= right && A[sx] > A[max])
    {
      max = sx;
    }
    if(max != root)
    {
      Scambia(A, root, max);
      root = max;
    }
    else break;
  }
}


void FixMinHeap(int *A, int root, int right, int scale)
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
    if(dx <= right && A[dx] < A[max])
    {
      max = dx;
    }
   if(sx <= right && A[sx] < A[max])
    {
      max = sx;
    }
    if(max != root)
    {
      Scambia(A, root, max);
      root = max;
    }
    else break;
  }
}


void BuildMaxHeap(int *A, int root, int right, int scale)
{
  int dim =(right-root)+1;
  int start =((dim/2)-1)+root;
  for(int i = start; i >= root; i--)
  {
    FixMaxHeap(A, i, right, scale);
  }
}


void BuildMinHeap(int *A, int root, int right, int scale)
{
  int dim =(right-root)+1;
  int start =((dim/2)-1)+root;
  for(int i = start; i >= root; i--)
  {
    FixMinHeap(A, i, right, scale);
  }
}


int SpecialMaxLeaf(int *A,int left, int right, int scale)
{
  int i = left+1;
  if(i > right)
  {
    return i-1;
  }

  while(i < right)
  {
    if(A[i] < A[i+1])
    {
      i = i+1;
    }
    Scambia(A,i,(i+scale-1)/2);

    i = (2*i+1)-scale;
  }
  if(i == right)
  {
    Scambia(A, (i+scale-1)/2,i);
    i = (2*i+1)-scale;
  }
  return (i+scale-1)/2;
}
int SpecialMinLeaf(int *A,int left, int right, int scale)
{
  int i = left+1;
  if(i > right)
  {
    return i-1;
  }
  while(i < right)
  {
    if(A[i] > A[i+1])
    {
      i = i+1;
    }
    Scambia(A, i, (i+scale-1)/2);
    i = (2*i+1)-scale;
  }
  if(i == right)
  {
    Scambia(A, i, (i+scale-1)/2);
    i = (2*i+1)-scale;
  }

  return (i+scale-1)/2;
}
