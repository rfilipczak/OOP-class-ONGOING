#ifndef ARRAY_H
#define ARRAY_H

//
// Array - simple wrapper around dynamic int array
//

typedef struct Array {
    int *data;
    int size;
    int capacity;
} Array;

// Creates empty array with given capacity
// Warning: will terminate program on allocation failure
Array *array_create(int capacity);

// Pushes value to the array
void array_push_back(Array *array, int value);

// Frees array's data and then array
void array_destroy(Array *array);

#endif // ARRAY_H
