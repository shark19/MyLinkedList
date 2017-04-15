#pragma once

#include "Element.h"
#include "Point.h"

template <class T>
class List
{
private: 
	unsigned int size;
	Element<T> *first, *last, *temp;
	typedef void(*to_string)(T);
	typedef int(*compare)(T, T);

public:
	List(void) :first(0), last(0), temp(0), size(0) {}
	~List(void) {}

	void add_start(T data) {
		if (!first) {
			first = new Element<T>(data);
		}
		else {
			temp = first;
			first = new Element<T>(data);
			first->next = temp;
			temp->previous = first;
			if (!temp->next) {
				last = temp;
			}
		}
		size++;
	}

	void add_end(T data) {
		if (!last) {
			if (first) {
				last = new Element<T>(data);
				first->next = last;
				last->previous = first;
			}
			else {
				first = new Element<T>(data);
			}
		}
		else {
			last->next = new Element<T>(data);
			last->next->previous = last;
			last = last->next;
		}
		size++;
	}

	void del_start() {
		temp = first;
		first = first->next;
		delete temp;
		temp = 0;
		size--;
	}

	void del_end() {
		switch (size) {
		case 0:
			return;
		case 1:
			delete first;
			first = 0;
			break;
		case 2:
			delete last;
			last = 0;
			break;
		default:
			temp = first;
			for (int i = 0; i < size - 2; i++) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = 0;
			last = temp;
		}
		size--;
	}

	void print(to_string single_item) {
		if (!first) {
			return;
		}
		temp = first;
		cout << "{";
		while (temp) {
			(single_item) (temp->data);
			temp = temp->next;
			if (temp) {
				cout << ", ";
			}
		}
		cout << "}" << endl;
	}

	unsigned int get_size() {
		return size;
	}

	T get_first(){
		return first->data;
	}

	T get_last(){
		return last->data;
	}

	T get_by_index(unsigned int index) {
		temp = first;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp->data;
	}

	void add_by_index(unsigned int index, T data) {
		if (index > size) { return; }
		if (index == 0) {
			add_start(data);
			return;
		}
		if (index == size) {
			add_end(data);
			return;
		}
		temp = first;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		temp->previous->next = new Element<T>(data);
		temp->previous->next->next = temp;
		temp->previous->next->previous = temp->previous->next;
		size++;
	}

	void del_by_index(unsigned int index){
		if (index > size-1) { return; }
		if (index == 0) {
			del_start();
			return;
		}
		if (index == size-1) {
			del_end();
			return;
		}
		temp = first;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		delete temp;
		temp = 0;
		size--;
	}

	void sort(compare pair){
		if (size < 2) {
			return;
		}
		temp = first;
		auto cur = *(temp->data);
		int i = 0;
		do {
			if (((pair)(temp->data, temp->next->data)) > 0) {
				cur = *(temp->data);
				*(temp->data) = *(temp->next->data);
				*(temp->next->data) = cur;
				temp = first;
				i = 0;
			}
			else {
				temp = temp->next;
				i++;
			}
		} while (i < size - 1);
	}
};

