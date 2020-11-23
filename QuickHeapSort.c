#include <stdio.h>

void Scambia(int *A, int i, int j); //Scambia due elementi dell'array
int ChoosePivot(int *A, int left, int right); //Ritorna la posizione iniziale del pivot
int ReversePartition(int *A, int left, int right, int m); //Effettua la ripartizione dell'array e ritorna la posizione finale del pivot
void BuildMaxHeap(int *A, int root, int right, int scale); //Costruisce una struttura Heap a partire da un albero binario completo o quasi completo
void BuildMinHeap(int *A, int root, int right, int scale);
void FixMaxHeap(int *A, int root, int right, int scale);
void FixMinHeap(int *A, int root, int right, int scale);
void StampaArray(int *A, int left, int right);


int main()
{
  int n = 0;
  printf("Inserire dimensione dell'array: ");
  scanf("%d", &n);
  int A[n]; //Array
  printf("Inserire elementi dell'array: ");
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  int left = 0;
  int right = n-1;
  int m = 0; //Variabile che memorizza la posizione iniziale del pivot
  int pivot = 0; //Variabile che memorizza la posizione finale del pivot
  int pivotEntry = 0; //Variabile che memorizza il pivot
  m = ChoosePivot(A, left, right);
  pivot = ReversePartition(A, left, right, m);
  pivotEntry = A[pivot];
  StampaArray(A, left, right);
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

void StampaArray (int *A, int left, int right)
{
  for(int i = left; i < right+1; i++)
  {
    printf("%d\t",A[i]);
  }
}

int ReversePartition(int *A, int left, int right, int m)
{
  while (left < right)
  {
    while(A[right] < A[m] && left < right)
    {
      right--;
    }
    while(A[left] >= A[m] && left < right)
    {
      left++;
    }
    Scambia(A, left, right);
  }
  Scambia(A, right, m);
  return right;
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
