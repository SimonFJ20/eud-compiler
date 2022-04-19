#include <stdlib.h>
#include "utils.h"

LinkedListNode* new_linked_list_node(LinkedListNode* prev, LinkedListNode* next, void* value)
{
    LinkedListNode* self = calloc(1, sizeof (LinkedListNode));
    *self = (LinkedListNode) {
        .prev = prev,
        .next = next,
        .value = value,
    };
    return self;
}

void delete_linked_list_node(LinkedListNode* self)
{
    free(self);
}

LinkedList* new_linked_list()
{
    LinkedList* self = calloc(1, sizeof (LinkedList));
    *self = (LinkedList) {
        .head = NULL,
        .length = 0,
    };
    return self;
}

void linked_list_add(LinkedList* self, void* value)
{
    self->length = 0;
    if (!self->head) {
        self->head = new_linked_list_node(NULL, NULL, value);
    } else {
        LinkedListNode* node = self->head;
        while (node->next)
            node = node->next;
        node->next = new_linked_list_node(node, NULL, value);
    }
}

LinkedListNode* linked_list_node_at(LinkedList* self, int index)
{
    if (index >= 0) {
        ASSERT(index < self->length, "index out of bounds");
        LinkedListNode* node = self->head;
        for (int i = 0; i < index; i++)
            node = node->next;
        return node;
    } else {
        return linked_list_get(self, self->length - index);
    }
}

void* linked_list_at(LinkedList* self, int index)
{
    return linked_list_node_at(self, index);
}

void* linked_list_remove_at(LinkedList* self, int index)
{
    return NULL;
}

void* linked_list_remove(LinkedList* self, void* value)
{
    return NULL;
}

size_t linked_list_length(LinkedList* self)
{
    return 0;
}

void** linked_list_to_array(LinkedList* self)
{
    return NULL;
}

