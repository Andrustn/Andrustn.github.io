#include "Deque.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
#include"Station.h"
#include"Deque.h"
#include"Containers.h"
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

	Station<unsigned int> myStation;

	string line, command, value;
	while (getline(in, line)) {
		try {
			if (line.size() == 0) continue;
			istringstream iss(line);
			iss >> command;
			out << line;

			//////////////////////////////////////////////////STATION FUNCTIONS/////////////////////////////////////////////////
			if (command == "Add:station") {
				iss >> value;
				out << myStation.addCar(stoi(value)) << endl;
			}
			else if (command == "Remove:station") {
				out << myStation.removeCar() << endl;
			}
			else if (command == "Train:") {
				out << " " << myStation.toString() << endl;
			}
			else if ("Find:" == line.substr(0, 5)) {
				int findValue = stoi(line.substr(5, line.find('\n') - 5));
				out << " " << myStation.find(findValue) << endl;
			}
			///////////////////////////////////////////////////QUEUE FUNCTIONS////////////////////////////////////////////////////
			else if (command == "Add:queue") {
				out << myStation.addQueue() << endl;
			}
			else if (command == "Top:queue") {
				out << " " << myStation.topQueue() << endl;
			}
			else if (command == "Remove:queue") {
				out << myStation.removeQueue() << endl;
			}
			else if (command == "Size:queue") {
				out <<  " " << myStation.sizeQueue() << endl;
			}
			/////////////////////////////////////////////////STACK FUNCTIONS/////////////////////////////////////////////////////
			else if (command == "Add:stack") {
				out << myStation.addStack() << endl;
			}
			else if (command == "Top:stack") {
				out << " " << myStation.topStack() << endl;
			}
			else if (command == "Remove:stack") {
				out << myStation.removeStack() << endl;
			}
			else if (command == "Size:stack") {
				out <<  " " << myStation.sizeStack() << endl;
			}
			else {
				throw string("INVALID INPUT");
			}
		}
		catch (string e) {
			out << e << endl;
		}
	}
}