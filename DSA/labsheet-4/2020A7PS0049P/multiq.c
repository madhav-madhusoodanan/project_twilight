#include"que.c"
#include"multiq.h"
// hierarchy -> 
    // queue <- node <- queue <- node <- task
MultiQ createMQ (int num) {
    // make a Queue
    // make num elements in the Queue
    // return the Queue
    MultiQ q = newQ();
    for(int i = 0; i < num; i++){
        Queue elem = newQ();
        q = addQ(q, (void*)&elem);
    }
    return q;
}

MultiQ addMQ (MultiQ mq, Task t) {
    // add t to the Queue at the right position
    // return the Queue
    // head is at priority 0
    if(mq.head == NULL) return mq;  // maybe create a queue?
    Node* ptr = mq.head;
    for(int i = 0; i < t.p; i++){
        ptr = ptr->next;
    }

    Queue *q = (Queue*)ptr->dataPointer;
    Queue temp = addQ(*q, (void*)&t);
    ptr->dataPointer = (void*)&temp;

    return mq;
}

Task nextMQ (MultiQ mq) {
    // return the next task in the Queue
    // return the task
    // head is at priority 0
    if(mq.head == NULL) return (Task){-1, -1};
    Queue *q = NULL;
    Queue *prev = NULL;
    Node* ptr = mq.head;

    while(ptr != NULL){
        prev = q;
        q = (Queue*)ptr->dataPointer;

        if(q == NULL || isEmpty(*q)) break;
        else ptr = ptr->next;
    }

    Task* t = (Task*)front(*prev);
    return *t;
    
}

MultiQ delNextMQ(MultiQ mq) {
    // delete the next task in the Queue
    // return the Queue
    // head is at priority 0
    if(mq.head == NULL) return mq;
    Queue *q = NULL;
    Queue *prev = NULL;
    Node* ptr = mq.head;
    Node* prevNode = NULL;

    while(ptr != NULL){
        prev = q;
        q = (Queue*)ptr->dataPointer;

        if(q == NULL || isEmpty(*q)) break;
        else {
            prevNode = ptr;
            ptr = ptr->next;
        }
    }

    Queue temp = delQ(*q);
    prevNode->dataPointer = (void*)&temp;

    return mq;
}

Boolean isEmptyMQ (MultiQ mq) {
    // return true if the Queue is empty
    // return false otherwise
    // head is at priority 0
    if(mq.head == NULL) return 1;
    Queue *q = NULL;
    Node* ptr = mq.head;

    while(ptr != NULL){
        q = (Queue*)ptr->dataPointer;
        if(q == NULL || isEmpty(*q)) return 1;
        else ptr = ptr->next;
    }

    return 0;
}

int sizeMQ(MultiQ mq) {
    return lengthQ(mq);
}

int sizeMQbyPriority(MultiQ mq, Priority p) {
    Queue t = getQueueFromMQ(mq, p);
    return lengthQ(t);
}

Queue getQueueFromMQ(MultiQ mq, Priority p) {
    Node* ptr = mq.head;
    for(int i = 0; i < p; i++){
        if(ptr == NULL) return newQ();
        if(ptr->next == NULL) break;
        ptr = ptr->next;
    }
    Queue *t = (Queue*)ptr->dataPointer;
    return *t;
}