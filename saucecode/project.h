#define TEST_NUM 100000
#define ARR_SIZE 1000
#define MAX_SIZE 50
#define DEBUG true
#define N 0

void run_sort_test(void (*sort)(int *, int), char *sort_name, int test_num);
void clear_files(char *sort_name);
void save_results(int n, char *sort_name, char *input_type);

int* rand_array(int n);
int* sorted_array_full(int n, bool inversed);
void rand_decrement_num(int *x);
void rand_increment_num(int *x);

void selection_sort(int *array, int n);
void insert_sort(int *array, int n);

int* copy_array(int* array, int n);
void merge_sort(int *a, int n);
void mergesplit(int B[], int istart, int iend, int A[]);
void merge(int A[], int istart, int imiddle, int iend, int B[]);

int linear_search(int value, int *array, int n);
bool binary_search(int value, int *array, int n);

void swap(int *x1, int *x2);
