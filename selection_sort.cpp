#include "selection_sort.h"

Item* findMin(Item* head) {

	if(head == nullptr) {
		return nullptr;
	}

	Item* temp = head;
	Item* minItem = head;

	while(temp->next != nullptr) {

		if(temp->getValue() < minItem->getValue()) {
			minItem = temp;
		}
		temp = temp->next; 
	}
	if(temp->next == nullptr) {
			if(temp->getValue() < minItem->getValue()) {
				minItem = temp;
			}
	}
	return minItem;
}


Item* LLSelectionSort(Item* head) {

	if(head == nullptr) {
		return nullptr;
	}

	Item* oldHead = head;
	Item* front;
	Item* newHead;
	bool first = false;

	while(oldHead->next != nullptr) {
		//finds the smallest node or the new head
		if(!first) {
			newHead = findMin(oldHead);
			first = true;
		}

		front = findMin(oldHead);
		Item* before = front->prev;

		if(front->getValue() == oldHead->getValue()) {
			
		} else {

			front->prev = oldHead->prev;
			if(front->prev != nullptr) {
				front->prev->next = front;
			}

			oldHead->prev = front;
			before->next = front->next;
			front->next = oldHead;

			
			if(oldHead == before) {
				if(oldHead->next == nullptr) { }
				else {
					oldHead->next->prev = before;
				}
			}
		}
		oldHead = front->next;
	}
	return newHead;
}


