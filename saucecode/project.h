#define TEST_NUM 100000
#define ARR_SIZE 1000
#define MAX_SIZE 50
#define DEBUG true
#define N 0

int* rand_array(int n, int max_size);

void selection_sort(int *array, int n);
void invert_sort(int *array, int n);

int* copy_array(int* array, int n);
void mergesort(int *a, int n);
void mergesplit(int B[], int istart, int iend, int A[]);
void merge(int A[], int istart, int imiddle, int iend, int B[]);

int linear_search(int value, int *array, int n);
bool binary_search(int value, int *array, int n);

void swap(int *x1, int *x2);
