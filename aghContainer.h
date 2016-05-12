#pragma once

template <class T>
class aghContainer
{
public:
	//\\desc: konstruktor klasy aghContainer.
	aghContainer();

	//\\desc: destruktor klasy aghContainer.
	virtual ~aghContainer() = 0;

	//\\desc: dodawanie na koniec.
	//\\param: T const &value - obiekt do umieszczenia w pojemniku.
	virtual void append(T const& value);

	//\\desc: stawia obiekt w wybrane miejsce. 
	//\\param: int number - indeks na ktorym ma byc umieszczony obiekt.
	//\\param: T const &value - obiekt do umieszczenia.
	//\\return: bool - Zwraca true je¿eli podane miejsce wstawienia jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool insert(int number, T const& value) = 0;

	//\\desc: podmienia podany obiekt z obiektem na wybranym miejscu. 
	//\\param: int number - indeks na ktorym ma byc umieszczony obiekt.
	//\\param: T const &value - obiekt do umieszczenia.
	//\\return: bool - Zwraca true je¿eli podane miejsce podmiany jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool replace(int, T const& value);

	//\\desc: funkcja dajaca dostep do obiektow w pojemniku.
	//\\param: int index - indeks z ktorego ma byc pobrany obiekt.
	//\\return: T& - zwraca referencje do obiektu na danym indeksie w pojeminku.
	virtual T& at(int index) const = 0;

	//\\return: int - zwraca iloœæ elementów w pojemniku.
	virtual int size(void) const = 0;

	//\\desc: usuwa element na danym miejscu. 
	//\\param: int index - indeks usuwanego obiektu.
	//\\return: bool - Zwraca true je¿eli podane miejsce usuniêcia jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool remove(int index) = 0;

	//\\desc: usuwa wszystkie elementy pojemnika.
	virtual void clear(void);

	//\\return: bool - zwraca true je¿eli pojemnik jest pusty, inaczej false.
	virtual bool isEmpty(void);

	//\\desc: wyszukuje indeks danego elementu w pojemniku.
	//\\param: T const& _value - szukany obiekt.
	//\\param: int _from = 0 - indeks od ktorego nalezy zaczac szukanie.
	//\\return: int - Zwraca indeks elementu o wartoœci _value.Je¿eli takiego elementu nie ma to zwraca -1.
	virtual int indexOf(T const& _value, int _from = 0) const;

	//\\desc: sprawdza czy jest dany element w pojemniku.
	//\\param: T const& _value - szukany obiekt.
	//\\param: int _from = 0 - indeks od ktorego nalezy zaczac szukanie.
	//\\return: bool - zwraca true je¿eli element o wartoœci _value znajduje siê w pojemniku inaczej zwraca false. 
	virtual bool contains(T const& _value, int _from = 0) const;

	//\\desc: sprawdza czy zawartoœæ pojemników jest taka sama.
	//\\param: aghContainer<T> const& right - pojemnik do porownania.
	//\\return: bool - zwraca true je¿eli pojemniki maja taka sama zawartosc w przeciwnym wypadku false. 
	virtual bool operator ==(aghContainer<T> const& right);

	//\\desc: sprawdza czy zawartoœæ pojemników jest rozna.
	//\\param: aghContainer<T> const& right - pojemnik do porownania.
	//\\return: bool - zwraca true je¿eli pojemniki maja rozna zawartosc w przeciwnym wypadku false. 
	virtual bool operator !=(aghContainer<T> const& right);

	//\\desc: operator dajacy dostep do obiektow w pojemniku.
	//\\param: int index - indeks z ktorego ma byc pobrany obiekt.
	//\\return: T& - zwraca referencje do obiektu na danym indeksie w pojeminku.
	virtual T& operator[](int index) const;

	//\\desc: dopisuje wszystkie elementy z pojemnika right. 
	//\\param: aghContainer<T> const& right - pojemnik do dodania.
	//\\return: aghContainer<T>& - zwraca referencje do pojemnika do ktorego zostaly dodane elementy.
	virtual aghContainer<T>& operator+=(aghContainer<T> const& right);

	//\\ dodaje element do pojemnika.
	//\\param: T const& element - element do dodania.
	//\\return: aghContainer<T>& - zwraca referencje do pojemnika do ktorego zostal dodany element.
	virtual aghContainer<T>& operator+=(T const& element);

	//\\ dodaje element do pojemnika.
	//\\param: T const& element - element do dodania.
	//\\return: aghContainer<T>& - zwraca referencje do pojemnika do ktorego zostal dodany element.
	virtual aghContainer<T>& operator<<(T const& element);

	//\\desc: dopisuje wszystkie elementy z pojemnika right. 
	//\\param: aghContainer<T> const& right - pojemnik do dodania.
	//\\return: aghContainer<T>& - zwraca referencje do pojemnika do ktorego zostaly dodane elementy.
	virtual aghContainer<T>& operator<<(aghContainer<T> const& right);

	//\\desc: operator przypisania. 
	//\\param: aghContainer<T> const& right - pojemnik do przypisania.
	//\\return: aghContainer<T>& - zwraca referencje do pojemnika na ktorym wywolano przypisanie.
	virtual aghContainer<T>& operator=(aghContainer<T> const& right);
};

#include "aghContainer_def.h"