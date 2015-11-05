// Originally written by Luke Simmons and Megan Sword
// Edited by Alfred Ledgin
// 11/4/2015
// CS 303
// Project 2
//testing this out
#include "Evaluator.h"
using namespace std;


Evaluator::Evaluator() {
	eqString = "";
}


Evaluator::Evaluator(string line) {
	eqString = line;
}
/*
bool Evaluator::test(string equation)
{
	if (equation[0] == ')')				//checks if equation starts with closing parenthesis
		throw std::invalid_argument("Expressions can't start with a closing parenthsesis at char: 0");

	if (!isdigit(equation[0]))			//checks if equation starts with a binary operator
	{
		if (!isdigit(equation[1]))
		{
			string temp;
			temp += equation[0];
			temp += equation[1];
			Operator tempOp("-");
			try
			{
				tempOp = Operator(temp);
			}
			catch (exception)
			{
				temp = equation[0];
				tempOp = Operator(temp);
			}
			if (tempOp.hasCategory() == 'b')
				throw std::invalid_argument("Expressions can't start with binary operators at char: 0");
		}
		else
		{
			string temp;
			temp += equation[0];
			Operator tempOp = Operator(temp);
			if (tempOp.hasCategory() == 'b')
				throw std::invalid_argument("Expressions can't start with binary operators at char: 0");
		}
	}

	int oParen = 0, cParen = 0;				//checks to make sure parenthesis are balanced
	for (int i = 0; i < equation.size(); i++)
	{
		if (equation[i] == '(')
			++oParen;
		if (equation[i] == ')')
			++cParen;
	}
	if (oParen != cParen)
		throw std::invalid_argument("Expression must have balanced parenthesis.");

	bool openParen = false;					//checks to make sure no closing parenthesis come before an opening parenthesis
	for (int i = 0; i < equation.size(); i++)
	{
		if (equation[i] == '(')
			openParen = true;
		if ((equation[i] == ')' && openParen == false))
		{
			string error = "Expression cannot have a closing parenthesis before an opening parenthesis at char: " + i;
			throw std::invalid_argument(error);
		}
	}

	for (int i = 0; i < equation.size(); i++)			//checks to make sure there are no divide by zero operations
	{
		if (equation[i] == '/')
		{
			if (equation[i + 1] == '0')
			{
				string error = "Expression cannot contain division by zero at char: " + i;
				throw std::invalid_argument(error);
			}
		}
	}

	for (int i = 0; i < equation.size(); i++)				//checks to make sure there are no two binary operations in a row
	{
		if (!isdigit(equation[i]))
		{
			if (!isdigit(equation[i + 1]))
			{
				string temp;
				temp += equation[i];
				temp += equation[i + 1];
				Operator tempOp("-");
				try
				{
					tempOp = Operator(temp);
				}
				catch (exception)
				{
					temp = equation[i];
					tempOp = Operator(temp);
				}
				if (tempOp.hasCategory() == 'b')
				{
					if (tempOp.hasType().length() == 1)
					{
						if (!isdigit(equation[i + 1]))
						{
							if (!isdigit(equation[i + 2]))
							{
								string temp2;
								temp2 += equation[i + 1];
								temp2 += equation[i + 2];
								Operator tempOp2 = Operator(temp2);
								if (tempOp2.hasCategory() == 'b')
								{
									string error = "Expression cannot contain two binary operators in a row at char: " + (i + 1);
									throw std::invalid_argument(error);
								}
							}
							else
							{
								string temp2;
								temp2 += equation[i + 1];
								Operator tempOp2 = Operator(temp2);
								if (tempOp2.hasCategory() == 'b')
								{
									string error = "Expression cannot contain two binary operators in a row at char: " + (i + 1);
									throw std::invalid_argument(error);
								}
							}
						}
					}
					else
					{
						if (!isdigit(equation[i + 2]))
						{
							if (!isdigit(equation[i + 3]))
							{
								string temp2;
								temp2 += equation[i + 2];
								temp2 += equation[i + 3];
								Operator tempOp2 = Operator(temp2);
								//if (tempOp2.hasCategory() == 'b')
								//{
									//string error = "Expression cannot contain two binary operators in a row at char: " + (i + 2);
									//throw std::invalid_argument(error);
								//}
							}
							else
							{
								string temp2;
								temp2 += equation[i + 2];
								Operator tempOp2 = Operator(temp2);
								if (tempOp2.hasCategory() == 'b')
								{
									string error = "Expression cannot contain two binary operators in a row at char: " + (i + 2);
									throw std::invalid_argument(error);
								}
							}
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < equation.size() - 2; i++)
	{
		if (isdigit(equation[i]))
			if (equation[i + 1] == ' ')
				if (isdigit(equation[i + 2]))
				{
					string error = "Expression cannot have two operands in a row at char: " + (i + 2);
					throw std::invalid_argument(error);
				}
	}

	for (int i = 0; i < equation.size(); i++)				//checks to make sure there are no unary operators followed by a binary operator
	{
		if (!isdigit(equation[i]))
		{
			if (!isdigit(equation[i + 1]))
			{
				string temp;
				try
				{
					temp += equation[i];
					temp += equation[i + 1];
				}
				catch (exception)
				{
					temp += equation[i];
				}
				Operator tempOp = Operator("temp");
				if (tempOp.hasCategory() == 'u')
				{
					if (tempOp.hasType().length() == 1)
					{
						if (!isdigit(equation[i + 1]))
						{
							if (!isdigit(equation[i + 2]))
							{
								string temp2;
								temp2 += equation[i + 1];
								temp2 += equation[i + 2];
								Operator tempOp2 = Operator(temp2);
								if (tempOp2.hasCategory() == 'b')
								{
									string error = "Expression cannot contain a unary followed by a binary: " + (i + 1);
									throw std::invalid_argument(error);
								}
							}
							else
							{
								string temp2;
								temp2 += equation[i + 1];
								Operator tempOp2 = Operator(temp2);
								if (tempOp2.hasCategory() == 'b')
								{
									string error = "Expression cannot contain a unary followed by a binary : " + (i + 1);
									throw invalid_argument(error);
								}
							}
						}
					}
					else
					{
						if (!isdigit(equation[i + 2]))
						{
							if (!isdigit(equation[i + 3]))
							{
								string temp2;
								temp2 += equation[i + 2];
								temp2 += equation[i + 3];
								Operator tempOp2 = Operator("temp2");
								if (tempOp2.hasCategory() == 'u')
								{
									string error = "Expression cannot contain two binary operators in a row at char: " + (i + 2);
									throw std::invalid_argument(error);
								}
							}
							else
							{
								string temp2;
								temp2 += equation[i + 2];
								Operator tempOp2 = Operator("temp2");
								if (tempOp2.hasCategory() == 'b')
								{
									string error = "Expression cannot contain two binary operators in a row at char: " + (i + 2);
									throw std::invalid_argument(error);
								}
							}
						}
					}
				}
			}
		}
	}
}
*/

