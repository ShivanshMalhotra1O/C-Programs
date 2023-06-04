#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t ", A[i]);
    }
 
}

int part(int A[], int fi, int li)
{
    int P = li; 
    int i=fi;
    int j=fi-1;
    int temp;

    while(i<P){
        if(A[i]>A[P]){
            i++;
        }
        else{
            j++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
        }
    }
    temp = A[j+1];
    A[j+1] = A[i];
    A[i] = temp;
    return j+1;
}

void quickSort(int A[], int fi, int li)
{
    int q;

    if (fi < li)
    {
        q = part(A, fi, li); 
        quickSort(A, fi, q - 1); 
        quickSort(A, q + 1, li); 
    }
}

int main()
{

    int A[] = {7,1,77,50,6,19,10,17};

    int n = 8;
    
    printf("Unsorted Array \n");
    printArray(A, n);
    quickSort(A, 0, 7);

    printf("\n");

    printf("Sorted Array \n");
    printArray(A, n);
    return 0;
}