#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	int data;
	char name[50];
	struct student *next;
};

struct student *newStudent(int data,char name[50]){//I have reserved space in my memory for the student list.
	struct student *student=(struct student*)malloc(sizeof(struct student));
	student->data=data;
	strncpy(student->name,name,sizeof(student->name));
	student->next=NULL;
	
	return student;
}

struct student *locateLongestName(struct student *head){//A function for comparing name lengths.
	struct student *longestNameStudent=NULL;
	int maxLenght=0;
	
	while(head!=NULL){
		int currentLenght=strlen(head->name);
		if(currentLenght>maxLenght){
			maxLenght=currentLenght;
			longestNameStudent=head;
		}
		head=head->next;

	}
	return longestNameStudent;//returns the longest name.
}
int main(){
	struct student *head=newStudent(1,"Misra");//I have identified the students on the list in order.
	head->next=newStudent(2,"Ahmet");
	head->next->next=newStudent(3,"Ali");
	head->next->next->next=newStudent(4,"Abdurrahmangazi");
	
	
	struct student *longestNameStudent=locateLongestName(head);
	
	if(longestNameStudent!=NULL){//I checked if the list is empty or full
		printf("The student with the longest name on the list: %s\n",longestNameStudent->name);
		printf("Lenght:%d\n",strlen(longestNameStudent->name));
	}
	else{
		printf("The searched name could not be found on the list.\n");
	}
	struct student*current=head;////I have cleared in my memory for the student list.
	while(current!=NULL){
		struct student *temp=current;
		current=current->next;
		free(temp);
	}
	return 0;
}






















