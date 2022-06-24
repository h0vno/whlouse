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

int *ga_array, *gb_array, g_n;

int main()
{
    srand(time(NULL));

    int array[] = {19, 16, 15, 13, 22, 7};

    /* merge(array, 5, 5, harray); */
    /* print_array(array, 10); */
    /* print_array(harray, 10); */
    test();
    mergesortfull(array, 6);

    return 0;
}


void mergesort(int *array, int n, int *harray)
{
    if (n == 1) 
        return;
    else {
        int middle = n / 2;
        int end = n - middle;
        mergesort(harray, middle, array);
        mergesort(harray+middle, end, array+middle);
        merge(array, middle, end, harray);
    }
}

// how do I implement merge?
// it probably doesn't really make sense to put two arrays
// in here like they are seperate
//
// there is need to know index of second one and length of two
// but syntax like that suggests there are two different arrays
// when there is only one continous
void merge(int *arr1, int middle, int end, int *harray)
{
    /* copy_array_to_2nd(arr1, harray, middle); */
    int *arr2;
    arr2 = arr1 + middle;

    // merge from harray(arr1) and arr1+middle to arr1
    int i, left, right;
    for (i = left = right = 0; left < middle && right < end; i++) {
        if (arr1[left] < arr2[right]) {
            harray[i] = arr1[left];
            left++;
        } else {
            harray[i] = arr2[right];
            right++;
        }
    }

    // move the rest of arr to merged
    // one of two activates, depends from left or right less than n
    for (; left < middle && i < middle+end; left++, i++)
        harray[i] = arr1[left];
    
    for (; right < end && i < middle+end; right++, i++)
        harray[i] = arr2[right];
}


void mergesortfull(int *array, int n)
{
    int *harray;
    harray = copy_array(array, n);

    ga_array = array;
    gb_array = harray;
    g_n = n;

    mergesort(array, n, harray);
    free(harray);
}


bool test()
{
    int *array, *array2, n, x, count = 0;

    for (int i = 0; i < TEST_NUM; i++) {
        n = rand() % ARR_SIZE + 1;
        if (N)
            n = N;
        array = rand_array(n, MAX_SIZE);
        array2 = copy_array(array, n);

        mergesortfull(array2, n);
        /* sssort(array2, n); */

        if (!testsort(array, array2, n, DEBUG))
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


