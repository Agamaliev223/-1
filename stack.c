#include "h/stack.h"

static size_t stack_count(const struct SStack *s)
{
    return s->count;
}


struct SStack stack_create( size_t size )
{
    return (struct SStack){.count = 0, .data = {.size = size, .data = calloc(size, sizeof(int64_t))}};
}

void stack_destroy( struct SStack* s )
{
    free(s->data.data);
    s = NULL;
}

bool stack_full( struct SStack s)
{
    return s.count >= s.data.size;
}

bool stack_empty( struct SStack s)
{
    return 0 == s.count;
}

bool stack_push( struct SStack* s, int64_t value )
{
    if (stack_full(*s))
    {
        printf("Stack is full\n");
    }
    else if (array_set(&s->data, stack_count(s), value))
    {
        ++s->count;
        return true;
    }
    return false;
}

struct SValidInt64 stack_pop( struct SStack* s )
{
    if (stack_empty(*s))
    {
        printf("Stack is empty\n");
    } 
    else 
    {
        struct SValidInt64 val = array_get(&s->data, stack_count(s) - 1);
        if (val.valid)
        {
            --s->count;
            return val;
        }
    }
    return none_int64;
}

void stack_print( struct SStack s )
{
    if (stack_empty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("\nStack:\n");
    for (size_t i = 0; i < stack_count(&s); ++i)
    {
        printf("%" PRId64 " ", array_get(&s.data, i).value);
    }
    print_newline();
}

