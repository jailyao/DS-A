#include <stdio.h>
#include <stddef.h>
#include "stack.h"

#define STACK_TEST_LEN  10

int main(void) {
    Stack S = InitStack(NULL);
    ElementType E = 0;

    if (IsEmpty(S)) 
        printf("stack is empty.\n");

    for (int i = 0; i < STACK_TEST_LEN; i++)
        Push(S, i);

    if (!IsEmpty(S)) 
        printf("stack length: %d\n", StackLen(S));

    for (int i = 0; i < STACK_TEST_LEN; i++) {
        Pop(S, &E);
        printf("pop element: %d\n", E);
    }

    if (IsEmpty(S)) 
        printf("stack is empty.\n");

    for (int i = 0; i < STACK_TEST_LEN; i++)
        Push(S, i);

    GetTop(S, &E);
    printf("stack top: %d\n", E);

    ClearStack(S);

    if (IsEmpty(S)) 
        printf("stack is empty.\n");

    DestroyStack(S);

    return 0;
}