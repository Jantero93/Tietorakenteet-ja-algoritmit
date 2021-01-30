//#if 0
#include <iostream>
#include "stack.h"
#include "functions.h"
#include <string>
#include <string.h>
#include "testit.h"

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char **argv)
{ 	
	Stack stored_numbers;

	if (argc == 1) {
		instructions();
		while (do_command(get_command(), stored_numbers));
		return 0;
	}	
	else if (argc > 1 && strcmp(argv[1], "-p") == 0) {

		while (true) {
			if (teht5(stored_numbers)) {
				double answer = 0;
				stored_numbers.top(answer);
				
				cout << "answer: " << answer;
				while (!stored_numbers.empty())
					stored_numbers.pop();
			}
			else {
				cout << "Cant calculate, Stack is empty" << endl;
				while (!stored_numbers.empty())
					stored_numbers.pop();
			}
			cout << endl;
		}
	}
	else {
		cout << "Invalid arguments";
		return 1;
	}
	
	system("pause");
}
