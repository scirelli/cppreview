#include "node.h"
#include <stdlib.h>
#include <stdio.h>

int intCompare( DATA *a, DATA *b ){
    return *a - *b;
}

int main( int argc, char *argv[] )
{
    DATA *d = (DATA*)malloc(sizeof(DATA));
    *d = 1;
    LinkList *p_list = createLinkList( d );
    printList(p_list);
    printf("\n");

    d = (DATA*)malloc(sizeof(DATA));
    *d = 2;
    append( p_list, d );
    printList(p_list);
    printf("\n");

    d = (DATA*)malloc(sizeof(DATA));
    *d = 0;
    prepend( p_list, d );
    printList(p_list);

    printf("\n");
    DATA find = 2;
    if( contains( p_list, &find, &intCompare ) != NULL )
    {
        printf("Found.\n");
    }else{
        printf("Not found.\n");
    }
    
    Node * tmp = removeNode(p_list, &find, &intCompare );
    printNode( "", tmp );
    free(tmp);
    printf("\n");
    printList( p_list );
    printf("\n");
    deleteList( p_list );
    return 0;
}
