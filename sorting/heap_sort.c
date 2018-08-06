/*

Reference: https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec04.pdf


1. Build Max Heap from unordered array;
2. Find maximum element A[1];
3. Swap elements A[n] and A[1]:
 now max element is at the end of the array!
4. Discard node n from heap
 (by decrementing heap-size variable)
5. New root may violate max heap property, but its
children are max heaps. Run max_heapify to fix this.
6. Go to Step 2 unless heap is empty. 


Build_Max_Heap(A, heapsize):
 for i=n/2 downto 1
 do Max_Heapify(A, i, heapsize) 

Max_Heapify(A, heapsize)
 l = left(i)
r = right(i)
if (l <= heap-size and A[l] > A[i])
 then largest = l else largest = i
if (r <= heap-sizeand A[r] > A[largest])
 then largest = r
if largest = i
 then exchange A[i] and A[largest]
 Max_Heapify(A, largest) 

*/

/*

Running time:
  after n iterations the Heap is empty
  every iteration involves a swap and a max_heapify
  operation; hence it takes O(log n) time

  Overall O(n log n) 

*/

#include <stdio.h>
#include <stdlib.h>

int array[10], sortedArray[10];
int n, temp, largest;
int heapSort(int a[], int heapsize);
int buildMaxHeap(int array[], int heapsize);
int maxHeapify(int array[], int i, int heapSize);

int main()
{

  printf("---* HEAP SORT *--- \n");

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
  int heapsize = n - 1;
  heapSort(array, heapsize);

  printf("\nSorted Array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }
}

int heapSort(int a[], int heapsize)
{
  int i, tmp;
  buildMaxHeap(a, heapsize);
  for (i = heapsize; i > 0; i--)
  {
    tmp = a[i];
    a[i] = a[0];
    a[0] = tmp;
    heapsize--;
    maxHeapify(a, 0, heapsize);
  }
}

int buildMaxHeap(int array[], int heapsize)
{

  for (int i = heapsize / 2; i >= 0; i--)
  {

    maxHeapify(array, i, heapsize);
  }
}

int maxHeapify(int array[], int i, int heapSize)
{

  int l = (2 * i) + 1;
  int r = (2 * i + 1) + 1;

  if (l <= heapSize && array[l] > array[i])
  {
    largest = l;
  }
  else
  {
    largest = i;
  }

  if (r <= heapSize && array[r] > array[largest])
  {
    largest = r;
  }

  if (largest != i)
  {
    printf("largest: %d", array[largest]);
    temp = array[i];
    array[i] = array[largest];
    array[largest] = temp;
    maxHeapify(array, largest, heapSize);
  }
}
