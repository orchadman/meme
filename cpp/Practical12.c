#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int arr[20];
int SIZE=10;
void merge(int beg,int mid,int end)
{
    int i=beg,j=mid+1,index=beg,temp[10],k;
    while(i<=mid && j<=end)
    {
        if (arr[i]<arr[j])
        {
            temp[index]=arr[i];
            i++;
        }
        else
        {
            temp[index]=arr[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=arr[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
    {
        arr[k]=temp[k];
    }
}
void mergesort(int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        mergesort(beg,mid);
        mergesort(mid+1,end);
        merge(beg,mid,end);
    }
}
void main()
{
    int n,i;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter %dth element : ",i);
        scanf("%d",&arr[i]);
    }
    mergesort(0,n-1);
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }   
}