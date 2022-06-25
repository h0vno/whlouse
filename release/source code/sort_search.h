// zwróć indeks wartości value jeżli value w tablicy array o długości n
// w innym wypadku, zwróć -1
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

// zwróć true jeżli value w tablicy array o długości n
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


// sortuj tablicę array o rozmiarze n
void selection_sort(int *array, int n)
{
    int i, i_min = 0; op_e++;
    for (i = 0, op_e++; i < n-1; i++, i_min = i, op_e+=3) {
        op_e+=2;
        for (int j = i+1; j < n; j++, op_e+=2)  {
            op_e+=3;
            op_d++;
            if (array[i_min] < array[j]) {
                i_min = j; op_e++;
            }
        }
        swap(&array[i], &array[i_min]); op_e+=2;
    }
}

// zamień x1 i x2
void swap(int *x1, int *x2)
{
    int temp = *x1; 
    *x1 = *x2; 
    *x2 = temp;
    op_e += 3;
}

// sortuj tablicę array o rozmiarze n
void insert_sort(int *array, int n)
{
    int temp, j, i;
    for (i = 1, op_e++; i < n; i++, op_e+=2) {
        temp = array[i]; op_e += 2;
        op_e+=2;
        op_d++;
        for (j = i-1; j >= 0 && temp < array[j]; j--, op_e+=5) {
            array[j+1] = array[j]; op_e+=4;
        }
        
        array[j+1] = temp; op_e+=2;
    }
}

// sortuj tablicę a o rozmiarze n
void merge_sort(int *a, int n)
{
    int *b = copy_array(a, n); op_e++;
    mergesplit(b, 0, n, a);
    free(b);
}

// zwróć kopię tablicy array o rozmiarze n
int* copy_array(int* array, int n)
{
    int *array_copy, i; 
    array_copy = malloc(sizeof(int)*n); op_e += 2;
    for (i = 0, op_e++; i < n; i++, op_e += 2) {
        array_copy[i] = array[i]; op_e += 3;
    }
    return array_copy;
}

// sortuj ciąg z tablicy b do tablicy a
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

// połącz posortowaną tablicę a[istart:imiddle]
// z posortowaną tablicą a[imiddle:iend] do tablicy b
void merge(int *a, int istart, int imiddle, int iend, int *b)
{
    int i = istart, j = imiddle, k; op_e += 2;
    for (k = istart, op_e++; k < iend; k++, op_e += 2) { 
        op_e += 7; 
        op_d++;
        if (i < imiddle && (j >= iend || a[i] <= a[j])) {
            b[k] = a[i]; op_e += 3;
            i++;         op_e++;
        } else {
            b[k] = a[j]; op_e += 3;
            j++;         op_e++;
        }
    }
}
