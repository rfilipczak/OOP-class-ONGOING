#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "./array.h"


Array *array_create(int capacity)
{
    assert(capacity > 0);

    Array *array = (Array *) malloc(sizeof(Array));
    if (array == NULL)
    {
        perror("Allocation failed when allocating array");
        abort();
    }
    array->data = (int *) malloc(sizeof(int) * (size_t) capacity);
    if (array->data == NULL)
    {
        perror("Allocation failed when allocating array->data");
        abort();
    }
    array->capacity = capacity;
    array->size = 0;
    return array;
}

void array_push_back(Array *array, int value)
{
    assert(array != NULL);
    assert(array->data != NULL);
    assert(array->size >= 0);
    assert(array->size < array->capacity);

    array->data[array->size++] = value;
}

void array_destroy(Array *array)
{
    assert(array != NULL);
    assert(array->data != NULL);
    
    free(array->data);
    free(array);
}
