/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;   // array of location

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);

 
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{

//Implement this function
//

 }
  
void insertelements (JobList list , int size, SeqList s[3])
{

// Implement this function

/* Make a location object from a job and insert into st */

    for (int i = 0; i < size; i++)
    {
        /* i iterates through list */
        SeqList* monitor = &s[list[i].pri];
        monitor->size++;

        int index = monitor->head;
        while(st[index].next != -1)
        {
            index = st[index].next;
        }

        // index now points to the last element of the list with the same priority

        Location loc = {list[i], -1};
        st[nextfreeloc] = loc;
        st[index].next = nextfreeloc;
        nextfreeloc++;
    }


/* update each of the size in s[0], s[1] and s[2] accordingly */
}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

// Implement this function

}

void printlist(SeqList sl)
{

// Implement this function

}

void printJobList(JobList list, int size)
{

// Implement this function

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list);
}
