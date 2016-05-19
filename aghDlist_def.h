#pragma once
#include "aghDlist.h"

template<class T>
Dlist<T>::aghDlist()
{
	head = NULL;
}

template<class T>
Dlist<T>::~aghDlist()
{
	while (head != NULL)
	{
		remove(0);
	}
}

template<class T>
Dlist<T>::aghDlist(const aghContainer<T>& value)
{
	head = NULL;
	for (int i = 0; i < value->size(); i++)
	{
		insert(i, value->at(i));
	}
}

template<class T>
bool Dlist<T>::insert(int number, T const & value)
{
	if (number < 0 || number > size())
	{
		return false;
	}
	Dnode<T> *tmp = head;
	Dnode<T> *help = tmp;
	int pos = 0;
	while (tmp != NULL)
	{
		if (pos == number)
		{
			Dnode<T> *nowy;
			nowy = new Dnode<T>;
			nowy->value = value;
			nowy->next = tmp;
			nowy->prev = tmp->prev;
			return true;
		}
		else
		{
			tmp = tmp->next;
			tmp->prev = help;
			tmp->next = help->next;
			pos++;
		}
	}
	tmp = new Dnode<T>;
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (tmp->prev == NULL)
	{
		head = tmp;
	}
	else
	{
		tmp->prev->next = tmp;
	}
	return true;
}

template<class T>
T & Dlist<T>::at(int index) const
{
	if (index < 0 || index > size())
	{
		throw aghException();
	}
	int pos = 0;
	Dnode<T> *tmp = head;
	Dnode<T> *help = temp;
	while (tmp != NULL)
	{
		if (pos == index)
		{
			return tmp->value;
		}
		else
		{
			tmp = tmp->next;
			tmp->prev = help; 
			help->next = tmp;
			pos++;
		}
	}
	throw aghException();
}

template<class T>
int Dlist<T>::size(void) const
{
	int pos = 0;
	Dnode<T> *tmp = head;
	Dnode<T> *help = tmp;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		tmp->prev = help;
		help->next = tmp;
		pos++;
	}
	return pos;
}

template<class T>
bool Dlist<T>::remove(int index)
{
	if (index < 0 || index > size())
	{
		return false;
	}
	Dnode<T> *tmp = head;
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
					tmp->prev->next = NULL;
				}
			}
			else
			{
				Dnode<T> *nast = tmp->next;
				delete tmp;
				if (prev == NULL)
				{
					head = nast;
				}
				else
				{
					tmp->prev->next = nast;
				}
			}
			return true;
		}
		tmp->prev = tmp;
		pos++;
		tmp = tmp->next;
	}
	return false;
}


