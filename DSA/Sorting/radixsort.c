#include<stdio.h>



void countsort(int a[],int n, int pos){

    int count[10]={0}, i;
    int b[100];

    for (i=0 ; i<n; i++){
        count[(a[i]/pos)%10]++;
    }

    for (i=1 ; i<10; i++){
        count[i] = count[i] + count[i-1];
    }

    for (i=n-1 ; i>=0; i--){
        b[--count[(a[i]/pos)%10]] = a[i];
    }

    for (i=0 ; i<n; i++){
        a[i] = b[i];
    }

   
}

void radixsort(int a[] , int n){
    int max = a[0];

    for(int i=0;i<n;i++){
        if(a[i]>max){
            max = a[i];
        }
    }

    for(int pos = 1 ; max/pos>0; pos*=10){
        countsort(a,n,pos);
    }
}

void main()
{
    int a[10] = {2,56,87,1,90,45,76,89,34,65};
    int i,n;

    n=10;

    printf("Unsorted Array \n");
    for (i=0 ; i<n; i++){
        printf("%d \t",a[i]);
    }

    radixsort(a,n);

    printf("\n");

    printf("Sorted Array \n");
    for (int j=0 ; j<n; j++){
        printf("%d \t",a[j]);
    }
    
}