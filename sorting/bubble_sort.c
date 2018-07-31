/*

procedure bubbleSort( A : list of sortable items )
    n = length(A)
    repeat
        swapped = false
        for i = 1 to n-1 inclusive do
            // if this pair is out of order 
            if A[i-1] > A[i] then
                // swap them and remember something changed 
                swap( A[i-1], A[i] )
                swapped = true
            end if
        end for
    until not swapped
end procedure


*/

/*

Case-1: O(n) (Best case): 
  This time complexity can occur if the array is already sorted, and that means that no swap occurred and only 1 iteration of n elements

Case-2: O(n^2) (Worst case): 
The worst case is if the array is already sorted but in descending order. 
This means that in the first iteration it would have to look at n elements, then after that it would look n - 1 elements (since the biggest integer is at the end) and so on and so forth till 1 comparison occurs. 
Big-O = n + n - 1 + n - 2 ... + 1 = n*(n - 1)/2 = O(n^2)    // 1 + 2 + ... + (n - 2 ) + (n - 1) + n
 
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
  int array[10];
  int temp, n, swaps = 0;

  printf("---* BUBBLE SORT *--- \n");

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

  while (true)
  {
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
      if (array[i] > array[i + 1])
      {
        swaps++;
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
    if (swapped == false)
    {
      break;
    }
  }

  printf("\nSorted Array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\nSwaps: %d\n", swaps);
}