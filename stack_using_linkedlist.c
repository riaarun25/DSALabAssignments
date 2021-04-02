#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}
*top,*top1,*temp;
 
int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();
 
int count = 0;
 
void main()
{
    int no, ch, e;
 
    printf("\n1 Push");
    printf("\n2 Pop");
    printf("\n3 Top");
    printf("\n4 Empty");
    printf("\n5 Exit");
    printf("\n6 Dipslay");
    printf("\n7 Stack Count");
    printf("\n8 Destroy stack");
 
    create();
 
    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top == NULL)
                printf("No elements in stack");
            else
            {
                e = topelement();
                printf("\nTop element is %d", e);
            }
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            stack_count();
            break;
        case 8:
            destroy();
            break;
        default :
            printf("Option unavailable. ");
            break;
        }
    }
}

void create()
{
    top = NULL;
}

void stack_count()
{
    printf("\nNumber of elements: %d", count);
}

void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }

void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nCan't pop from stack");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\nPopped value is %d", top->info);
    free(top);
    top = top1;
    count--;
}

int topelement()
{
    return(top->info);
}

void empty()
{
    if (top == NULL)
        printf("\nStack is empty");
    else
        printf("\nStack has %d elements", count);
}

void destroy()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("\nStack element have been destroyed");
    count = 0;
}
