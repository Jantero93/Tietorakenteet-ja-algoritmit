#pragma once
#include "stack.h"
#include "Utility.h" 

char get_command();
bool do_command(char, Stack&);
void instructions();
bool promptOnly(int, char **, Stack&);
bool teht5(Stack&);

Error_code calcAverage(Stack &);
Error_code calcAddition(Stack &);
Error_code calcMultiply(Stack &);
Error_code calcDivision(Stack &);
Error_code calcSubtraction(Stack &);
Error_code calcTotalSum(Stack &);
Error_code calcPower(Stack &);
Error_code exchangeNumbers(Stack &);
Error_code calcRoot(Stack &);
Error_code calcModulos(Stack &);