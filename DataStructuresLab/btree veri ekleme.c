#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//Ýkili agac olusturmak ve veri eklemek


typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}BTREE;

BTREE *new_node(int data){
	
	BTREE *p=(BTREE*)malloc(sizeof(BTREE));
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	
	return p;
	
}

BTREE *insert(BTREE *root,int data){
	if(root!=NULL){
		if(data < root->data)
			root->left=insert(root->left,data);
		
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
		printf("%d ",root->data);
		postorder(root->right);
	}
}
int main(){
	BTREE *root=NULL;
	int i;
	printf("Agaca eklenecek verileri giriniz:\n",i);
	do{
		scanf("%d",&i);
		if(i!=-1)
			root=insert(root,i);
		
	}while(i!=-1);

	printf("Inorder traversal of the binary tree is: ");
	inorder(root);
	
	return 0;
}

