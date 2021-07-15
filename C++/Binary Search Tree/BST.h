#ifndef BST_H
#define BST_H
#include "BSTInterface.h"
#include<istream>
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

template<typename T>
class BST :
	public BSTInterface<T> {

private:
	struct Node {
		T data;
		struct Node* leftChild = NULL;
		struct Node* rightChild = NULL;
		friend class BST;
	};
	typedef struct Node* nodePtr;
	nodePtr root = NULL;
	int size = 0;

public:
	BST(void) {}
	virtual ~BST(void) {}

	friend ostream& operator<<(ostream& os, BST<T>& userList) {
		os << userList.toString();
		return os;
	}

	/** Return true if node added to BST, else false */
	virtual bool addNode(const T& value);
	/** Return true if node removed from BST, else false */
	virtual bool removeNode(const T& value) {
		if (eraseNode(root, value)) {
			size--;
			return true;
		}
		else {
			return false; 
		}
	}
	/** Return true if BST cleared of all nodes, else false */
	virtual bool clearTree() {
		if (root == NULL) {
			return false;
		}
		else {
			deleteNode(root);
			root = NULL;
			return true;
		}
	}
	/** Return a level order traversal of a BST as a string */
	virtual std::string toString() const;
	bool deleteNode(nodePtr searchNode) {
		if (searchNode == NULL) {
			return false;
		}
 		deleteNode(searchNode->leftChild);
		deleteNode(searchNode->rightChild);
		delete searchNode;
		searchNode = NULL;
		size--;
	}
	bool findNode(Node* searchNode, T& value);
	bool searchNode(T& value) {
		return findNode(root, value);
	}
	bool insertNode(nodePtr& rootNode, const T& value);
	bool outLevel(Node* root, int level, stringstream& out) const; // end outLevel()
	bool eraseNode(nodePtr& rootNode, const T& value);
	nodePtr maxValue(Node* originalNode) {
		Node* current = originalNode;

		while (current && current->rightChild != NULL) {
			current = current->rightChild;
		}

		return current;
	 }
	int getSize() {
		return size;
	}
};
#endif

template<typename T>
bool BST<T>::addNode(const T& value) {
	if (root == NULL) {
		nodePtr newNode = new Node;
		newNode->data = value;
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
		root = newNode;
		size++;
		return true;
	}
	else {
		insertNode(root, value);
	}
}

template<typename T>
string BST<T>::toString() const {
	stringstream out;
	if (root == NULL) out << "empty";
	else
	{
		int level = 0;
		do {
			out << endl << "  " << ++level << ":";
		} while (outLevel(root, level, out));
	}
	return out.str();
}

template<typename T>
bool BST<T>::findNode(Node* searchNode, T& value) {
	if (searchNode == NULL) {
		return false;
	}
	else if (searchNode->data == value) {
		return true;
	}
	else if (value > searchNode->data) {
		return findNode(searchNode->rightChild, value);
	}
	else if (value < searchNode->data) {
		return findNode(searchNode->leftChild, value);
	}
}

template<typename T>
bool BST<T>::insertNode(nodePtr& rootNode, const T& value) {
	if (rootNode == NULL) {
		nodePtr newNode = new Node;
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
		newNode->data = value;
		rootNode = newNode;
		size++;
		return true;
	}
	else if (value > rootNode->data) {
		return insertNode(rootNode->rightChild, value);
	}
	else if (value < rootNode->data) {
		return insertNode(rootNode->leftChild, value);
	}
	else if (value == rootNode->data) {
		return false;
	}
}

template<typename T>
bool BST<T>::outLevel(Node* root, int level, stringstream& out) const {
	if (root == NULL) return false;
	if (level == 1)
	{
		out << " " << root->data;
		if ((root->leftChild != NULL) || (root->rightChild != NULL)) return true;
		return false;
	}
	if ((level == 2) && !root->leftChild && root->rightChild) out << " _";
	bool left = outLevel(root->leftChild, level - 1, out);
	bool right = outLevel(root->rightChild, level - 1, out);
	if ((level == 2) && root->leftChild && !root->rightChild) out << " _";
	return left || right;
} // end outLevel()

