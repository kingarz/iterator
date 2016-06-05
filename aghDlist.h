#pragma once
#include "aghContainer.h"
#include "aghException.h"

template <class T>
class Dnode
{
public:
	Dnode *next;
	Dnode *prev;
	T value;
};

template<class T>
class aghDlist : public aghContainer<T>
{
public:
	//\\desc: konstruktor klasy aghDlist
	aghDlist();

	//\\desc: destruktor klasy aghDlist
	~aghDlist();

	//\\desc: konstruktor inicjalizujacy z value
	aghDlist(const aghContainer<T> &value);

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
	virtual aghDlist<T>& operator=(aghDlist<T> const& list);

private:
	Dnode<T> *head;
};

#include "aghDlist_def.h"

