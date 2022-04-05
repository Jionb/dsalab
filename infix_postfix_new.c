#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct stack
{
  int top;
  int capacity;
  char *arr;

}stack;

void create(stack *s,int c)
{
  s->capacity=c;
  s->top=-1;
  s->arr=(char *)malloc(s->capacity*sizeof(char));
}
void push(stack *s,char data)
{
  if(s->top==s->capacity-1)
{
  printf("stack overflow\n");
  return;
}
s->top++;
s->arr[s->top]=data;
}

int prec(char x)
{
  switch(x)
  {
    case '(':return 1;
    case '+':
    case '-':return 2;
    case '*':
    case '/':
    case '%':return 3;
    case '^':return 4;
  }
  return -1;
}

char pop(stack *s)
{
  if(s->top==-1)
  {
    printf("Stack Undeflow\n");
    return '$';
  }

  char result=s->arr[s->top];
  s->top--;
  return result;

}

char peek(stack *s)
{
  if(s->top==-1)
  {
    printf("Stack Undeflow\n");
    return '$';
  }

  return s->arr[s->top];
}
void validation(char arr[])
{
  int len=strlen(arr);
  if((arr[0]!='(' && isalnum(arr[0])==0 ) || (isalnum(arr[len-1])==0 && arr[len-1]!=')') )
  {
    printf("Invalid infix expressionn\n");
    exit(0);
  }
  for(int i=0;i<len-1;i++)
  {

    if(isalnum(arr[i])==0 && arr[i]!=')' && prec(arr[i])==-1)
    {
      printf("Invalid infix expression\n");
      exit(0);
    }
  }
}

int isempty(stack *s)
{
  if(s->top==-1)
  return 1;
  else
  return 0;
}

void itp(stack *s,char arr[],int c)
{
  int k=-1;
  for(int i=0;arr[i]!='\0';i++)
  {

    if(isalnum(arr[i])!=0)
    {
      arr[++k]=arr[i];
    }
    else if(arr[i]=='(')
    {
      push(s,arr[i]);
    }
    else if((isempty(s)==1 || peek(s)=='(') && arr[i]!=')')
    {
        push(s,arr[i]);
    }
      else if(arr[i]==')')
      {
        while(isempty(s)==0 && peek(s)!='(')
        {
          arr[++k]=pop(s);
        }
        if(isempty(s)==1)
        {
          printf("Invalid infix expressiona\n");
          return;
        }
        char x=pop(s);
      }
      else
      {
        while(isempty(s)==0 && prec(arr[i])<=prec(peek(s)) && arr[i]!='^')
        {
          arr[++k]=pop(s);
        }
        push(s,arr[i]);
      }
    }

  while(isempty(s)==0)
  {
    arr[++k]=pop(s);
  }
  arr[++k]='\0';
  printf("The postfix expression is: %s",arr);

}
int main()
{
  stack s;
  int n;
  printf("Enter the capacity\n");
  scanf("%d",&n);
  create(&s,n);
  char infix[100];
  printf("Enter the infix expression\n");
  scanf("%s",infix);
  validation(infix);
  itp(&s,infix,n);
  return 0;

}
