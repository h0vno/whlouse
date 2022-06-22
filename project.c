#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "arrhelp.c"

#define invert_isort(arr, n) isort(arr, n, isgreater)
#define iisort(arr, n) isort(arr, n, isless)

#define invert_ssort(arr, n) ssort(arr, n, isless)
#define sssort(arr, n) ssort(arr, n, isgreater)

void isort(int *array, int n, bool (*compare)(int *, int *));
void ssort(int *array, int n, bool (*compare)(int *, int *));
int *mergesort(int *array, int n);
int *merge(int *array1, int *array2, int n1, int n2);

bool testsort(int *arr1, int *arr2, int n, bool print_successful);

int linear_search(int value, int *array, int n);
bool binary_search(int value, int *array, int n);

bool isprime(int n);
void swap(int *x1, int *x2);
bool isless(int *x1, int *x2);
bool isgreater(int *x1, int *x2);

int main()
{
    srand(time(NULL));

    int *array, *array2, n, x, count = 0;

    for (int i = 0; i < 100000000; i++) {
        n = rand() % 50 + 1;
        array = rand_array(n);
        array2 = copy_array(array, n);

        array2 = mergesort(array2, n);
        /* sssort(array2, n); */

        if (!testsort(array, array2, n, false))
            count++;

        // test search
        /* x = rand() % n; */
        /* if(linear_search(array2[x], array2, n) == -1) { */
        /* if(!binary_search(array2[x], array2, n)) { */
        /*     printf("\nsearch for array[%d] == %d failed\n", x, array2[x]); */
        /*     print_array(array2, n); */
        /*     count++; */
        /* } */

        free(array);
        free(array2);
    }

    printf("count: %d\n", count);

    return 0;
}

bool testsort(int *array, int *array_sorted, int n, bool print_succesful)
{

    bool inorder = print_hierarchy(array_sorted, n, false);
    bool same = cmp_array(array, array_sorted, n) ;

    if (print_succesful)
        printf("arrays elements are %s\n", same ? "the same" : "not same");

    bool result = (inorder * same);
    if (!result) {
        /* printf("n is: %s\n", n); */
        /* print_array(array, n); */
        /* print_array(array_sorted, n); */
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
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++) 
            if ((*compare)(&array[i], &array[j]))
                swap(&array[i], &array[j]);
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


int *mergesort(int *array, int n)
{
    // sort the smallest possible arrays
    if (isprime(n)) {
        sssort(array, n);
        return array;
    } else {
        int half = n / 2;
        int half2 = n - half;
        int *left = mergesort(array, half);
        int *right = mergesort(array+half, half2);
        int *arr = merge(left, right, half, half2);
        return arr;
    }
}

int* merge(int *arr1, int *arr2, int n1, int n2)
{
    int merged_length = n1 + n2;
    int *merged;
    merged = malloc(sizeof(int) * (merged_length));

    int i, left, right;
    for (i = left = right = 0; left < n1 && right < n2; i++) {
        if (arr1[left] < arr2[right]) {
            merged[i] = arr1[left];
            left++;
        } else {
            merged[i] = arr2[right];
            right++;
        }
    }

    // move the rest of arr to merged
    // one of two activates, depends from left or right less than n
    for (; left < n1 && i < merged_length; left++, i++)
        merged[i] = arr1[left];
    
    for (; right < n2 && i < merged_length; right++, i++)
        merged[i] = arr2[right];

    return merged;
}

bool isprime(int n)
{
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
        return true;
    for (int i = 2; i < n; i++)
        if (n % i == 0) return false;
    return true;
}
