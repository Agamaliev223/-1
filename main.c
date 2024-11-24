#include "h/main.h"


static void test_list()
{
    struct SList* mylist = node_create(3);
    list_add_front(&mylist, 2);
    list_add_front(&mylist, 1);
    list_add_back(&mylist, 4);
    list_print(mylist);

    print_int64(list_at(mylist, 1).value);
    print_newline();
    print_uint64((uint64_t)list_length(mylist));
    print_newline();
    print_newline();

    struct SList *reversed_list = list_reverse(mylist);
    list_print(reversed_list);
    print_int64(list_at(reversed_list, 1).value);
    print_newline();
    print_uint64((uint64_t)list_length(mylist));
    list_destroy(reversed_list);
    reversed_list = NULL;
    print_newline();
    print_newline();

    list_destroy(mylist);
    mylist = NULL;
    list_print(mylist);
    print_uint64((uint64_t)list_length(mylist));
    print_newline();
    print_newline();
}

static void test_array()
{
    size_t array_size = 0;
    int64_t* array = array_int_read(&array_size);
    array_int_print(array, array_size);
    array_int_free(array);
    print_newline();

    size_t marray_rows = 0;
    size_t* marray_sizes = 0;
    int64_t** marray = marray_read(&marray_rows, &marray_sizes);
    marray_print(marray, marray_sizes, marray_rows);
    marray_free(marray, marray_rows);
    free(marray_sizes);
}

static void test_stack()
{
    printf("\nStack test\n");
    struct SStack st = stack_create(3);
    stack_push(&st, 1);
    stack_push(&st, 2);
    print_int64(stack_pop(&st).value);
    stack_push(&st, 3);

    stack_print(st);
    stack_push(&st, 4);
    stack_push(&st, 5);
    stack_print(st);

    stack_destroy(&st);
}


int main()
{
    test_list();
    test_array();
    test_stack();

    return 0;
}