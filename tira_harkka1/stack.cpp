#include "stack.h"


Error_code Stack::push(const Stack_entry &item)
/*
Pre:  None.
Post: If the Stack is not full, item is added to the top
of the Stack.  If the Stack is full,
an Error_code of overflow is returned and the Stack is left unchanged.
*/

{
	Error_code outcome = success;
	if (count >= maxstack)
		outcome = overflow;
	else
		entry[count++] = item;
	return outcome;
}


Error_code Stack::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
the Stack is removed.  If the Stack
is empty, an Error_code of underflow is returned.
*/

{
	Error_code outcome = success;
	if (count == 0)
		outcome = underflow;
	else --count;
	return outcome;
}


Error_code Stack::top(Stack_entry &item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
the Stack is returned in item.  If the Stack
is empty an Error_code of underflow is returned.
*/

{
	Error_code outcome = success;
	if (count == 0)
		outcome = underflow;
	else
		item = entry[count - 1];
	return outcome;
}


bool Stack::empty() const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
Otherwise false is returned.
*/

{
	bool outcome = true;
	if (count > 0) outcome = false;
	return outcome;
}


Stack::Stack()
/*
Pre:  None.
Post: The stack is initialized to be empty.
*/
{
	count = 0;
}

void Stack::print()
{
	/*
	bool first_time = true;

	cout << title_p << endl;
	for ( int i = 0; i < ( int )( strlen( title_p ) ); i++ )
		cout << "=";
	cout << endl << endl;

	if ( false == this->empty() ) {
		for ( int i = this->count - 1; i >= 0; i-- ) {
			cout << this->entry[ i ];

			if ( true == first_time && this->count > 0 )
				cout << " <--- top" << endl;
			else
				cout << endl;

			first_time = false;
		}

		cout << "--" << endl << endl << endl;
	}
	else
		cout << "Stack is empty." << endl << endl << endl
;

*/

	for (int i = 0; i < count; i++) {
		cout << entry[i] << " ";
	}
	if (count == 0) {
		cout << "Stack is empty" << endl; 
	}
	else {
		cout << "Last one is top of stack" << endl;
	}
	return;
}

