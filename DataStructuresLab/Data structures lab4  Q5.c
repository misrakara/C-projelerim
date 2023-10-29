#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	int data;
	char name[50];
	struct student *next;
};

struct student *newStudent(int data,char name[50]){ //I have reserved space in my memory for the student list.
	struct student *student=(struct student *)malloc(sizeof(struct student));
	student->data=data;
	strncpy(student->name,name,sizeof(student->name));
	student->next=NULL;
	
	return student;
}
struct student *locate(struct student *head,char key[50]){//I wrote struct looking for the student.
	while(head!=NULL){
		if(strcmp(head->name,key)==0){
			return head;
		}
		else{
			head=head->next;
		}
	}
	return NULL;
}

void printData(struct student *head){
		struct student *temp2=head;
				while(temp2->next!=NULL){
					printf("%s ->",temp2->name);
					temp2=temp2->next;
				}
				printf("%s",temp2->name);
				printf("\n");
	}
int main(){
	struct student *head=newStudent(1,"Misra");
	head->next=newStudent(2,"Ali");
	head->next->next=newStudent(3,"Ayse");
	head->next->next->next=newStudent(4,"Mehmet");
	head->next->next->next->next=newStudent(5,"Zeynep");
	
	printf("Please enter the name of the student you want to search for: ");
	char key[50];
	scanf("%s",&key);
	
	struct student *locatedStudent=locate(head,key);//i called the locate function.
	
	if(locatedStudent!=NULL){
		printf("The stduent was found:%s\n",locatedStudent->name);
		printData(head);
		struct student *temp=(struct student *)malloc(sizeof(struct student));
		temp=locatedStudent->next->next; //silme kýsmý
		locatedStudent->next=NULL;
		locatedStudent->next=temp;
		printData(head);
		
	}
	else{
		printf("The student  wasn't found.\n");
	}
	
}



























