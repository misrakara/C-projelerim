#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	int data;
	char name[50];
	struct student *next;
};

struct student *newStudent(int data,char name[50]){ //I have reserved space in my memory for the student list.
	struct student*student=(struct student*)malloc(sizeof(struct student));
	student->data=data;
	strncpy(student->name,name,sizeof(student->name));
	student->next=NULL;
	
	return student;
}

struct student *locate(struct student *head,char key[50]){ //I wrote struct looking for the student.
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
	
	
int main(){
	struct student *head=newStudent(1,"Misra");// I have identified the students on the list in order.
	head->next=newStudent(2,"Gulce");
	head->next->next=newStudent(3,"Irmak");
	head->next->next->next=newStudent(4,"Elif");
	head->next->next->next->next=newStudent(5,"Berre");
	
	printf("Please enter the name of the student you want to search for: ");
	char key[50];
	scanf("%s",key);
	
	struct student *locatedStudent=locate(head,key); //i called the locate function.

	if(locatedStudent!=NULL){
		printf("The student was found: %s\n ",locatedStudent->name);
	}
	else{
		printf("The student wasn't found.\n");
	}
	struct student *current=head; //I have cleared in my memory for the student list.
	while(current!=NULL){
		struct student *temp=current;
		current=current->next;
		free(temp);
	}
	
	
}
