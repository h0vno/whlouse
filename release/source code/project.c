#include "project.h"
#include "generation.h"
#include "sort_search.h"

int main()
{
    srand(time(NULL));

    // generuj wyniki testu do katalogu data
    run_sort_test(selection_sort, "selection_sort", TEST_SIZE);
    run_sort_test(insert_sort, "insert_sort", TEST_SIZE);
    run_sort_test(merge_sort, "merge_sort", TEST_SIZE);

    return 0;
}



