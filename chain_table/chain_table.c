#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "chain_table.h"

#pragma pack(1)
struct Node
{
    ElementType element;
    Position next;
};
#pragma pack()

/** create an empty list L */
List MakeEmpty(List L) {
    List tmp = (Position)malloc(sizeof(struct Node));
    tmp->next = NULL;
    return tmp;
}

/** check if the list is empty */
int IsEmpty(List L) {
    return !L->next;
}

/** check if the position is the last node of the list */
int IsLast(List L, Position P) {
    return !P->next;
}

/** find the element which value is E in the list */
Position Find(List L, ElementType E) {
    L = FindPrevious(L, E);
    return L->next;
}

/** delete the element which value is E from the list */
void Delete(List L, ElementType E) {
    L = FindPrevious(L, E);
    List tmp = L->next;
    L->next = tmp->next;
    free(tmp);
}

/** find the previous element of the one which value is E in the list */
Position FindPrevious(List L, ElementType E) {
    Position tmp = L->next;
    while (tmp && (tmp->element != E)) {
        L = tmp;
        tmp = L->next;
    }
    return L;
}

/** insert an element which value is E after the position P in the list */
void Insert(List L, Position P, ElementType E) {
    List tmp = (Position)malloc(sizeof(struct Node));
    if (!tmp) {
        printf("Out of memory!\n");
        exit(-1);
    }
    tmp->element = E;
    tmp->next = P->next;
    P->next = tmp;
}

/** add an element at the end of the list */
void Append(List L, ElementType E) {
    List tmp = Last(L);
    Insert(L, tmp, E);
}

/** delete all elements of the list */
void DeleteList(List L) {
    List tmp = L->next;
    while (tmp) {
        L->next = tmp->next;
        free(tmp);
        tmp = L->next;
    }
    free(L);
    // L->next = NULL;
}

/** the header of the list */
Position Header(List L) {
    return L;
}

/** get the first node of the list */
Position First(List L) {
    return L->next;
}

/** get the last node of the list */
Position Last(List L) {
    while (L->next) {
        L = L->next;
    }
    return L;
}

/** get the next node of the node */
Position Advance(Position P) {
    return P->next;
}

/** get the value of the node */
ElementType Retrieve(Position P) {
    return P->element;
}