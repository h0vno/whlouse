#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