template<typename T>
bool BST<T>::eraseNode(nodePtr& rootNode, const T& value) {
	if (rootNode == NULL) {
		return false;
	}

	if (root == rootNode && rootNode->data == value) {
		if (root->leftChild == NULL && root->rightChild == NULL) {
			delete root;
			root = NULL;
			return true;
		}
		else {
			nodePtr temp = maxValue(root->leftChild);
			root->data = temp->data;
			eraseNode(root->leftChild, temp->data);


			return true;
		}
	}

	if (rootNode->data == value) {
		if (rootNode->leftChild == NULL && rootNode->rightChild == NULL) {
			delete rootNode;
			rootNode = NULL;
			return true;
		}
		else {
			nodePtr temp = maxValue(rootNode->leftChild);
			rootNode->data = temp->data;
			eraseNode(rootNode->leftChild, temp->data);
			delete temp;

			return true;
		}
	}


	else if (rootNode->leftChild != NULL) {
		if (rootNode->leftChild->data == value) {
			if (rootNode->leftChild->leftChild == NULL && rootNode->leftChild->rightChild == NULL) {
				delete rootNode->leftChild;
				rootNode->leftChild = NULL;
				return true;
			}

			if (rootNode->leftChild->leftChild == NULL) {
				T temp = rootNode->leftChild->rightChild->data;
				rootNode->leftChild->rightChild->data = rootNode->leftChild->data;
				rootNode->leftChild->data = temp;
				delete rootNode->leftChild->rightChild;
				rootNode->leftChild->rightChild = NULL;
				return true;
			}
			else if (rootNode->leftChild->rightChild == NULL) {
				T temp = rootNode->leftChild->leftChild->data;
				rootNode->leftChild->leftChild->data = rootNode->leftChild->data;
				rootNode->leftChild->data = temp;
				delete rootNode->leftChild;
				rootNode->leftChild->leftChild = NULL;
				return true;
			}
			else {
				nodePtr temp = maxValue(rootNode->leftChild);
				rootNode->leftChild->data = temp->data;
				eraseNode(rootNode->leftChild, temp->data);
				delete temp;

				return true;
			}
		}
	}

	else if (rootNode->rightChild != NULL) {
		if (rootNode->rightChild->data == value) {
			if (rootNode->rightChild->leftChild == NULL && rootNode->rightChild->rightChild == NULL) {
				delete rootNode->rightChild;
				rootNode->rightChild = NULL;
				return true;
			}

			if (rootNode->rightChild->leftChild == NULL) {
				T temp = rootNode->rightChild->rightChild->data;
				rootNode->rightChild->rightChild->data = rootNode->rightChild->data;
				rootNode->rightChild->data = temp;
				delete rootNode->rightChild->rightChild;
				rootNode->rightChild->rightChild = NULL;
				return true;
			}
			else if (rootNode->rightChild->rightChild == NULL) {
				T temp = rootNode->rightChild->leftChild->data;
				rootNode->rightChild->leftChild->data = rootNode->rightChild->data;
				rootNode->rightChild->data = temp;
				delete rootNode->rightChild->leftChild;
				rootNode->rightChild->leftChild = NULL;
				return true;

			}
			else {
				nodePtr temp = maxValue(rootNode->rightChild);
				rootNode->rightChild->data = temp->data;
				eraseNode(rootNode->rightChild, temp->data);
				delete temp;

				return true;
			}
		}
	}
	if (value < rootNode->data) {
		eraseNode(rootNode->leftChild, value);
	}
	else if (value > rootNode->data) {
		eraseNode(rootNode->rightChild, value);
	}
}
