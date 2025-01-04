#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node *left;
	struct node *right;
};
//function to create new node
struct node* createnode(int value)
{
	struct node* newnode=malloc(sizeof(struct node));
	newnode->item=value;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
//Insert a node to the left of the given node
struct node *insertleft(struct node *root,int value)
{
	root->left=createnode(value);
	return root->left;
}
//Inserta node to the right of the given node
struct node *insertright(struct node *root,int value)
{
	root->right=createnode(value);
	return root->right;
}

int odd_data(struct node *root)
{
	int sum=0;
	if(root!=NULL)
	{
		if(root->item %2 != 0)
		{
			sum=sum+root->item;
		}
		sum=sum+odd_data(root->left);
		sum=sum+odd_data(root->right);
	}
	return sum;
}
int even_data(struct node *root)
{
	int sum=0;
	if(root!=NULL)
	{
		if(root->item %2 ==0)
		{
			sum=sum+root->item;
		}
		sum=sum+even_data(root->left);
		sum=sum+even_data(root->right);

	}
	return sum;

}

int main()
{
	//Create root node
	struct node* root= createnode(40);

	//Insert nodes
	insertleft(root,22);
	insertright(root,60);
	insertleft(root->left,7);
	insertleft(root->right,25);
	insertright(root->right,44);

	int odd=odd_data(root);
	printf("\n Sum of odd data is %d",odd);
	int even=even_data(root);
	printf("\n Sum of even data is %d",even);
	return 0;
}

