#include<stdio.h>

void countingsort(int array[], int n){

int max,i,j;
int b[10];

max = array[0];

for(j=1;j<n;j++){
    if(array[j]>max){
        max = array[j];
    }
}

int c[100];  

for(i=0;i<=max;i++){
c[i]=0;
}

for(i=0 ; i<n;i++){
    c[array[i]]++;
}

for(i=1 ; i<=max;i++){
    c[i] += c[i-1];
}

for(i = n; i>=0;i--){
    b[c[array[i]]-1] = array[i];
    c[array[i]]--;
}

for(i = 0; i<n;i++){
    array[i] = b[i];
}
}

void printarray(int array[],int n ){
    for(int i=0;i<n;i++){
    printf("%d\t",array[i]);
}
}

void main()

{
int array[10]={};
int n ,i;

printf("Enter the length of the array:");
scanf("%d",&n);

printf("Enter the elements in the array :\n");
for(i=0;i<n;i++){
    scanf("%d",&array[i]);
}

printf("Unsorted Array\n");
for(i=0;i<n;i++){
    printf("%d\t",array[i]);
}

countingsort(array, n);

printf("\n");
printf("Sorted Array after Counting Sort :\n");
printarray(array,n); 
}