#include<stdio.h>
#include<stdlib.h>

typedef struct minheap
{
  int *arr;
  int capacity;
  int size;

}minheap;

void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}

void create(minheap *h,int c)
{
  h->capacity=c;
  h->arr=(int *)malloc(h->capacity*sizeof(int));
  h->size=0;
}

int left(int i)
{
  return (2*i+1);
}

int right(int i)
{
  return (2*i+2);
}

int parent(int i)
{
  return ((i-1)/2);
}

void insert(minheap *h,int data)
{
  if(h->size==h->capacity)
  {
    printf("Heap Full\n");
    return;
  }
  h->size++;
  h->arr[h->size-1]=data;
  for(int i=h->size-1;i!=0 && h->arr[parent(i)]>h->arr[i];)
  {
    swap(&h->arr[parent(i)],&h->arr[i]);
    i=parent(i);
  }


}

void minHeapify(minheap *h,int i)
{
  int lt=left(i);
  int rt=right(i);
  int smallest=i;
  if(lt<h->size && h->arr[lt]<h->arr[i])
  smallest=lt;
  if(rt<h->size && h->arr[rt]<h->arr[smallest])
  smallest=rt;

  if(smallest!=i)
  {
    swap(&h->arr[smallest],&h->arr[i]);
    minHeapify(h,smallest);
  }

}

int extractMin(minheap *h)
{
  if(h->size==0)
  return 999;

  if(h->size==1)
  {
    h->size--;
    return h->arr[0];
  }

  swap(&h->arr[0],&h->arr[h->size-1]);
  minHeapify(h,0);
  return h->arr[h->size];
}

void buildHeap(minheap *h)
{
  for(int i=(h->size-2)/2;i>=0;i--)
  {
    minHeapify(h,i);
  }

}
void display(minheap *h)
{
  for(int i=0;i<h->size;i++)
  {
    printf("%d ",h->arr[i]);
  }
  printf("\n");
}




int main()
{
  minheap h;
  int c;
  int opt;
  int n;
  int ele;
  printf("Enter the capacity\n");
  scanf("%d",&c);
  create(&h,c);
  do
  {
    printf("Enter the option\n");
    printf("1.buildheap\t2.insert\t3.extract Minimum\t4.display\t0.exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:
              printf("Enter number of elements\n");
              scanf("%d",&n);
              printf("Enter the elements\n");
              for(int i=0;i<n;i++)
              {
                scanf("%d",&h.arr[i]);
              }
              buildHeap(&h);
              printf("heap built succesfully\n");
              break;

        case 2:printf("Enter the element\n");
                      scanf("%d",&ele);
                      insert(&h,ele);
                      break;
        case 3:printf("The deleted element is: %d\n",extractMin(&h));
        break;

        case 4:printf("The heap:\n");
               display(&h);
               break;
        case 5:
               break;

    }


  }while(opt!=0);


}
