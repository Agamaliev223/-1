#ifndef ARRAY_H
#define ARRAY_H

#include <malloc.h>
#include <inttypes.h>
#include <stdio.h>

#include "io.h"


size_t read_size();

int64_t * array_int_read(size_t * size);
void array_int_free(int64_t * array);

void array_int_print(int64_t * array, size_t);


int64_t ** marray_read(size_t * rows, size_t ** sizes);
void marray_print(int64_t ** marray, size_t * sizes, size_t rows);

void marray_free(int64_t ** marray, size_t rows);


#endif
