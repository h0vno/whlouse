#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "project.h"

#define RAND_SIZE 50
#define RAND_SIZE_MODIFY 25
#define TEST_SIZE 3000

int op_e, op_d;

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    srand(time(NULL));

    clear_files("selection_sort");
    clear_files("insert_sort");
    clear_files("merge_sort");

    run_sort_test(selection_sort, "selection_sort", TEST_SIZE);
    run_sort_test(insert_sort, "insert_sort", TEST_SIZE);
    run_sort_test(merge_sort, "merge_sort", TEST_SIZE);

    return 0;
}

// run (*sort) function number of test_num on 3 different data types
// save everything to file
void run_sort_test(void (*sort)(int *, int), char *sort_name, int test_num)
{
    clear_files(sort_name);
    int *array;
    for (int n = 1; n < test_num; n++) {
        array = rand_array(n);
        (*sort)(array, n);
        save_results(n, sort_name, "random");
        free(array);

        array = sorted_array_full(n, false);
        (*sort)(array, n);
        save_results(n, sort_name, "sort");
        free(array);

        array = sorted_array_full(n, true);
        (*sort)(array, n);
        save_results(n, sort_name, "inversed_sort");
        free(array);
    }
}

void clear_files(char *sort_name)
{
    FILE *fp;
    char filename_t[64] = "../data/", filename[64];
    strcat(filename_t, sort_name);
    strcat(filename_t, "-");

    strcpy(filename, filename_t);
    strcat(filename, "inversed_sort.txt");
    fp = fopen(filename, "w");
    fclose(fp);
    
    strcpy(filename, filename_t);
    strcat(filename, "sort.txt");
    fp = fopen(filename, "w");
    fclose(fp);
    
    strcpy(filename, filename_t);
    strcat(filename, "random.txt");
    fp = fopen(filename, "w");
    fclose(fp);
}

void save_results(int n, char *sort_name, char *input_type)
{
    // generate name of file
    char filename[64] = "../data/";
    strcat(filename, sort_name);
    strcat(filename, "-");
    strcat(filename, input_type);
    strcat(filename, ".txt");

    // save result to file
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL) printf("error\n"); // can't open file
    fprintf(fp, "%d %d %d\n", n, op_d, op_e);
    fclose(fp);

    // reset counters
    op_e = 0;
    op_d = 0;
}

int* copy_array(int* array, int n)
{
    int *array_copy, i; 
    array_copy = malloc(sizeof(int)*n); op_e += 2;
    for (i = 0, op_e++; i < n; i++, op_e += 2) {
        array_copy[i] = array[i]; op_e += 3;
    }
    return array_copy;
}

int* rand_array(int n)
{
    int *array;
    array = malloc(n * sizeof (int));

    for (int i = 0; i < n; i++)
        array[i] = rand() % RAND_SIZE;

    return array;
}

int* sorted_array_full(int n, bool inversed)
{
    int *array;
    array = malloc(n * sizeof (int));

    void (*modify_num)(int *) =
        (inversed) ? &rand_decrement_num : &rand_increment_num;

    // first element size
    int x = rand() % RAND_SIZE;

    if (inversed) 
        x += n * RAND_SIZE_MODIFY;
            
    for (int i = 0; i < n; i++) {
        (*modify_num)(&x);
        array[i] = x;
    }
    return array;
}

void rand_increment_num(int *x)
{
    *x += rand() % RAND_SIZE_MODIFY + 1;
}

void rand_decrement_num(int *x)
{
    *x -= rand() % RAND_SIZE_MODIFY + 1;
}


int linear_search(int value, int *array, int n)
{
    int i;
    for (i = 0, op_e++; i < n; i++, op_e += 2) {
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


void selection_sort(int *array, int n)
{
    int i, i_min = 0; op_e++;
    for (i = 0, op_e++; i < n-1; i++, i_min = i, op_e+=3) {
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


void insert_sort(int *array, int n)
{
    int temp, j, i;
    for (i = 1, op_e++; i < n; i++, op_e+=2) {
        temp = array[i]; op_e += 2;
        op_e+=2;
        for (j = i-1; j >= 0 && temp < array[j]; j--, op_e+=5) {
            array[j+1] = array[j]; op_e+=4;
        }
        
        array[j+1] = temp; op_e+=2;
    }
}


void merge_sort(int *a, int n)
{
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
    int i = istart, j = imiddle, k; op_e += 2;
    for (k = istart, op_e++; k < iend; k++, op_e += 2) { 
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
