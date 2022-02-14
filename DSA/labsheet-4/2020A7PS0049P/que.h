#ifndef QUE_H
#define QUE_H

    #include<stdio.h>
    #include<stdlib.h>
    #include<time.h>

    typedef struct node Node;
    typedef struct queue Queue;
    typedef int Boolean;
    struct node {
        void* dataPointer;
        struct node* next;
    };

    struct queue {
        Node *head;
        Node *tail;
    };

    unsigned int space();
    Node* myalloc();
    void myfree(void* ptr);
    void myfreeAll(Queue q);
    void* front (Queue q);
    Boolean isEmpty(Queue q);
    Queue delQ (Queue q);
    Queue addQ (Queue q, void* data);
    int lengthQ (Queue q);
    Queue newQ();
    
#endif // !QUE_H
