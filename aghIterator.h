#pragma once
#include "aghContainer.h"

template<class T>
class aghIterator
{
public:
	aghIterator();
	aghIterator<T>& first();
	aghIterator<T>& last();
	void next();
	void prev();
	T& current();
	void atFirst();
	void atLast();
	int size();
	aghIterator<T>& operator=(aghContainer<T> const& value);
	bool operator==(aghIterator<T> const& value);
	bool operator!=(aghIterator<T> const& value);
	T& operator*();
	T& operator[](int position);
	aghIterator& operator+(int position);
	void operator+=(int position);
	aghIterator<T>& operator--(int position);
	void operator-=(int position);
	aghIterator<T>& operator++(int position);
	aghIterator<T>& operator++();
	aghIterator<T>& operator--();
	aghIterator<T>& operator-(int position);
	int operator int();
private:
	int position;
	aghContainer<T> *pointer;
};

#include "aghIterator_def.h"


