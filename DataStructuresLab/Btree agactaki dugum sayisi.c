#include<stdio.h>
#include<stdlib.h>

/*ikili bir agacin dugum sayisini bulmak*/

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
		if(x< root->data)
			root->left=insert(root->left,x);
		else
			root->right=insert(root->right,x);
	}
		
	return root;
}

void inorder(BTREE root){
	if(root!=NULL){
		inorder(root->left);
		printf("%3d",root->data);
		inorder(root->right);
	}
}

int size(BTREE root){
	if(root==NULL)
			return 0;
	
	else
		return size(root->left)+1+size(root->right);
	
	
}

void mirror(BTREE root){
	if(root==NULL)
		return;
	
	else{
		struct node *temp;
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		mirror(root->left);
		mirror(root->right);
	}
}

int main(){
	BTREE myroot=NULL;
	int nodeCount;
	int i;
	printf("Agaca eklenecek verileri giriniz:\n",i);
	scanf("%d",&i);
	while(i!=-1){
		myroot=insert(myroot,i);
		scanf("%d",&i);
	}
	
	printf("Olusturdugunuz ineorder binary agaci:\t");
	inorder(myroot);
	printf("\n");
	
	printf("Agactaki dugum sayisi:%d\n",size(myroot));
	
	printf("Degistireceginiz veriyi giriniz:\n");
	mirror(myroot);
	scanf("%d",&i);

	printf("Olusturdugunuz yeni ineorder binary agaci:\t");
	inorder(myroot);
	printf("\n");
	
	
}
