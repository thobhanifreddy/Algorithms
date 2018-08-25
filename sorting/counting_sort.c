/* 

procedure countingSort( A : list of sortable items )
  n = length(A)
  max = find_max(A)   //finding max from input array

  for i = 0 to  i <= max do       //Initializong count array with 0 of lenght max
    countArray[i] = 0

  for i = 0 to i < n do           //Store the frequencies of each distinct element of A[]
    countArray[A[i]]++

  let j = 0
  for i = 0 to i <= max do
    let temp  = countArray[i]   // stores which element occurs how many times

    while temp do               //  Add i in sortedA[] according to the number of times i occured in A[]
      sortedA[j] = i
      j++
      temp--
*/

/*

It will take O(N) time to traverse through array A and O(K) time to traverse through countA

So time complexity will be O(N + K)


*/

#include <stdio.h>
#include <stdbool.h>

int find_max(int array[]);

int main()
{
  int array[10], countArray[10];
  int max, temp, n, swaps = 0;

  printf("---* COUNTING SORT *--- \n");

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

  //finding max
  max = find_max(array);

  //making an array of size max
  for (int i = 0; i <= max; i++)
  {
    countArray[i] = 0;
  }

  // inc count in count array
  for (int i = 0; i < n; i++)
  {
    countArray[array[i]]++;
  }

  int j = 0;
  for (int i = 0; i <= max; i++)
  {
    temp = countArray[i];
    while (temp--)
    {
      array[j] = i;
      j++;
    }
  }

  printf("\nSorted Array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }
}

int find_max(int array[])
{

  int max = 0;
  for (int i = 0; i < sizeof(array); i++)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
  }

  return max;
}
