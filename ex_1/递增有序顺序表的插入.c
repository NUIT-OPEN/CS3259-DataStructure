#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read();
void Print( List L );

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

List Insert( List L, ElementType X ){
    PtrToNode node, next;
    node = L;
    while(node){
        next = node->Next;
        if(X >= node->Data && (!next || X <= next->Data))
            break;
        node = next;
    }

    PtrToNode new = (PtrToNode) malloc(sizeof(PtrToNode));
    new->Data = X;
    new->Next = next;
    node->Next = new;
    return L;
}
