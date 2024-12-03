#include "h/list.h"


struct SList *node_create(int64_t value)
{
    struct SList *l = malloc(sizeof(struct SList));
    l->value = value;
    l->next = NULL;
    return l;
}

void list_destroy(struct SList *list)
{
    while (list)
    {
        struct SList *current = list;
        list = current->next;
        free(current);
    }
}

void list_add_front(struct SList **old, int64_t value)
{
    if (!old) return;
    struct SList *new_l = node_create(value);
    new_l->next = *old;
    *old = new_l;
}

struct SList *list_last(struct SList *list)
{
    if (!list)
    {
        return NULL;
    }
    struct SList *current = list;
    while (NULL != current->next)
    {
        current = current->next;
    }
    return current;
}

void list_add_back(struct SList **old, int64_t value)
{
    if (!old)
        return;

    struct SList *new_l = node_create(value);
    struct SList *last_old = list_last(*old);
    if (NULL != last_old)
    {
        last_old->next = new_l;
        return;
    }
    *old = new_l;
}

size_t list_length(struct SList const *list)
{
    size_t size = 0;
    if (NULL == list)
    {
        return size;
    }

    struct SList const *current_node = list;
    do
    {
        size++;
        current_node = current_node->next;
    } while (NULL != current_node);

    return size;
}

struct SList *list_node_at(struct SList *list, size_t idx)
{
    for (struct SList *cur = list; cur != NULL; cur = cur->next)
    {
        if (0 == idx)
        {
            return cur;
        }
        idx--;
    }
    return NULL;
}

struct SValidInt64 list_at(struct SList *list, size_t idx)
{
    if (!list)
        return none_int64;
    
    struct SList *list_node = list_node_at(list, idx);
    if (NULL != list_node)
    {
        return some_int64(list_node->value);
    }
    return none_int64;
}

struct SList *list_reverse(const struct SList *list)
{
    if (!list) 
        return NULL;

    struct SList *reversed_list = NULL;
    for (const struct SList *cur = list; cur != NULL; cur = cur->next)
    {
        list_add_front(&reversed_list, cur->value);
    }
    return reversed_list;
}

void list_print(const struct SList *l)
{
    if (NULL == l)
    {
        printf("List is empty\n");
        return;
    }
    while (NULL != l)
    {
        print_int64(l->value);
        l = l->next;
    }
    print_newline();
}
