#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */

void InorderTraversal( BinTree BT ){
    if(!BT)
        return;
    if(BT->Left)
        InorderTraversal( BT->Left );
    printf(" %c", BT->Data);
    if(BT->Right)
        InorderTraversal( BT->Right );
}
void PreorderTraversal( BinTree BT ){
    if(!BT)
        return;
    printf(" %c", BT->Data);
    if(BT->Left)
        PreorderTraversal( BT->Left );
    if(BT->Right)
        PreorderTraversal( BT->Right );
}
void PostorderTraversal( BinTree BT ){
    if(!BT)
        return;
    if(BT->Left)
        PostorderTraversal( BT->Left );
    if(BT->Right)
        PostorderTraversal( BT->Right );
    printf(" %c", BT->Data);
}

typedef struct queue {
    int front;
    int rear;
    int size;
    BinTree *trees;
} *MyQueue;

MyQueue queue_init(int size){
    MyQueue q = malloc(sizeof(MyQueue));
    q->front = q->rear = 0;
    q->size = size;
    q->trees = malloc(sizeof(BinTree) * size);
    return q;
}

void queue_push(MyQueue q, BinTree BT){
    q->trees[q->rear++ % q->size] = BT;
}

BinTree queue_pop(MyQueue q){
    return q->trees[q->front++ % q->size];
}

int queue_empty(MyQueue q){
    return q->rear - q->front == 0;
}

void LevelorderTraversal( BinTree BT ){
    MyQueue q = queue_init(100);
    queue_push(q, BT);
    while(!queue_empty(q)){
        BinTree t = queue_pop(q);
        if(!t)
            continue;
        printf(" %c", t->Data);
        queue_push(q, t->Left);
        queue_push(q, t->Right);
    }
}
