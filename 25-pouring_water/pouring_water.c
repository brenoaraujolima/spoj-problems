#include<stdio.h>
#include <stdlib.h>

typedef struct State {
    int x;
    int y;
    int visited; // 0 non-visited; 1- being visited; 2-visited
    struct State *pred;
    struct State *next;
} state;

int a = 3, b = 5, c = 4;

int queue_size;
state *head;
state *tail;
int **matriz;
int solutionFound = 0; 

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

state *getNeighbors(state s) {
    state *neighbors = malloc(sizeof(state)*6);

    state n;
    n = s;

    n.x = 0;
    neighbors[0] = n; // Esvaziar vaso A

    n = s;
    n.y = 0;
    neighbors[1] = n; // Esvaziar vaso B

    n = s;
    n.x = a;
    neighbors[2] = n; // Encher vaso A

    n = s;
    n.y = b;
    neighbors[3] = n; //Encher vaso B

    n = s;
    if (s.x >= (b-s.y)) {
        n.x = s.x - (b-s.y);
        n.y = b;
    } else {
        n.x = 0;
        n.y = s.y + s.x;
    }
    neighbors[4] = n; // Transferir de A para B

    n = s;
    if (s.y >= (a-s.x)) {
        n.x = a;
        n.y = (s.y-(a-s.x));
    } else {
        n.x = s.x + s.y;
        n.y = 0;
    }
    neighbors[5] = n; // Trasnferir de B para A

    return neighbors;
}

void bfs(state initial) {
    // state *neighbors;
    // initial.visited = 0;
    // initQueue();
    // insert(&initial);

    // while (!isEmpty()) {
    //     state *current = dequeue();

    //     neighbors = getNeighbors(*current);


    // }
}

int main() {
    // state inicio = {0,0,0};
    // bfs(inicio, c);

    state s = {3,5};
    state *n = getNeighbors(s);

    printf("n[0]: (%d , %d)", n[0].x, n[0].y);
    printf("visited:  %d", s.visited);
    // printf("n[0]: (%d , %d)", n[0].x, n[0].y);
    // printf("n[0]: (%d , %d)", n[0].x, n[0].y);
    // printf("n[]: (%d , %d)", n[1]->x, n[1]->y);
    // printf("n[]: (%d , %d)", n[]->x, n[]->y);
    // printf("n[]: (%d , %d)", n[]->x, n[]->y);
    // printf("n[]: (%d , %d)", n[]->x, n[]->y);
    // printf("n[]: (%d , %d)", n[]->x, n[]->y);
    // printf("n[]: (%d , %d)", n[]->x, n[]->y);

    return 0;
}