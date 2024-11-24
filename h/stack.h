#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include <stdio.h>

#include "io.h"
#include "valid_int.h"
#include "array_int.h"

struct SStack {
  size_t count;
  struct SArrayInt data;
};


struct SStack stack_create( size_t size );
void stack_destroy( struct SStack* s );
bool stack_full( struct SStack s);
bool stack_empty( struct SStack s);

bool stack_push( struct SStack* s, int64_t value );
struct SValidInt64 stack_pop( struct SStack* s );
void stack_print( struct SStack s );


#endif
