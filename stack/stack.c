#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct _Stack {
    ElementType s[STACK_SIZE_MAX];
    int p;
};


Stack InitStack(Stack S) {
    Stack tmp = (Stack)malloc(sizeof(struct _Stack));
    tmp->p = -1;
    return tmp;
}

void DestroyStack(Stack S) {
    free(S);
    S = NULL;
}

void ClearStack(Stack S) {
    S->p = -1;
}

int IsEmpty(Stack S) {
    return (S->p == -1 ? 1 : 0);
}

void GetTop(Stack S, ElementType *e) {
    *e = S->p;
}

void Push(Stack S, ElementType e) {
    if (S->p < STACK_SIZE_MAX - 1)
        S->s[++S->p] = e;
    else 
        printf("out of stack!\n");
}

void Pop(Stack S, ElementType *e) {
    if (S->p != -1)
        *e = S->s[S->p--];
    else
        printf("end of stack!\n");
}

int StackLen(Stack S) {
    return (S->p + 1);
}
