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
				//na pocz i na koniec, czyli jak list ma jeden element
				if (tmp->next == NULL)
				{
					nowy->value = value;
					nowy->prev = tmp->prev;
					tmp->prev = nowy;
					nowy->next = tmp;
				}
				nowy->value = value;
				nowy->next = tmp;
				nowy->prev = NULL;
				tmp->prev = nowy;
				head = nowy;
				return true;	
			}
			//dodawanie na koniec
			if (tmp->next == NULL)
			{
				nowy->value = value;
				nowy->next = tmp;
				nowy->prev = tmp->prev;
				tmp->prev = nowy;
				nowy->prev->next = nowy;
				return true;
			}
			//dodawanie w srodku listy
			help = tmp->prev;
			nowy->next = tmp;
			nowy->prev = help;
			help->next = nowy;
			tmp->prev = nowy;
			nowy->value = value;
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
	if (help != NULL)
	{
		help->next = tmp;
		tmp->prev = help;
	}
	if (help == NULL)
	{
		head = tmp;
		tmp->prev = NULL;
	}
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
	Dnode<T> *poprz = NULL;
	int pos = 0;
	while (tmp != NULL)
	{
		if (pos == index)
		{
			//spr czy usuwamy z konca
			if (tmp->next == NULL)
			{
				//czy usuwamy z konca i pocz
				if (tmp->prev == NULL)
				{
					head = NULL;
					delete tmp;
				}
				else
				{
					tmp->prev->next = NULL;
					delete tmp;
				}
				
				return true;
			}
			else
				//usuwamy nie z konca
			{
				//gdy usuwamy tylko z samego poczatku , na pewno nie jest lista 1elem
				if (tmp->prev == NULL)
				{
					head = tmp->next;
					tmp->next->prev = NULL;
					delete tmp;
					return true;
				}
				//usuwamy ze srodka listy
				Dnode<T> *nast = tmp->next;
				poprz = tmp->prev;
				poprz->next = nast;
				nast->prev = poprz;
				delete tmp;
				return true;
			}
		}
		poprz = tmp;
		pos++;
		tmp = tmp->next;
	}
	return false;
}


template<class T>
aghDlist<T>& aghDlist<T>::operator=(const aghDlist<T>& list)
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

