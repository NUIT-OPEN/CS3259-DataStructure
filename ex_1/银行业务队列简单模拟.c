#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int size;
    int *data;
} *Queue;

Queue queue_init(int size) {
    Queue q = (Queue) malloc(sizeof(Queue));
    q->front = q->rear = 0;
    q->size = size;
    q->data = (int *) malloc(sizeof(int) * size);
    return q;
}

int queue_empty(Queue q){
    return q->rear - q->front == 0;
}

int queue_pop(Queue q) {
    if (queue_empty(q)) {
        printf("Queue Empty");
        exit(1);
    }
    return q->data[q->front++ % q->size];
}

void queue_push(Queue q, int x) {
    if (q->rear - q->front >= q->size) {
        printf("Queue Overflow");
        exit(1);
    }
    q->data[q->rear++ % q->size] = x;
}

int main() {
    int n;
    scanf("%d", &n);

    Queue a = queue_init(n);
    Queue b = queue_init(n);

    int t;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        queue_push(t % 2 == 0 ? b : a, t);
    }

    int flag = 0;
    for(int i = 1; !queue_empty(a) || !queue_empty(b); i++){
        if(!queue_empty(a)){
            if(flag)
                printf(" ");
            t = queue_pop(a);
            printf("%d", t);
            flag=1;
        }
        if(i % 2 == 0 && !queue_empty(b)){
            t = queue_pop(b);
            if(flag)
                printf(" ");

            printf("%d", t);
            flag=1;
        }
    }

    return 0;
}
