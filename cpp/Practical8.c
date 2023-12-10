#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL,*temp=NULL;
struct node *insert(struct node *front);
int deleteq();
void display(struct node *front);
int main()
{
    int choice,val;
    do{
        printf("\n***MAIN MENU***\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
        case 1: front=insert(front);
            break;
        case 2: val=deleteq();
            if(val!=-1)
            {
                printf("The value deleted is %d \n",val);
            }
            break;
        case 3: display(front);
            break;
        default:
            break;
        }
    } while (choice!=4);
    return 0;
}
void display(struct node *front)
{
    temp=front;
    if (temp==NULL&&front==NULL)
    {
        printf("Queue is Empty!");
    }
    else
    {
        printf("Queue is : ");
        while (temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
struct node *insert(struct node *front)
{
    int val;
    struct node *newnode;
    printf("Enter the data : ");
    scanf("%d",&val);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if(front==NULL)
    {
        front=newnode;
        rear=newnode;
        newnode->next=NULL;
    }
    else
    {
        rear->next=newnode;
        newnode->next=NULL;
        rear=newnode;
    }
    printf("Successfully Inserted.\n");
    return front;
}
int deleteq()
{
    int val;
    struct node *temp;
    if (front==NULL)
    {
        printf("Queue is Empty\n");
        val=-1;
    }
    else
    {
        temp=front;
        val=front->data;
        front=front->next;
        free(temp);
    }
    return val;
}