// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include "conio.h"
#include "iostream"
#include "Point.h"
#include "El_mas.h"

using namespace std;

string point_to_string(Point *point) 
{
	return "(" + to_string(point->x) + ", " + to_string(point->y) + ")";
}

string int_to_string(int *a) 
{
	return to_string(*a);
}

int compare_int(int *a, int *b)
{
	return *a - *b;
}

int compare_point(Point *point1, Point *point2)
{
	return (point1->x + point1->y) - (point2->x + point2->y);
}

int main()
{
	List<int*> *list = new List<int*>();
	for (int i = 1; i < 6; i++) 
	{
		list->add_end(new int(i));
	}
	list->print(&int_to_string);
	list->clear();
	List<Point*> *pList = new List<Point*>();
	for (int i = 0; i < 5; i++) 
	{
		pList->add_end(new Point(i, i+10));
	}
	pList->print(&point_to_string);
	getch();
	pList->clear();
	return 0;
}