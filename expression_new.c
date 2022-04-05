#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define CAPACITY 100


typedef struct treenode{
  char data;
  struct treenode *left;
  struct treenode *right;
}treenode;

typedef struct stack{
  treenode *arr[CAPACITY];
  int capacity;
  int top;
}stack;

treenode *createTree(char data)
{
  treenode *temp=(treenode *)malloc(sizeof(treenode));
  temp->left=NULL;
  temp->right=NULL;
  temp->data=data;
  return temp;
}

void createStack(stack *s)
{
  s->top=-1;
}

void push(stack *s,treenode *data)
{
  if(s->top==s->capacity-1)
  {
    printf("Stack overflow\n");
    return;
  }

  s->top++;
  s->arr[s->top]=data;
}

treenode *pop(stack *s)
{
  if(s->top==-1)
  {
    printf("Stack Underflow\n");
    return NULL;
  }
  treenode *result=s->arr[s->top];
  s->top--;
  return result;
}

treenode *peek(stack *s)
{
  if(s->top==-1)
  {
    printf("Stack Underflow\n");
    return NULL;
  }
  return s->arr[s->top];

}

treenode *insert(treenode *second,treenode *first,treenode *op)
{
  op->right=first;
  op->left=second;
  return op;
}

int prec(char x)
{
  switch(x)
  {
    case '+':
    case '-':return 1;
    case '*':
    case '/':return 2;
    case '^':return 3;
  }
  return -1;
}

treenode *itp(stack *s,stack *t,char arr[])
{
  for(int i=0;arr[i]!='\0';i++)
  {
    if(!isalnum(arr[i]) && prec(arr[i])==-1)
    {
      printf("Invalid infix expression\n");
      exit(0);
    }
    if(isalnum(arr[i]))
    {
      treenode *temp=createTree(arr[i]);
      push(t,temp);
    }
    else if(s->top==-1)
    {
      treenode *temp=createTree(arr[i]);
      push(s,temp);
    }
    else
    {
      while(s->top!=-1 && prec(arr[i])<=prec(peek(s)->data) && arr[i]!='^')
      {
        if(t->top==0)
        {
          printf("Invalid infix expression\n");
          exit(0);
        }
        treenode *temp=insert(pop(t),pop(t),pop(s));
        push(t,temp);
      }
      push(s,createTree(arr[i]));
    }
  }

  while(s->top!=-1)
  {
    if(t->top==0)
    {
      printf("Invalid infix expression\n");
      exit(0);
    }
    treenode *temp=insert(pop(t),pop(t),pop(s));
    push(t,temp);
  }

  return peek(t);
}

void postOrder(treenode *root)
{
  if(root==NULL)
  return;

  postOrder(root->left);
  postOrder(root->right);
  printf("%c",root->data);

}

int main()
{
  stack s,t;
  char infix[100];
  printf("Enter the infix expression\n");
  scanf("%s",infix);
  createStack(&s);
  createStack(&t);
  treenode *root=itp(&s,&t,infix);
  postOrder(root);

}
