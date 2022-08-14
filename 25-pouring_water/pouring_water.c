#include<stdio.h>
#include <stdlib.h>

typedef struct State {
    int x;
    int y;
    int distance;
    struct State *pred;
    struct State *next;
} state;

int a = 3, b = 5, c = 4;

state *head, *tail;

int visited[4000][4000];
int queue_size;

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

state *getNeighbors(state s) {
    state *neighbors = malloc(sizeof(state)*6);

    state n;
    n = s;
    n.distance = s.distance + 1;

    n.x = 0;
    neighbors[0] = n; // Esvaziar vaso A

    n = s;
    n.distance = s.distance + 1;
    n.y = 0;
    neighbors[1] = n; // Esvaziar vaso B

    n = s;
    n.distance = s.distance + 1;
    n.x = a;
    neighbors[2] = n; // Encher vaso A

    n = s;
    n.distance = s.distance + 1;
    n.y = b;
    neighbors[3] = n; //Encher vaso B

    n = s;
    n.distance = s.distance + 1;
    if (s.x >= (b-s.y)) {
        n.x = s.x - (b-s.y);
        n.y = b;
    } else {
        n.x = 0;
        n.y = s.y + s.x;
    }
    neighbors[4] = n; // Transferir de A para B

    n = s;
    n.distance = s.distance + 1;
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

void printSolution(state s) {
    int size = s.distance;
    state solution[size];
    while(s.x!=0 || s.y!=0) {
        solution[s.distance-1] = s;
        s = *s.pred;
    }
    printf("(0 , 0)\n");
    for(int i=0; i<size; i++) {
        printf("(%d , %d)\n", solution[i].x, solution[i].y);
    }
}

int bfs(state initial) {
    state *n, *current;

    initQueue();
    insert(&initial);

    while(queue_size != 0) {
        current = dequeue();
        visited[current->x][current->y] = 1;

        n = getNeighbors(*current);

        for(int i=0; i<6; i++) {
            if (!visited[n[i].x][n[i].y]) {
                visited[n[i].x][n[i].y] = 1;
                n[i].pred = current;
                insert(&n[i]);
                if (n[i].x==c || n[i].y==c) {
                    printSolution(n[i]);
                    return n[i].distance;
                }
            }
        }
        visited[current->x][current->y] = 2;
    }
    return -1;
}

int main() {
    state inicio = {0,0,0};
    int answer = bfs(inicio);
    printf("Numero minimo de passos: %d\n", answer);
    return 0;
}