#include<iostream>
#include<string>
#include<fstream>
#include "LinkedList.h"
#include"LinkedListInterface.h"
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
	//outputFile << "Input file: " << argv[1] << endl;
	ifstream inputFile(argv[1]);                                  // creating ifstream input file and opening
	if (!inputFile.is_open()) {
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	//outputFile << "Output file: " << argv[2] << endl;
	ofstream outputFile(argv[2]);								//creating ofstream output file and opening
	if (!outputFile.is_open()) {
		inputFile.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	LinkedList<string> myList;
	
	// process input strings

	for (string line; getline(inputFile, line);)
	{
		string item1, item2;
		if (line.size() == 0) continue;
		outputFile << endl << line;
		istringstream iss(line);
		iss >> item1;
		if (item1 == "Insert")
		{
			while (iss >> item2) {
				myList.push_front(item2);
			}
		}
		try {                                // try catch block with throws within function declarations
			if (item1 == "PrintList") {
				outputFile << myList.toString();
			}
			else if (item1 == "Clear") {
				myList.clear();
				outputFile << " OK";
			}
			else if (item1 == "Size") {

				outputFile << " " << myList.size();
			}

			else if (item1 == "Empty") {
				if (myList.empty() == true) {
					outputFile << " true";
				}
				else {
					outputFile << " false";
				}
			}
			else if (item1 == "First") {
				outputFile << " " << myList.front();
			}
			else if (item1 == "Remove") {
				while (iss >> item2) {
					myList.remove(item2);
				}
			}
			else if (item1 == "Delete") {
				myList.pop_front();
				outputFile << " OK";
			}
			else if (item1 == "Reverse") {
				myList.reverse();
				outputFile << " OK";
			}
		}
		catch (int e) {
			outputFile << " Empty!";
		}
	}
	try {
		myList.clear();
	}
	catch (int f) {
	}
	return 0;
}