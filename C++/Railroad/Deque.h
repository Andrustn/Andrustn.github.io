#ifndef DEQUE_H
#define DEQUE_H
#include <string>
#include "DequeInterface.h"
#include<iostream>
using namespace std;
#define DEFAULT_CAPACITY  4

template<typename T>
class Deque : public DequeInterface<T> {

private:
	unsigned int capacity;
	unsigned int num_items;
	unsigned int front_index;
	unsigned int rear_index;
	T* the_data;

	// leaving function definitions in class declaration
	// because it's a template class


public:
	Deque(void) {
		capacity = DEFAULT_CAPACITY;
		num_items = 0;
		front_index = 0;
		rear_index = (DEFAULT_CAPACITY - 1);
		the_data = (new T[DEFAULT_CAPACITY]);
	}

	virtual ~Deque(void) { clear(); }

	unsigned int getFrontIndex() {
		return front_index;
	}
	unsigned int getRearIndex() {
		return rear_index;
	}

	void clear() {
		delete[] the_data;
		the_data = NULL;
	}

	virtual void push_front(const T& value) {
		if (num_items == capacity) {
			reallocate();
		}
		num_items++;
		front_index = (front_index - 1) % capacity;
		the_data[front_index] = value;
	}

	/** Insert item at rear of deque */
	virtual void push_back(const T& value) {
		if (num_items == capacity) {
			reallocate();
		}
		num_items++;
		rear_index = (rear_index + 1) % capacity;
		the_data[rear_index] = value;
	}

	/** Remove the front item of the deque */
	virtual void pop_front(void) {
		num_items--;
		front_index = (front_index + 1) % capacity;
		return;
	}

	/** Remove the rear item of the deque */
	virtual void pop_back(void) {
		num_items--;
		rear_index = (rear_index - 1) % capacity;
		return;
	}

	/** Return the front item of the deque (Do not remove) */
	virtual T& front(void) {
		return the_data[front_index];
	}

	/** Return the rear item of the deque (Do not remove) */
	virtual T& back(void) {
		return the_data[rear_index];
	}

	/** Return the number of items in the deque */
	virtual size_t size(void) const {
		return num_items;
	}

	/** Return true if deque is empty */
	virtual bool empty(void) const {
		return front_index == rear_index;
	}
	/** Return item in deque at index (0 based) */
	virtual T& at(size_t index) {
		return the_data[index];
	}

	/** Return the deque items */
	virtual std::string toString(void) const {
		string data_string;
		if (num_items == 0) {
			throw string("Empty!");
		}
		else {
			for (unsigned int i = front_index; i < rear_index + 1; i++) {
				data_string = data_string + to_string(the_data[i]) + " ";
			}
			return data_string;
		}
	}

	void reallocate() {
		size_t new_capacity = 2 * capacity;
		T* new_data = new T[new_capacity];
		size_t old = front_index;
		for (size_t i = 0; i < num_items; i++) {
			new_data[i] = the_data[old];
			old = (old + 1) % capacity;                 
		}											
		front_index = 0;
		rear_index = num_items - 1;
		capacity = new_capacity;
		swap(the_data, new_data);
		delete[] new_data;
	}
};
#endif

