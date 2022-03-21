#include <stdio.h>
#include <stdlib.h>

typedef struct tree *Tree;
struct tree {
    Tree left;
    Tree right;
    int data;
};

Tree tree_new(int data){
    Tree t = malloc(sizeof(Tree));
    t->left = t->right = NULL;
    t->data = data;
    return t;
}

void tree_insert(Tree t, int data){
    Tree *tp = NULL;
    if (data < t->data)
        tp = &t->left;
    else if(data > t->data)
        tp = &t->right;

    if(tp){
        if(*tp)
            tree_insert(*tp, data);
        else
            *tp = tree_new(data);
    }
}

void tree_dump(Tree t, int *array, int *index){
    if(!t)
        return;
    array[(*index)++] = t->data;
    if(t->left)
        tree_dump(t->left, array, index);
    if(t->right)
        tree_dump(t->right, array, index);
}

int compare(int *a, int *b, int n){
    Tree ta, tb;
    for(int i = 0; i < n; i++){
        if(i == 0){
            ta = tree_new(a[i]);
            tb = tree_new(a[i]);
        } else{
            tree_insert(ta, a[i]);
            tree_insert(tb, b[i]);
        }
    }
    int da[n],db[n], index;

    index = 0;
    tree_dump(ta, da, &index);
    index = 0;
    tree_dump(tb, db, &index);
    for(int i = 0; i < n; i++)
        if(da[i] != db[i])
            return 0;

    return 1;
}

void judge(int n, int l, int *sp_flag){
    int a[n], b[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int j = 0; j < l; j++) {
        for(int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        if(*sp_flag)
            printf("\n");
        printf(compare(a,b,n) ? "Yes": "No");
        (*sp_flag)++;
    }
}

int main(){
    int sp_flag = 0;
    for(int n,l;1;){
        scanf("%d", &n);
        if(!n)
            break;
        scanf("%d", &l);
        judge(n, l, &sp_flag);
    }

    return 0;
}
