#pragma once
#include<iostream>
#include "aghContainer.h"
#include "aghException.h"

using namespace std;

template <class T>
class aghVector : public aghContainer<T>
{
public:
	//\\desc: konstruktor klasy aghVector
	aghVector();

	//\\desc: destruktor klasy aghVector
	~aghVector();

	//\\desc: konstruktor inicjalizujacy z value
	aghVector(const aghVector<T> &value);

	//\\desc: konstruktor inicjalizujacy z value
	aghVector(const aghContainer<T> &value);

	//\\desc: stawia obiekt w wybrane miejsce. 
	//\\param: int number - indeks na ktorym ma byc umieszczony obiekt.
	//\\param: T const &value - obiekt do umieszczenia.
	//\\return: bool - Zwraca true je¿eli podane miejsce wstawienia jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool insert(int number, T const &value);

	//\\desc: funkcja dajaca dostep do obiektow w pojemniku.
	//\\param: int index - indeks z ktorego ma byc pobrany obiekt.
	//\\return: T& - zwraca referencje do obiektu na danym indeksie w pojeminku.
	virtual T& at(int index) const;

	//\\return: int - zwraca iloœæ elementów w pojemniku.
	virtual int size(void) const;

	//\\desc: usuwa element na danym miejscu. 
	//\\param: int index - indeks usuwanego obiektu.
	//\\return: bool - Zwraca true je¿eli podane miejsce usuniêcia jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool remove(int index);

	//\\desc: operator przypisania. 
	//\\param: aghVector<T> const& right - pojemnik do przypisania.
	//\\return: aghVector<T>& - zwraca referencje do pojemnika na ktorym wywolano przypisanie.
	virtual aghVector<T>& operator =(aghVector<T> const& right);

	//\\desc: operator przypisania. 
	//\\param: aghContainer<T> const& right - pojemnik do przypisania.
	//\\return: aghVector<T>& - zwraca referencje do pojemnika na ktorym wywolano przypisanie.
	virtual aghVector<T>& operator =(aghContainer<T> const& right);
private:
	//\\ size- ilosc elementow
	int Size;

	//\\ tabsize - rozmiar wektora
	int tabsize;

	//\\ wskaznik na tablice przechowujaca elementy wektora
	T *tab;
};

#include "aghVector_def.h"