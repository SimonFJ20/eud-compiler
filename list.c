#include <stdlib.h>
#include "utils.h"

List* new_list()
{
    List* self = calloc(1, sizeof (List));
    *self = (List) {
        .values = NULL,
        .length = 0,
    };
    return self;
}

void delete_list(List* self)
{
    free(self->values);
    free(self);
}

void list_add(List* self, void* value)
{
    self->length++;
    if (self->length == 0) {
        self->values = calloc(1, sizeof (void*));
        self->values[0] = value;
    } else {
        self->length++;
        self->values = realloc(self->values, sizeof (void*) * self->length);
        self->values[self->length - 1] = value;
    }
}

void* list_at(List* self, int index)
{
    if (index >= 0) {
        ASSERT(index < self->length, "index out of bounds");
        return self->values[index];
    } else {
        return list_at(self, self->length - index);
    }
}

void* list_remove(List* self, int index)
{
    self->length--;
    if (index >= 0) {
        ASSERT(index < self->length, "index out of bounds");
        return self->values[index];
    } else {
        return list_at(self, self->length - index);
    }
}

size_t list_length(List* self)
{
    return self->length;
}

void** list_to_array(List* self)
{
    void** array = calloc(self->length, sizeof (void*));
    for (int i = 0; i < self->length; i++)
        array[i] = self->values[i];
    return array;
}



