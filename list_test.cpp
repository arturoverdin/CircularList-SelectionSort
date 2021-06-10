#include "circular_list_int.h"
#include <iostream>

using namespace std;

void checkEmpty(CircularListInt *list, bool expEmpty) {
	if (list->empty() == expEmpty) {
		cout << "SUCCESS: List is ";
		if (!expEmpty) cout << "not ";
		cout << "empty" << endl;
	}
	else {
		cout << "FAIL: List is ";
		if (expEmpty) cout << "not ";
		cout << "empty" << endl;
	}
}

void checkSize(CircularListInt *list, size_t expSize) {
	size_t size = list->size();
	if (size == expSize) {
		cout << "SUCCESS: List has size " << size << endl;
	}
	else {
		cout << "FAIL: List has size " << size;
		cout << " but expected " << expSize << endl;
	}
}

void checkGet(CircularListInt *list, int pos, const int &expInt) {
	int num = list->get(pos);
	if (num == expInt) {
		cout << "SUCCESS: String at index " << pos 
		<< " is \'" << expInt << "\'" << endl;
	} 
	else {
		cout << "FAIL: String at index " << pos << " is \'" 
		<< num << "\'";
		cout << " but expected \'" << expInt << "\'" << endl;
	}
}

void checkRemove(CircularListInt *list, int pos) {

	if(list->size() == 0) {

		cout << "SUCCESS: no item to remove at index: " 
		<< pos << endl;
		return;

	}

	int num1 = list->get(pos);

	list->remove(pos);

	int num2 = list->get(pos);
	
	if(num1 != num2) {

		cout << "SUCCESS: Removed Item at index " 
		<< pos << " which was " << num1 << endl;

	} else {
	
		cout << "FAIL: did not remove item at " << pos 
		<< " expected " << num2 << endl;
	}
}

void checkPush(CircularListInt* list, const int value) {

	list->push_back(value);

	if(list->get(list->size()-1) == value) {

		cout << "SUCCESS: Value inserted at tail is " 
		<< list->get(list->size()-1) << endl; 

	} else {

		cout << "FAIL: Expected value at tail is " << value
		 << " but instead got " 
		<< list->get(list->size()-1) << endl;
	}

}

void checkSet(CircularListInt* list, int pos, int expected) {

	list->set(pos, expected);
	int after = list->get(pos);

	if(after == expected) {

		cout << "SUCCESS: Value at index " << pos 
		<< " was changed to " << expected << endl;

	} else {

		cout << "False: Expected value " << expected 
		<< "at index " << pos << " but instead got " << after << endl;
	}
}

int main() {

	CircularListInt* object = new CircularListInt();
	
	checkSize(object, 0);
	checkEmpty(object, 1);
	checkSize(object, 0);
	checkPush(object, 1);
	checkSize(object, 1);
	checkPush(object, 2);
	checkSize(object, 2);
	checkPush(object, 3);
	checkSize(object, 3);
	checkPush(object, 4);
	checkSize(object, 4);
	checkPush(object, 5);
	checkSize(object, 5);
	checkPush(object, 6);
	checkSize(object, 6);
	checkEmpty(object, 0);
	checkSize(object, 6);
	checkSet(object, 0, 40);
	checkSet(object, 1, 30);
	checkSet(object, 2, 20);
	checkSet(object, 3, 10);
	checkSet(object, 4, 11);
	checkSet(object, 5, 22);
	checkSet(object, 6, 3);
	checkSet(object, 7, 44);
	checkSize(object,6);
	checkRemove(object,3);
	checkRemove(object,2);
	checkRemove(object,4);
	checkRemove(object,3);
	checkRemove(object,1);
	checkRemove(object,0);
	checkSize(object,0);
	checkEmpty(object, 1);

	delete object;

}