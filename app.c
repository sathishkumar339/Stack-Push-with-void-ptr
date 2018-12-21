#include<stdio.h>
#include "stack.h"

int main() {

	int choice,num,nmax;
	stack_t *sd;

	printf("Enter no of items to Push : \t");
	scanf("%d",&nmax);

	if((nmax <= MIN_ITEMS) || (nmax >= MAX_ITEMS)) {
		fprintf(stderr,"No of Items should be between %d .. %d \n",MIN_ITEMS,MAX_ITEMS);
		main();
	}

	sd = open_stack(nmax, sizeof num);
	if(sd == NULL) {
		fprintf(stderr,"Failed to open stack\n");
		exit(1);
	}

	while(1) {
		help();
		printf("Enter your choice :\t");	
		scanf("%d",&choice);
		
		switch (choice) {
		case PUSH_OP:
			if(is_stack_full(sd)) {
				printf("stack is Full\n");
			}	else {
				printf("Enter the Number to Push : \t");
				scanf("%d",&num);
				push(sd,&num);
			}
			break;

		case POP_OP:
			if(is_stack_empty(sd)) {
				fprintf(stderr,"stack is empty\n");
			} else {
				pop(sd,&num);
				printf("Popped num is : %d\n",num);
			}
			break;

		case EXIT_OP:
			printf("Bye\n");
			free(sd->start);
			free(sd);
			exit(1);
		
		default :
			printf("Invalid choice\n");
			break;
		}
	}
}	

int help() {

	printf(" Press 1 for PUSH_OP\n Press 2 for POP_OP\n press 3 for EXIT\n");

}			
			
				
