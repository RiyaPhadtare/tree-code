#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *llink,*rlink;
}*tmp=NULL;

typedef struct node NODE;
NODE *create();
void preorder(NODE*);
void inorder(NODE*);
void postorder(NODE*);
void insert(NODE*);

void main()
{
	int i,n,m;
	do
	{
		printf("\n0.Create\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder\n5.Exit");
		printf("\n Enter your choice=");
		scanf("%d",&m);
		switch(m)
		{
			case 0: tmp=create();
				break;
			case 1: insert(tmp);
				break;
			case 2: printf("\n Display Preorder");
			        preorder(tmp);
			        break;
			case 3: printf("\n Display Postorder");
			        postorder(tmp);
			        break;
			case 4: printf("\n Display Inorder");
			        inorder(tmp);
			        break;
			case 5: exit(0);	
		}
	}while(n!=5);
}
void insert(NODE *root)
{
	NODE *newnode;
	if(root==NULL)
	{
		newnode=create();
		root=newnode;
	}
	else
	{
		newnode=create();
		while(1)
		{
			if(newnode->data<root->data)
			{
				if(root->llink==NULL)
				{
					root->llink=newnode;
					break;
				}
				root=root->llink;
			}
			else
			{
				if(root->rlink==NULL)
				{
					root->rlink=newnode;
					break;
				}
				root=root->rlink;
			}
		}
	}	
}
NODE* create()
{
	NODE* newnode=malloc(sizeof(NODE));
	int value;
	printf("\n Enter Value=");
	scanf("%d",&value);
	newnode->data=value;
	newnode->llink=NULL;
	newnode->rlink=NULL;
	return newnode;

}
void preorder(NODE* root)
{
	if(root==NULL)
		return;
	printf("\n %d=",root->data);
	preorder(root->llink);
	preorder(root->rlink);
}
void postorder(NODE* root)
{
	if(root==NULL)
		return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("\n %d=",root->data);
}
void inorder(NODE* root)
{
	if(root==NULL)
		return;
	inorder(root->llink);
	printf("\n %d=",root->data);
	inorder(root->rlink);
}
