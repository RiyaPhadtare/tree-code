#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node *left;
	struct node *right;
};
void inorderTraversal(struct node *root)
{
	if(root==NULL)
		return;
	inorderTraversal(root->left);
	printf("%d=",root->item);
	inorderTraversal(root->right);
}
void preorderTraversal(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d=",root->item);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
void postorderTraversal(struct node *root)
{
	if(root==NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d=",root->item);
}
struct node *createnode(value)
{
	struct node *newnode=malloc(sizeof(struct node));
	newnode->item=value;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node *insertleft(struct node *root,int value)
{
	root->left=createnode(value);
	return root->left;
}
struct node *insertright(struct node *root,int value)
{
	root->right=createnode(value);
	return root->right;
}
int main()
{
	struct node *root=createnode(1);
	insertleft(root,2);
	insertright(root,3);
	insertleft(root->left,4);
	insertright(root->right,5);
	printf("\n Inoder Traversal");
	inorderTraversal(root);
	printf("\n Preorder Traversal");
	preorderTraversal(root);
	printf("\n Postorder Traversal");
	postorderTraversal(root);
}

