#pragma once

#include "stack.h"
#include "utility.h"

Error_code copy_stack_a(Stack &dest, const Stack &source);
Error_code copy_stack_b(Stack &dest,  Stack &source);
Error_code copy_stack_c(Stack &dest,  const Stack &source);
bool full(Stack &s);
Error_code pop_top(Stack &s, Stack_entry &t);
void clear(Stack &s);
int size(Stack &s);
void delete_all(Stack &s, Stack_entry x);

