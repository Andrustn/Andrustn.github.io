#include "ExpressionManager.h"
#include<string>
#include<iomanip>
using namespace std;

int ExpressionManager::value(void) {
	stack<int> operandStack;
	int rightArgument;
	int leftArgument;
	int operatorResult;

	for (unsigned int i = 0; i < postFix.size(); i++) {
		if (isNumber(postFix.at(i))) {
			operandStack.push(stoi(postFix.at(i)));
		}
		else if (isOperator(postFix.at(i))) {
			if (operandStack.size() < 2) {
				throw "Missing Operand";
			}
			else {
				rightArgument = operandStack.top();
				operandStack.pop();
				leftArgument = operandStack.top();
				operandStack.pop();
				if (postFix.at(i) == "+") {
					operatorResult = leftArgument + rightArgument;
				}
				else if (postFix.at(i) == "-") {
					operatorResult = leftArgument - rightArgument;
				}
				else if (postFix.at(i) == "*") {
					operatorResult = leftArgument * rightArgument;
				}
				else if (postFix.at(i) == "/") {
					operatorResult = leftArgument / rightArgument;
				}
				else if (postFix.at(i) == "%") {
					operatorResult = leftArgument % rightArgument;
				}
				else {
				}
				operandStack.push(operatorResult);
			}
		}
	}
	return operandStack.top();
}

string ExpressionManager::infix(void) {
	stack<string> parenthesisStack;
	string parseExpression = userExpression + " ;"; // adding semi colon at end of expression to end loop

	while (parseExpression != ";") {
		string subString = parseExpression.substr(0, parseExpression.find(' '));
		if (isLeftParen(subString)) {
			parenthesisStack.push(subString);
		}
		else if (isRightParen(subString)) {
			if (parenthesisStack.empty()) {
				throw string("Unbalanced");
			}
			else {
				if (isPair(parenthesisStack.top(), subString)) {   //checking if parenthesis are balanced
					parenthesisStack.pop();
				}
				else {
					throw string("Unbalanced");
				}
			}
		}
		else {
		}
		parseExpression = parseExpression.substr(parseExpression.find(' ') + 1);
	}
	if (parenthesisStack.size() > 0) {
		throw string("Unbalanced");
	}
	stack<string> operatorStack;
	stack<string> operandStack;
	parseExpression = userExpression + " ;";

	while (parseExpression != ";") {
		string subString = parseExpression.substr(0, parseExpression.find(' '));
		inFix.push_back(subString);
		parseExpression = parseExpression.substr(parseExpression.find(' ') + 1);
	}
	if (isOperator(inFix.at(0))) {
		throw string("Missing Operand");
	}
	for (unsigned int i = 1; i < inFix.size(); i++) {
		if (isNumber(inFix.at(i - 1)) && isNumber(inFix.at(i))) {
			throw string("Missing Operator");
		}
		else if (isOperator(inFix.at(i - 1)) && isOperator(inFix.at(i))) {
			throw string("Missing Operand");
		}
	}
	parseExpression = userExpression + " ;";
	while (parseExpression != ";") {
		string subString = parseExpression.substr(0, parseExpression.find(' '));
		if (isNumber(subString)) {
			operandStack.push(subString);
		}
		else if (isOperator(subString)) {
			operatorStack.push(subString);
		}
		else if (VALID_CHARACTERS.find(subString) == string::npos) {
			throw string("Illegal Operator");
		}
		else {
		}
		parseExpression = parseExpression.substr(parseExpression.find(' ') + 1);
	}
	if (operandStack.size() - operatorStack.size() > 1) {
		throw string("Missing Operator");
	}
	else if (operandStack.size() - operatorStack.size() < 1) {
		throw string("Missing Operand");
	}
	else {
	}
	return userExpression;
}

string ExpressionManager::postfix(void) {
	if (inFix.size() == 0) {
		string parseExpression = userExpression + " ;";
		while (parseExpression != ";") {
			string subString = parseExpression.substr(0, parseExpression.find(' '));
			inFix.push_back(subString);
			parseExpression = parseExpression.substr(parseExpression.find(' ') + 1);
		}
	}
	stack<string> operatorStack;
	int currentValue;
	int compareValue;
	for (unsigned int i = 0; i < inFix.size(); i++) {
		currentValue = precedence(inFix.at(i));
		string currentString = inFix.at(i);
		if (isNumber(inFix.at(i))) {
			postFix.push_back(inFix.at(i));
		}
		else if (operatorStack.size() == 0 && (VALID_CHARACTERS.find(inFix.at(i)) != string::npos)) {
			operatorStack.push(inFix.at(i));
			compareValue = precedence(operatorStack.top());
		}
		else if (isLeftParen(inFix.at(i))) {
			operatorStack.push(inFix.at(i));
			compareValue = precedence(operatorStack.top());
		}
		else if (isOperator(inFix.at(i))) {
			if (operatorStack.size() == 0) {
				operatorStack.push(inFix.at(i));
				compareValue = precedence(operatorStack.top());
			}
			else if (currentValue > compareValue) {
				operatorStack.push(inFix.at(i));
				compareValue = precedence(operatorStack.top());
			}
			else {
				while (compareValue >= currentValue) {
					postFix.push_back(operatorStack.top());
					operatorStack.pop();
					if (operatorStack.size() == 0) {
						break;
					}
					compareValue = precedence(operatorStack.top());
				}
				operatorStack.push(inFix.at(i));
				compareValue = precedence(operatorStack.top());
			}
		}
		else if (isRightParen(inFix.at(i))) {
			while (!isPair(operatorStack.top(), inFix.at(i))) {
				postFix.push_back(operatorStack.top());
				operatorStack.pop();
				compareValue = precedence(operatorStack.top());
			}
			operatorStack.pop();
			if (operatorStack.size() == 0) {
			}
			else {
				compareValue = precedence(operatorStack.top());
			}
		}
	}
	while (operatorStack.size() != 0) {
		if (isLeftParen(operatorStack.top())) {
			operatorStack.pop();
		}
		else {
			postFix.push_back(operatorStack.top());
			operatorStack.pop();
		}
	}
	string postFixString;
	for (unsigned int i = 0; i < postFix.size(); i++) {
		postFixString = postFixString + postFix.at(i) + " ";
	}
	return postFixString;
}

