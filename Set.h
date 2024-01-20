#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "Vector.h"

typedef struct {
    Vector* vector;
} Set;

Set* CreateSet() {
    Set* newSet = NULL;
    while (newSet == NULL) { newSet = (Set*)malloc(sizeof(Set)); }
    newSet->vector = CreateVector();
    return newSet;
}

int GetSetSize(Set* set) {
    if (set == NULL) {
        printf("Warning: trying to get the set's size but set uninitialized\n");
        return INT_MIN;
    } else return GetVectorLength(set->vector);
}

bool SetContains(Set* set, int value) {
    if (set == NULL) {
        printf("Warning: trying to find element in the set but set uninitialized\n");
        return false;
    } else return FindInVector(set->vector, value) != -1;
}

bool InsertIntoSet(Set* set, int value) {
    if (set == NULL) {
        printf("Warning: trying to insert element into the set but set uninitialized\n");
        return false;
    } else if (SetContains(set, value)) return false;
    else {
        VectorPush(set->vector, value);
        return true;
    }
}

bool DeleteFromSet(Set* set, int value) {
    if (set == NULL) {
        printf("Warning: trying to remove element from set but set uninitialized\n");
        return false;
    } else if (!SetContains(set, value)) return false;
    else {
        RemoveFromVector(set->vector, value);
        return true;
    }
}

Set* SetUnion(Set* set1, Set* set2) {
    if (set1 == NULL || set2 == NULL) {
        printf("Warning: trying to perform union but one of the sets is uninitialized\n");
        return NULL;
    } else {
        Set* newSet = CreateSet();
        for (int i = 0; i < GetSetSize(set1); i++)
            InsertIntoSet(newSet, VectorGet(set1->vector, i));
        for (int i = 0; i < GetSetSize(set2); i++)
            InsertIntoSet(newSet, VectorGet(set2->vector, i));
        return newSet;
    }
}

Set* SetIntersection(Set* set1, Set* set2) {
    if (set1 == NULL || set2 == NULL) {
        printf("Warning: trying to perform intersection but one of the sets is uninitialized\n");
        return NULL;
    } else {
        Set* newSet = CreateSet();
        for (int i = 0; i < GetSetSize(set1); i++) {
            int set1Int = VectorGet(set1->vector, i);
            if (SetContains(set2, set1Int)) InsertIntoSet(newSet, set1Int);
        }
        return newSet;
    }
}

Set* SubtractSet(Set* set1, Set* set2) {
    if (set1 == NULL || set2 == NULL) {
        printf("Warning: trying to perform set subtraction but one of the sets is uninitialized\n");
        return NULL;
    } else {
        Set* newSet = CreateSet();
        for (int i = 0; i < GetSetSize(set1); i++) {
            int set1Int = VectorGet(set1->vector, i);
            if (!SetContains(set2, set1Int)) InsertIntoSet(newSet, set1Int);
        }
        return newSet;
    }
}

void PrintSet(Set* set) {
    if (set == NULL) printf("Set: { Uninitialized Set }\n");
    else {
        printf("Set: { ");
        for (int i = 0; i < set->vector->length; i++) printf("%d, ", set->vector->data[i]);
        printf("}\n");
    }
}

