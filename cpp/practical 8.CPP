#include<stdio.h>
#include<stdlib.h> // Include <stdlib.h> for exit()

#define MAXSIZE 5

void insert();
void del();
void display();

int front = -1, rear = -1;
int queue[MAXSIZE];

int main() {
    int choice = 0; // Initialize choice

    while (choice != 4) {
        printf("\n ***********main menu***************\n");
        printf("\n1.insert \n2.delete \n3.display the queue \n4.exit \n");
        printf("\n enter your choice: ");
        scanf("%d", &choice); // Capture user choice

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0); // Use the standard exit() function from <stdlib.h>
                break;
            default:
                printf("\n enter valid choice \n");
                break;
        }
    }

    return 0;
}

void insert() {
    int item;
    printf("\n enter the element: ");
    scanf("%d", &item);

    if (rear == MAXSIZE - 1) {
        printf("\n overflow \n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("\n value inserted");
}

void del() {
    int item;
    if (front == -1 || front > rear) {
        printf("\n underflow \n");
        return;
    } else {
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
        printf("\n value deleted");
    }
}

void display() {
    int i;
    if (rear == -1) {
        printf("\n Empty queue \n");
    } else {
        printf("\n printing values .... \n");
        for (i = front; i <= rear; i++) {
            printf("\n %d \n", queue[i]); // Use %d to print integers
        }
    }
}
