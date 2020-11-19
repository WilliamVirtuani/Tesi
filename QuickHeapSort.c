#include <stdio.h>

void Scambia(int *A, int i, int j); //Scambia due elementi dell'array
int ChoosePivot(int *A, int left, int right); //Ritorna la posizione iniziale del pivot
int ReversePartition(int *A, int left, int right, int m); //Effettua la ripartizione dell'array e ritorna la posizione finale del pivot
void BuildMaxHeap(int *A, int left, int right);
void FixMaxHeap(int *A, int left, int right);
void StampaArray(int *A, int left, int right);
int Massimo(int *A, int i, int j);

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
