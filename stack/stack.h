#ifndef __STACK_H__
#define __STACK_H__


#define STACK_SIZE_MAX  100

typedef struct _Stack *Stack;
typedef int ElementType;

/** initialize and return the pointer to the stack */
Stack InitStack(Stack S);
void DestroyStack(Stack S);
void ClearStack(Stack S);
/** if stack is empty, return 1, else return 0 */
int IsEmpty(Stack S);
void GetTop(Stack S, ElementType *e);
void Push(Stack S, ElementType e);
void Pop(Stack S, ElementType *e);
int StackLen(Stack S);





#endif