#include "stack.h"
#include "utility.h"

Error_code copy_stack_a(Stack &dest, const Stack &source)
	/* Pre: None.
	Post: Stack dest has become an exact copy of Stack source; source is unchanged. If an error is
	detected, an appropriate code is returned; otherwise, a code of success is returned. */
{
	dest = source;
	return success;
}

Error_code copy_stack_b(Stack &dest,  Stack &source)
	/* Pre: None.
	Post: Stack dest has become an exact copy of Stack source; source is unchanged. If an error is
	detected, an appropriate code is returned; otherwise, a code of success is returned. */
{
	Error_code detected = success;
	Stack temp;
	Stack_entry item;
	while (detected == success && !source.empty( )) {
		detected = source.top(item);
		detected = source.pop( );
		if (detected == success) detected = temp.push(item);
	}
	while (detected == success && !temp.empty( )) {
		detected = temp.top(item);
		detected = temp.pop( );
		if (detected == success) detected = source.push(item);
		if (detected == success) detected = dest.push(item);
	}
	return detected;
}

Error_code copy_stack_c(Stack &dest, const Stack &source)
	/* Pre: None.
	Post: Stack dest has become an exact copy of Stack source; source is unchanged. If an error is
	detected, an appropriate code is returned; otherwise, a code of success is returned. */
{
	dest.count = source.count;
	for (int i = 0; i < source.count; i++)
		dest.entry[i] = source.entry[i];
	return success;
}

bool full(Stack &s)
	/* Pre: None
	Post: Leaves the Stack s unchanged. Returns a value of true or false according to whether the
	Stack s is or is not full */
{
	Stack_entry test;
	Error_code outcome;
	outcome = s.push(test);
	if (outcome == success) {
		s.pop( );
		return false;
	}
	return true;
}

Error_code pop_top(Stack &s, Stack_entry &t)
	/* Pre: None
	Post: The top entry from the Stack s is removed and returned as value of the output parameter
	t. */
{
	if (s.empty( )) return underflow;
	s.top(t);
	s.pop( );
	return success;
}

void clear(Stack &s)
	/* Pre: None
	Post: Deletes all entries and returns s as an empty Stack. */
{
	while (!s.empty( ))
		s.pop( );
	return;
}

int size(Stack &s)
	/* Pre: None
	Post: The Stack s is unchanged. A count of the number of entries in Stack s is returned. */
{
	int count = 0;
	Stack temp;
	Stack_entry item;
	while (!s.empty( )) {
		s.top(item);
		s.pop( );
		temp.push(item);
		count++;
	}
	while (!temp.empty( )) {
		temp.top(item);
		temp.pop( );
		s.push(item);
	}
	return count;
}

void delete_all(Stack &s, Stack_entry x)
	/* Pre: None
	Post: All occurrences (if any) of x are removed from s the remaining entries in s remain in the
	same relative order. */
{
	Stack temp;
	Stack_entry item;
	while (!s.empty( )) {
		s.top(item);
		s.pop( );
		if (item != x) temp.push(item);
	}
	while (!temp.empty( )) {
		temp.top(item);
		temp.pop( );
		s.push(item);
	}
	return;
}
