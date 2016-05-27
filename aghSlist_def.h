#include "aghSlist.h"
#pragma once

//test testooooooooooooooooooooooooooow
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
	node<T> *tmp = head;
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
			//dodawanie na pocz
			if (prev == NULL)
			{
				//dod na koniec i pocz jednoczesnie, gdy lista ma elem
				if (tmp->next == NULL)
				{
					nowy->next = tmp;
					prev = nowy;
					head = nowy;
					return true;
				}
				nowy->next = tmp;
				prev = nowy;
				head = nowy;
				return true;
			}
			//dodawanie na sam koniec
			if (tmp->next == NULL)
			{
				nowy->next = tmp;
				prev = nowy;
				return true;
			}
			//dodawanie w srodku listy
			prev = nowy;
			nowy->next = tmp;
			return true;
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
			pos++;
		}
	}
	//tmp jest nullem,lista jest pusta
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



template<class T>
aghSlist<T>& aghSlist<T>::operator=(const aghSlist<T>& list)
{
	int tsize = size();
	int lsize = list.size();

	for (int i = 0; i < min(lsize, tsize); i++)
	{
		at(i) = list.at(i);
	}

	if (lsize > tsize)
	{
		for (int i = tsize; i < lsize; i++)
		{
			append(list.at(i));
		}
	}
	else if (lsize < tsize)
	{
		for (int i = lsize; i < tsize; i++)
		{
			remove(i);
		}
	}

	return *this;
}
