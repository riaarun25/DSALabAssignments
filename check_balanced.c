#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack
{
    int top;
    char arr[MAX_SIZE];
} 
st;

void init()
{
    st.top = -1;
}

bool isEmpty()
{
    if(st.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if(st.top == MAX_SIZE-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(char item)
{
    if(isFull())
    {
        printf("Full stack");
    }
    else
    {
        st.top++;
        st.arr[st.top] = item;
    }
}

void pop()
{
    if(isEmpty())
    {
        printf("Empty stack");
    }
    else
    {
        st.top--;
    }
}

char gettop()
{
    return st.arr[st.top];
}

bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

void main()
{
    char in_expr[MAX_SIZE];
    int length=0,i,j;

    init();

    printf("Enter expression:");
    gets(in_expr);

    length = strlen(in_expr);

    for(i=0;i<length;i++)
    {
        if(in_expr[i] == '(' || in_expr[i] == '{' || in_expr[i] == '[')
        {
                push(in_expr[i]);
        }
        else 
        if(in_expr[i] == ')' || in_expr[i] == '}' || in_expr[i] == ']')
        {
            char a = gettop();
            printf("%c",a);
            if(isEmpty() || !ArePair(gettop(),in_expr[i]))
            {
                printf("\nThe expression is unbalanced.");
                return 0;
            }else
            {
                pop();
            }
        }
    }
    if(isEmpty())
    {
        printf("\nThe expression is balanced.");
    }
    else
    {
        printf("\nThe expression is unbalanced.");
    }
}
