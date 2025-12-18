#ifndef DLIST_H
#define DLIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node  Node;
typedef struct DList DList;

struct Node
{
    void *data;
    Node *next;
    Node *prev;
};

struct DList
{
    Node  *head;
    Node  *tail;
    size_t size;
    size_t data_size;
};

#endif
