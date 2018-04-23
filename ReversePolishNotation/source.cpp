
#include "stdafx.h"
#include <iostream>
#include <stdlib.h> //atof
#include <math.h> // floor
#include "Stack.h"

int MaxLength = 100;

//check if character is number
bool isNum(char c)
{
	return (c >= '0' && c <= '9');
}

//check if character is operation
bool isOperation(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

//length of char*
int strlen(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

double calculate(char *str)
{
	Stack numbers;

	if (strlen(str) > MaxLength)
	{
		std::cout << "Invalid expression! The entered string is too long." << std::endl;
		return -1;//error
	}
	else
	{
		//initializing the variables
		double num = 0;// the number read from the user's input
		char *charNum=new char[strlen(str)];//dynamic char array 
		int counterCharNum = 0;//the index of the char array
		double result = 0;//the result of calculations wich is being pushed in the stack

		for (int i = 0; i < strlen(str); i++)
		{
			//if current char is a digit, a decimal separator or a sign - (for negative real numbers)
			if (isNum(str[i]) || str[i] == '.' || (str[i]=='-' && isNum(str[i+1])))
			{
				charNum[counterCharNum] = str[i];
				counterCharNum++;
			}

			else if (isNum(str[i - 1]) && str[i]==' ')//if previous character is number and current is not number
			{
				num = atof(charNum);//parses char to double
				numbers.push(num);//push the number from type double in the stack
				num = 0;
				delete [] charNum;
				charNum = new char[strlen(str)];
				counterCharNum = 0;
			}

			// if afetr + or - does not follow a number but a space:
			else if (isOperation(str[i]) && !isNum(str[i+1]))
			{
				if (numbers.size() >= 2)
				{
					//popping last 2 numbers
					double b = numbers.pop();//the second number in operation is popped first
					double a = numbers.pop();//the first number in operation is popped second
					switch (str[i])
					{
					//cases are about all the operations in the expression
					case '+':
						result = a + b;
						break;
					case '-':
						result = a - b;
						break;
					case '*':
						result = a * b;
						break;
					case '/':
						result = a / b;
						break;
					case '%':
						//floor-rounds a and b downward to whole numbers
						//if a and be are whole numbers, this condition returns true
						if (a ==floor(a) && b ==floor(b))
						{
							result = (int)a % (int)b;
						}
						break;
					}
					numbers.push(result);//pushing the result from the operation
				}

				else
				{
					std::cout << "Invalid expression! Too few numbers." << std::endl;
					return -1;//error
				}
			}
		}

		if (numbers.isEmpty())
		{
			std::cout << "Invalid expression! Too few numbers." << std::endl;
			return -1;//error
		}
		else if (numbers.size() > 1)
		{
			std::cout << "Invalid expression! Too many numbers." << std::endl;
			return -1;//error
		}

		else
		{
			return numbers.pop();//popping the only number in the stack
		}

		delete[] charNum;//dleting the dynamic char array
	}
}


int main()
{
	char yourStr[100];
	std::cout << "Enter your exoression:";
	std::cin.getline(yourStr, 100);
	std::cout<< "Your calculated expression:"<<calculate(yourStr)<<std::endl;

	std::cout << "-------------------------" << std::endl;

	std::cout << "Click enter to other tests:" << std::endl;
	std::cin.clear();
	std::cin.ignore();

	//0. expression with %

	char zeroStr[20] = "30.0 8.43 4.57 + %";

	std::cout << "Calculated notation 0:" << calculate(zeroStr) << std::endl;

	std::cout << "-------------------------" << std::endl;

	//1. normal expression with no exceptions 
	char firstStr[20] = "5 1 2 + 4 * + 3 - ";
	std::cout << "Calculated notation 1:"<<calculate(firstStr)<<std::endl;

	std::cout << "-------------------------"<<std::endl;
	
	//2. expression with number >9
	char secondStr[20] = "105 2 3 + - ";
	std::cout << "Calculated notation 2:" << calculate(secondStr) << std::endl;

	std::cout << "-------------------------" << std::endl;

	//3. expression with real numbers >0
	char thirdStr[20] = "3.5 2.1 3.3 + - ";
	std::cout << "Calculated notation 3:" << calculate(thirdStr) << std::endl;

	std::cout << "-------------------------" << std::endl;

	//4. expression with real numbers >10
	char fourthStr[30] = "300.5 22.7 30.3 + + ";
	std::cout << "Calculated notation 4:" << calculate(fourthStr) << std::endl;

	std::cout << "-------------------------" << std::endl;

	//5. expression with real numbers
	char fifthStr[30] = "-3.567 -22.7 30.3 + - ";
	std::cout << "Calculated notation 5:" << calculate(fifthStr) << std::endl;

	std::cout << "-------------------------" << std::endl;

	//6. expression with length > MaxLength(=100)
	char sixthStr[150] = "123 456 + 7890 - 456 + 7890 - 456 + 7890 - 456 + 7890 - 456 + 7890 - 456 + 7890 - 456 + 7890 - 456 + 7890 - ";
	std::cout << "Calculated notation 6:" << calculate(sixthStr) << std::endl;

	std::cout << "-------------------------" << std::endl;

	//7. expression with too few numbers
	char seventhStr[30] = "9.0 4.10234 * - 2.8 5.9 * - ";
	std::cout << "Calculated notation 7:" << calculate(seventhStr) << std::endl; 

	std::cout << "-------------------------" << std::endl;

	//8. expression with too many numbers
	char eighthStr[30] = "5 1 2 10 + 4 * + 3 - ";
	std::cout << "Calculated notation 8:" << calculate(eighthStr) << std::endl;

	std::cout << "-------------------------" << std::endl;

	//9.random string
	char ninthStr[30] = "I'm not a math expression.";
	std::cout << "Calculated notation 9:" << calculate(ninthStr) << std::endl;

    return 0;
}

