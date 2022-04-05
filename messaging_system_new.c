#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define capacity 1000
#define length 1000

typedef struct queue
{
  char arr[capacity][length];
  int front;
  int size;

}queue;

void create(queue *q)
{
  q->front=0;
  q->size=0;
}

int getFront(queue *q)
{
  if(q->size==0)
  return -1;

  return q->front;
}

int getRear(queue *q)
{
  if(q->size==0)
  return -1;

  return (q->front+q->size-1)%capacity;
}

void enqueue(queue *q,char a[])
{
  if(q->size==capacity)
  {
    printf("Message Buffer Full\n");
    return;
  }

 int rear=getRear(q);
 rear=(rear+1)%capacity;
 strcpy(q->arr[rear],a);
 q->size++;

}

void dequeue(queue *q)
{
  if(q->size==0)
  {
    printf("Message Buffer Empty\n");
    return;
  }
 q->front=(q->front+1)%capacity;
 q->size--;

}

void read(queue *q)
{
  if(q->size==0)
  {
    printf("No messages\n");
    return;
  }

  printf("%s\n",q->arr[q->front]);

}


int main()
{
printf("________________Welcome to the messaging system____________________\n");
int opt;
queue q;
create(&q);
int o;
char mssg[length];
do
{
  printf("Enter the choice\n");
  printf("1.send message\t2.read message\t3.exit\n");
  scanf("%d",&opt);
  getchar();
  switch(opt)
  {
    case 1:
    printf("Enter the message\n");
    scanf("%[^\n]",mssg);
    enqueue(&q,mssg);
    break;

    case 2:
    printf("You have %d new messages\n",q.size);
    printf("Enter 1.For oldest one\t2.All message");
    scanf("%d",&o);
    if(o==1)
    {
      read(&q);
      dequeue(&q);
    }
    else
    {
      while(q.size>0)
      {
        read(&q);
        dequeue(&q);
      }
    }

    break;

    case 3:
    break;
  }

}while(opt!=3);
return 0;
}
