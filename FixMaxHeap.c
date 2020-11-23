#include <stdio.h>

void Scambia(int *A, int i, int j);
void BuildMaxHeap(int *A, int root, int right, int scale);
void BuildMinHeap(int *A, int root, int right, int scale);
void FixMaxHeap(int *A, int root, int right, int scale);
void FixMinHeap(int *A, int root, int right, int scale);
void StampaArray(int *A, int n);

int main()
{
  int n = 7;
  int A[] = {21, 1, 20, 12, 15, 14, 11};
  BuildMinHeap(A,2,5,2);
  StampaArray(A,n);
  return 0;

}


void Scambia(int *A, int i, int j)
{
  int buffer = 0;
  buffer = A[i];
  A[i] = A[j];
  A[j] = buffer;
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

void StampaArray(int *A, int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%d\t", A[i]);
  }
}
