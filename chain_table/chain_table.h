#ifndef __CHAIN_TABLE_H__
#define __CHAIN_TABLE_H__

// structures
// struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
// element type

// functions to op ct
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(List L, Position P);
Position Find(List L, ElementType E);
void Delete(List L, ElementType E);
Position FindPrevious(List L, ElementType E);
void Insert(List L, Position P, ElementType E);
void Append(List L, ElementType E);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Last(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);


#endif