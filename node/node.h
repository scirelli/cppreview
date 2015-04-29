#ifndef node_h
#define node_h

#include <stdbool.h>

typedef int DATA;

typedef struct Node 
{
    struct Node *next;
    DATA  *data;
} Node;

typedef struct DNode
{
    struct DNode *next;
    struct DNode *prev;
    DATA *data;
} DNode;

typedef struct LinkList
{
    Node *head;
    Node *tail;
} LinkList;

Node* append ( LinkList **ll, DATA *d );
bool prepend ( LinkList **ll, DATA *d );
bool contains( LinkList *ll,  DATA *d );
Node* delete ( LinkList **ll, DATA *d );

#endif
