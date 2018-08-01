/*
Pseudocode:

  i ← 1
  while i < length(A)
      j ← i
      while j > 0 and A[j-1] > A[j]
          swap A[j] and A[j-1]
          j ← j - 1
      end while
      i ← i + 1
  end while


*/

/*

Time Complexity:

  outer loop will always execute (n-1) times

  Best Case: Ω(n):
    It happens when only one one element is unsorted and thus 2nd while loops iterates only once. eg. 2 4 7 8, insert 9
    So,
      1 + 1 + 1 + .... + (n-1) + 1 = n   //outer while loop + inner while loop)

  worst casr: O(n^2):
    it happens when inner loop will execute everytime i.e. (n-2) times eg. 10 14 16 17 insert 9
    so, 
    1 + 2 + 3 + ... + (n-1) = n * (n-1) / 2 = O(n^2)                  //inner loop + outer loop 

Space complexity:
  The total space complexity of merge sort is O(n) since you have to store the elements somewhere. Nevertheless, there can indeed be a difference in additional space complexity, between an array implementation and a linked-list implementation.
  Note that you can implement an iterative version that only requires O(1) additional space. 
    

*/

#include <stdio.h>

int main()
{
  int array[10];
  int n, swaps = 0, temp;

  printf("---* INSERTION SORT *--- \n");

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
  int i = 1;
  while (i < n)
  {
    int j = i;
    while (j > 0 && array[j - 1] > array[j])
    {
      swaps++;
      temp = array[j - 1];
      array[j - 1] = array[j];
      array[j] = temp;
      j--;
    }
    i++;
  }
  printf("\nSorted Array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\nSwaps: %d\n", swaps);
}
