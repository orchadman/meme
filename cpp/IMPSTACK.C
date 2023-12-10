#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *searchll(struct node *);
struct node *deletell(struct node *);

int main()
{
    int opt;
    do
    {
        printf("\n*****Main Menu*****\n");
        printf("1. Create a list\n");
        printf("2. Display list\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert after\n");
        printf("6. Search\n");
        printf("7. Delete an element\n");
        printf("8. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &opt);
        printf("\n");
        switch (opt)
        {
        case 1:
            start = create(start);
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = insert_after(start);
            break;
        case 6:
            start = searchll(start);
            break;
        case 7:
            start = deletell(start);
            break;
        case 8:
            break;
        }
    } while (opt != 8);
    return 0;
}

struct node *create(struct node *start)
{
    struct node *new_node = NULL, *temp = NULL;
    int val;
    printf("Enter the data or enter -1 to exit:");
    scanf("%d", &val);
    while (val != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = val;
        if (start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = NULL;
        }
        printf("Enter the data or enter -1 to exit:");
        scanf("%d", &val);
    }
    printf("Linked list successfully created.\n");
    return start;
}

struct node *display(struct node *start)
{
    struct node *temp = NULL;
    temp = start;
    printf("The Linked List is:");
    while (temp != NULL)
    {
        printf("\t %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node = NULL;
    int val;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to be inserted:");
    scanf("%d", &val);
    new_node->data = val;
    new_node->next = start;
    start = new_node;
    printf("Successfully Inserted.\n");
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *new_node = NULL, *temp = NULL;
    int val;
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to be inserted:");
    scanf("%d", &val);
    new_node->data = val;
    temp->next = new_node;
    new_node->next = NULL;
    printf("Successfully inserted.\n");
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node = NULL, *temp = NULL;
    int val, val1;
    printf("Enter value after which new node is to be inserted:");
    scanf("%d", &val1);
    temp = start;
    while (temp->data != val1)
    {
        temp = temp->next;
    }
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to be inserted:");
    scanf("%d", &val);
    new_node->data = val;
    new_node->next = temp->next;
    temp->next = new_node;
    printf("Successfully Inserted.\n");
    return start;
}

struct node *searchll(struct node *start)
{
    int val, count, x = 0;
    struct node *temp;
    printf("Which value are you looking for?:\n");
    scanf("%d", &val);
    count = 1;
    temp = start;
    while (temp->data != val && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL && temp->data != val)
    {
        printf("Value not found\n");
    }
    else if (temp->next == NULL && temp->data == val)
    {
        printf("Value found at %d node\n", count);
    }
    else
    {
        printf("Value found at %d node\n", count);
    }
    return start;
}

struct node *deletell(struct node *start)
{
    int val;
    struct node *pre = NULL, *temp = NULL;
    printf("Enter value to be deleted:");
    scanf("%d", &val);
    temp = start;
    while (temp->data != val && temp->next != NULL)
    {
        pre = temp;
        temp = temp->next;
    }
    if (temp == start)
    {
        start = start->next;
        free(temp);
        printf("Successfully Deleted.\n");
    }
    else if (temp->next == NULL && temp->data != val)
    {
        printf("Value not found\n");
    }
    else if (temp->next == NULL && temp->data == val)
    {
        pre->next = NULL;
        free(temp);
        printf("Successfully Deleted.\n");
    }
    else
    {
        pre->next = temp->next;
        free(temp);
        printf("Successfully Deleted.\n");
    }
    return start;
}
