#include "aghVector.h"
#include<iostream>
using namespace std;

template<class T>
aghVector<T>::aghVector()
{
	size = 0;
	tab = NULL;
}

template<class T>
aghVector<T>::~aghVector()
{
	if (size == 0)
	{
		delete[] tab;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			delete[] tab[i];
		}
		delete[] tab;
	}
}

template<class T>
void aghVector<T>::append(T const & value)
{
	if (size == 0)
	{
		tab[0] = value;
		size += 1;
	}
	else
	{
		tab[size - 1] = value;
		size += 1;

	}
}

template<class T>
bool aghVector<T>::insert(int number, T const &value)
{
	if (number < 0 || number >= size)
	{
		return false;
	}
	else
	{
		tab[number] = value;
		return true;
	}
}

template<class T>
bool aghVector<T>::replace(int, T const &)
{
	
}

template<class T>
T & aghVector<T>::at(int number) const
{
	if (number < 0 || number >= size - 1)
	{
		//wyjatek/bledny numer
	}
	else
	{
		return tab[number];
	}
}

template<class T>
int aghVector<T>::size(void) const
{
	return size;
}

template<class T>
bool aghVector<T>::remove(int number)
{
	if (!insert())
	{
		return false;
	}
	else
	{
		delete[] tab[number];
		//poprzesuwanie elementow w wektorze
		for (int i = number; i< size; i++)
		{
			tab[i] = tab[i+1]
		}
		size = size - 1;
		return true;
	}
}

template<class T>
void aghVector<T>::clear(void)
{
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] tab[i];
		}
		delete[] tab;
	}
	else
	{
		delete[] tab;
	}
}

template<class T>
bool aghVector<T>::isEmpty(void)
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
int aghVector<T>::indexOf(T const & _value, int _from) const
{
	for (int i = _from; i < size; i++)
	{
		if (tab[i] == _value)
		{
			return i;
			break;
		}
	}
	return -1;
}

template<class T>
bool aghVector<T>::contains(T const & _value, int _from) const
{
	for (int i = _from; i < size; i++)
	{
		if (tab[i] == _value)
		{
			return true;
		}
	}
	return false;
}














