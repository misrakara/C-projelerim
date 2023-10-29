#include<stdio.h>
#include<stdlib.h>


struct node{ //define the structure for a node.
	int data;
	struct node *next;
};
	struct node *addhead(struct node *head,int key){// Function to add a node to the head of the linked list.
		struct node *temp=(struct node *)malloc(sizeof(struct node));
			temp->data=key;
			temp->next=head;
			
			return temp;
	}
	
	struct node *addlast(struct node *head,int key){
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->data=key;
		temp->next=NULL;
		
		if(head==NULL){
			return temp;
		}else{
			struct node *temp2=head;
			while(temp2->next!=NULL){
				temp2=temp2->next;
			}
			temp2->next=temp;
			return head;
		}
	}
	
	void printData(struct node *head){
		struct node *temp2=head;
				while(temp2->next!=NULL){
					printf("%d ->",temp2->data);
					temp2=temp2->next;
				}
				printf("%d ->",temp2->data);
	}
	
	struct node *freeData(struct node *head){
		while(head!=NULL){
		struct node *temp=head;
		head=head->next;
		free(temp);
	  }
	return head;
	}
			
main(){
	struct node *head=NULL;
	int key;
	int i;
	
	while(1){
			printf("Please enter a number: ");
			scanf("%d",&key);
			if(key==-1){
				printData(head);
				exit(0);
			}
			if(key%2!=0){
			    head=addhead(head,key);
			}else{
				head=addlast(head,key);
			}
			
	}	
	
	return 0;
}

