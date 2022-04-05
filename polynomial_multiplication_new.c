#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int coef;
  int power;
  struct node *next;

}node;

node *createNode(int coef,int power)
{
  node *temp=(node *)malloc(sizeof(node));
  temp->coef=coef;
  temp->power=power;
  temp->next=NULL;
  return temp;
}

node *insertAtEnd(node *head,int coef,int power)
{
  node *temp=createNode(coef,power);
  if(head==NULL)
  return temp;
  node *cur=head;
  while(cur->next!=NULL)
  {
    cur=cur->next;
  }
  cur->next=temp;
  return head;
}

node *addition(node *head)
{
  node *cur=head;
  node *temp;
  while(cur->next!=NULL)
  {
    temp=cur->next;
    while(temp!=NULL)
    {
      if(cur->power==temp->power)
      {
        cur->coef=cur->coef+temp->coef;
        temp->coef=0;
        temp->power=0;
      }
      temp=temp->next;
    }
    cur=cur->next;
  }
  return head;

}

node *multiply(node *head1,node *head2)
{
  node *head3=createNode(-1,-1);
  node *cur3=head3;
  node *cur1=head1;
  node *cur2=head2;
  while(cur1!=NULL)
  {
    while(cur2!=NULL)
    {
      cur3->next=createNode(cur1->coef*cur2->coef,cur1->power+cur2->power);
      cur3=cur3->next;
      cur2=cur2->next;
    }
    cur1=cur1->next;
    cur2=head2;
  }
  head3=head3->next;
  head3=addition(head3);
  return head3;

}

void display(node *head)
{
  if(head==NULL)
  {
    printf("0");
    return;
  }

  node *cur=head;
  int flag=0;
  while(cur!=NULL)
  {
    if(cur->coef!=0)
    {
      if(cur!=head && cur->coef>0)
      printf("+");

      printf("%dx^%d",cur->coef,cur->power);
      flag=1;
    }
    cur=cur->next;
  }
  if(flag==0)
  printf("0");
  printf("\n");
}


int main()
{
  node *head1=NULL;
  int coef,power;
  node *head2=NULL;
  int n;
  printf("Enter number of temrms in poly-1\n");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    printf("Enter the coef and power\n");
    scanf("%d %d",&coef,&power);
    head1=insertAtEnd(head1,coef,power);
  }
 printf("Poly-1 :\n");
 display(head1);
  printf("Enter number of temrms in poly-2\n");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    printf("Enter the coef and power of polynomial\n");
    scanf("%d %d",&coef,&power);
    head2=insertAtEnd(head2,coef,power);
  }
  printf("Poly-2 :\n");
  display(head2);
  node *head3=multiply(head1,head2);
  printf("Poly-3 :\n");
  display(head3);

}
