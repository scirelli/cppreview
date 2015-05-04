#include "node.h"
#include <stdlib.h>
#include <stdio.h>

int intCompare( DATA *a, DATA *b ){
    return *a - *b;
}

int main( int argc, char *argv[] )
{
    printf("Create a list.\n");
    DATA *d = (DATA*)malloc(sizeof(DATA));
    *d = -1;
    LinkList *p_list = createLinkList( d );
    printList(p_list);
    printf("\n");
   
    int cnt = 10;
    printf("Append %d things to the list.\n", cnt);
    for( int i=0; i<cnt; i++ ){
        d = (DATA*)malloc(sizeof(DATA));
        *d = i;
        append( p_list, d );
    }
    printList(p_list);
    printf("\n");
     
    printf("Prepend something to the list.\n");
    d = (DATA*)malloc(sizeof(DATA));
    *d = 0;
    prepend( p_list, d );
    printList(p_list);
    printf("\n");

    printf("See if the list contains 2.\n");
    DATA find = 2;
    if( contains( p_list, &find, &intCompare ) != NULL ){
        printf("Found.\n");
    }else{
        printf("Not found.\n");
    }
   
    printf("Remove a node. Node = %d. ", find);
    Node * tmp = removeNode(p_list, &find, &intCompare );
    printNode( "It does. Found ", tmp );
    free(tmp);
    printf("\n");
    printList( p_list );
    printf("\n");

    printf("Is the list cyclical?\n");
    if( cyclical(p_list) ){
        printf("Yes.\n");
    }else{
        printf("No. Then create one.\n");
        p_list->tail->next = p_list->head;
        if( cyclical(p_list) ){
            printf("Cyclic list created.\n");
        }else{
            printf("Still not cyclic.\n");
        }
    }
    
    printf("Clean up.");
    deleteList( p_list );
    return 0;
}