bool ExpressionManager::isPair(string left, string right) {
	if (right == ")") {
		if (left == "(") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (right == "]") {
		if (left == "[") {
			return true;
		}
		else {
			return false;
		}
	}
	else if (right == "}") {
		if (left == "{") {
			return true;
		}
		else {
			return false;
		}
	}
	else {}
}

string ExpressionManager::prefix(void)
{
	if (inFix.size() == 0) {
		string parseExpression = userExpression + " ;";
		while (parseExpression != ";") {
			string subString = parseExpression.substr(0, parseExpression.find(' '));
			inFix.push_back(subString);
			parseExpression = parseExpression.substr(parseExpression.find(' ') + 1);
		}
	}
	stack<string> temporaryStack;
	vector<string> backwardsExpression;
	for (unsigned int i = 0; i < inFix.size(); i++) {
		temporaryStack.push(inFix.at(i));
	}
	while (temporaryStack.size() != 0) {
		backwardsExpression.push_back(temporaryStack.top());
		temporaryStack.pop();
	}
	for (unsigned int i = 0; i < backwardsExpression.size(); i++) {
		if (backwardsExpression.at(i) == ")") {
			backwardsExpression.at(i) = "(";
		}
		else if (backwardsExpression.at(i) == "(") {
			backwardsExpression.at(i) = ")";
		}
		else if (backwardsExpression.at(i) == "]") {
			backwardsExpression.at(i) = "[";
		}
		else if (backwardsExpression.at(i) == "[") {
			backwardsExpression.at(i) = "]";
		}
		else if (backwardsExpression.at(i) == "}") {
			backwardsExpression.at(i) = "{";
		}
		else if (backwardsExpression.at(i) == "{") {
			backwardsExpression.at(i) = "}";
		}
		else {
		}
	}

	stack<string> operatorStack;
	int currentValue = 0;
	int compareValue = 0;
	for (unsigned int i = 0; i < backwardsExpression.size(); i++) {
		currentValue = precedence(backwardsExpression.at(i));
		if (isNumber(backwardsExpression.at(i))) {
			preFix.push_back(backwardsExpression.at(i));
		}
		else if (operatorStack.size() == 0 && (VALID_CHARACTERS.find(backwardsExpression.at(i)) != string::npos)) {
			operatorStack.push(backwardsExpression.at(i));
			compareValue = precedence(operatorStack.top());
		}
		else if (isLeftParen(backwardsExpression.at(i))) {
			operatorStack.push(backwardsExpression.at(i));
			compareValue = precedence(operatorStack.top());
		}
		else if (isOperator(backwardsExpression.at(i))) {
			if (operatorStack.size() == 0) {
				operatorStack.push(backwardsExpression.at(i));
				compareValue = precedence(operatorStack.top());
			}
			else if (currentValue >= compareValue) {
				operatorStack.push(backwardsExpression.at(i));
				compareValue = precedence(operatorStack.top());
			}
			else {
				while (compareValue > currentValue) {
					backwardsExpression.push_back(operatorStack.top());
					operatorStack.pop();
					if (operatorStack.size() == 0) {
						break;
					}
					compareValue = precedence(operatorStack.top());
				}
				operatorStack.push(backwardsExpression.at(i));
				compareValue = precedence(operatorStack.top());
			}
		}
		else if (isRightParen(backwardsExpression.at(i))) {
			while (!isPair(operatorStack.top(), backwardsExpression.at(i))) {
				preFix.push_back(operatorStack.top());
				operatorStack.pop();
				compareValue = precedence(operatorStack.top());
			}
			operatorStack.pop();
			if (operatorStack.size() == 0) {
			}
			else {
				compareValue = precedence(operatorStack.top());
			}
		}
	}
	while (operatorStack.size() != 0) {
		if (isLeftParen(operatorStack.top())) {
			operatorStack.pop();
		}
		else {
			preFix.push_back(operatorStack.top());
			operatorStack.pop();
		}
	}
	vector<string> forwardsExpression;
	for (unsigned int i = 0; i < preFix.size(); i++) {
		temporaryStack.push(preFix.at(i));
	}
	while (temporaryStack.size() != 0) {
		forwardsExpression.push_back(temporaryStack.top());
		temporaryStack.pop();
	}
	string preFixString;
	for (unsigned int i = 0; i < forwardsExpression.size(); i++) {
		preFixString = preFixString + forwardsExpression.at(i) + " ";
	}
	return preFixString;
}