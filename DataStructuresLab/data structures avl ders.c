#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
};

typedef struct node AVLTREE;

int maxValue(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}

int height(AVLTREE *root) {
	if(root == NULL)
		return -1;
	else {
		int left_height, right_height;
		left_height = height(root -> left);
		right_height = height(root -> right);
		if(right_height > left_height)
			return right_height + 1;
		else
			return left_height + 1;
	}
}

AVLTREE *rightRotate(AVLTREE *z){
	AVLTREE* temp=z->left;
	z->left=temp->right;
	temp->right=z;
	z->height=maxValue(height(z->left),height(z->right))+1;
	temp->height=maxValue(height(temp->left),height(temp->right))+1;
	
	return temp;
}

AVLTREE *leftRotate(AVLTREE *z){
	AVLTREE *temp=z->right;
	z->right=temp->left;
	temp->left=z;
	z->height=maxValue(height(z->left),height(z->right))+1;
	temp->height=maxValue(height(temp->left),height(temp->right))+1;
	
	return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z){
	z->left=leftRotate(z->left);
	return rightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z){
	z->right=rightRotate(z->right);
	return leftRotate(z);
}

AVLTREE *new_node(int data) {
	AVLTREE *p = (AVLTREE*) malloc(sizeof(AVLTREE));
	int height=0;
	p -> data = data;
	p -> left = NULL;
	p -> right = NULL;
	return p;
}

AVLTREE *insertToAVL(int x,AVLTREE *tree){
	if(tree!=NULL){
		if(x<tree->data)
			tree->left=insertToAVL(x,tree->left);
		else if(x>tree->data)
			tree->right=insertToAVL(x,tree->right);
		else
			return tree;
		
		tree->height=maxValue(height(tree->left),height(tree->right))+1;
		
		if((height(tree->left)-height(tree->right))>1 && x<tree->left->data)
			return rightRotate(tree);
		if((height(tree->left)-height(tree->right))>1 && x>tree->left->data)
			return leftRightRotate(tree);
		if((height(tree->left)-height(tree->right))<-1 && x>tree->right->data)
			return leftRotate(tree);
		if((height(tree->left)-height(tree->right))<-1 && x<tree->right->data)
			return leftRightRotate(tree);
	}
	else
		tree=new_node(x);
	return tree;
}

void inorder(AVLTREE *root){
	if(root!=NULL){
		inorder(root->left);
		printf("\n%5d\n",root->data);
		inorder(root->right);
	}
}

int getBalance(AVLTREE* origin) {
	if (origin == NULL)
		return 0;
	return height(origin ->left) - height(origin ->right);
}

int minValue(AVLTREE *root) {
	if(root == NULL)
		return 0;
	while(root -> left != NULL)
		root = root -> left;
	return(root -> data);
}

AVLTREE *deleteNode(AVLTREE *root, int key) {
	if(root == NULL)
		return root;
	if(key < root -> data) 
		root -> left = deleteNode(root -> left, key);
	else if(key > root -> data) 
		root -> right = deleteNode(root -> right, key);
	else { 
		if((root -> left == NULL) || (root -> right == NULL)) {
			AVLTREE *temp = root -> left ? root -> left : root -> right;
			if(temp == NULL) { 
				temp = root;
				root = NULL;
			} 
			else 
				*root = *temp; 
				free(temp);
			} 
		else { 
			AVLTREE *temp = minValue(root -> right);
			root -> data = temp -> data;
			root -> right = deleteNode(root -> right, temp -> data);
		}
	}
	if (root == NULL)
		return root;

	root -> height = maxValue(height(root -> left), height(root -> right)) + 1;

	if (getBalance(root) > 1 && getBalance(root -> left) >= 0)
		return rightRotate(root); 

	if (getBalance(root) > 1 && getBalance(root -> left) < 0) {
		root -> left = leftRotate(root -> left); 
		return rightRotate(root); 
	}

	if (getBalance(root) < -1 && getBalance(root -> right) <= 0)
		return leftRotate(root); 

	if (getBalance(root) < -1 && getBalance(root -> right) > 0) {
		root -> right = rightRotate(root -> right); 
		return leftRotate(root); 
	}
	return root;
}

/*int main() {
	AVLTREE *myroot = NULL;
	int i;
	scanf("%d",&i);
	while(i!=-1){
		myroot=insertToAVL(i,myroot);
		scanf("%d",&i);
	}
	
	inorder(myroot);
	printf("\nheight:%5d",myroot->height);
}*/
/*void listinfo(struct node* head) {
	int i = 1;
	while(head != NULL) {
		printf("%d. Dugumunun Adresi = %p \n", i, head);
		printf("%d. Dugumunun verisi = %d \n", i, head -> data);
		printf("%d. Dugumunun Bagli Oldugu Dugumun Adresi= %p\n\n",i, head->next);
		head = head -> next;
		i++;
	}
}*/
main(){
	int secim,data;
	AVLTREE *myroot = NULL;
	while(1){
	printf("1-Agaca Eleman Ekle\n");
	printf("2-Eleman Sil\n");
	printf("3-Agaci goruntule\n");
	printf("4-Programdan Cikma\n");
	printf("Seciminiz\n");
	scanf("%d",&secim);
		switch(secim){
			case 1:
				printf("\nEklemek istedigin degeri gir\n");
				scanf("%5d",&data);
				while(data!=-1){
					myroot=insertToAVL(data,myroot);
					scanf("%5d",&data);
				}
	
				inorder(myroot);
				printf("\nheight:%5d\n",myroot->height);
				break;
			case 2:
				printf("\nSilmek istedigin degeri gir\n");
				scanf("%5d",&data);
				myroot=deleteNode(myroot,data);
				break;
			case 3:
				//listinfo(head);
				inorder(myroot);
				printf("\nheight:%5d\n",myroot->height);
				break;
			case 4:
				exit(1);
				break;
			default: printf("\nYanlis secim\n");
		}
	}
}

