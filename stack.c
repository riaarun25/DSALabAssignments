#include<stdio.h>
#include<conio.h>
int list[5],tos=-1,size=4,ch;
void main()
{
    void push();
    void display();
    void pop();
    void peep();
    
    printf("\n1:Push");
    printf("\n2:Display");
    printf("\n3:Pop");
    printf("\n4:Peep");
    printf("\n0:Exit");
    do
    {
      printf("\nEnter your choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
    
       case 1:
           push();
           break;
       case 2:
           display();
           break;
       case 3:
           pop();
           break;
       case 4:
           peep();
           break;
        case 5:
            break;
     }
     }
     while(ch!=0);
}
void push()
{
   int value;
   if(tos>=size)
   {
     printf("\nStack overflow.");
     return;
   }
   else
   {
      printf("\nEnter the value: ");
      scanf("%d",&value);
      tos=tos+1;
      list[tos]=value;
   }
}
void display()
{
   int i;
   if(tos==-1)
   {
     printf("\nElement is not availabe");
     return;
   }
   else
   {
      for(i=0;i<=tos;i++)
      printf("\nThe element is %d",list[i]);
   }
}
void pop()
{
  if(tos==0)
  {
    printf("\nStack underflow.");
    return;
  }
  else
  {
    tos=tos-1;
   printf("\nElement deleted");
 }
}
void peep()
{
   int s;
   printf("\nEnter position: ");
   scanf("%d",&s);
   if(tos-s<=-1)
   {
      printf("\nStack overflow.");
      return;
   }
   else
   {
     printf("\nThe element is %d",list[tos-s]);
   }
}
