#ifndef STATION_H
#define STATION_H
#include <string>
#include "DequeInterface.h"
#include "Containers.h"
#include "Deque.h"
#include<iostream>
using namespace std;
// leaving function definitions in class declaration
// because it's a template class
template<typename T>
class Station {

public:
	Station() {
		turn_table_car = 0;
		empty = true;
	}
	~Station() {}

	string addCar(const unsigned int& value) {
		turn_table_car = value;
		empty = false;
		return string(" OK");
	}
	string removeCar() {
		if (empty) {
			throw string(" Turntable empty!");
		}
		else {
			train.push_back(turn_table_car);
			empty = true;
			return string(" OK");
		}
	}
	string topCar() {
		if (empty) {
			return string(" EMPTY");
		}
		return train.back();
	}
	string addStack() {
		if (empty) {
			throw string(" Turntable empty!");
		}
		else {
			stack.push(turn_table_car);
			empty = true;
			return string(" OK");
		}
	}
	string removeStack() {
		if (stack.size() == 0) {
			return string(" Stack empty!");
		}
		else if (empty) {
			turn_table_car = stack.top();
			stack.pop();
			empty = false;
			return string(" OK");
		}
		else {
			throw string(" Turntable Occupied!");
		}
	}
	string topStack() {
		return to_string(stack.top());
	}
	string sizeStack() {
		return to_string(stack.size());
	}
	string addQueue() {
		if (empty) {
			throw string(" Turntable empty!");
		}
		else {
			queue.push(turn_table_car);
			empty = true;
			return string(" OK");
		}
	}
	string removeQueue() {
		if (queue.size() == 0) {
			return string(" Queue empty!");
		}
		else if (empty) {
			turn_table_car = queue.top();
			queue.pop();
			empty = false;
			return string(" OK");
		}
		else {
			throw string(" Turn table occupied");
		}
	}
	string topQueue() {
		return to_string(queue.top());
	}
	string sizeQueue() {
		return to_string(queue.size());
	}
	string find(unsigned int value) {
		if (empty) {

		}
		else {
			if (turn_table_car == value) {
				return "Turntable";
			}
			else{}
		}
		if (stack.size() == 0) {
		}
		else {
			for (unsigned int i = stack.getFrontIndex(); i < stack.getRearIndex() + 1; i++) {
				if (stack.at(i) == value) {
					string returnValue = "Stack[" + to_string(i - stack.getFrontIndex()) + "]";
					i--;
					return returnValue;
				}
				else{}
			}
		}
		if (queue.size() == 0) {
		}
		else {
			for (unsigned int i = queue.getFrontIndex(); i < queue.getRearIndex() + 1; i++) {
				if (queue.at(i) == value) {
					string returnValue = "Queue[" + to_string(i - queue.getFrontIndex()) + "]";
					i--;
					return returnValue;
					
				}
				else {}
			}
		}
		if (train.size() == 0) {
		}
		else {
			for (unsigned int i = train.getFrontIndex(); i < train.getRearIndex() + 1; i++) {
				if (train.at(i) == value) {
					string returnValue = "Train[" + to_string(i - train.getFrontIndex()) + "]";
					i--;
					return returnValue;
				}
				else {}
			}
		}
		return "Not Found!";
	}
	const string toString() {
		return train.toString();
	}

	void clear() {
		train.clear();
		queue.clear();
		stack.clear();
	}

private:
	Vector<unsigned int> train;
	Queue<unsigned int> queue;
	Stack<unsigned int> stack;
	unsigned int turn_table_car;
	bool empty;
};
#endif
