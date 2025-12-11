// Linked List in C
// Linked lists are useful in situations where you need to remove/insert
// elements in a really big list, where arrays would be to slow due to
// rearranging all the other elements  in the array to insert/remove a single
// element Linked Lists have NODES, and each node has a POINTER to the next
// node, this way Removing/Inserting becomes O(1). The FIRST element/node is the
// HEAD The LAST element/node is the TAIL and theres also the SIZE of the list
// which is the count of elements/nodes in that list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int          value;
    struct node* next;
} node_t;

void printList(node_t* head)
{
    node_t* temporary = head;

    while (temporary != NULL) {
        printf("%d -> ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

node_t* create_new_node(int value)
{
    // void* malloc(size_t size);
    // allocate memory of specified size at runtime.
    // malloc() returns a void* pointer to the beginning of the allocated memory
    // block. This pointer should be cast to the appropriate data type for use
    // in your program. if it fails (ex: insufficient memory), it returns NULL.
    // Its useful when the exact memory requirements are NOT known at
    // COMPILE-TIME, such as for dynamic arrays, linked lists or other data
    // structures whose size MAY vary.
    // 'size_t size'  specifies the number of bytes of memory to be allocated.
    node_t* result = malloc(sizeof(node_t));
    result->value  = value;
    result->next   = NULL;
    return result;
}

node_t* insert_at_head(node_t** head, node_t* node_to_insert)
{
    node_to_insert->next = *head;
    *head                = node_to_insert;
    return node_to_insert;
}

void insert_after_node(node_t* previous_node, node_t* newnode)
{
    newnode->next       = previous_node->next;
    previous_node->next = newnode;
}

node_t* find_node(node_t* head, int value)
{
    node_t* tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int main()
{
    node_t* head = NULL;
    node_t* tmp;

    if (head == NULL) {
        for (int i = 0; i < 25; i++) {
            tmp = create_new_node(i);
            insert_at_head(&head, tmp);
        }
    }

    tmp = find_node(head, 10);
    printf("found node with value %d\n", tmp->value);

    printList(head);
    return 0;
}
