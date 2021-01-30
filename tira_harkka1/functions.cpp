#include "functions.h"
#include <iostream>
#include <math.h>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::atof;
using std::string;
using std::getline;
using std::vector;

char get_command()
{
	char command;
	bool waiting = true;
	cout << "Select command and press <Enter>: ";

	while (waiting) {
		cin >> command;
		command = tolower(command);

		if (command == '?' || command == '=' || command == '+' || command == 'x' ||
			command == '-' || command == '*' || command == '/' || command == 'q' ||
			command == 's' || command == 'a' || command == '^' || command == 'v' ||
			command == 'p' || command == '@' || command == '%') {
			waiting = false;
		}
		else {
			cout << "Enter a command: " << endl;
			cout << "[?] push to stack, [=]print top, [x]exchange changes order of top two items" << endl;
			cout << "[@] prints whole content of stack" << endl;
			cout << "[s] sums all numbers in stack" << endl;
			cout << "[a] deletes other entrys and put only avarage of numbers on top element" << endl;
			cout << "[v] print squareroot of last number, [p] power" << endl;
			cout << "[+][-][*][/] are arithmetic operations" << endl;
			cout << "[%] is modulos" << endl;
			cout << "[Q]uit" << endl;
		}
	}
	return command;
}

bool do_command(char command, Stack &numbers)
{

	/*Pre:	The first parameter speci es a valid calculator command.
	 Post:  The command speci ed by the  rst parameter has been applied to theStackof numbers given by the second parameter.
	 A result of true is returned unless command =='q'.
	 Uses:	The classStack.*/
	Error_code state;
	double p, q;
	switch (command) {

	case '?':
		cout << "enter a real number: " << flush;
		cin >> p;

		if (numbers.push(p) == overflow) {
			cout << "Warning: Stackk full, lost number" << endl;
		}
		break;

	case '@':
		numbers.print();
		break;

	case 'v':
		state = calcRoot(numbers);
		if (state != success) {
			cout << "Calculating root went wrong!" << endl;
		}

		break;

	case '=':
		state = success;
		if (numbers.top(p) == underflow) {
			cout << "Stack empty" << endl;
		}
		else {
			cout << p << endl;
		}
		if (state != success) {
			cout << "Viewing top element went something wrong!" << endl;
		}
		break;

	case 's':
		state = calcTotalSum(numbers);
		if (state != success) {
			cout << "Calculating Total sum went wrong!" << endl;
		}

		break;

	case 'a':
		state = calcAverage(numbers);
		if (state != success) {
			cout << "Calculating average went wrong!" << endl;
		}

		break;

	case '+':
		state = calcAddition(numbers);
		if (state != success) {
			cout << "Calulating addioton went wrong!" << endl;
		}

		break;

	case '*':
		state = calcMultiply(numbers);
		if (state != success) {
			cout << "Calculating multiply went wrong!" << endl;
		}

		break;

	case '/':
		state = calcDivision(numbers);
		if (state != success) {
			cout << "Calculating division went wrong!" << endl;
		}

		break;

	case '-':
		state = calcSubtraction(numbers);
		if (state != success) {
			cout << "Calculating substraction went wrong!" << endl;
		}
		break;

	case 'p':

		state = calcPower(numbers);
		if (state != success) {
			cout << "Calulating power went wrong!" << endl;
		}

		break;

	case '%':
		state = calcModulos(numbers);
		if (state != success) {
			cout << "Modulos went wrong!" << endl;
		}
		break;

	case 'x':
		state = exchangeNumbers(numbers);
		if (state != success) {
			cout << "Exchanging numbers went wrong!" << endl;
		}
		break;

	case 'q':
		cout << "Calculation finished, goodbye!" << endl;
		return false;
	}
	return true;
}

void instructions()
{
	cout << "[?]push to stack, [=]print top, [x]exchanges order of top two elements" << endl;
	cout << "[a] deletes other entrys and put only avarage of numbers on top element" << endl;
	cout << "[+][-][*][/] are arithmetic operations" << endl;
	cout << "[s]sums all numbers in stack" << endl;
	cout << "[@] shows all content in stack" << endl;
	cout << "[v]print squareroot of last number, [p] power" << endl;
	cout << "[%]is modulos" << endl;
	cout << "[Q]uit" << endl;
}




