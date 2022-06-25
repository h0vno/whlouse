#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "arrhelp.c"
#include "project.h"

#define TEST_NUM 100000
#define ARR_SIZE 1000
#define MAX_SIZE 50
#define DEBUG true
#define N 0

int op_e, op_d;

int main()
{
    srand(time(NULL));

    test();

    return 0;
}

bool clean_counter()
{
    op_e = 0;
    op_d = 0;
}

int* copy_array(int* array, int n)
{
    int *array_copy; op_e++;
    array_copy = malloc(sizeof(int)*n); op_e += 2;
    for (int i = 0, op_e++; i < n; i++, op_e += 2) {
        array_copy[i] = array[i]; op_e += 3;
    }
    return array_copy;
}

void mergesort(int *a, int n)
{
    clean_counter();
    int *b = copy_array(a, n); op_e++;
    mergesplit(b, 0, n, a);
    free(b);
}

// sort data from array b to array a
void mergesplit(int *b, int istart, int iend, int *a)
{
    if (iend - istart < 2)
        return; op_e += 2;
    int imiddle = (istart + iend) / 2; op_e += 3;
    mergesplit(a, istart, imiddle, b); 
    mergesplit(a, imiddle, iend, b);
    // merge array b into a
    merge(b, istart, imiddle, iend, a);
}


void merge(int *a, int istart, int imiddle, int iend, int *b)
{
    int i = istart, j = imiddle; op_e += 2;
    for (int k = istart, op_e++; k < iend; k++, op_e += 2) { 
        op_e += 7; 
        if (i < imiddle && (j >= iend || a[i] <= a[j])) {
            b[k] = a[i]; op_e += 3;
            i++;         op_e++;
        } else {
            b[k] = a[j]; op_e += 3;
            j++;         op_e++;
        }
    }
}


int linear_search(int value, int *array, int n)
{
    for (int i = 0, op_e++; i < n; i++, op_e += 2) {
        op_e += 2;
        if (array[i] == value)
            return i;
    }
        
    return -1;
}


bool binary_search(int value, int *array, int n)
{
    op_e++;
    if (n == 1) {
        op_e += 5;
        return (array[0] == value || array[1] == value);
    }

    int left = n / 2;
    int right = (n % 2) ? left + 1 : left;
    op_e += 6;

    op_e++; if (array[left] > value)
        return binary_search(value, array, left);

    op_e++; if (array[left] < value) {
        op_e++;
        return binary_search(value, array+left, right);
    }

    return true;
}


void swap(int *x1, int *x2)
{
    int temp = *x1; 
    *x1 = *x2; 
    *x2 = temp;
    op_e += 3;
}


void ssort(int *array, int n, bool (*compare)(int *, int *))
{
    int i_min = 0; op_e++;
    for (int i = 0, op_e++; i < n-1; i++, i_min = i, op_e+=3) {
        op_e+=2;
        for (int j = i+1; j < n; j++, op_e+=2)  {
            op_e += 3;
            if (array[i_min] < array[j]) {
                i_min = j; op_e++;
            }
        }
        swap(&array[i], &array[i_min]); op_e+=2;
    }
}


void isort(int *array, int n, bool (*compare)(int *, int *))
{
    int temp, j;
    for (int i = 1, op_e++; i < n; i++, op_e+=2) {
        temp = array[i]; op_e += 2;
        op_e+=2;
        for (j = i-1; j >= 0 && temp < array[j]; j--, op_e+=5) {
            array[j+1] = array[j]; op_e+=4;
        }
        
        array[j+1] = temp; op_e+=2;
    }
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

        mergesort(array2, n);
        /* sssort(array2, n); */

        /* if (!testsort(array, array2, n, DEBUG)) */
        /*     count++; */

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
