#include "ExpressionManager.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

int main(int argc, char* argv[]) {
	VS_MEM_CHECK
		if (argc < 3) {
			cerr << "Please provide name of input and output files";  // checking that files are accounted for
			return 1;
		}
	//out << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);                                  // creating ifstream input file and opening
	if (!in.is_open()) {
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	//out << "output file: " << argv[2] << endl;
	ofstream out(argv[2]);								//creating ofstream output file and opening
	if (!out.is_open()) {
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}
	// process input strings
	string line, command;
	ExpressionManager expression;
	while (getline(in, line)) {
		try {
			if (line.size() == 0) continue;
			istringstream iss(line);
			iss >> command;
			if (command == "Expression:") {
				out << line << endl;
				string expressionSubstring = line.substr(12, line.find("\n"));
				expression = ExpressionManager(expressionSubstring);
				continue;
			}
			else if (command == "Infix:") {
				out << "Infix: ";
				expression.infix();
				 out << expression << endl;
			}
			else if (command == "Postfix:") {
				out << "Postfix: ";
				out << expression.postfix() << endl;
			}
			else if (command == "Prefix:") {
				out << "Prefix: ";
				out << expression.prefix() << endl;

			}
			else if (command == "Value:") {
				out << "Value: ";
				expression.postfix();
				out << expression.value() << endl;
			}
			else {
				throw string("invalid input");
			}
		}
		catch (string error) {
			out << error << endl;
		}
	}
	return 0;
}