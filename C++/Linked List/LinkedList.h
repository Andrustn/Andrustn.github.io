#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include <iostream>
#include "LinkedListInterface.h"
using namespace std;

template<typename T>
class LinkedList : 
	public LinkedListInterface<T> {

private:
	struct Node {
		T data;
		struct Node* next = NULL;
	};
	typedef struct Node* nodePtr;
	nodePtr headNode = NULL;
public:	
	LinkedList() {}
	~LinkedList() {}
	virtual void push_front(const T& value);
	virtual void pop_front(void);
	virtual T& front(void);
	virtual bool empty(void) const;
	virtual void remove(const T& value);
	virtual void clear(void);
	virtual void reverse(void);
	virtual size_t size(void) const;
	virtual std::string toString(void) const;
	friend ostream& operator<<(ostream& os, LinkedList<T>& userList) {
		os << userList.toString();
		return os;
	}
};
template<typename T>
void LinkedList<T>::push_front(const T& value) {
	if (headNode == NULL) {
		nodePtr temporaryNode = NULL;
		nodePtr newNode = new Node;
		newNode->data = value;
		temporaryNode = newNode;
		headNode = newNode;
		newNode->next = NULL;
	}
	else {
		nodePtr temporaryNode = NULL;
		nodePtr newNode = new Node;
		newNode->data = value;
		temporaryNode = newNode;
		temporaryNode->next = headNode;
		headNode = newNode;
	}
}
template<typename T>
void LinkedList<T>::pop_front(void) {
	if (headNode == NULL) {
		throw 20;
	}
	else {
		nodePtr temporaryNode = NULL;
		temporaryNode = headNode;
		headNode = temporaryNode->next;
		delete temporaryNode;
	}
}
template<typename T>
 T& LinkedList<T>::front(void) {
	if (headNode == NULL) {
		throw 20;
	}
	else {
		return headNode->data;
	}
}
 template<typename T>
 bool LinkedList<T>::empty(void) const {
	 bool empty;
	 if (headNode == NULL) {
		 empty = true;
	 }
	 else {
		 empty = false;
	 }
	 return empty;
 }
 template<typename T>
void LinkedList<T>::remove(const T& value) {
	 nodePtr temporaryNode = headNode;
	 nodePtr secondTemporaryNode = headNode;

	 if (headNode->data == value) {
		 temporaryNode = headNode->next; // checking if headNode is Value
		 delete headNode;
		 headNode = temporaryNode;
	 }
	 secondTemporaryNode = temporaryNode;
	 while (secondTemporaryNode->next != NULL) {
		 secondTemporaryNode = temporaryNode->next;
		 if (secondTemporaryNode->data == value) {     // iterating through rest of linked list
			 temporaryNode->next = secondTemporaryNode->next;
			 delete secondTemporaryNode;
			 secondTemporaryNode = temporaryNode;
		 }
		 else {
			 temporaryNode = secondTemporaryNode;
		 }
	 }
	 if (headNode->next == NULL && headNode->data == value) {
		 delete headNode;
		 headNode = NULL;       // checking again if headNode is Value (in the event that it's the only node left)
	 }
 }
template<typename T>
void LinkedList<T>::clear(void) {
	if (headNode == NULL) {
		throw 20;	
 	}
	
	else {
		nodePtr temporaryNode = headNode->next;
		while (temporaryNode != NULL) {
			delete headNode;
			headNode = temporaryNode;
			temporaryNode = temporaryNode->next;
		}
		delete headNode;
		headNode = NULL;
	}
}
template<typename T>
void LinkedList<T>::reverse(void) {
	if (headNode == NULL) {
		throw 20;
	}
	else {
		nodePtr currentNode = headNode;
		nodePtr previousNode = NULL;
		nodePtr nextNode = NULL;
		while (currentNode != NULL) {
			nextNode = currentNode->next;
			currentNode->next = previousNode;
			previousNode = currentNode;
			currentNode = nextNode;
		}
		headNode = previousNode;
	}
}
template<typename T>
size_t LinkedList<T>::size(void) const {
	nodePtr temporaryNode = headNode;
	int counter = 0;
	while (temporaryNode != NULL) {
		counter++;
		temporaryNode = temporaryNode->next;
	}
	return counter;
}
template<typename T>
string LinkedList<T>::toString(void) const {
	nodePtr temporaryNode = headNode;
	string listContents = "";
	if (headNode == NULL) {
		throw 20;
	}
	else {
		while (temporaryNode != NULL) {
			listContents = listContents + " " + temporaryNode->data;
			temporaryNode = temporaryNode->next;
		}
	}
	return listContents;
}
#endif