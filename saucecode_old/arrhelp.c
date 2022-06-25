#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct numcount {
    int value;
    int count;
    struct numcount *left;
    struct numcount *right;
};

struct numcount *makenode(int value)
{
    struct numcount *node;
    node = malloc(sizeof(struct numcount));
    node->value = value;
    node->count = 0;
    node->left = 0;
    node->right = 0;
}


bool bintree_count_equal(struct numcount *node, int value);
void bintree_free(struct numcount *node);
bool print_hierarchy(int *array, int n, bool print_succesful);
bool isle(int *x1, int *x2);
bool isge(int *x1, int *x2);

bool test();
bool testsort(int *arr1, int *arr2, int n, bool print_successful);

bool print_hierarchy(int *array, int n, bool print_succesful)
{
    int i;
    for (i = 0; array[i] == array[i+1] && i < n; i++);

    if (i == n-1) { 
        if (print_succesful)
            printf("array elements are the same\n");
        return true;
    }

    bool descending = (array[i] > array[i+1]);
    bool (*compare)(int *, int *) = descending ? isge : isle;

    for (; i < n-1; i++)
        if (!(*compare)(&array[i], &array[i+1]))
            return false;

    if (print_succesful)
        printf("array is in %s order\n",
                descending ? "descending" : "ascending");
    return true;
}



void bintree_change(int value, int change, struct numcount *node)
{
    for (;;) {
        if (value < node->value) {
            if (!node->left)
                node->left = makenode(value);
            node = node->left;
        }
        else if (value > node->value) {
            if (!node->right)
                node->right = makenode(value);
            node = node->right;
        }
        else {
            node->count+=change;
            break;
        }
    }
}

bool copy_array_to_2nd(int* array, int* array2, int n);
bool cmp_array(int *array, int *array2, int n);

bool copy_array_to_2nd(int* array, int* array2, int n)
{
    for (int i = 0; i < n; i++)
        array2[i] = array[i];
}

// adds +1 count to every value from first array
// subtracts for every value from second
// if any value in bintree with count different from 0
// arrays are different
bool cmp_array(int *array, int *array2, int n)
{
    struct numcount *bintree = makenode(array[0]);
    bintree->count++;
    bintree_change(array2[0], -1, bintree);

    for (int i = 1; i < n; i++) {
        bintree_change(array[i], 1, bintree);
        bintree_change(array2[i], -1, bintree);
    }

    bool result = bintree_count_equal(bintree, 0);
    bintree_free(bintree); 
    return result;
}

void bintree_free(struct numcount *node)
{
    if (node->left)
        bintree_free(node->left);

    if (node->right)
        bintree_free(node->right);

    free(node);
}

bool bintree_count_equal(struct numcount *node, int value)
{
    if (node->count != value) 
        return false;

    return ((node->left) ? bintree_count_equal(node->left, value) : true) *
           ((node->right) ? bintree_count_equal(node->right, value) : true);
}


void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\n");
}


bool isge(int *x1, int *x2)
{
    return *x1 >= *x2;
}

bool isle(int *x1, int *x2)
{
    return *x1 <= *x2;
}
