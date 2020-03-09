#include <stdio.h>
#include <stddef.h>
#include "chain_table.h"

void showAll(List L) {
    while (L) {
        printf("%d\n", Retrieve(L));
        L = Advance(L);
    }
    printf("====== end of show ======\n");
}

int main(void) {
    List L = MakeEmpty(NULL);
    printf("list L: 0x%p\n", L);

    for (int i = 1; i < 10; i++) 
        Append(L, i);
        // Insert(L, tmp, i);
    showAll(L);

    Delete(L, 5);
    showAll(L);

    Position tmp = Find(L, 4);
    Insert(L, tmp, 5);
    showAll(L);
    
    DeleteList(L);

    return 0;
}