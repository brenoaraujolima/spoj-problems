#include<stdio.h>
#include <stdlib.h>

typedef struct State {
    int x;
    int y;
    int visited;
    struct State *next;
} state;

int queue_size;
state *head;
state *tail;

int isEmpty() {
    if (queue_size == 0) {
        return 1;
    }
    return 0;
}

void *initQueue() {
    head = (state *) malloc(sizeof(state));
    head->next = NULL;
    queue_size = 0;
}

void insertQueue(state *s) {
    if (queue_size == 0) {
        s->next = NULL;
        head = s;
        printf("%p\n", head->next);
        printf("-------------------\n");
    } else if (queue_size == 1) {
        tail = s;
        printf("head: %d\n", head->x);
        printf("tail: %d\n", tail->x);

    } else {

    }
    queue_size++;
}

int main() {
    initQueue();
    state inicio = {0,0,0};
    state s2 = {1,1,0};
    // state s3 = {2,2,0};
    // state s4 = {3,3,0};
    // state s5 = {4,4,0};
    insertQueue(&inicio);
    insertQueue(&s2);
    // insertQueue(head, s3);
    // insertQueue(head, s4);
    // insertQueue(head, s5);
    return 0;
}