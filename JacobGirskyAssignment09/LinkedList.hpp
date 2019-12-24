// Jacob Girsky 
// CSCI 3250
// Programming Assignment 9


#pragma once
#include <stdexcept>

template <class T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <class T>
class LinkedList {
private:
	Node<T>* mHead;
	Node<T>* mTail;

	int mSize;
	void clear();
	void copy(const LinkedList&);
	bool isEmpty();

public:
	LinkedList();
	LinkedList(const LinkedList&);
	~LinkedList();
	LinkedList<T>& operator=(const LinkedList&);
	int size() const;
	T at(int) const;
	void push_front(T);
	void push_back(T);
	T pop_front();
	T pop_back();
};

/*
* LinkedList() - default constructor that sets head and tail to null and size to 0;
* @params - none
* precondition - none
* postcondition - none
*/
template <class T>
LinkedList<T>::LinkedList() {
	mHead = nullptr;
	mTail = nullptr;
	mSize = 0;
}

/*
* LinkedList(const LinkedList&) - copy contructor copies one object to another
* @params - list - a LinkedList object
* precondition - the list must not be empty
* postcondition - the object is copied
*/
template <class T>
LinkedList<T>::LinkedList(const LinkedList& list) {
	copy(list);
}

/*
* ~LinkedList() - destructor
* @params - none
* precondition - list cannot be empty
* postcondition - list will be empty
*/
template <class T>
LinkedList<T>::~LinkedList() {
	clear();
}

/*
* operator= - overloaded assignment operator
* @params - list - a LinkedList object
* precondition - the list cannot be empty
* postcondition - none
*/
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& list) {
	if (this != &list) {
		~LinkedList();
		copy(list);
	}
	return *this;
}

/*
* size() - returns the size of the list
* @params - none
* precondition - none
* postcondition - none
*/
template <class T>
int LinkedList<T>::size() const {
	return mSize;
}

/*
* at(int) - returns the index of the element passed in
* @params - index - an int
* precondition - list cannot be empty
* postcondition - none
*/
template <class T>
T LinkedList<T>::at(int index) const {
	if (index < 0 || index >= mSize) {
		throw std::invalid_argument("Index out of bounds.");
	}
	Node<T>* temp = mHead;

	if (index == 0) {
		return mHead->data;
	}
	if (index + 1 == mSize) {
		return mTail->data;
	}
	else {
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp->data;
	}
}

/*
* push_front(T) - adds a element to the beggining of the list
* @params - T - the value to be added
* precondition - none
* postcondition - the size of the list increases by one
*/
template <class T>
void LinkedList<T>::push_front(T value) {
	Node<T>* node = new Node<T>;
	node->data = value;

	if (isEmpty()) {
		mHead = node;
		mTail = node;
		node->next = nullptr;
		node->prev = nullptr;
	}
	else {
		mHead->prev = node;
		node->next = mHead;
		node->prev = nullptr;
		mHead = node;
	}
	mSize++;
}

/*
* push_back(T) - adds a element to the end of the list
* @params - T - the value to be added
* precondition - none
* postcondition - the size of the list increases by one
*/
template <class T>
void LinkedList<T>::push_back(T value) {
	Node<T>* node = new Node<T>;
	node->data = value;

	if (isEmpty()) {
		mHead = node;
		mTail = node;
		node->next = nullptr;
		node->prev = nullptr;
	}
	else {
		node->prev = mTail;
		mTail->next = node;
		mTail = mTail->next;
		node->next = nullptr;
	}
	mSize++;

}

/*
* pop_front() - deletes the element at the beginning of the list
* @params - none
* precondition - list cannot be empty
* postcondition - the size of the list decreases by one
*/
template <class T>
T LinkedList<T>::pop_front() {
	if (isEmpty()) {
		throw std::logic_error("The list is empty.");
	}
	T val = mHead->data;
	Node<T> *oldHead = mHead;
	if (mSize == 1) {
		mHead = nullptr;
		mTail = nullptr;
	}
	else {
		mHead = mHead->next;
		mHead->prev = nullptr;
	}
	delete oldHead;
	mSize--;
	return val;
}

/*
* pop_back() - deletes the element at the end of the list
* @params - none
* precondition - the list cannot be empty
* postcondition - the size of the list decreases by one
*/
template <class T>
T LinkedList<T>::pop_back() {
	if (isEmpty()) {
		throw std::logic_error("The list is empty.");
	}
	T val = mTail->data;
	Node<T> *oldTail = mTail;
	if (mSize == 1) {
		mHead = nullptr;
		mTail = nullptr;
	}
	else {
		mTail = mTail->prev;
		mTail->next = nullptr;
	}
	delete oldTail;
	mSize--;
	return val;
}

/*
* isEmpty() - returns true if the list is empty
* @params - none
* precondition - none
* postcondition - none
*/
template <class T>
bool LinkedList<T>::isEmpty() {
	return mHead == nullptr;
}

/*
* clear() - deletes all the elements in the list
* @params - none
* precondition - list cannot be empty
* postcondition - the size of the list goes to 0
*/
template <class T>
void LinkedList<T>::clear() {
	while (mHead != nullptr) {
		pop_front();
	}
}

/*
* copy() - copies one object to another
* @params - list - a LinkedList object
* precondition - list cannot be empty
* postcondition - none
*/
template <class T>
void LinkedList<T>::copy(const LinkedList& list) {
	mSize = 0;

	Node<T>* curs = list.mHead;
	for (int i = 0; i < list.mSize; i++) {
		T value = curs->data;
		push_back(value);
		curs = curs->next;
	}
}



