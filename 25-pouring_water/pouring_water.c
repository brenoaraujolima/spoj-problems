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
    int count = 0;
    if (queue_size == 0) {
        return NULL;
    } else if (queue_size == 1) {
        removed = head;
        head = NULL;
        tail = NULL;
        queue_size--;
        return removed;
    } else {
        removed = tail;
        tail = head;
    }
    queue_size--;
    while(count < queue_size-1) {
        tail = tail->next;
        count++;
    }
    tail->next = NULL;
    return removed;
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
    state s2 = {1,1,0};
    state s3 = {2,2,0};
    state s4 = {3,3,0};
    state s5 = {4,4,0};
    insert(&inicio);
    insert(&s2);
    insert(&s3);
    insert(&s4);
    insert(&s5);

    printQueue();

    state *st0 = dequeue();
    printQueue();
    printf("removido: %d", st0->x);
    printf("--------------------------\n");

    st0 = dequeue();
    printQueue();    
    printf("removido: %d", st0->x);
    printf("--------------------------\n");

    st0 = dequeue();
    printQueue();
    printf("removido: %d", st0->x);
    printf("--------------------------\n");

    // printf("%d", st2->x);

    return 0;
}