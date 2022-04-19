#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>

#define ASSERT(v, msg) \
    if (!(v)) { \
        printf("ASSERTATION FAILED: %s\nat %s:%d\n", msg, __FILE__, __LINE__); \
        exit(1); \
    }

typedef struct {
    void** values;
    size_t length;
} List;

List* new_list();
void delete_list(List* self);

void list_add(List* self, void* value);
void* list_at(List* self, int index);
void* list_remove(List* self, int index);
void* list_remove_at(List* self, void* value);
size_t list_length(List* self);
void** list_to_array(List* self);

typedef struct LinkedListNodeStruct {
    struct LinkedListNodeStruct* prev, * next;
    void* value;
} LinkedListNode;

LinkedListNode* new_linked_list_node(LinkedListNode* prev, LinkedListNode* next, void* value);
void delete_linked_list_node(LinkedListNode* self);

typedef struct {
    LinkedListNode head;
    size_t length;
} LinkedList;

LinkedList* new_linked_list();
void delete_linked_list();

void linked_list_add(LinkedList* self, void* value);
void* linked_list_at(LinkedList* self, int index);
void* linked_list_remove_at(LinkedList* self, int index);
void* linked_list_remove(LinkedList* self, void* value);
size_t linked_list_length(LinkedList* self);
void** linked_list_to_array(LinkedList* self);

#endif
