// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include "conio.h"
#include "iostream"
#include "Point.h"
#include "El_mas.h"

using namespace std;

void point_to_string(Point *point) {
	cout << "(" << point->x << ", " << point->y << ")";
}

void el_mas_to_string(El_mas *mas) {
	cout << "(" << mas->num << ", " << mas->j << ")";
}

void int_to_string(int *a) {
	cout << *a << " ";
}

int compare_int(int *a, int *b){
	return *a - *b;
}

int compare_point(Point *point1, Point *point2){
	return (point1->x + point1->y) - (point2->x + point2->y);
}

void list_with_list_to_string(List<El_mas*> *list) {
	for (int i = 0; i < list->get_size(); i++) {
		el_mas_to_string(list->get_by_index(i));
		cout << " ";
	}
	cout << "\n";
}

int main()
{
	//List<int*> *list = new List<int*>();
	//list->add_end(new int(3));
	//list->add_end(new int(2));
	//list->add_end(new int(5));
	//list->add_end(new int(1));
	//list->add_by_index(3, new int(7));
	//list->print(&int_to_string);
	//list->sort(&compare_int);
	//list->print(&int_to_string);
	List<List<El_mas*>*> *list = new List<List<El_mas*>*>();
	list->add_end(new List<El_mas*>());
	list->add_end(new List<El_mas*>());
	list->add_end(new List<El_mas*>());
	list->add_end(new List<El_mas*>());
	list->add_end(new List<El_mas*>());
	for (int i = 0; i < list->get_size(); i++) {
		List<El_mas*> *ilist = list->get_by_index(i);
		for (int i = 0; i < 4; i++) {
			ilist->add_end(new El_mas(1, 2));
			ilist->add_end(new El_mas(3, 4));
			ilist->add_end(new El_mas(5, 6));
		}
	}
	list->print(&list_with_list_to_string);
	getch();
	delete list;
	return 0;
}