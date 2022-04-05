#include<stdio.h>
#include<stdlib.h>

typedef struct S
{
  int *arr;
  int capacity;
  int top;

}S;

void create(S *s,int c)
{
  s->capacity=c;
  s->top=-1;
  s->arr=(int *)malloc(s->capacity*sizeof(int));
}

void push(S *s,int data)
{
  if(s->top>s->capacity-1)
  {
    printf("Stack Overflow\n");
    return;
  }
  s->top++;
  s->arr[s->top]=data;

}


int pop(S *s)
{
  if(s->top==-1)
  {
    printf("Stack underflow\n");
    return 999; //error code
  }
  int result=s->arr[s->top];
  s->top--;
  return result;

}

int peek(S *s)
{
  if(s->top==-1)
  {
    printf("Stack underflow\n");
    return 999;
  }
  return s->arr[s->top];

}

void display(S *s)
{
  if(s->top==-1)
  {
    printf("Stack is empty\n");
    return;
  }
  for(int i=s->top;i>=0;i--)
  {
    printf("%d\n",s->arr[i]);
  }
  printf("\n");
}

int size(S *s)
{
  return s->top+1;
}

int thirdFromTop(S *s,S *t)
{
  if(size(s)<3)
  {
    printf("Size of the stack is less then 3\n");
    return 999;
  }

  int i=0;
  while(i<2)
  {
    push(t,pop(s));
    i++;
  }
  int Y=peek(s);
  i=0;
  while(i<2)
  {
    push(s,pop(t));
    i++;
  }
  return Y;
}

int thirdFromBottom(S *s,S *t)
{
  if(size(s)<3)
  {
    printf("Size of the stack is less then 3\n");
    return 999;
  }
  for(int i=s->top;i>2;i--)
  {
    push(t,pop(s));
  }
  int Y=peek(s);

  for(int i=t->top;i>=0;i--)
  {
    push(s,pop(t));
  }

  return Y;
}

void popNelement(S *s,S *t,int n)
{
  if(size(s)<n)
  {
    printf("Stack as element less then N\n");
    return;
  }

  int i=0;
  while(i<n)
  {
    push(t,pop(s));
    i++;
  }
printf("Actual Stack Content\n");
display(s);
printf("Auxilary Stack Content\n");
display(t);

i=0;
while(i<n)
{
  push(s,pop(t));
  i++;
}

printf("Stack after the operation\n");
display(s);

}

int main()
{
  S s,t;
  int c;
  int d;
  int a;
  int ele;
  int N;
  int choice;
  printf("Enter the capcity of the stack\n");
  scanf("%d",&c);
  create(&s,c);
  create(&t,c);
  do {
    printf("Enter the choice\n");
    printf("1.push\t2.pop\t3.peek\t4.size\t5.third from top\t6.third from bottom\t7.pop N element\t8.display\t0.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("Number of elements to be pushed?(should be less than stack capacity)\n");
      scanf("%d",&a);
      for(int i=0;i<a;i++)
      {
        printf("Enter the element\n");
        scanf("%d",&ele);
        push(&s,ele);
      }

      break;

      case 2:
          if(peek(&s)==999)
          {

          }
          else
          {
            printf("element %d popped succesfully\n",pop(&s));
          }
          break;

      case 3:
      if(peek(&s)==999)
      {

      }
      else
      {
        printf("Element at the top: %d\n",peek(&s));
      }
      break;

      case 4:
      printf("size of the stack: %d\n",size(&s));
      break;

      case 5:
      if(thirdFromTop(&s,&t)==999)
      {

      }
      else
      {
        printf("The third element from the top is: %d\n",thirdFromTop(&s,&t));
      }
      break;

      case 6:

      if(thirdFromBottom(&s,&t)==999)
      {

      }
      else
      {
        printf("The third element from the Bottom is: %d\n",thirdFromBottom(&s,&t));
      }
      break;

      case 7:
      printf("Enter N\n");
      scanf("%d",&N);
      popNelement(&s,&t,N);
      break;

      case 8:
      printf("Stack content:\n");
      display(&s);
      break;
      case 0:
      break;
      default:
      printf("Invalid input\n");
      break;
    }

  } while(choice!=0);
  return 0;
}
