#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H
#include "ExpressionManagerInterface.h"
#include<stack>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

const string LEFT_PARENTHESIS = "([{";
const string RIGHT_PARENTHESIS = ")]}";
const string PRIORITY_OPERATORS = "*/%"; // declaring global constants to check for valid characters
const string SECONDARY_OPERATORS = "+-";  
const string ALL_OPERATORS = "*/%+-";
const string VALID_CHARACTERS = "([{}])*/%+-";

class ExpressionManager :
	public ExpressionManagerInterface{
public:

	ExpressionManager(string expression) {
		userExpression = expression;
	}
	ExpressionManager() {
		userExpression = "NULL";
	}
	virtual ~ExpressionManager(void) {}
	virtual int value(void);
	friend ostream& operator<<(ostream& os, ExpressionManager& userExpression) {
		os << userExpression.toString();
		return os;
	}
	virtual string infix(void);
	virtual string postfix(void);
	virtual string prefix(void);
	virtual std::string toString(void) const {
		string inFixString;
		for (unsigned int i = 0; i < inFix.size(); i++) {
			inFixString = inFixString + inFix.at(i) + " ";
		}
		return inFixString;
	}
	bool isLeftParen(string t) {
		if (LEFT_PARENTHESIS.find(t) == string::npos) {
			return false;
		}
		else {
			return true;
		}
	}
	bool isRightParen(string t) {
		if (RIGHT_PARENTHESIS.find(t) == string::npos) {
			return false;
		}
		else {
			return true;
		}
	}
	bool isPair(string left, string right);
	bool isNumber(string t) {
		try {
			stoi(t);
		}
		catch (...) {
			return false;
		}
		return true;
	}
	bool isSpace(string t) {
		return(t == " ");
	}
	bool isOperator(string t) {
		if (ALL_OPERATORS.find(t) == string::npos) {
			return false;
		}
		else {
			return true;
		}
	}
	int precedence(string givenOperator) {
		if (PRIORITY_OPERATORS.find(givenOperator) != string::npos) {
			return 2;
		}
		else if (SECONDARY_OPERATORS.find(givenOperator) != string::npos) {
			return 1;
		}
		else if (isLeftParen(givenOperator)) {
			return 0;
		}
		else {}
	}
private: 
	string userExpression;
	vector<string> inFix;
	vector<string> postFix;
	vector<string> preFix;
};
#endif