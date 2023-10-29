#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	int studentNum;
	char name[50];
	int age;
	struct student *next;
};

struct student *newStudent(int number , const char* name,int age){
	struct student*student=(struct student*)malloc(sizeof(struct student));
	student->studentNum=number;
	strncpy(student->name,name,sizeof(student->name));
	student->age=age;
	student->next=NULL;
	
	return student;		
}
void studentInfoPrint(struct student *head){
	int count=0;
 	while (head != NULL) {
    	printf("%d) ",count+1);
        printf("%s ", head->name);
        printf("%d  ", head->age);
        printf("%d ", head->studentNum);
        printf("\n");
        count++;
        head = head->next;
    }
	printf("Total number of student:%d\n",count);
}
int main(){
	struct student*head=newStudent(100,"Misra",21);// I have identified the students on the list in order.
	head->next=newStudent(215,"Elif",20);
	head->next->next=newStudent(350,"Gulce",25);
	head->next->next->next=newStudent(420,"Berre",21);

	studentInfoPrint(head);
	
	return 0;
	
	
	
	
}
