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

void insert(state *s) {
    if (queue_size == 0) {
        s->next = NULL;
        head = s;
    } else if (queue_size == 1) {
        tail = s;
        head->next = tail;
    } else {
        s->next = NULL;
        tail->next = s;
        tail = s;
    }
    queue_size++;
}

state *dequeue() {
    state *removed;
    if (queue_size == 0) {
        return NULL;
    } else if (queue_size == 1) {
        removed = head;
        head = NULL;
        queue_size--;
        return removed;
    } else {
        removed = head;
        head = head->next;
        queue_size--;
        return removed;
    }
}

void printQueue() {
    state *runner = head;
    while(runner != NULL) {
        printf("%d\n", runner->x);
        runner = runner->next;
    }
}

int main() {
    initQueue();
    state inicio = {0,0,0};
    
    return 0;
}