#include<stdio.h>
#include<conio.h>
int a[10];
void search(int, int);
void main()
{
    int i,n,val;
    printf("Enter the size of array:");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter the %d element of array : ",i);
        scanf("%d",&a[i]);
    }
    printf("Enter the value to be searched:");
    scanf("%d",&val);
    search(n,val);
    getch();
}
void search(int n, int val)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        if (a[i]==val)
        {
            printf("Value found at %dth postion",i);
            break;
        }
        
    }
    
}