double Evaluator::evaluate(string equation) {

	//test(equation);
	bool hitNumber = false;
	bool hitOperator = false;
	stack<Operator> opStack;
	stack<double> numbers;
	int index = 0;

	while (index < equation.size()) {

		if (equation[index] == ' ') {
			index++;
		}

		else if (equation[index] == '(') { //If the item is an '(', evaluate the substring.
			int subIdx = index;
			int parens = 1;
			while (parens > 0)
			{
				subIdx++; // Need error protection.
				if (equation[subIdx] == '(')
					parens++;
				if (equation[subIdx] == ')')
					parens--;
			}
			string substring = equation.substr(index + 1, subIdx - (index + 1));
			// Reference (for using substr function):
			// "std::string::substr." _cplusplus.com_. cplusplus.com, 2015.
			// Web. 4 Nov. 2015.
			// <http://www.cplusplus.com/reference/string/string/substr/>.
			numbers.push(evaluate(substring));
			index = subIdx;
			index++;
		}

		else if (isdigit(equation[index])) { // If the item is a digit, build the number until the item is no longer a digit.
			if (hitOperator == false && !numbers.empty()) {
				string error = "Expression cannot have two operands in a row at char: " + index;
				throw std::invalid_argument(error);
			}
			hitNumber = true;
			double newOperand = 0;
			string newOperandString;
			while (isdigit(equation[index])) {
				newOperandString += equation[index];
				index++;
			}
			hitOperator = false;
			numbers.push(stoi(newOperandString));
		}

		else { // The item must be an operator.
			hitOperator = true;
			string temp;
			temp += equation[index];
			if (index == 0 && temp == "-")
			{
				if (equation.length() > 1 && equation[1] != '-')
					// If the first operator is a -, then it is the negation operator.
					temp += "#";
			}
			else if (equation.length() > index + 1)
			{
				if (temp == "-" && !isdigit(equation[index - 1]) && equation[index + 1] != '-')
					// If the operator is a -, and the preceding character is not a digit,
					// then the operator is the negation operator.
					temp += "#";
			}
			index++;
			if (!isdigit(equation[index]) && equation[index] != '('
				&& equation[index] != ')' && equation[index] != '!') { // Check whether the operator contains 2 characters.
				if (equation[index - 1] == equation[index] || equation[index - 1] == '!'
					|| equation[index - 1] == '<' || equation[index - 1] == '>') // Check for valid two-char operator.
				{
					if (temp.length() == 1) // Cannot have operator with more than 2 characters.
					{
						if (equation[index - 1] != '-')
						{
							temp += equation[index];
							index++;
						}
						else // -- is decrement operator only in special cases.
						{
							if (index >= 2)
							{
								if (!isdigit(equation[index - 2]))
								{

									{
										temp += equation[index];
										index++;
									}
								}
							}
							else
							{
								temp += equation[index];
								index++;
							}
						}
					}
				}
			}
			Operator tempO = Operator(temp);
			if (opStack.empty()) {
				if (hitNumber == false && tempO.hasCategory() == 'b' && numbers.empty()) {
					string message = "cannot start expression with binary operator @ "+ index;
					throw invalid_argument(message);
				}
				else if (hitNumber == false && temp == ")" && numbers.empty()) {
					string message = "cannot start expression with closing parenthesis @ " + index;
					throw invalid_argument(message);
				}
				opStack.push(tempO);
				hitNumber = false;
			}
			else if (tempO < opStack.top()) {
				while (!opStack.empty() && tempO < opStack.top()) {
					if (opStack.top().hasCategory() == 'u') {
						double tempNum1 = numbers.top();
						numbers.pop();
						numbers.push(opStack.top().execute(tempNum1));
						opStack.pop();
					}
					else if (opStack.top().hasCategory() == 'b') {
						double tempNum1 = numbers.top();
						numbers.pop();
						double tempNum2 = numbers.top();
						numbers.pop();
						numbers.push(opStack.top().execute(tempNum2, tempNum1));
						opStack.pop();
					}
				}
				opStack.push(tempO);
			}
			else {
				if (!opStack.empty()) {
					if (tempO.hasCategory() == 'b' && opStack.top().hasCategory() == 'b' && hitNumber == false) {
						string message = "cannot have two binary operators in a row @ " + index;
						throw invalid_argument(message);
					}
					else if (tempO.hasCategory() == 'u' && opStack.top().hasCategory() == 'b' && hitNumber == false) {
						string message = "cannot have a unary operator followed by a binary operator @ " + index;
						throw invalid_argument(message);
					}
				}
				opStack.push(tempO);
				hitNumber = false;
			}
		}

	}

	while (index = equation.size() && !opStack.empty()) { // After all of the numbers are read, we need to finish evaluating.
		if (opStack.top().hasCategory() == 'u') {
			double tempNum1 = numbers.top();
			numbers.pop();
			numbers.push(opStack.top().execute(tempNum1));
			opStack.pop();
		}
		if (opStack.empty())
			break;
		if (opStack.top().hasCategory() == 'b') {
			double tempNum1 = numbers.top();
			numbers.pop();
			double tempNum2 = numbers.top();
			numbers.pop();
			numbers.push(opStack.top().execute(tempNum2, tempNum1));
			opStack.pop();
		}
	}

	return numbers.top();

}
