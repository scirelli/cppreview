#ifndef node_h
#define node_h

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

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

Node*     createNode    ( );
LinkList* createLinkList( DATA *d );
Node*     append        ( LinkList *ll, DATA *d );
Node*     prepend       ( LinkList *ll, DATA *d );
Node*     contains      ( LinkList *ll, DATA *d, int (*compare)(DATA *a, DATA *b) );
Node*     removeNode    ( LinkList *ll, DATA *d, int (*compare)(DATA *a, DATA *b) );
bool      cyclical      ( LinkList *ll          );
bool      deleteList    ( LinkList *ll          );
bool      clearList     ( LinkList *ll          );
void      printNode     ( char str[], Node * n  );
void      printList     ( LinkList *ll          );

#endif
