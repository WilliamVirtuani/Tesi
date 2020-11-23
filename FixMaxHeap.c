#include <stdio.h>

void Scambia(int *A, int i, int j);
void BuildMaxHeap(int *A, int root, int right);
void FixMaxHeap(int *A, int root, int right);
void StampaArray(int *A, int n);

int main()
{
  int n = 7;
  int A[] = {21,1,20,12,15,14,11};
  FixMaxHeap(A,3,6);
  //StampaArray(A,n);
  return 0;

}


void Scambia(int *A, int i, int j)
{
  int buffer = 0;
  buffer = A[i];
  A[i] = A[j];
  A[j] = buffer;
}

void FixMaxHeap(int *A, int root, int right)
{
  int max = 0;
  int sx = 0;
  int dx = 0;
  int pos = 0;

  while(root <= right-1)
  {
    dx = ((root*2)+2)-root;
    sx = ((root*2)+1)-root;
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
      StampaArray(A,7);
      root = max;
    }
    else break;
  }
}

void StampaArray(int *A, int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%d\t", A[i]);
  }
}
