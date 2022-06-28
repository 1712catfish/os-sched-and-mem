#include <stdlib.h>
#include "queue.h"
#include <pthread.h>
#include <stdio.h>

/* Remember to initilize the queue before using it */
void initialize_queue(struct pqueue_t * q) {
	q->head = q->tail = NULL;
	pthread_mutex_init(&q->lock, NULL);
}

/* Return non-zero if the queue is empty */
int empty(struct pqueue_t * q) {
	return (q->head == NULL);
}

/* Get PCB of a process from the queue (q).
 * Return NULL if the queue is empty */
struct pcb_t * de_queue(struct pqueue_t * q) {
    pthread_mutex_lock(&q->lock);
    struct qitem_t * head = q->head;
    struct pcb_t * proc = NULL;

    if (head != NULL) {
        proc = head->data;
        struct qitem_t * p = head->next;
        free(q->head);
        q->head = p;
    }

    pthread_mutex_unlock(&q->lock);
    return proc;
}

/* Put PCB of a process to the queue. */
void en_queue(struct pqueue_t * q, struct pcb_t * proc) {
    struct qitem_t * proc_qitem = (struct qitem_t *) malloc(sizeof(struct qitem_t));
    proc_qitem->data=proc;
    proc_qitem->next=NULL;

    pthread_mutex_lock(&q->lock);
	if (q->head == NULL)
	    q->head = proc_qitem;
	else
	    q->tail->next = proc_qitem;
    q->tail = proc_qitem;
    pthread_mutex_unlock(&q->lock);
}


