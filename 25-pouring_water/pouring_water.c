#include<stdio.h>
#include <stdlib.h>

typedef struct State {
    int x;
    int y;
    struct State *pred;
    struct State *next;
} state;

int a = 3, b = 5, c = 4;

int queue_size;
state *head;
state *tail;
int visited[4000][4000];
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
    printf("*******FILA******\n");
    state *runner = head;
    int cont = 0;
    while(cont < queue_size) {
        cont++;
        printf("(%d,%d) -> ", runner->x, runner->y);
        runner = runner->next;
    }
    printf("\n");
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
    state *n, *current;

    initQueue();
    insert(&initial);

    int cont = 0;
    while(!isEmpty() && cont<100) {
        cont++;
        current = dequeue();
        visited[current->x][current->y] = 1;

        n = getNeighbors(*current);

        for(int i=0; i<6; i++) {
            if(!visited[n[i].x][n[i].y]) {
                printf("nao foi visitado: (%d,%d)\n", n[i].x, n[i].y);
                visited[n[i].x][n[i].y] = 1;
                n[i].pred = current;
                insert(&n[i]);
            } else {
                printf("ja foi visitado: (%d,%d)\n", n[i].x, n[i].y);
            }
        }
        visited[current->x][current->y] = 2; 
        printQueue();
    }
}

int main() {
    state inicio = {0,0,0};
    bfs(inicio);

    return 0;
}

        // printf("n[0]: (%d , %d)\n", n[0].x, n[0].y);
        // printf("n[1]: (%d , %d)\n", n[1].x, n[1].y);
        // printf("n[2]: (%d , %d)\n", n[2].x, n[2].y);
        // printf("n[3]: (%d , %d)\n", n[3].x, n[3].y);
        // printf("n[4]: (%d , %d)\n", n[4].x, n[4].y);
        // printf("n[5]: (%d , %d)\n", n[5].x, n[5].y);