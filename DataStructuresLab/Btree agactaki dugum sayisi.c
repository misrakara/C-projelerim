#include<stdio.h>
#include<stdlib.h>

/*ikili bir agacin dugum sayisini bulmak*/

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
		if(data< root->data)
			root->left=insert(root->left,data);
			
		else
			root->right=insert(root->right,data);
	}else
		root=new_node(data);
		
	return root;
}

void preorder(BTREE *root){
	if(root!=NULL){
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int size(BTREE *root){
	if(root==NULL)
			return 0;
	
	else
		return size(root->left)+1+size(root->right);
	
	
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
	
	printf("Olusturdugunuz Binary Agaci:\t");
	preorder(root);
	printf("\n");
	
	int nodeCount=size(root);
	printf("Agactaki dugum sayisi: ",nodeCount);
	
}
