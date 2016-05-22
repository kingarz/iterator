#include "aghSlist.h"
#pragma once

template<class T>
aghSlist<T>::aghSlist()
{
	head = NULL;
}

template<class T>
aghSlist<T>::~aghSlist()
{
	while (head != NULL)
	{
		remove(0);
	}
}

template<class T>
aghSlist<T>::aghSlist(const aghContainer<T> & value)
{
	head = NULL;
	for (int i = 0; i < value.size(); i++)
	{
		insert(i, value.at(i));
	}
}

template<class T>
bool aghSlist<T>::insert(int number, T const & value)
{
	if (number < 0 || number > size())
	{
		return false;
	}
	node<T> *tmp;
	tmp = head;
	node<T> *prev;
	prev = NULL;
	int pos = 0;
	while (tmp != NULL)
	{
		if (pos == number)
		{
			node<T> *nowy;
			nowy = new node<T>;
			nowy->value = value;
			nowy->next = tmp;
			prev->next = nowy;
			return true;
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
			pos++;
		}
	}
	tmp = new node<T>;
	tmp->value = value;
	tmp->next = NULL;
	if (prev != NULL)
	{
		prev->next = tmp;
	}
	if (prev == NULL)
	{
		head = tmp;
	}
	return true;
}

template<class T>
T & aghSlist<T>::at(int index) const
{
	if (index < 0 || index > size())
	{
		throw aghException();
	}
	int pos = 0;
	node<T> *tmp = head;
	while(tmp != NULL)
	{
		if (pos == index)
		{
			return tmp->value;
		}
		else
		{
			pos++;
			tmp = tmp->next;
		}
	}
	throw aghException();
}

template<class T>
int aghSlist<T>::size(void) const
{
	int pos = 0;
	node<T> *tmp = head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		pos++;
	}
	return pos;
}

template<class T>
bool aghSlist<T>::remove(int index)
{
	if (index < 0 || index > size())
	{
		return false;
	}
	node<T> *tmp = head;
	node<T> *prev = NULL;
	int pos = 0;
	while (tmp != NULL)
	{
		if (pos == index)
		{
			if (tmp->next == NULL)
			{
				delete tmp;
				if (prev == NULL)
				{
					head = NULL;
				}
				else
				{
					prev->next = NULL;
				}
			}
			else
			{
				node<T> *nast = tmp->next;
				delete tmp;
				if (prev == NULL)
				{
					head = nast;
				}
				else
				{
					prev->next = nast;
				}
			}
			return true;
		}
		prev = tmp;
		pos++;
		tmp = tmp->next;
	}
	return false;
}
