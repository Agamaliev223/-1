#ifndef _ARRAY_INT_H
#define _ARRAY_INT_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "valid_int.h"

struct SArrayInt
{
    int64_t *data;
    size_t size;
};


bool array_set(struct SArrayInt *a, size_t index, int64_t value);
struct SValidInt64 array_get(struct SArrayInt *a, size_t index);


#endif