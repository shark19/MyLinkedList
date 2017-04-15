#pragma once

template <class T>
class Element
{
public:
	Element(void): data(0), next(0), previous(0) {}
	Element(T content): data(content), next(0), previous(0) {}
	~Element(void) {}
	T data;
	Element *next, *previous;
};

