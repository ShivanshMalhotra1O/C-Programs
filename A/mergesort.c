#include <stdio.h>
#include<stdlib.h>

void merge(int A[], int mid, int first_index, int last_index)
{
    int i, j, k;
    int b[10];
    i = first_index;
    j = mid + 1;
    k = first_index;

    while (i <= mid && j <= last_index)
    {
        if (A[i] <= A[j])
        {
            b[k] = A[i];
            i++;         
            k++;
        }
        else
        {
            b[k] = A[j];
            j++;
            k++;
        }
    }
    if(j > last_index){
    while (i <= mid)
    {
        b[k] = A[i];
        i++;
        k++;
    }
    }
    else{
    while (j <= last_index)
    {
        b[k] = A[j];
        j++;
        k++;
    }
    }
    for (int i = first_index; i <= last_index; i++)
    {
        A[i] = b[i];
    }
}

void mergesort(int A[], int first_index, int last_index)
{
    int mid;

    if (first_index < last_index)
    {
        mid = (first_index + last_index) / 2;
        mergesort(A, first_index, mid);
        mergesort(A, mid + 1, last_index);
        merge(A, mid,first_index,last_index);
    }
}
void main()
{
    // int A[] = {17, 2, 5, 9, 7, 94, 10,68};

    int n,i;

    printf("Size of the array:");
    scanf("%d",&n);

    int *arr = calloc(n,sizeof(int));


    printf("Enter the elements of the array:");
    for (i=0;i<n;i++){
        scanf("%d",arr+i);
    }
  

    printf("Unsorted Array:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t ", *(arr+i));
    }
    printf("\n\n");

    mergesort(arr, 0, n-1);

    printf("Sorted Array:\t");
    for (int i = 0; i < 8; i++)
    {
        printf("%d\t ", *(arr+i));
    }
    printf("\n\n"); 
}