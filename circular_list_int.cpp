#include "circular_list_int.h"
#include <iostream>

/* already been initialized in the .h file */
CircularListInt::CircularListInt() {}

/* Removes the head until the list is empty */
CircularListInt::~CircularListInt() {
	while(!empty()) {
		remove(0);
	}
}

/* Iterates through Linked list to find index value */
int CircularListInt::get(size_t index) const {
	if(head == nullptr) {
		return 0;
	}
	Item* temp = head;
	size_t real_index = index % count;
	for(size_t i = 0; i < real_index; i++) {
		temp = temp->next;
	}
	return temp->value;
}

/* Returns the number of items in the Linked List */
size_t CircularListInt::size() const {
	
	return count;

}

/* Returns whether or no the Linked List is empty */
bool CircularListInt::empty() const {

	if(count == 0) {
		return 1;
	}
	return 0;
}

/* Pushes a new Item to the back of the List */
void CircularListInt::push_back(int value) {
	Item* push = new Item(value);
	if(head == nullptr) {

		head = push;
		head->next = push;
		head->prev = push;

		tail = push;

	} else {

		tail->next = push;
		head->prev = push;
		push->next = head;
		push->prev = tail;

		tail = push;
	}
	count++;
}

/* Sets the value of an Item at index to value */
void CircularListInt::set(size_t index, int value) {
	if(head == nullptr) {
		return;
	}

	Item* temp = head;
	size_t real_index = index % count;
	for(size_t i = 0; i < real_index; i++) {
		temp = temp->next;
	}
	temp->value = value;

}

/* Removes the Item at index */
void CircularListInt::remove(size_t index) {
	if(head == nullptr) {
		return;
	}
	Item* temp = head;
	size_t real_index = index % count;

	if(real_index == count-1) {
		
		temp = tail;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		tail = temp->next;
		delete temp;

	} else if(real_index == 0) {

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		head = head->next;
		delete temp;

	} else {

		for(size_t i = 0; i < real_index; i++) {
			temp = temp->next;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}

	count--;
	if(count == 0 ) {
		head = nullptr;
	} 
}

CircularListInt::Item* CircularListInt::findItem(size_t index) const {
	if(head == nullptr) {
		return nullptr;
	}

	Item* temp = head;
	size_t real_index = index % count;
	for(size_t i = 0; i < real_index; i++) {
		temp = temp->next;
	}
	return temp;

}