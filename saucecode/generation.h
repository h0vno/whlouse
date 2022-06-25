#define RAND_SIZE 50
#define RAND_SIZE_MODIFY 25
#define TEST_SIZE 25

int op_e, op_d;

// wykonaj test_num*3(dane losowe, posortowane i posortowane odwrotnie)
// funkcji sortującej (*sort), zapisz do pliku o nazwie
// nazwa_sortowania-typ_danych.txt w folderze data
void run_sort_test(void (*sort)(int *, int), char *sort_name, int test_num)
{
    clear_files(sort_name);  // wyczyść poprzednie wyniki programu
    int *array;
    for (int n = 1; n <= test_num; n++) {
        array = rand_array(n);
        (*sort)(array, n);  // merge_sort dla run_sort_test(merge_sort, ... )
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

// wyczyść pliki z sortowania sort_name
void clear_files(char *sort_name)
{
    FILE *fp;

    // generacja nazwy pliku do zapisu
    // do każdego algorytmu sortującego są generowane 3 pliki
    // o 3 innych końcówkach, filename_t to część wspólna 3 nazw
    char filename_t[64] = "../data/", filename[64];
    strcat(filename_t, sort_name);
    strcat(filename_t, "-");

    strcpy(filename, filename_t);           // skopiuj filename_t do filename
    strcat(filename, "inversed_sort.txt");  // dodaj oryginalną koncówkę
    fp = fopen(filename, "w");              // wyczyść 
    fclose(fp);                             // i zamknij 
    
    strcpy(filename, filename_t);           // zresetuj filename z filename_t
    strcat(filename, "sort.txt");           // powtórz operacje opisane wyżej
    fp = fopen(filename, "w");
    fclose(fp);
    
    strcpy(filename, filename_t);
    strcat(filename, "random.txt");
    fp = fopen(filename, "w");
    fclose(fp);
}

// zapisz wyniki sortowania sort_name z danymi typu input_type
// do odpowiedniego pliku
void save_results(int n, char *sort_name, char *input_type)
{
    // generacja nazwy pliku do zapisu
    char filename[64] = "../data/";
    strcat(filename, sort_name);  // strcat dodaje kolejne ciągi znaków do
    strcat(filename, "-");        // ciągu filename
    strcat(filename, input_type);
    strcat(filename, ".txt");

    // zapisz wyniki do pliku
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL) printf("error\n");
    fprintf(fp, "%d %d %d\n", n, op_d, op_e);
    fclose(fp);

    // resetuj liczniki
    op_e = 0;
    op_d = 0;
}

// zwróć pointer do tablicy o rozmiarze n
// z wylosowanymi wartościami o rozmiarze stałej RAND_SIZE
int* rand_array(int n)
{
    int *array;
    array = malloc(n * sizeof (int));

    for (int i = 0; i < n; i++)
        array[i] = rand() % RAND_SIZE;

    return array;
}

// zwróć pointer do tablicy o rozmiarze n
// funkcja zwraca tablice posortowaną lub posortowaną odwrotnie
// w zależności od wartości zmiennej inversed
int* sorted_array_full(int n, bool inversed)
{
    int *array;
    array = malloc(n * sizeof (int));

    void (*modify_num)(int *) =
        (inversed) ? &rand_decrement_num : &rand_increment_num;

    int x = rand() % RAND_SIZE;    // wartość pierwszego elementu tablicy

    // zwiększa wartość pierwszego elementu,
    // dzięki temu liczby w tablicy nie będą miały wartości negatywnych
    if (inversed)                 
        x += n * RAND_SIZE_MODIFY;
                                
    // wypełnij tablicę rosnącymi/malejącymi wartościami
    for (int i = 0; i < n; i++) {
        (*modify_num)(&x);  // aktywuje rand_increment_num
                            //  lub rand_decrement_num
        array[i] = x;
    }

    return array;
}

// zwiększ wartość x o pseudolosową liczbę
// o maksymalnym rozmiarze stałej RAND_SIZE_MODIFY
void rand_increment_num(int *x)
{
    *x += rand() % RAND_SIZE_MODIFY + 1;
}

// zmniejsz wartość x o pseudolosową liczbę
// o maksymalnym rozmiarze stałej RAND_SIZE_MODIFY
void rand_decrement_num(int *x)
{
    *x -= rand() % RAND_SIZE_MODIFY + 1;
}
