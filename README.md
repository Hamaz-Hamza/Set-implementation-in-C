# Set-implementation-in-C
An integer set implementation in C, uses my vector implementation as a helper class.

Stores unique integeres. Automatically allocates and deallocates memory during runtime according to the amount of data stored in it.

Note: It is better to use these provided methods instead of directly accessing the set's data, because these methods perform appropriate validity and error checking.

Functions:
1. CreateSet: create a empty set and return it.
2. GetSetSize: returns the length of the set (number of elements in it).
3. SetContains: returns true if the set contains the specified value otherwise false.
4. InsertIntoSet: add an integer to the set, returns true if value was successfully inserted into the set otherwise false.
5. DeleteFromSet: remove an integer from set and return it, returns true if value was successfully deleted from the set otherwise false.
5  SetUnion: create a new set that contains all non-duplicate values of both specified sets and returns it.
6. SetIntersection: create a new set that contains all duplicate values of both specified sets and returns it.
7. SubtractSet: returns a new set that contains the elements of the first set that are not in the second set.
8. PrintSet: prints elements in the set, if the set pointer is null, prints accordingly


In case of invalid arguments or symantical errors, these methods will print the appropriate errors to the console.


