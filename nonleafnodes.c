#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node *left,*right;
};
struct node *createnode(int key)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->item=key;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
int count=0;
int nln(struct node *newnode)
{
	if(newnode!=NULL)
	{
		nln(newnode->left);
		if(newnode->left!=NULL||newnode->right!=NULL)
		{
			count++;
		}
		nln(newnode->right);
	}
	return count;
}
int leafnodes(struct node *newnode)
{
	if(newnode!=NULL)
	{
		leafnodes(newnode->left);
		if((newnode->left==NULL)&&(newnode->right==NULL))
		{
			count++;
		}
		leafnodes(newnode->right);
	}
	return count;
}
int main()
{
	struct node *newnode=createnode(30);
	newnode->left=createnode(10);
	newnode->right=createnode(50);
	newnode->left->left=createnode(8);
	newnode->left->right=createnode(22);
	newnode->right->left=createnode(42);
	newnode->right->right=createnode(80);


	printf("\n Count of non leaf node is %d\t",nln(newnode));
	count=0;
	printf("\n Count of leaf nodes is %d\t",leafnodes(newnode));
	return 0;
}

