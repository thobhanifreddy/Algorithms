/*

MergeSort(low, high)
If low > high
     1. Find the middle point to divide the array into two halves:  
             middle m = (low+high)/2
     2. Call mergeSort for first half:   
             Call mergeSort(low, mid)
     3. Call mergeSort for second half:
             Call mergeSort(mid + 1, high)
     4. Merge the two halves sorted in step 2 and 3 using 2 finger algorithm https://youtu.be/Kg4bqzAqRBM?t=28m36s:
             Call merge(low, high, mid)


*/

/*

Time Complexcity: nlogn   (base 2)

  If there are n elemnts in an array we can divide it in n/2 and n/2,  
  further we can devide one n/2 to n/4 and n/4 and so on till when there is only 1 element.
  If u imagine it like a tree...there will be (1 + logn) levels...
  in each level there will be n elements(eg. first level n/2 + n/2 = n second level n/4 + n/4 + n/4 + n/4 = n)

  thus,
    (Cn) * (1 + logn) = O(nlogn)


Space Complexity: O(n): 
    We use an extra array of n elements so auxilary spacre is n

*/

#include <stdio.h>

int array[10], helper[10];
int n, temp;
int mergeSort(int low, int high);
int merge(int low, int mid, int high);

int main()
{

  printf("---* MERGE SORT *--- \n");

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

  mergeSort(0, n - 1);

  printf("\nSorted Array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }
}

int mergeSort(int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;

    mergeSort(low, mid);      //left side of array
    mergeSort(mid + 1, high); //right side of array

    merge(low, mid, high); //here's when magic happens. sort&merge
  }
}

int merge(int low, int mid, int high)
{
  for (int i = low; i <= high; i++)
  {
    helper[i] = array[i]; //helper array
  }

  int i = low;
  int j = mid + 1;
  int k = low;

  //2 finger algorithm - https://youtu.be/Kg4bqzAqRBM?t=28m36s
  while (i <= mid && j <= high)
  {

    if (helper[i] <= helper[j])
    {
      array[k] = helper[i];
      i++;
    }
    else
    {
      array[k] = helper[j];
      j++;
    }
    k++;
  }
  while (i <= mid)
  {
    array[k] = helper[i];
    i++;
    k++;
  }
}