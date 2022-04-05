#include<stdio.h>
#include<stdlib.h>

typedef struct myhash
{
  int *table;
  int bucket;
}myhash;

void create(myhash *h,int b)
{
  h->bucket=b;
  h->table=(int *)malloc(sizeof(int)*h->bucket);
  for(int i=0;i<h->bucket;i++)
  {
    h->table[i]=-1;
  }
}

void insert(myhash *h,int key)
{
  int j=key%h->bucket;
  int i=j;
 while(h->table[i]!=-1 && h->table[i]!=-2)
 {
   if(h->table[i]==key)
   {
     printf("Error while inserting\n");
     printf("Note: Element in the hash table should be unique\n");
     return;
   }
   i=(i+1)%h->bucket;
   if(i==j)
   {
     printf("No empty slots in the hash table\n");
     return;
   }
 }

 printf("Insertion Successfull\n");
 h->table[i]=key;

}

void deletee(myhash *h,int key)
{
  int j=key%h->bucket;
  int i=j;
  while(h->table[i]!=-1)
 {
   if(h->table[i]==key)
   {
     h->table[i]=-2;
     printf("deletion successfull\n");
     return;
   }
   i=(i+1)%h->bucket;
   if(i==j)
   {
     printf("Deletion failed\n");
     printf("No empty slots\n");
     return;
   }

 }

 printf("deletiom failed\n");
 printf("Element not found\n");

}


void search(myhash *h,int key)
{
  int j=key%h->bucket;
  int i=j;
  while(h->table[i]!=-1)
  {
    if(h->table[i]==key)
    {

      printf("searching successfull\n");
      printf("Note :element found\n");
      return;
    }
    i=(i+1)%h->bucket;
    if(i==j)
    {
      printf("searching failed\n");
      printf("No empty slots\n");
      return;
    }
}
printf("searching failed\n");
printf("Element not found\n");
}

void display(myhash *h)
{
  for(int i=0;i<h->bucket;i++)
  {
    printf("|%d|",h->table[i]);
  }
  printf("\n");
}

int main()
{
  int b;
  printf("Enter the capacity of hash table\n");
  scanf("%d",&b);
  myhash h;
  int n;
  int ele;
  int opt;
  create(&h,b);
  do
  {
    printf("Enter the option\n");
    printf("1.insert\t2.delete\t3.search\t0.exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:
           printf("Enter number of elements to be inserted\n");
           scanf("%d",&n);
           for(int i=0;i<n;i++)
           {
             printf("Enter element\n");
             scanf("%d",&ele);
             insert(&h,ele);
           }
           break;

        case 2:
              printf("Enter the key to be deleted\n");
              scanf("%d",&ele);
              deletee(&h,ele);
              break;

        case 3:
              printf("Enter the key to be searched\n");
              scanf("%d",&ele);
              search(&h,ele);
              break;
        case 4:
             display(&h);
             break;
        case 0:
             break;
    }

  }while(opt!=0);

  return 0;

}
