#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#define MAX_SIZE 100000


typedef struct pri_queue {
    int *heap;
    int *cid;
    int count;
} p_queue;

void node_change(int *a, int*b);
p_queue *p_queue_make(int cnum);
p_queue *p_queue_push(p_queue *root, int data, int cid_data);
int p_queue_pop(p_queue *root);
void p_queue_free(p_queue *q);

#endif