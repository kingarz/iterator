#pragma once
#include<iostream>
#include "aghContainer.h"
#include "aghException.h"

using namespace std;

template <class T>
class aghVector : public aghContainer<T>
{
public:
	//\\ konstruktor klasy aghVector
	aghVector();

	//\\ destruktor klasy aghVector
	~aghVector();

	aghVector(const aghVector &value);

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

	virtual bool operator =(aghVector<T> const& right);
private:
	//\\ size- ilosc elementow
	int Size;

	//\\ tabsize - rozmiar wekora
	int tabsize;

	//\\ wskaznik na tablice przechowujaca elementy wektora
	T *tab;
};



template<class T>
aghVector<T>::aghVector()
{
	Size = 0;
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
	else if (Size+1 < tabsize)
	{
		for (int i = number ; i < Size -1 ; i++)
		{
			tab[i+1] = tab[i];
		}
		tab[number] = value;	
		Size += 1;
		return true;
	}
	else
	{
		tabsize = 2*tabsize + 1;
		tmp = new T [tabsize];
		for (int i = 0; i < Size; i++)
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
	if ((index > Size) || (index < 0))
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
	return Size;
}

template<class T>
bool aghVector<T>::remove(int index)
{
	if (index < 0 || index > Size)
	{
		return false;
	}
	else
	{
		for (int i = index; i < Size - 1; i++)
		{
			tab[i] = tab[i + 1];
		}
		return true;
	}
}

