#include "h/array.h"

int64_t * array_int_read(size_t * size)
{
    printf("Enter array size: ");
    *size = read_size();
    int64_t* array = calloc(*size, sizeof(int64_t));

    struct SValidInt64 val = none_int64;
    for (size_t i = 0; i != *size; ++i)
    {
        do {
            printf("Enter array item %zu: ", i);
            val = read_int64();
        } while (!val.valid);
        array[i] = val.value;
    }
    return array;
}

void array_int_free(int64_t * array)
{
    free(array);
}

void array_int_print(int64_t * array, size_t size)
{
    if (!array)
    {
        printf("Array is empty!\n");
        return;
    }
    for (size_t i = 0; i != size; ++i)
    {
        print_int64(array[i]);
    }
    print_newline();
}

int64_t ** marray_read(size_t * rows, size_t ** sizes)
{
    printf("Enter Marray rows count: ");
    *rows = read_size();
    print_newline();

    int64_t** marray = calloc(*rows, sizeof(int64_t*));
    *sizes = calloc(*rows, sizeof(size_t));

    for (size_t i = 0; i != *rows; ++i)
    {
        marray[i] = array_int_read(&(*sizes)[i]);
    }
    return marray;
}

void marray_print(int64_t ** marray, size_t * sizes, size_t rows)
{
    if (!marray)
    {
        printf("Marray is empty!\n");
        return;
    }
    printf("\nMarray:\n");
    for (size_t i = 0; i != rows; ++i)
    {
        array_int_print(marray[i], sizes[i]);
    }
    print_newline();
}

void marray_free(int64_t ** marray, size_t rows)
{
    for (size_t i = 0; i != rows; ++i)
    {
        free(marray[i]);
    }
    free(marray);
    marray = NULL;
}
