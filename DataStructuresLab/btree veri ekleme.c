#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//İkili agac olusturmak ve veri eklemek

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node *BTREE;

BTREE new_node(int x){
	BTREE p;
	p=(BTREE)malloc(sizeof(struct node));
	p->data=x;
	p->left=p->right=NULL;

	
	return p;
	
}

BTREE insert(BTREE root,int x){
	if(root==NULL)
		root=new_node(x);
	
	else{
		if(x<root->data)
			root->left=insert(root->left,x);
		else
			root->right=insert(root->right,x);
	}
	
	return root;
}
void preorder(BTREE root){
	if(root!=NULL){
		printf("%3d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(BTREE root){
	if(root!=NULL){
		inorder(root->left);
		printf("%3d",root->data);
		postorder(root->right);
	}
}

void postorder(BTREE root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%3d",root->data);
	}
}

int main(){
	BTREE myroot=NULL;
	int i;
	printf("Agaca eklenecek verileri giriniz:\n",i);
	scanf("%d",&i);
	while(i!=-1){
		myroot=insert(myroot,i);
		scanf("%d",&i);
	}
	
	
	printf("Preorder traversal of the binary tree is:\n");
	preorder(myroot);
	printf("\n");
	
	printf("Inorder traversal of the binary tree is:\n");
	inorder(myroot);
	printf("\n");
	
	printf("Postorder traversal of the binary tree is:\n");
	postorder(myroot);
	printf("\n");
		
	
	return 0;
}

