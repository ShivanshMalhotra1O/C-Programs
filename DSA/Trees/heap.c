#include <stdio.h>
#include <stdlib.h>

void maxheap(int a[], int n, int i)
{
  int swap;
  int largest = i;
  int l = 2 * i + 1; // left child
  int r = 2 * i + 2; // right child

  if (l < n && a[l] > a[largest])
    largest = l;

  if (r < n && a[r] > a[largest])
    largest = r;

  if (largest != i)
  {
    swap = a[i];
    a[i] = a[largest];
    a[largest] = swap;

    maxheap(a, n, largest);
  }
}

void heapsort(int a[], int n)
{
  int i;
  int swap;
  for (i = n / 2 - 1; i >= 0; i--) // Here we are inserting elements in max loop
  {
    maxheap(a, n, i);
  }
  for (i = n - 1; i >= 0; i--) // Here we are deleting element in max loop and storing them in ascemding order
  {
    swap = a[0];
    a[0] = a[i];
    a[i] = swap;
    maxheap(a, i, 0);
  }
}

int main()
{

  int n, i;

  printf("Size of the array:");
  scanf("%d", &n);

  int *arr = calloc(n, sizeof(int));

  printf("Enter the elements of the array:");
  for (i = 0; i < n; i++)
  {
    scanf("%d", arr + i);
  }

  printf("Unsorted array:\t");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", *(arr + i));
  }

  printf("\n");
  heapsort(arr, n);
  printf("\n");

  printf("Sorted array: \t ");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", *(arr + i));
  }

  return 0;
}