#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
}node;

node * createNode(int data)
{
  node *temp=(node *)malloc(sizeof(node));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

node *insert(node *root,int data)
{
  if(root==NULL)
  {
    return createNode(data);
  }
  if(data<root->data)
  {
    root->left=insert(root->left,data);
  }
  else if(data>root->data)
  {
    root->right=insert(root->right,data);
  }
  else
  {
    return root;
  }
  return root;
}

void search(node *root,int data)
{
  node *cur=root;
  char path[100];
  int found=0;
  int i=0;
  while(cur!=NULL)
  {
    if(cur->data==data)
    {
      found=1;
      break;
    }
    else if(data<cur->data)
    {
      path[i++]='L';
      cur=cur->left;
    }
    else
    {
      path[i++]='R';
      cur=cur->right;
    }

  }

  if(found==0)
  {
    printf("Element is not found\n");
    return;
  }
  else
  {
    printf("Element is found in location\n");
    for(int k=0;k<i;k++)
    {
      printf("%c ",path[k]);
    }
  }
  return;

}

node *getSuccessor(node *root)
{
  node *cur=root->right;
  while(cur!=NULL && cur->left!=NULL)
  {
    cur=cur->left;
  }
  return cur;
}

node *delete(node *root,int data)
{
  if(root==NULL)
  return NULL;

  if(data<root->data)
  {
    root->left=delete(root->left,data);
  }
  else if(data>root->data)
  {
  root->right=delete(root->right,data);
  }
  else
  {
    if(root->left==NULL)
    {
      node *temp=root->right;
      free(root);
      return temp;
    }
    else if(root->right==NULL)
    {
      node *temp=root->left;
      free(root);
      return temp;
    }
    else
    {
      node *temp=getSuccessor(root);
      root->data=temp->data;
      root->right=delete(root->right,temp->data);
    }

  }
    return root;
}

void inOrder(node *root)
{
  if(root==NULL)return;

  inOrder(root->left);
  printf("%d ",root->data);
  inOrder(root->right);
}

void preOrder(node *root)
{
  if(root==NULL)return;

  printf("%d ",root->data);
  preOrder(root->left);
  preOrder(root->right);
}


void postOrder(node *root)
{
  if(root==NULL)return;

  postOrder(root->left);
  postOrder(root->right);
  printf("%d ",root->data);
}

int main()
{
  node *root=NULL;
  int opt;
  int n;int ele;
  do {
    printf("\nEnter the option\n");
    printf("1.insert\t2.delete\t3.search\t4.inorder\t5.preorder\t6.postorder\t0.exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:
            printf("Number of elements\n");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
            printf("Enter the element\n");
            scanf("%d",&ele);
            root=insert(root,ele);
            }
            break;
        case 2:
              printf("Enter the element\n");
              scanf("%d",&ele);
              root=delete(root,ele);
            break;
        case 3:printf("Enter the element\n");
              scanf("%d",&ele);
              search(root,ele);
              break;
        case 4:
             printf("\n");
             printf("Inorder:\n");
             inOrder(root);
             break;
        case 5:
            printf("\n");
            printf("Preorder:\n");
            preOrder(root);
            break;

        case 6:
             printf("\n");
             printf("Postorder:\n");
             postOrder(root);
             break;

         case 0:
         break;

    }
  } while(opt!=0);
  return 0;
}
