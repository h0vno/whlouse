#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// funkcje przeprowadzające testy
void run_sort_test(void (*sort)(int *, int), char *sort_name, int test_num);
void clear_files(char *sort_name);
void save_results(int n, char *sort_name, char *input_type);

// funkcje generujące tablice
int* rand_array(int n);
int* sorted_array_full(int n, bool inversed);
void rand_decrement_num(int *x);
void rand_increment_num(int *x);

// algorytmy sortujące i funkcje pomocnicze
void insert_sort(int *array, int n);

void selection_sort(int *array, int n);
void swap(int *x1, int *x2);

void merge_sort(int *a, int n);
int* copy_array(int* array, int n);
void mergesplit(int B[], int istart, int iend, int A[]);
void merge(int A[], int istart, int imiddle, int iend, int B[]);

// algorytmy wyszukiwania
int linear_search(int value, int *array, int n);
bool binary_search(int value, int *array, int n);


