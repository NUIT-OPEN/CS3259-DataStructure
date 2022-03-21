#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef struct {
    int top;
    int size;
    int *data;
} *Stack;

Stack stack_init(int size) {
    Stack s = (Stack) malloc(sizeof(Stack));
    s->top = -1;
    s->size = size;
    s->data = (int *) malloc(sizeof(int) * size);
    return s;
}

int stack_pop(Stack s) {
    if (s->top < 0) {
        printf("Stack Empty");
        exit(1);
    }
    return s->data[s->top--];
}

void stack_push(Stack s, int x) {
    if (s->top + 1 >= s->size) {
        printf("Stack Overflow");
        exit(1);
    }
    s->data[++s->top] = x;
}

int calc(int a, int b, char op) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/') {
        if (b == 0) {
            printf("ERROR: %d/0\n", a);
            exit(0);
        } else
            return a / b;
    }

    printf("OPERROR: %c\n", op);
    return ERROR;
}

int main() {
    int n;
    scanf("%d", &n);

    Stack s1 = stack_init(n);
    Stack s2 = stack_init(n - 1);

    int t;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        stack_push(s1, t);
    }

    char c[1];
    for (int i = 0; i < n - 1; ++i) {
        scanf("%s", c);
        stack_push(s2, c[0]);
    }

    int a, b, r, op;
    for (int i = 0; i < n - 1; ++i) {
        b = stack_pop(s1);
        a = stack_pop(s1);
        op = stack_pop(s2);
        r = calc(a, b, op);
//        printf("%d %c %d = %d\n", a, op, b, r);
        stack_push(s1, r);
    }

    r = stack_pop(s1);
    printf("%d\n", r);

    return 0;
}
