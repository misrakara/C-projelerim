#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
	int top;
	int cap; //The capacity of the stack.
	int *array;
}Stack;

Stack *createStack(int cap){
	Stack *stack=(Stack*)malloc(sizeof(Stack));
	stack->cap=cap;
	stack->top=-1;
	stack->array=(int*)malloc(stack->cap *sizeof(int));
    return stack;
}

void push(Stack *stack,char x){ //x is the input value that you will use to add to the stack
	if(stack->top==stack->cap-1){
		printf("\nStack is over flow");
		return;
	}
	stack->array[++stack->top]=x;
	
}

char pop(Stack *stack){
	if(stack->top==-1){
		return '\0'; //this is a constant,it returns the min value that int can get
	}
	return stack->array[stack->top--];
}
void display(Stack *stack){
	int i;
	if(stack->top>=0){
		printf("\nThe elements in stack\n");
		for(i=stack->top; i>=0;i--)
		printf("%d\n",stack->array[i]);
	}
	else{
		printf("\nThe stack is empty");
	}
}

int main(){
	int cap;
	FILE *file=fopen("dosya.txt","r");
	if(file==NULL){
		printf("File was not opened.\n");
		return 1;
	}
	Stack *stack=createStack(100);
	char ch;
	int line=1;
	
	while((ch=fgetc(file))!=EOF){
		if(ch=='('){
			push(stack,ch);
			
		}else if(ch==')'){
			if(pop(stack)=='\0'){
				printf("Line %d: The parenthetical error\n",line);
			}
			
		}else if(ch=='\n'){
			if(stack->top!=-1){
			printf("Line %d: The parenthetical error\n",line);	
			while(stack->top!=-1){
				pop(stack);
			}
		}
		line++;	
		}
		printf("\nEnter the size of stack[max=100]: ");
		scanf("%d",&cap);
		Stack *stack=createStack(cap);
	
		printf("\n1.PUSH\n2.POP\n3.Display\n4.EXIT");
		int choice,x;
	
		do{
			printf("\nEnter the choice: ");
			scanf("%d",&choice);
			switch(choice){
				case 1: 
				printf("\nEnter a value to be pushed: ");
				scanf("%d",&x);
				push(stack,x);
				break;
				
				
				case 2:
				printf("The popped element is %d\n",pop(stack));
				break;
				
				case 3: 
				display(stack);
				break;
				default:
					printf("\nPlease enter a valid choice(1/2/3/4)");
			}
		
		
			}while(choice!=4);
		}
		fclose(file);
		free(stack->array);
		free(stack);
		
		return 0;
	
	
}













