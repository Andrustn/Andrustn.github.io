#include<iostream>
#include<fstream>
#include<sstream>
#include"BST.h"
#include"BSTInterface.h"
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
	//cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);                                  // creating ifstream input file and opening
	if (!in.is_open()) {
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	//cout << "output file: " << argv[2] << endl;
	ofstream out(argv[2]);								//creating ofstream output file and opening
	if (!out.is_open()) {
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}


	string line, command, value;
	while (getline(in, line)) {
		try {
			if (line.size() == 0) continue;
			istringstream iss(line);
			iss >> command;
			out << line << " ";


			if (command == "INT") {
				out << "true" << endl;

				BST<int> integerTree;

				while (getline(in, line)) {
					try {
						if (line.size() == 0) continue;
						istringstream iss(line);
						iss >> command;
						out << line;

						if (command == "add") {

							iss >> value;
							int userInt = stoi(value);
							if (integerTree.addNode(userInt)) {
								out << " true";
							}
							else {
								out << " false";
							}
						}
						else if (command == "print") {
							out <<": " << integerTree;
						}
						else if (command == "remove") {
							iss >> value;
							int userInt = stoi(value);

							if (integerTree.removeNode(userInt)) {
								out << " true";
							}
							else {
								out << " false";
							}

						}
						else if (command == "clear") {
							integerTree.clearTree();
								out << " true";
						}
						else if (command == "size") {
							out << " " << integerTree.getSize();

						}
						else if (command == "tree") {
							out << "     tree";

						}
						else if (command == "find") {
							iss >> value;
							int userInt = stoi(value);
							if (integerTree.searchNode(userInt)) {
								out << " found";
							}
							else {
								out << " not found";
							}

						}
						else {
							break;
						}
						out << endl;
					}
					catch (...) {}
				}
				integerTree.clearTree();
			}

			


			if (command == "STRING") {
				out << " true" << endl;
				BST<string> stringTree;


				while (getline(in, line)) {
					try {
						if (line.size() == 0) continue;
						istringstream iss(line);
						iss >> command;
						out << line;

						if (command == "add") {

							iss >> value;
							if (stringTree.addNode(value)) {
								out << " true";
							}
							else {
								out << " false";
							}
						}
						else if (command == "print") {
							out << ": " << stringTree;
						}
						else if (command == "remove") {
							iss >> value;

							if (stringTree.removeNode(value)) {
								out << " true";
							}
							else {
								out << " false";
							}

						}
						else if (command == "clear") {
							stringTree.clearTree();
								out << " true";
						}
						else if (command == "size") {
							out << " " << stringTree.getSize();

						}
						else if (command == "tree") {
							out << "     tree";

						}
						else if (command == "find") {
							iss >> value;
							if (stringTree.searchNode(value)) {
								out << " found";
							}
							else {
								out << " not found";
							}

						}
						else {
							break;
						}
						out << endl;
					}
					catch (...) {}
				}
				stringTree.clearTree();

				out << endl;
			}
		}
		catch (...) {
			out << "error";
		}
	}

	return 0;
}
