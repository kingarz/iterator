#pragma once
#include<iostream>
#include "aghContainer.h"
#include "aghException.h"

using namespace std;

template <class T>
class aghVector : public aghContainer
{
public:
	//\\ konstruktor klasy aghVector
	aghVector();

	//\\ destruktor klasy aghVector
	~aghVector();

	//\\ wstawia obiekt typu T w wybrane miejsce
	//\\ Zwraca true je¿eli podane miejsce wstawienia jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool insert(int number, T const &value);

	//\\ zwraca wartoœæ w pojemniku
	virtual T& at(int index) const;

	//\\zwraca iloœæ elementów w pojemniku
	virtual int size(void) const;

	//\\ usuwa element na danym miejscu
	//\\ Zwraca true je¿eli podane miejsce usuniêcia jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool remove(int index);

private:
	//\\ size- ilosc elementow
	int size;

	//\\ tabsize - rozmiar wekora
	int tabsize;

	//\\ wskaznik na tablice przechowujaca elementy wektora
	T *tab;
};



template<class T>
aghVector<T>::aghVector()
{
	size = 0;
	tabsize = 0;
	tab = NULL;
}

template<class T>
aghVector<T>::~aghVector()
{
	if (tab != NULL)
	{
		delete[] tab;
	}
	tab = NULL;
}


template<class T>
bool aghVector<T>::insert(int number, T const & value)
{
	if (number < 0 || number > size())
	{
		return false;
	}
	else if (size+1 < tabsize)
	{
		for (int i = number ; i < size -1 ; i++)
		{
			tab[i+1] = tab[i];
		}
		tab[number] = value;	
		size += 1;
		return true;
	}
	else
	{
		tabsize = 2*tabsize + 1;
		tmp = new T [tabsize];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = tab[i];
		}
		delete[] tab;
		tab = tmp;
		return insert(number, value);
	}
}

template<class T>
T & aghVector<T>::at(int index) const
{
	if ((index > size) || (index < 0))
	{
		throw aghException();
	}
	else
	{
		return tab[index];
	}
}

template<class T>
int aghVector<T>::size(void) const
{
	return size;
}

template<class T>
bool aghVector<T>::remove(int index)
{
	if (index < 0 || index > size)
	{
		return false;
	}
	else
	{
		for (int i = index; i < size - 1; i++)
		{
			tab[i] = tab[i + 1];
		}
		return true;
	}
}

