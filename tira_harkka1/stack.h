#pragma once

#include "utility.h"
// Section 2.2:

typedef double Stack_entry;  //  The program will use stacks with int entries.

const int maxstack = 1024;   //  small value for testing

class Stack {
public:
   Stack();
   bool empty() const;
   Error_code pop();
   Error_code top(Stack_entry &item) const;
   Error_code push(const Stack_entry &item);
   void print();

   friend Error_code copy_stack_c(Stack &dest, const Stack &source);
private:
   int count;
   Stack_entry entry[maxstack];
};