Error_code calcAverage(Stack &numbers) {
	double tempA;
	
	if (numbers.top(tempA) == underflow) {
		cout << "Stack empty" << endl;
		return underflow;
	}
	else {
		int i = 0;
		double totalSum = 0;
		double temp;

		while (!numbers.empty()) {
			numbers.top(temp);
			totalSum += temp;
			numbers.pop();
			i++;
		}

		numbers.push(totalSum / (double)i);
	}
	return success;
}

Error_code calcAddition(Stack &numbers) {
	double tempA, tempB;
	
	if (numbers.top(tempA) == underflow) {
		cout << "Stack empty" << endl;
		return underflow;
	}
	else {
		// pop tempA, check is there more numbers
		numbers.pop();
		if (numbers.top(tempB) == underflow) {
			cout << "Stack has just one entry" << endl;
			numbers.push(tempA);
			return underflow;
		}
		else {
			numbers.pop();
			if (numbers.push(tempB + tempA) == overflow) {
				cout << "Warning: Stack full, lost result" << endl;
				return overflow;
			}
		}
	}

	return success;
}

Error_code calcMultiply(Stack &numbers) {
	double tempA, tempB;
	
	if (numbers.top(tempB) == underflow) {
		cout << "Stack empty" << endl;
		return underflow;
	}
	else {
		// pop first number, check is there more numbers
		numbers.pop();
		if (numbers.top(tempA) == underflow) {
			cout << "Stack has just one entry" << endl;
			numbers.push(tempB);
			return underflow;
		}
		else {			
			numbers.pop();
			if (numbers.push(tempA*tempB) == overflow) {
				cout << "Warning: Stack full, lost result" << endl;
				return overflow;
			}
			
		}
	}

	return success;
}

Error_code calcDivision(Stack &numbers) {
	double tempA, tempB;

	if (numbers.top(tempB) == underflow) {
		cout << "Stack empty" << endl;
		return underflow;
	}
	else {
		// pop first number, check is there more numbers
		numbers.pop();
		if (numbers.top(tempA) == underflow) {
			numbers.push(tempB);
			return underflow;
		}
		else {
			numbers.pop();			
			if (numbers.push(tempA / tempB) == overflow) {
				cout << "Warning stack, lost result" << endl;
				return overflow;
			}
		}
	}

	return success;
}

Error_code calcSubtraction(Stack &numbers) {
	double tempA, tempB;

	if (numbers.top(tempA) == underflow) {
		cout << "Stack empty" << endl;
		return underflow;
	}
	else {
		numbers.pop();
		if (numbers.top(tempB) == underflow) {
			cout << "Stack has just one entry" << endl;
			numbers.push(tempA);
			return underflow;
		}
		else {
			numbers.pop();
			if (numbers.push(tempB - tempA) == overflow) {
				cout << "Warning: Stack full, lost result" << endl;
				return overflow;
			}
		}
	}

	return success;
}

Error_code calcTotalSum(Stack &numbers) {
	double tempA, tempB, tempDouble;
	double totalSum = 0;

	if (numbers.top(tempB) == underflow) {
		cout << "Stack empty" << endl;
		return underflow;
	}
	else {
		if (numbers.top(tempA) == underflow) {
			cout << "Stack has just one entry" << endl;
			numbers.push(tempB);
			return underflow;
		}
		else {
			while (!numbers.empty()) {
				numbers.top(tempDouble);
				totalSum += tempDouble;
				numbers.pop();
			}

			numbers.push(totalSum);
		}
	}

	return success;
}

Error_code calcPower(Stack &numbers) {
	double tempX, tempY;

	if (numbers.top(tempY) == underflow) {
		cout << "Stack empty" << endl;
		return underflow;
	}
	else {
		numbers.pop();
		if (numbers.top(tempX) == underflow) {
			cout << "Stack has just one entry" << endl;
			numbers.push(tempY);
			return underflow;
		}
		else {
			numbers.pop();
			numbers.push(pow(tempX, tempY));
		}

	}

	return success;
}

