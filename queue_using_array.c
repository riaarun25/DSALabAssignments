#include <stdio.h>
#define MAX 50
 
void insert();
void delete();
void display();

int queue_array[MAX];
int rear = - 1;
int front = - 1;
int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element\n");
        printf("2.Delete element\n");
        printf("3.Display all elements\n");
        printf("4.Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            return 0;
            
            default:
            printf("Option unavailable\n");
        } 
    } 
} 

void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("\nInset the element: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue underflow \n");
        return ;
    }
    else
    {
        printf("\nElement deleted: %d\n", queue_array[front]);
        front = front + 1;
    }
}
 
void display()

{
    int i;
    if (front == - 1)
        printf("\nEmpty queue\n");
    else
    {
        printf("\nQueue is \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
