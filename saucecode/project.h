
#define invert_isort(arr, n) isort(arr, n, isgreater)
#define iisort(arr, n) isort(arr, n, isless)

#define invert_ssort(arr, n) ssort(arr, n, isless)
#define sssort(arr, n) ssort(arr, n, isgreater)

void isort(int *array, int n, bool (*compare)(int *, int *));
void ssort(int *array, int n, bool (*compare)(int *, int *));

void mergesort(int *a, int n);
void mergesplit(int B[], int istart, int iend, int A[]);
void merge(int A[], int istart, int imiddle, int iend, int B[]);

bool test();
bool testsort(int *arr1, int *arr2, int n, bool print_successful);

int linear_search(int value, int *array, int n);
bool binary_search(int value, int *array, int n);

bool isprime(int n);
void swap(int *x1, int *x2);
bool isless(int *x1, int *x2);
bool isgreater(int *x1, int *x2);
