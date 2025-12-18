#include "dlist.h"

DList *dlist_create(size_t data_size)
{
    DList *list = malloc(sizeof(DList));
    if (!list) {
        return NULL;
    }

    list->head      = NULL;
    list->tail      = NULL;
    list->size      = 0;
    list->data_size = data_size;

    return list;
}

static Node *create_node(void *data, size_t data_size)
{
    Node *node = malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }

    node->data = malloc(data_size);
    if (!node->data) {
        free(node);
        return NULL;
    }

    memcpy(node->data, data, data_size);
    node->next = NULL;
    node->prev = NULL;

    return node;
}
