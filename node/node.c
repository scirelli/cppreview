#include "node.h"
#include <stdlib.h>

Node* append( LinkList **ll, DATA *d )
{
    (*ll)->tail->next = malloc( sizeof(Node) );
    (*ll)->tail->data = d;
    (*ll)->tail = (*ll)->tail->next;
    return (*ll)->tail;
}
