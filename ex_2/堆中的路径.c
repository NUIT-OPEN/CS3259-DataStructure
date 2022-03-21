#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int len;
    int size;
} *Heap;

Heap init_heap(int len) {
    Heap h = malloc(sizeof(Heap));
    h->array = malloc(sizeof(int) * (len + 1));
    h->array[0] = -10001;
    h->len = len;
    h->size = 0;
    return h;
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void insert_heap(Heap h, int data){
    int i = ++h->size;
    h->array[i] = data;
    while(i > 0 && h->array[i] < h->array[i / 2]) {
        swap(&(h->array[i]), &(h->array[i / 2]));
        i /= 2;
    }
}

void route_print_heap(Heap h, int index){
    int flag = 0;
    while(index > 0){
        if(flag)
            printf(" ");
        flag = 1;
        printf("%d", h->array[index]);
        index /= 2;
    }
}

int main() {
    int n, m, t;
    scanf("%d %d", &n, &m);

    Heap h = init_heap(n);

    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        insert_heap(h, t);
    }

    for(int i = 0; i < m; i++){
        scanf("%d", &t);
        if(i > 0)
            printf("\n");
        route_print_heap(h, t);
    }

    return 0;
}
