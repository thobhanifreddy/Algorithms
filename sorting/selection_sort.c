/*
Algorithm
Step 1 − Set MIN to location 0
Step 2 − Search the minimum element in the list
Step 3 − Swap with value at location MIN
Step 4 − Increment MIN to point to next element
Step 5 − Repeat until list is sorted
Pseudocode
procedure selection sort 
   list  : array of items
   n     : size of list

   for i = 1 to n - 1
   // set current element as minimum
      min = i    
  
      // check the element to be minimum 

      for j = i+1 to n 
         if list[j] < list[min] then
            min = j;
         end if
      end for

      // swap the minimum element with the current element
      if indexMin != i  then
         swap list[min] and list[i]
      end if
   end for
	
end procedure
*/

/*
running time of Selection sort is quite insensitive to the input.
Selection sort gonna iterate till end everytime and it spends most of its time trying to find the minimum element in the unsorted part of the array.

Whatever is a case,
Selecting the first lowest element requires scanning all n elements (this takes n - 1 comparisons) and then swapping it into the first position. 
 
Finding the next lowest element requires scanning the remaining n - 1 elements and so on, 
= (n - 1) + (n - 2) + ... + 2 + 1 = n(n - 1) / 2 
= O(n^2) comparisons.

Thus,
Best Case :       O(n)^2 
Worst Case :    O(n)^2 
Average Case : O(n)^2 
*/

#include <stdio.h>

int main()
{
  int array[10];
  int n, swaps = 0, temp;

  printf("---* SELECTION SORT *--- \n");

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

  for (int i = 0; i < n - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (array[j] < array[min])
      {
        min = j;
      }
    }
    if (min != i)
    {
      swaps++;
      temp = array[i];
      array[i] = array[min];
      array[min] = temp;
    }
  }

  printf("\nSorted Array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\nSwaps: %d\n", swaps);
}
