#include<stdio.h>
#include<conio.h>
void main()
{
 int arr[6],i;
 printf("Enter the array elements");
 for(i=0;i<6;i++)
{
 scanf("%d",& arr[i]);
}
 for(i=0;i<6;i++)
{
 printf("The %dth element of the array is %d\n",i,arr[i]);
}
 getch();
}
