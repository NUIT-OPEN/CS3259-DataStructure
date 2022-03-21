#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}

/* 你的代码将被嵌在这里 */

bool Insert( List L, ElementType X ){
    if(L->Last + 1 >= MAXSIZE)
        return false;

    if(X < L->Data[L->Last]){
        L->Data[++L->Last] = X;
        return true;
    }

    for(int i = 0; i <= L->Last; i++){
        if(X > L->Data[i]){
            L->Last++;
            for(int j = L->Last; j > i; j--)
                L->Data[j] = L->Data[j - 1];
            L->Data[i] = X;
            return true;
        } else if (X == L->Data[i]){
            return false;
        }
    }

    return false;
}
