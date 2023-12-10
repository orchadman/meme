#include<stdio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node*next;
};
struct node*x,*y,*z;
void main()
{
 int val;
 printf("Enter value 0 for 1st node");
 scanf("%d",&val);
x=(struct node*)malloc(sizeof(struct node));
y=(struct node*)malloc(sizeof(struct node));
z=(struct node*)malloc(sizeof(struct node));
x->data=val;
printf("Enter value 0 for 2nd node");
scanf("%d",&val);
y->data=val;
printf("Enter value 0 for 3rd node");
scanf("%d",&val);
z->data=val;
x->next=y;
y->next=z;
printf("The data in 1st node is\n%d\n",x->data);
printf("The data in 2nd node is %d\n",x->next->data);
printf("The data in 3rd node is %d\n",x->next->next->data);
}