Error_code exchangeNumbers(Stack &numbers) {
	double tempA, tempA;

	if (numbers.top(tempA) == underflow) {
		cout << "Stack empty" << endl;
		return underflow;
	}
	else {
		numbers.pop();
		if (numbers.top(tempA) == underflow) {
			cout << "Stack has just one entry" << endl;
			numbers.push(tempA);
			return underflow;
		}
		else {
			numbers.pop();
			if (numbers.push(tempA) == overflow || numbers.push(tempA) == overflow) {
				cout << "Warning: Stack full, lost result" << endl;
				return overflow;
			}
		}
	}

	return success;
}

Error_code calcModulos(Stack &numbers) {
	double tempA, tempB;

	if (numbers.top(tempB) == underflow) {
		cout << "Stack empty" << endl;
		return underflow;
	}
	else {
		numbers.pop();
		if (numbers.top(tempA) == underflow) {
			cout << "Stack has just one entry" << endl;
			numbers.push(tempB);
			return underflow;
		}
		else {
			numbers.pop();
			if (numbers.push((int)tempA % (int)tempB) == overflow) {
				cout << "Warning stack full" << endl;
				return overflow;
			}
		}
	}

	return success;
}

Error_code calcRoot(Stack &numbers) {
	double temp;

	if (numbers.top(temp) == underflow) {
		cout << "Stack empty" << endl;
		return underflow;
	}
	else {
		numbers.pop();
		temp = sqrt(temp);
		numbers.push(temp);
	}

	return success;
}

bool promptOnly(int argc, char **argv, Stack &numbers)
{
	double number;
	Error_code state = success;
	string command;


	for (int i = 2; i < argc; i++) {
		command = argv[i];

		if (isdigit(command[0])) {
			number = stod(command);
			numbers.push(number);
		}
		else {
			string argument = argv[i];
			char operation = argument[0];

			switch (operation) {


			case '@':
				numbers.print();
				break;

			case 'v':
				state = calcRoot(numbers);
				break;

			case '%':
				state = calcModulos(numbers);
				break;

			case 's':
				state = calcTotalSum(numbers);
				break;

			case 'a':
				state = calcAverage(numbers);
				break;

			case '+':
				state = calcAddition(numbers);
				break;

			case '*':
				state = calcMultiply(numbers);
				break;

			case '/':
				state = calcDivision(numbers);
				break;

			case '-':
				state = calcSubtraction(numbers);
				break;

			case 'p':
				state = calcPower(numbers);
				break;

			case 'x':
				state = exchangeNumbers(numbers);
				break;
			}

		}

	}

	if (state != success) {
		return false;
	}
	else {
		return true;
	}

}

bool teht5(Stack &numbers) {
	vector<string> inputs;
	string command;
	const string delimiter = " ";
	size_t pos = 0;
	string token;
	Error_code state = success;

	getline(cin, command);

	while ((pos = command.find(delimiter)) != std::string::npos) {
		token = command.substr(0, pos);
		inputs.push_back(token);

		command.erase(0, pos + delimiter.length());
		if (command.length() == 1) {
			inputs.push_back(command);
			break;
		}
	}
	

	if (inputs.size() <= 1) {
		state = underflow;
	}
	for (unsigned int i = 0; i < inputs.size(); i++) {
		command = inputs.at(i);

		bool has_only_digits = (command.find_first_not_of("0123456789.") == std::string::npos);
		if (has_only_digits) {
			double number = stod(command);
			numbers.push(number);
		}
		else {			
			char operation = command[0];

			switch (operation) {


			case '@':
				numbers.print();
				break;

			case 'v':
				state = calcRoot(numbers);
				break;

			case '%':
				state = calcModulos(numbers);
				break;

			case 's':
				state = calcTotalSum(numbers);
				break;

			case 'a':
				state = calcAverage(numbers);
				break;

			case '+':
				state = calcAddition(numbers);
				break;

			case '*':
				state = calcMultiply(numbers);
				break;

			case '/':
				state = calcDivision(numbers);
				break;

			case '-':
				state = calcSubtraction(numbers);
				break;

			case 'p':
				state = calcPower(numbers);
				break;

			case 'x':
				state = exchangeNumbers(numbers);
				break;

			default :
				cout << "Wrong operator" << endl;
				return false;
			}
		}
	}

	if (state == success) {
		return true;
	}
	else {
		inputs.clear();
		return false;		
	}
}
