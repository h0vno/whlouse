#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "arrhelp.c"
#include "project.h"

#define TEST_NUM 1
#define ARR_SIZE 10
#define MAX_SIZE 50
#define DEBUG true
#define N 5

void TopDownMergeSort(int *a, int n);
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[]);
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[]);

int main()
{
    srand(time(NULL));

    test();

    return 0;
}


// Array A[] has the items to sort; array B[] is a work array.
void TopDownMergeSort(int *a, int n)
{
    int *b = copy_array(a, n);       // one time copy of a[] to b[]
    TopDownSplitMerge(b, 0, n, a);   // sort data from b[] into a[]
    free(b);
}

// Split A[] into 2 runs, sort both runs into B[], merge both runs from B[] to A[]
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
    if (iEnd - iBegin <= 1)                     // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
    TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

//  Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
    int i = iBegin, j = iMiddle;
 
    // While there are elements in the left or right runs...
    for (int k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}


bool testsort(int *array, int *array_sorted, int n, bool print_succesful)
{

    bool inorder = print_hierarchy(array_sorted, n, false);
    bool same = cmp_array(array, array_sorted, n) ;

    bool result = (inorder * same);
    if (!result && print_succesful) {
        printf("n is: %d\n", n);
        print_array(array, n);
        print_array(array_sorted, n);
    }

    return result;
}

int linear_search(int value, int *array, int n)
{
    for (int i = 0; i < n; i++)
        if (array[i] == value)
            return i;
    return -1;
}

bool binary_search(int value, int *array, int n)
{
    if (n == 1)
        return (array[0] == value || array[1] == value);

    int left = n / 2;
    int right = (n % 2) ?  left + 1 : left;

    if (array[left] > value)
        return binary_search(value, array, left);

    if (array[left] < value)
        return binary_search(value, array+left, right);

    return true;
}

void swap(int *x1, int *x2)
{
    int temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}

bool isgreater(int *x1, int *x2)
{
    return *x1 > *x2;
}

bool isless(int *x1, int *x2)
{
    return *x1 < *x2;
}


void ssort(int *array, int n, bool (*compare)(int *, int *))
{
    int i_min = 0;
    for (int i = 0; i < n-1; i++, i_min = i) {
        for (int j = i+1; j < n; j++) 
            if ((*compare)(&array[i_min], &array[j]))
                i_min = j;
        swap(&array[i], &array[i_min]);
    }
}


void isort(int *array, int n, bool (*compare)(int *, int *))
{
    int temp, j;
    for (int i = 1; i < n; i++) {
        temp = array[i];
        for (j = i-1; j >= 0 && (*compare)(&temp, &array[j]); j--) 
            array[j+1] = array[j];
        
        array[j+1] = temp;
    }
}


