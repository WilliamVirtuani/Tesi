#include <stdio.h>

void Scambia(int *A, int i, int j); //Scambia due elementi dell'array
void FixMaxHeap(int *A, int root, int right);
void StampaArray (int *A, int left, int right);
void FixMaxHeap(int *A, int root, int right);
void BuildMaxHeap(int *A, int root, int right);
void BuildMinHeap(int *A, int root, int right);
int Massimo(int *A, int i, int j); //Ritorna il massimo tra A[i] e A[j]
int PosizioneMax(int *A, int i, int j);
int Minimo(int *A, int i, int j);
int PosizioneMin(int *A, int i, int j);
void FixMinHeap(int *A, int root, int right);

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

  BuildMaxHeap(A,3,6);
  BuildMinHeap(A,0,2);
  StampaArray(A,0,n-1);
  return 0;
}


void Scambia(int *A, int i, int j)
{
  int buffer = 0;
  buffer = A[i];
  A[i] = A[j];
  A[j] = buffer;
}

void StampaArray (int *A, int left, int right)
{
  for(int i = left; i < right+1; i++)
  {
    printf("%d\t",A[i]);
  }
}

void FixMaxHeap(int *A, int root, int right)
{
  int max = 0;
  int dx = 0;
  int sx = 0;
  int pos = 0;

  while((root*2+2)-root <= right || (root*2+1)-root <= right) //caso in cui root ha sia foglia destra che sinistra
  {
    dx = (root*2+2)-root;
    sx = (root*2+1)-root;
    max = Massimo(A, sx, dx);
    if(sx <= right && dx <= right && A[root] < max)
    {
      pos = PosizioneMax(A, dx, sx);
      Scambia(A, root, pos);
      root = pos;
    }
    else if(sx > right && A[root] < A[dx] && dx <= right) //caso in cui manca foglia sinistra di root
    {
      Scambia(A, root, dx);
      root = dx;
    }
    else if(dx > right && A[root] < A[sx] && sx <= right) //caso in cui manca foglia destra di root
    {
      Scambia(A, root, sx);
      root = sx;
    }
    else break;
  }
}


void BuildMaxHeap(int *A, int root, int right)
{
  int dim = (right-root)+1;
  int start = ((dim/2)-1)+root;
  for(int i = start; i >= root; i--)
  {
    FixMaxHeap(A, i, right);
  }
}

void BuildMinHeap(int *A, int root, int right)
{
  int dim = (right-root)+1;
  int start = ((dim/2)-1)+root;
  for(int i = start; i >= root; i--)
  {
    FixMinHeap(A, i, right);
  }
}


int Massimo(int *A, int i, int j)
{
  if(A[i] >= A[j])
  {
    return A[i];
  }
  else
  {
    return A[j];
  }
}

int Minimo(int *A, int i, int j)
{
  if(A[i] <= A[j])
  {
    return A[i];
  }
  else
  {
    return A[j];
  }
}

int PosizioneMax(int *A, int i, int j)
{
  if (A[i] >= A[j])
  {
    return i;
  }
  else return j;
}

int PosizioneMin(int *A, int i, int j)
{
  if (A[i] <= A[j])
  {
    return i;
  }
  else return j;
}

void FixMinHeap(int *A, int root, int right)
{
  int min = 0;
  int dx = 0;
  int sx = 0;
  int pos = 0;

  while((root*2+2)-root <= right || (root*2+1)-root <= right) //caso in cui root ha sia foglia destra che sinistra
  {
    dx = (root*2+2)-root;
    sx = (root*2+1)-root;
    min = Minimo(A, sx, dx);
    if(sx <= right && dx <= right && A[root] > min)
    {
      pos = PosizioneMin(A, dx, sx);
      Scambia(A, root, pos);
      root = pos;
    }
    else if(sx > right && A[root] > A[dx] && dx <= right) //caso in cui manca foglia sinistra di root
    {
      Scambia(A, root, dx);
      root = dx;
    }
    else if(dx > right && A[root] > A[sx] && sx <= right) //caso in cui manca foglia destra di root
    {
      Scambia(A, root, sx);
      root = sx;
    }
    else break;
  }
}
