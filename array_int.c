#include "h/array_int.h"


bool array_set(struct SArrayInt *a, size_t index, int64_t value)
{
    if (!a)
    {
        return false;
    }
    if (index < a->size)
    {
        a->data[index] = value;
        return true;
    }
    return false;
}

struct SValidInt64 array_get(struct SArrayInt *a, size_t index)
{
    if (!a)
    {
        return none_int64;
    }
    if (index < a->size)
    {
        return some_int64(a->data[index]);
    }
    return none_int64;
}
