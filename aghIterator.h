#pragma once
#include "aghContainer.h"

template<class T>
class aghIterator
{
public:
	aghIterator();
	aghIterator(aghContainer<T> *value);
	aghIterator<T> first();
	aghIterator<T> last();
	aghIterator<T>& next();
	void prev();
	T& current();
	aghIterator<T>& atFirst();
	aghIterator<T>& atLast();
	int size();
	aghIterator<T>& operator=(aghContainer<T> const& value);
	bool operator==(aghIterator<T> const& value);
	bool operator!=(aghIterator<T> const& value);
	T& operator*();
	T& operator[](int position);
	aghIterator operator+(int position);
	void operator+=(int position);
	aghIterator<T> operator--(int position);
	void operator-=(int position);
	aghIterator<T> operator++(int position);
	aghIterator<T>& operator++();
	aghIterator<T>& operator--();
	aghIterator<T> operator-(int position);
	operator int();
private:
	int position;
	aghContainer<T> *pointer;
};

#include "aghIterator_def.h"


