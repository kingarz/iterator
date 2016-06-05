#include "aghIterator.h"
#pragma once

template<class T>
aghIterator<T>::aghIterator()
{
	position = 0;
	pointer = NULL;
}

template<class T>
aghIterator<T>& aghIterator<T>::first()
{
	position = 0;
	return *this;
}

template<class T>
aghIterator<T>& aghIterator<T>::last()
{
	position = pointer->size() - 1;
	return *this;
}

template<class T>
void aghIterator<T>::next()
{
	position += 1;
}

template<class T>
void aghIterator<T>::prev()
{
	position -= 1;
}

template<class T>
T& aghIterator<T>::current()
{
	return pointer->at(position);
}

template<class T>
void aghIterator<T>::atFirst()
{
	position = 0;
}

template<class T>
void aghIterator<T>::atLast()
{
	position = pointer->size() - 1;
}

template<class T>
int aghIterator<T>::size()
{
	return pointer->size() - position;
}

template<class T>
aghIterator<T>& aghIterator<T>::operator=(aghContainer<T> const & value)
{
	pointer = &value;
}


template<class T>
bool aghIterator<T>::operator==(aghIterator<T> const & value)
{
	if ((pointer == value->pointer) && (position == value->position))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool aghIterator<T>::operator!=(aghIterator<T> const & value)
{
	if (this == value)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<class T>
T & aghIterator<T>::operator*()
{
	//zwraca akt pokazywany element
	return this->current();
}

template<class T>
T & aghIterator<T>::operator[](int position)
{
	//zwraca element znajduj¹cy siê o i pozycji dalej wzglêdem aktualnego elementu
	this->position += position;
	return this->operator*;
}

template<class T>
aghIterator<T>& aghIterator<T>::operator+(int position)
{
	//zwraca iterator przesuniêty o i elementów dalej
	this->position += position;
	return *this;
}

template<class T>
void aghIterator<T>::operator+=(int position)
{
	// przesuwa iterator o i elementów dalej.
	this->position += position;
}

template<class T>
aghIterator<T> & aghIterator<T>::operator--(int position)
{
	//zwraca iterator pokazuj¹cy na i-ty element a nastêpnie przesuwa iterator na i-1 element
	this->position = position;
	aghIterator<T> actual;
	actual->pointer = pointer;
	actual->position = this->position;
	this->position -= 1;
	return *actual;
}

template<class T>
void aghIterator<T>::operator-=(int position)
{
	//przesuwa iterator o i elementów wczeœniej
	this->position -= position;
}

template<class T>
aghIterator<T>& aghIterator<T>::operator++(int position)
{
	// zwraca iterator pokazuj¹cy na i-ty element a nastêpnie przesuwa iterator na i+1 element
	this->position = position;
	aghIterator<T> actual;
	actual->pointer = pointer;
	actual->position = position;
	this->position += 1;
	return *actual;
}

template<class T>
aghIterator<T>& aghIterator<T>::operator++()
{
	//przesuwa iterator na i+1 element i zwraca iterator pokazuj¹cy na i+1 element
	position += 1;
	return *this;
}

template<class T>
aghIterator<T>& aghIterator<T>::operator--()
{
	// przesuwa iterator na i-1 element i zwraca iterator pokazuj¹cy na i-1 element
	position -= 1;
	return *this;
}

template<class T>
aghIterator<T> & aghIterator<T>::operator-(int position)
{
	//zwraca iterator przesuniêty o i elementów bli¿ej
	this->position -= position;
	return *this;
}

template<class T>
aghIterator<T>::operator int()
{
	return this->pointer;
	//zwraca pointer wskazujacy na kontener
}
