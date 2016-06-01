#pragma once
#include "aghContainer.h"
#include "aghException.h"

template<class T>
class node
{
public:
	node *next;
	T value;
};

template <class T>
class aghSlist : public aghContainer<T>
{
public:
	//\\desc: konstruktor klasy aghSlist
	aghSlist();

	//\\desc: destruktor klasy aghSlist
	~aghSlist();

	//\\desc: konstruktor inicjalizujacy z value
	aghSlist(const aghContainer<T> &value);

	//\\desc: stawia obiekt w wybrane miejsce. 
	//\\param: int number - indeks na ktorym ma byc umieszczony obiekt.
	//\\param: T const &value - obiekt do umieszczenia.
	//\\return: bool - Zwraca true je¿eli podane miejsce wstawienia jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool insert(int number, T const& value);

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
	virtual aghSlist<T>& operator=(aghSlist<T> const& list);

private:
	node<T> *head;
};

#include "aghSlist_def.h"