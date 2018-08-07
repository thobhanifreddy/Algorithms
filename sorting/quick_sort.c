/*

reference: CLRS page no 171;
CLRS pdf link: https://mcdtu.files.wordpress.com/2017/03/introduction-to-algorithms-3rd-edition-sep-2010.pdf

*/

/*

for array A[p.....r]:
  QUICKSORT(A, p, r)
  1. if(p<r)
  2.   q = PARTITION(A, p, r)
  3.   QUICKSORT(A, p, r)
  4.   QUICKSORT(A, p, r)

  PARTITION(A, p, r)
  1. pivot = A[r]
  2. i = p - 1 
  3. for j = p to r - 1
  4.  if A[j] < pvot  
  5.    i = i + 1
  6.    swap A[i] and A[j]
  7. swap A[i+1] and A[r]
  8. return i+1 

*/

/*
TIME ANALYSIS:

  If the partitioning is balanced, the algorithm runs asymptotically as fast as merge
  If the partitioning is unbalanced, however, it can run asymptotically as slowly as insertion sort

  Worst Case:  θ(n^2):

    when array is sorted or reverse sorted(desending order)
    one side will have n - 1 elements while other side will have 0.
    T(n)  =  T(n -1) + T(0) +  θ(n)<-divide steps  
    T(n) = T(n-1) + θ(1) + θ(n)
    T(n) = T(n-1) + θ(n)                //ignore constant time
    T(n) = θ(n^2)

  Best Case: θ(nlogn):

    When both part of array are of n/2,
    T(n) = 2T(n/2) +  θ(n)
    T(n) = θ(nlogn)                   //if you don't understand this: https://stackoverflow.com/questions/10324830/how-to-get-onlogn-from-tn-2tn-2-on

*/

#include <stdio.h>

int array[10];
int n;
int quickSort(int array[], int p, int r);
int partition(int array[], int p, int r);

int main()
{

  printf("---* QUICK SORT *--- \n");

  printf("Enter array lenght(max allowed 10):");
  scanf("%d", &n);

  while (n > 10)
  {
    printf("Array can't be of lenght more than 10!\n");
    printf("Enter array lenght(max allowed 10):");
    scanf("%d", &n);
  }

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &array[i]);
  }
  printf("Unsorted Array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }

  quickSort(array, 0, n);

  printf("\nSorted Array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }
}

int quickSort(int array[], int p, int r) //p -> 0th element, q -> nth element
{
  if (p < r)
  {
    int q = partition(array, p, r);
    quickSort(array, p, q - 1);
    quickSort(array, q + 1, r);
  }
}

int partition(int array[], int p, int r) //p -> 0th element, q -> nth element
{
  int pivot = array[r]; // choosing pivot as nth element
  int i = p - 1, temp;  //i initialized to -1;

  for (int current = p; current < r - 1; current++)
  {
    if (array[current] < pivot)
    {
      i++;
      temp = array[i];
      array[i] = array[current];
      array[current] = temp;
    }
    //swaping i+1th element with nth element
    temp = array[i + 1];
    array[i + 1] = pivot;
    array[r] = temp;
  }
  return i + 1; //this will be q in quickSort
}