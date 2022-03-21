#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *Node;

Node readNums() {
    Node list, node, prev;
    int num;
    list = node = prev = NULL;
    do {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }

        node = (Node) malloc(sizeof(Node));
        node->data = num;
        if (prev)
            prev->next = node;
        prev = node;
        if (!list)
            list = node;
    } while (1);

    return list;
}

void printList(Node list) {
    Node node = list;
    int sp_flag = 0;
    while (node) {
        if (sp_flag)
            printf(" ");
        printf("%d", node->data);
        node = node->next;

        sp_flag = 1;
    }
}

int checkInList(Node list, int value) {
    Node node = list;
    while (node) {
        if (node->data == value)
            return 1;
        node = node->next;
    }
    return 0;
}

Node mergeList(Node list_1, Node list_2) {
    Node list, node, prev, node_1, node_2;
    list = node = prev = NULL;

    node_1 = list_1;
    node_2 = list_2;

    while (node_1) {
        if (checkInList(list_2, node_1->data)) {
            node = (Node) malloc(sizeof(Node));
            node->data = node_1->data;
            if (prev)
                prev->next = node;
            prev = node;
            if (!list)
                list = node;
        }

        node_1 = node_1->next;
    }

    while (node_2) {
        if (checkInList(list_1, node_2->data) && !checkInList(list, node_2->data)) {
            node = (Node) malloc(sizeof(Node));
            node->data = node_2->data;
            if (prev)
                prev->next = node;
            prev = node;
            if (!list)
                list = node;
        }

        node_2 = node_2->next;
    }

    return list;
}

int main() {
    Node list_1 = readNums();
    Node list_2 = readNums();

    if (!list_1 || !list_2) {
        printf("NULL");
        return 0;
    }

    Node list_3 = mergeList(list_1, list_2);
    if (!list_3) {
        printf("NULL");
        return 0;
    }

    printList(list_3);

    return 0;
}
