#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node* createNode()
{
    Node *n = (Node*)malloc( sizeof(Node) );
    if( !n ) return NULL;
    n->next = NULL;
    n->data = NULL;
    return n;
}

LinkList* createLinkList( DATA *d )
{
    LinkList *ll = (LinkList*)malloc( sizeof(LinkList) );
    if( !ll ) return NULL;
    ll->head = createNode();
    ll->tail = ll->head;
    ll->head->data = d;
    return ll;
}
Node* append( LinkList *ll, DATA *d )
{
    Node *n = createNode();
    if( !n ) return NULL;
    n->data = d;
    ll->tail->next = n;
    ll->tail = n;
    return ll->tail;
}

Node* prepend( LinkList *ll, DATA *d )
{
    Node *n = createNode();
    if( !n ) return NULL;
    n->data = d;
    n->next = ll->head;
    ll->head = n;
    return n;
}

Node* contains( LinkList *ll, DATA *d, int (*compare)(DATA *a, DATA *b) )
{
    if( ll == NULL ) return false;

    Node *n = ll->head;
    Node tmp;
    
    while( n != NULL ){
        tmp = *n;
        if( compare( tmp.data, d ) == 0 )
        {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

Node* removeNode( LinkList *ll, DATA *d, int (*compare)(DATA *a, DATA *b) ){
    if( ll == NULL ) return false;

    Node *curNode = ll->head,
         *prevNode = NULL;
    
    while( curNode != NULL ){
        if( compare( curNode->data, d ) == 0 )
        {
            if( prevNode != NULL ){
                prevNode->next = curNode->next;
                return curNode;
            }else{//Must be at the head
                ll->head = curNode->next;
                return curNode;
            }
        }
        prevNode = curNode;
        curNode = curNode->next;
    }
    return NULL;
}

bool clearList( LinkList *ll )
{
    Node *curNode = ll->head;
    
    while( ll->head != NULL ){
        ll->head = curNode->next;
        free(curNode);
        curNode = ll->head;
    }
    return true;
}
bool deleteList( LinkList *ll )
{
    clearList( ll );
    if( ll != NULL ){
        free(ll);
    }
    return true;
}

void printNode( char str[], Node * n ){
    if( n != NULL ){
        printf("%s", str);
        printf("%d", *n->data );
    }
}

void printList( LinkList *ll )
{
    Node *n = ll->head;

    printNode("", n );
    n = n->next;
    while( n != NULL ){
        printNode(",", n );
        n = n->next;
    }
}
