#ifndef _LIST_H_
#define _LIST_H_

#include <stdint.h>
#include <stddef.h>
#include <malloc.h>

#include "valid_int.h"
#include "io.h"

struct SList {
  int64_t value;
  struct SList* next;
};

struct SList* node_create( int64_t value );

void list_destroy( struct SList* list );
void list_add_front( struct SList** old, int64_t value );

struct SList* list_last( struct SList * list );

void list_add_back( struct SList** old, int64_t value );

size_t list_length( struct SList const* list );

struct SList* list_node_at( struct SList* list, size_t idx );
struct SValidInt64 list_at(struct SList* list, size_t idx);

struct SList* list_reverse( const struct SList* list );

void list_print(const struct SList* l);

#endif
