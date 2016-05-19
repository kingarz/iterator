#pragma once
#include "aghContainer.h"
#include "aghException.h"

template<class T>
class node
{
public:
	node *next;
	T value;
};

template <class T>
class aghSlist : public aghContainer<T>
{
public:
	aghSlist();
	~aghSlist();
	aghSlist(const aghContainer<T> &value);
	virtual bool insert(int number, T const& value);
	virtual T& at(int index) const;
	virtual int size(void) const;
	virtual bool remove(int index);


private:
	node<T> *head;
};

#include "aghSlist_def.h"