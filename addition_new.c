#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
   int data;
   struct node *next;
}node;

node *createNode(int data)
{
  node *temp=(node *)malloc(sizeof(node));
  temp->next=temp;
  temp->data=data;
  return temp;
}

node *insertAtEnd(node *head,int data)
{
  head->data++;
  node *temp=createNode(data);
  if(head->next==head)
  {
    head->next=temp;
    temp->next=head;
    return head;
  }
  node *cur=head->next;
  while(cur->next!=head)
  {
    cur=cur->next;
  }
  cur->next=temp;
  temp->next=head;
  return head;

}

node *addition(node *head1,node *head2,node *head3)
{
  node *cur1=head1->next;
  node *cur2=head2->next;
  int carry=0;
  int d;
  while(cur1!=head1 && cur2!=head2)
  {
    if(cur1->data+cur2->data+carry>9)
    {
      int d=(cur1->data+cur2->data+carry)%10;
      head3=insertAtEnd(head3,d);
      carry=1;
    }
    else
    {
      head3=insertAtEnd(head3,cur1->data+cur2->data+carry);
      carry=0;
    }
    cur1=cur1->next;
    cur2=cur2->next;
}
if(cur1!=head1)
{
  while(cur1!=head1)
  {
    if(cur1->data+carry>9)
    {
      int d=(cur1->data+carry)%10;
      head3=insertAtEnd(head3,d);
      carry=1;
    }
    else
    {
      head3=insertAtEnd(head3,cur1->data+carry);
      carry=0;
    }
    cur1=cur1->next;

  }
}
else
{
  while(cur2!=head2)
  {
    if(cur2->data+carry>9)
    {
      int d=(cur2->data+carry)%10;
      head3=insertAtEnd(head3,d);
      carry=1;
    }
    else
    {
      head3=insertAtEnd(head3,cur2->data+carry);
      carry=0;
    }
    cur2=cur2->next;

  }
}

return head3;

}

void tostring(node *head)
{
  node *cur=head->next;
  char arr[100];
  int i=0;
  while(cur!=head)
  {
    arr[i++]=cur->data+48;
    cur=cur->next;
  }
  arr[i]='\0';
  int j=strlen(arr)-1;
  for(int i=0;i<j;i++,j--)
  {
    char temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
  }
  printf("Result: %s\n",arr);

}
int main()
{
  char s1[100];
  char s2[100];
  printf("Enter number-1\n");
  scanf("%s",s1);
  printf("Enter number-2\n");
  scanf("%s",s2);
  int n1=strlen(s1);
  int n2=strlen(s2);
  node *head1=createNode(0);
  node *head2=createNode(0);
  node *head3=createNode(0);
  for(int i=n1-1;i>=0;i--)
  {
    head1=insertAtEnd(head1,s1[i]-48);
  }
  for(int i=n2-1;i>=0;i--)
  {
    head2=insertAtEnd(head2,s2[i]-48);
  }
  head3=addition(head1,head2,head3);
  tostring(head3);
  return 0;
}
