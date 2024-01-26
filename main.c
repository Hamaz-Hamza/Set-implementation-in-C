#include <stdio.h>
#include "Set.h"

int main() {
    Set* set1 = CreateSet();
    for (int i = 0; i < 10; i++) InsertIntoSet(set1, i);
    PrintSet(set1);

    InsertIntoSet(set1, -1);
    PrintSet(set1);

    DeleteFromSet(set1, 1);
    PrintSet(set1);

    Set* set2 = CreateSet();
    for (int i = 5; i < 15; i++) InsertIntoSet(set2, i);
    PrintSet(set2);

    Set* unionSet = SetUnion(set1, set2);
    PrintSet(unionSet);

    Set* intersectionSet = SetIntersection(set1, set2);
    PrintSet(intersectionSet);

    Set* set1_minus_set2 = SubtractSet(set1, set2);
    PrintSet(set1_minus_set2);

    Set* set2_minus_set1 = SubtractSet(set2, set1);
    PrintSet(set2_minus_set1);

    DeleteSet(&set1);
    DeleteSet(&set2);
    DeleteSet(&unionSet);
    DeleteSet(&intersectionSet);
    DeleteSet(&set1_minus_set2);
    DeleteSet(&set2_minus_set1);
}
