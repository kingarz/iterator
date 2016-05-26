#pragma once
#include "aghDlist.h"
//teeest

template<class T>
aghDlist<T>::aghDlist()
{
	head = NULL;
}

template<class T>
aghDlist<T>::~aghDlist()
{
	while (head != NULL)
	{
		remove(0);
	}
}

template<class T>
aghDlist<T>::aghDlist(const aghContainer<T>& value)
{
	head = NULL;
	for (int i = 0; i < value.size(); i++)
	{
		insert(i, value.at(i));
	}
}

template<class T>
bool aghDlist<T>::insert(int number, T const & value)
{
	if (number < 0 || number > size())
	{
		return false;
	}
	Dnode<T> *tmp = head;
	Dnode<T> *help;
	help = NULL;
	int pos = 0;
	while (tmp != NULL)
	{
		if (pos == number)
		{
			//dodawanie w srodku listy
			Dnode<T> *nowy;
			nowy = new Dnode<T>;
			//dodawanie na pocz,gdy nie ma poprzednika
			if (help == NULL)
			{
				nowy->next = tmp;
				nowy->prev = NULL;
				tmp->prev = nowy;
				nowy->next = tmp;
				head = nowy;
				return true;
			}
			//dodawanie na koniec
			if (tmp->next == NULL)
			{
				nowy->next = tmp;
				nowy->prev = tmp->prev;
				tmp->prev = nowy;
				nowy->prev->next = nowy;
				return true;
			}
			//dodawanie w srodku listy
			nowy->next = tmp;
			nowy->prev = tmp->prev;
			nowy->prev->next = nowy;
			tmp->prev = nowy;
			return true;
		}
		else
		{
			help = tmp;
			tmp = tmp->next;
			pos++;
		}
	}
	//tmp jest nullem,lista jest pusta
	tmp = new Dnode<T>;
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	head = tmp;
	return true;
}

template<class T>
T & aghDlist<T>::at(int index) const
{
	if (index < 0 || index > size())
	{
		throw aghException();
	}
	int pos = 0;
	Dnode<T> *tmp = head;
	while (tmp != NULL)
	{
		if (pos == index)
		{
			return tmp->value;
		}
		else
		{
			tmp = tmp->next;
			pos++;
		}
	}
	throw aghException();
}

template<class T>
int aghDlist<T>::size(void) const
{
	int pos = 0;
	Dnode<T> *tmp = head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		pos++;
	}
	return pos;
}

template<class T>
bool aghDlist<T>::remove(int index)
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

				if (tmp->prev == NULL)
				{
					head = NULL;
				}
				else
				{
					tmp->prev->next = NULL;
				}
				delete tmp;
			}
			else
			{
				Dnode<T> *nast = tmp->next;
				if (tmp->prev == NULL)
				{
					head = nast;
				}
				else
				{
					tmp->prev->next = nast;
				}
				tmp->next->prev = tmp->prev;
				delete tmp;
			}
			return true;
		}
		tmp->prev = tmp;
		pos++;
		tmp = tmp->next;
	}
	return false;
}


