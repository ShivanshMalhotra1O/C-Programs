#include<stdio.h>

void main(){
int a[6];
int i,j;
int b;

printf("enter the element:");
for ( i = 0; i < 5; i++)
{
    scanf("%d",&b);

if(a[i]==0){
    a[i]=b;
    }

else{
    j=i-1;
}
while (a[j]>b && a[j]>=0)
{
    a[j+1]=a[j];
    j=j-1;
}
a[j+1]=b;
}

printf("Sorted Array is :\n");
for( i=0;i<5;i++){
    printf("%d\t",a[i]);
}

}