#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

int vectorMinimumSize = 10;

typedef struct {
    int* data;
    int length;
    int size;
} Vector;

Vector* CreateVector() {
    Vector* newVector = NULL;
    while (newVector == NULL) { newVector = (Vector*)malloc(sizeof(Vector)); }
    newVector->data = (int*)malloc(sizeof(int) * vectorMinimumSize);
    newVector->length = 0;
    newVector->size = vectorMinimumSize;
    return newVector;
};

void GrowVector(Vector* vector) {
    vector->size *= 2;
    int* newData = (int*)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) newData[i] = vector->data[i];
    free(vector->data);
    vector->data = newData;
}

void ShrinkVector(Vector* vector) {
    if (vector->size == vectorMinimumSize) return;
    vector->size /= 2;
    int* newData = (int*)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) newData[i] = vector->data[i];
    free(vector->data);
    vector->data = newData;
}

int GetVectorLength(Vector* vector) {
    if (vector == NULL) {
        printf("Warning: trying to get length but vector is null\n");
        return INT_MIN;
    } else return vector->length;
}

void VectorPush(Vector* vector, int num) {
    if (vector == NULL) {
        printf("Warning: trying to push but vector uninitialized\n");
        return;
    } else {
        vector->data[vector->length++] = num;
        if (vector->length == vector->size) GrowVector(vector);
    }
};

int VectorPop(Vector* vector) {
    if (vector == NULL) {
        printf("Warning: trying to pop but vector uninitialized\n");
        return INT_MIN;
    } else if (vector->length == 0) {
        printf("Warning: trying to pop but vector is empty\n");
        return INT_MIN;
    } else {
        int num = vector->data[--vector->length];
        if (vector->length <= vector->size/3) ShrinkVector(vector);
        return num;
    }
}

int VectorGet(Vector* vector, int index) {
    if (vector == NULL) {
        printf("Warning: trying to get value but vector uninitialized\n");
        return INT_MIN;
    } else if (index >= vector->length || index < 0) {
        printf("Warning: trying to get value but index out of bounds\n");
        return INT_MIN;
    } else return vector->data[index];
};

bool VectorSet(Vector* vector, int index, int value) {
    if (vector == NULL) {
        printf("Warning: trying to set value but vector uninitialized\n");
        return false;
    } else if (index >= vector->length || index < 0) {
        printf("Warning: trying to set value but index out of bounds\n");
        return false;
    } else {
        vector->data[index] = value;
        return true;
    }
}

bool VectorInsertAt(Vector* vector, int value, int index) {
    if (vector == NULL) {
        printf("Warning: trying to insert value but vector uninitialized\n");
        return false;
    } else if (index >= vector->length || index < 0) {
        printf("Warning: trying to insert value but index out of bounds\n");
        return false;
    } else {
        for (int i = vector->length; i > index; i--) 
            vector->data[i] = vector->data[i-1];
        vector->data[index] = value;
        if (++vector->length == vector->size) GrowVector(vector);
        return true;
    }
}

bool VectorRemoveAt(Vector* vector, int index) {
    if (vector == NULL) {
        printf("Warning: trying to remove value but vector uninitialized\n");
        return false;
    } else if (vector->length == 0) {
        printf("Warning: trying to remove value but vector is empty\n");
        return false;
    } else if (index >= vector->length || index < 0) {
        printf("Warning: trying to remove value but index out of bounds\n");
        return false;
    } else {
        while (index < vector->length - 1) {
            vector->data[index] = vector->data[index + 1];
            index++;
        }
        if (--vector->length <= vector->size/3) ShrinkVector(vector);
        return true;
    }
}

int FindInVector(Vector* vector, int value) {
    if (vector == NULL) {
        printf("Warning: trying to find value but vector uninitialized\n");
        return -1;
    } else {
        for (int i = 0; i < vector->length; i++) 
            if (vector->data[i] == value) return i;
        return -1;
    }
}

bool RemoveFromVector(Vector* vector, int value) {
    if (vector == NULL) {
        printf("Warning: trying to remove value but vector uninitialized\n");
        return false;
    } else if (vector->length == 0) {
        printf("Warning: trying to remove value but vector is empty\n");
        return false;
    } else return VectorRemoveAt(vector, FindInVector(vector, value));
}

void PrintVector(Vector* vector) {
    if (vector == NULL) printf("Vector: { Uninitialized Vector }\n");
    else {
        printf("Vector: { length: %d, size: %d, data: { ", vector->length, vector->size);
        for (int i = 0; i < vector->length; i++) printf("%d, ", vector->data[i]);
        printf("} }\n");
    }
}