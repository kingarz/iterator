#pragma once

#include <algorithm> //min()

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
	Size = 0;
	tabsize = 0;
}

template<class T>
aghVector<T>::aghVector(const aghContainer<T>& value)
{
	tabsize = 0;
	Size = 0;
	tab = NULL;
	for (int i = 0; i < value.size(); i++)
	{
		this->append(value.at(i));
	}
}


template<class T>
bool aghVector<T>::insert(int number, T const & value)
{
	if (number < 0 || number > Size)
	{
		return false;
	}
	else if (Size + 1 < tabsize)
	{
		for (int i = number; i < Size; i++)
		{
			tab[i + 1] = tab[i];
		}

		tab[number] = value;
		Size += 1;
		return true;
	}
	else
	{
		tabsize = 2 * tabsize + 1;
		T *tmp;
		tmp = new T[tabsize];

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
	if ((index >= Size) || (index < 0))
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
	if (index < 0 || index >= Size)
	{
		return false;
	}
	else
	{
		for (int i = index; i < Size - 1; i++)
		{
			tab[i] = tab[i + 1];
		}
		Size = Size - 1;
		return true;
	}
}

template<class T>
aghVector<T>& aghVector<T>::operator=(aghVector<T> const & right)
{
	if (tab != NULL)
	{
		delete[] tab;
		tab = NULL;
	}

	this->Size = right.Size;
	this->tabsize = right.tabsize;

	if (tabsize > 0)
	{
		tab = new T[tabsize];
	}

	for (int i = 0; i < Size; i++)
	{
		tab[i] = right.tab[i];
	}

	return *this;
}

