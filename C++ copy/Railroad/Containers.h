#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <string>
#include "DequeInterface.h"
#include<iostream>
#include "Deque.h"
using namespace std;
// leaving function definitions in class declaration
// because it's a template class

template<typename T>
class Vector {
private:
	Deque<T> container;
public:
	Vector() {}
	~Vector() {
	}
	void push_back(const T& value) {
		container.push_back(value);
	}
	void pop_back() {
		container.pop_back();
	}
	T& back() {
		return container.back();
	}
	size_t size() {
		return container.size();
	}
	T& at(size_t value) {
		return container.at(value);
	}
	const string toString() {
		return container.toString();
	}
	unsigned int getFrontIndex() {
		return container.getFrontIndex();
	}
	unsigned int getRearIndex() {
		return container.getRearIndex();
	}
	void clear() {
		container.clear();
	}
};

template<typename T>
class Queue {
private:
	Deque<T> container;
public:

	Queue() {}
	~Queue() {}

	void push(const T& value) {
		container.push_back(value);
	}
	void pop() {
		container.pop_front();
	}
	T& top() {
		return container.front();
	}
	size_t size() {
		return container.size();
	}
	T& at(size_t value) {
		return container.at(value);
	}
	const string toString() {
		return container.toString();
	}
	unsigned int getFrontIndex() {
		return container.getFrontIndex();
	}
	unsigned int getRearIndex() {
		return container.getRearIndex();
	}
	void clear() {
		container.clear();
	}

};

template<typename T>
class Stack {
private:
	Deque<T> container;
public:

	Stack() { }
	~Stack() {}
	void push(const T& value) {
		container.push_back(value);
	}
	void pop() {
		container.pop_back();
	}
	T& top() {
		return container.back();
	}
	size_t size() {
		return container.size();
	}
	T& at(size_t value) {
		return container.at(value);
	}
	const string toString() {
		return container.toString();
	}
	unsigned int getFrontIndex() {
		return container.getFrontIndex();
	}
	unsigned int getRearIndex() {
		return container.getRearIndex();
	}
	void clear() {
		container.clear();
	}
};
#endif