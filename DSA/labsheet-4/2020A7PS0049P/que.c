
#include "que.h"
unsigned int HEAP = 0;

Node* last = NULL;

unsigned int space(){
	return sizeof(Node);
}

Node* myalloc(){
	HEAP += space();
	return malloc(space());
}

void myfree(void* ptr){
	if(HEAP == 0) return;
	free(ptr);
	HEAP -= space();
}

void myfreeAll(Queue q){

	q.tail->next = NULL;
	Node* ptr = q.head->next;
	printf("\n");

	while(q.head != NULL){
		ptr = q.head->next;
		q.head->next = NULL;
		myfree(q.head);
		q.head = ptr;
	}

}

// q1 implementation
void* front (Queue q){
    if(q.head == NULL) return NULL;
    return q.head->dataPointer;
}

Boolean isEmpty(Queue q){
    return (q.head == NULL);
}

Queue delQ (Queue q){
    if(isEmpty(q)) return q;
    Node* ptr = q.head->next;
    q.head->next = NULL;
    myfree(q.head);
    q.head = ptr;
    return q;
}

Queue addQ (Queue q, void* data){
    Node* ptr = myalloc();
    ptr->dataPointer = data;
    ptr->next = NULL;
    if(q.head == NULL){
        q.head = ptr;
        q.tail = ptr;
    }
    else{
        q.tail->next = ptr;
        q.tail = ptr;
    }
    return q;
}

int lengthQ (Queue q){
    if(q.head == NULL) return 0;
    Node* ptr = q.head;
    int len = 0;
    while(ptr != NULL){
        len++;
        ptr = ptr->next;
    }
    return len;
}

Queue newQ(){

	Queue q;
    q.head = NULL;
    q.tail = NULL;

    return q;
}

// void record(unsigned int N, double time, int HEAP, int result){
// 	// automatic analytics collection function
// 	// use file handling to update the excel sheet
	
// 	FILE* fp;
// 	fp = fopen("observations.csv", "a+");
	
// 	fprintf(fp, "%u,%lf,%d,", N, time, HEAP);
// 	if(result) fprintf(fp, "YES\n");
// 	else fprintf(fp, "NO\n");
	
// 	// printf("%u,%d,%d,", N, time, HEAP);
// 	// if(result) printf("YES\n");
// 	// else printf("NO\n");
	
// 	fclose(fp);
// }

void main(){
	
}

