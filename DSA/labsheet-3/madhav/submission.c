#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned int HEAP = 0;

struct node {
	int number;
	struct node *next;
};

// for the purpose of deallocating in the end
struct node* LAST = NULL;

unsigned int space(){
	return sizeof(struct node);
}

struct node* myalloc(){
	HEAP += space();
	return malloc(space());
}

void myfree(void* ptr){
	if(HEAP == 0) return;
	free(ptr);
	HEAP -= space();
}

void myfreeAll(struct node* head){
	
	LAST->next = NULL;
	struct node* ptr = head->next;
	printf("\n");
	while(head != NULL){
		ptr = head->next;
		head->next = NULL;
		myfree(head);
		head = ptr;
	}
}

int isCyclic(struct node* head){
	struct node* hare = head;
	struct node* tortoise = head;
	
	while(hare != NULL && hare->next != NULL){
		
		tortoise = tortoise->next;
		hare = hare->next->next;
		
		if(hare == tortoise) return 1;
	}
	return 0;
	
}

struct node* createList(unsigned int length, unsigned int reconnect_point){
	// if length is smaller than reconnect point then it becomes a linear list
	// else it becomes a cyclic list
	// reconnect_point is the node which succeeds the last created node of the list
	
	struct node *head = NULL;
	struct node *current = NULL, *prev = NULL, *reconnect = NULL;
	
	prev = myalloc();
	prev->next = NULL;
	prev->number = HEAP/space();
	head = prev;
	
	for(unsigned int i = 1; i < length; ++i) {
		current = myalloc();
		current->number = HEAP/space();
		
		prev->next = current;
		current->next = NULL;
		
		if(i == reconnect_point) reconnect = prev;
		
		prev = current;
		current = NULL;
		
	}
	prev->next = reconnect;
	LAST = prev;
	return head;
}

void record(unsigned int N, double time, int HEAP, int result){
	// automatic analytics collection function
	// use file handling to update the excel sheet
	
	FILE* fp;
	fp = fopen("observations.csv", "a+");
	
	fprintf(fp, "%u,%lf,%d,", N, time, HEAP);
	if(result) fprintf(fp, "YES\n");
	else fprintf(fp, "NO\n");
	
	// printf("%u,%d,%d,", N, time, HEAP);
	// if(result) printf("YES\n");
	// else printf("NO\n");
	
	fclose(fp);
}

void main(){
	unsigned int N, RECONNECT;
	clock_t start, end;
	double runtime;
	int result;
	
	// setting up N
	srand((unsigned) clock());
	N =  rand() % 1000000;
	RECONNECT =   rand() % 1000000;
	
	struct node* head = createList(N, RECONNECT);
	
	start = clock();
	// processes
	result = isCyclic(head);
	
	
	end = clock();
	runtime = ((double) (end - start))/ CLOCKS_PER_SEC;
	// runtime = difftime(end, start) * 1000.0;
	
	record(N, runtime, HEAP, result);
	myfreeAll(head);
}


