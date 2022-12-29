#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void node_change(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

p_queue *p_queue_make(int cnum) {
    p_queue *p_q = malloc(sizeof *p_q);
    p_q->heap = (int*)malloc(sizeof(int) * cnum);
    p_q->cid = (int*)malloc(sizeof(int) * cnum);
    p_q->count = 0;
    return p_q;
}

p_queue *p_queue_push(p_queue *root, int data, int cid_data) {
    if( root->count >= MAX_SIZE ) return (p_queue*)-1;
    //printf("%d\n", root->count);
    root->heap[root->count] = data;
    root->cid[root->count] = cid_data;

    int now = root->count;

    int parent = (root->count - 1) /2;

    while( now > 0 && root->heap[now] < root->heap[parent]) {
        node_change( &root->heap[now], &root->heap[parent] );
        node_change( &root->cid[now],  &root->cid[parent] );

        now = parent;
        parent = (parent - 1) /2 ;
    }

    root->count++;

    return root;
}

int p_queue_pop(p_queue* root) {
    if( root->count <= 0) return -1;

    //int res_data = root->heap[0];
    int res_cid = root->cid[0];
    
    root->count--;

    root->heap[0] = root->heap[root->count];
    root->cid[0]  = root->cid[root->count];

    int now = 0, left_child = 1, right_child = 2;

    int target = now;

    while( left_child < root->count) {
        if( root->heap[target] > root->heap[left_child]) target = left_child;

        if( root->heap[target] > root->heap[right_child] && right_child < root->count )
            target = right_child;
        
        if( target == now) break;
        else {
            node_change(&root->heap[now], &root->heap[target]);
            node_change(&root->cid[now],  &root->cid[target]);

            now = target;

            left_child = now*2 + 1;
            right_child = now*2 + 2;

        }

        
    }
    return res_cid;
}

void p_queue_free(p_queue *q) {
    free( q->heap );
    free( q->cid );
    free( q );
}