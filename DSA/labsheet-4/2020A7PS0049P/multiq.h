#ifndef MULTIQ_H
#define MULTIQ_H

    #include"que.h"

    typedef struct queue MultiQ;
    typedef int TaskID;
    typedef int Priority;

    typedef struct {
        Priority p;
        TaskID tid;
    } Task;

    // hierarchy -> 
        // queue <- node <- queue <- node <- task
    MultiQ createMQ (int num);
    MultiQ addMQ (MultiQ mq, Task t);
    Task nextMQ (MultiQ mq);
    MultiQ delNextMQ(MultiQ mq);
    Boolean isEmptyMQ (MultiQ mq);
    int sizeMQ(MultiQ mq);
    int sizeMQbyPriority(MultiQ mq, Priority p);
    Queue getQueueFromMQ(MultiQ mq, Priority p);

#endif // !MULTIQ_H