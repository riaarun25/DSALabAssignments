#include<stdio.h>
#include<conio.h>
#define MAX 5
int list[MAX];
int len=0,i;
void insert(int,int);
void del(int);
void display();
main(){
int n;
do
{
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Search\nEnter your choice: ");
    scanf("%d",&n);
    if(n==1)
    {
        int e,p;
        printf("Enter element to insert and the position: ");
        scanf("%d %d",&e,&p);
        insert(e,p-1);
        
    }
    else if(n==2)
    {
        int e;
        printf("Enter position: ");
        scanf("%d",&e);
        del(e-1);
        
    }
    else if(n==3)
    {
        display();
        
    }
    else if(n==4)
    {
        int e,value=0;
        printf("Enter value to be searched:");
        scanf("%d",&e);
        printf("Position of %d = %d\n",e,search(e));
        
    }
    
}
while(1);
    
}
int search(int e)
{
    for(i=0;i<len;i++)
    {
        if(list[i]==e)
        return i;
        
    }
    return -1;
    
}
void insert(int e,int p)
{
    if(len==MAX || (p<0||p>len))
    printf("LIST FULL! OR Invalid position\n");
    else
    {
        for(i=len-1;i>=p;i--)
        list[i+1]=list[i];
        list[p]=e;
        len++;
        
    }
    
}
void del(int p)
{
    if((p<0||p>=len) || len==0)
    printf("Invalid position OR list empty\n");
    else
    {
        for(i=p+1;i<len;i++)
        list[i-1]=list[i];
        len--;
        
    }
    
}
void display()
{
    if(len)
    {
        for(i=0;i<len;i++)
        printf("%d ",list[i]);
        printf("\n");
        
    }
    else
    printf("List empty\n");
}
