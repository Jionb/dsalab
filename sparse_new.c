#include<stdio.h>
#include<stdlib.h>

int mat[100][100];

typedef struct node
{
  int data;
  int r;
  int c;
  struct node *next;
  struct node *prev;
}node;

node *createNode(int data,int r,int c)
{
  node *temp=(node *)malloc(sizeof(node));
  temp->data=data;
  temp->next=NULL;
  temp->prev=NULL;
  temp->r=r;
  temp->c=c;
}

node *insertAtEnd(node *head,int data,int r,int c)
{
  node *temp=createNode(data,r,c);
  if(head==NULL)
  {
    return temp;
  }
  node *cur=head;
  while(cur->next!=NULL)
  {
    cur=cur->next;
  }
  cur->next=temp;
  temp->prev=cur;
  return head;
}

node *createSparse(node *head,int m,int n)
{
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(mat[i][j]!=0)
      {
        head=insertAtEnd(head,mat[i][j],i,j);
      }
    }
  }
  return head;
}

void getsparse(node *head,int m,int n)
{
  node *cur=head;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(cur!=NULL && cur->r==i && cur->c==j)
      {
        printf("%d ",cur->data);
        cur=cur->next;
      }
      else
      {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

void traverse(node *head)
{
  node *cur=head;
  while(cur!=NULL)
  {
    printf("<--|%d||%d||%d|-->",cur->data,cur->r,cur->c);
    cur=cur->next;
  }
  printf("\n");
}


int main()
{
  int n,m;
  printf("Enter number of rows and columns in a matrix\n");
  scanf("%d %d",&m,&n);
  printf("Enter the matrix elements\n");
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      scanf("%d",&mat[i][j]);
    }
  }
  node *head=NULL;
  head=createSparse(head,m,n);
  printf("Linked list:\n");
  traverse(head);
  printf("Sparse matrix:\n");
  getsparse(head,m,n);
  printf("\n");


  return 0;
}
