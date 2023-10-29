#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{ //define the structures for node.
	int data;
	struct node *next;
};

struct node *addlist(struct node *head,int key){ //I created a linked list.
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=key;
	temp->next=head;
	return temp;
}
void printData(struct node *head){
		struct node *temp2=head;
				while(temp2->next!=NULL){
					printf("%d ->",temp2->data);
					temp2=temp2->next;
				}
				printf("%d\n",temp2->data);
	}
	
	
struct node* swap(struct node* ptr1, struct node* ptr2)
{
    struct node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
void bubbleSort(struct node** head, int count)
{
    struct node** h;
    int i, j, swapped;
 
    for (i = 0; i <= count; i++) {
 
        h = head;
        swapped = 0;
 
        for (j = 0; j < count - i - 1; j++) {
 
            struct node* p1 = *h;
            struct node* p2 = p1->next;
 
            if (p1->data > p2->data) {
                *h = swap(p1, p2);
                swapped = 1;
            }
 
            h = &(*h)->next;
        }
        if (swapped == 0)
            break;
    }
}

int main(){
	struct node *head=NULL;
	int key;
	int i;
	
	srand(time(NULL)); //I randomly generated 100 numbers.
	for(i=0;i<100;i++){
		key=rand()%100;
		head=addlist(head,key);
	}
	bubbleSort(&head,100);
	printData(head);
    
	while(head!=NULL){
		struct node *temp=head;
		head=head->next;
		free(temp);
	}
	
	
	return 0;
	
}
