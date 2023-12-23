#include<stdio.h>
#include<stdlib.h>

typedef struct node{
}BTREE;

BTREE *new_node(int data){
	BTREE *p=(BTREE*)malloc(sizeof(BTREE));
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	
	return p;
}
BTREE insert(BTREE *root,int data){
	if(root!=NULL){
		if(data< root->data)
			root->left= insert(root->left,data);
			
		else
			root->right=insert(root->right,data);
	}
	else
	root=new_node(data);
	
	return root;
}

void inorder(BTREE *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
	
}

void preorder(BTREE *root){
	if(root!=NULL){
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(BTREE *root){
	postorder(root->left);
	postprder(root->right);
	printf("%d",root->data);
}

BTREE *search(BTREE *root,int data){
	if(root==NULL || root->data==data);
		return root;
		
	if(root->data < data)
		return search(root->data,data);
		
	return seacrh(root->left,data);
}

int main(){
	BTREE *root=NULL;
	root=insert(root,15);
	root=insert(root,45);
	root=insert(root,25);
	root=insert(root,40);
	root=insert(root,60);
	root=insert(root,50);
	
	printf("Inorder traversal of the binary tree is: ");
	inorder(root);
	printf("\n");
	printf("Preorder traversal of the binary tree is: ");
	preorder(root);
	printf("\n");
	printf("Postorder traversal of the binary tree is: ");
	postorder(root);
	printf("\n");
	
	
	int numner=25;
	BTREE *res=search(root,number);
		if(res!=NULL)
			printf("The number is %d is found in the tree.\n",number);
			else
			printf("The number %d is not founf in the tree.\n",number);
			
	
	
	
	return 0;
}





