#pragma once
#include "aghContainer.h"

template <class T>
class aghVector : public aghContainer
{
public:
	//\\ konstruktor klasy aghVector
	aghVector();
	//\\ destruktor klasy aghVector
	~aghVector();
	//\\dodawanie podanego jako argument obiektu typu T do pojemnika
	void append(T const &value);
	//\\wstawia obiekt typu T w wybrane miejsce. Zwraca true je¿eli podane miejsce wstawienia jest prawid³owe, w przeciwnym wypadku zwraca false.
	//\\number- numer miejsca, w ktore podstawiamy wartosc okreslona przez argument value
	bool insert(int number, T const &value);
	//\\ podmienia obiekt typu T z obiektem na wybranym miejscu. Zwraca true je¿eli podane miejsce podmiany jest prawid³owe, w przeciwnym wypadku zwraca false.
	bool replace(int, T const&);
	//\\ zwraca wartoœæ w pojemniku, number- nr elementu wektora,ktorego wartosc chcemy zwrocic
	T& at(int number) const;
	//\\zwraca iloœæ elementów w pojemniku
	int size(void) const;
	//\\ usuwa element na danym miejscu. Zwraca true je¿eli podane miejsce usuniêcia jest prawid³owe, w przeciwnym wypadku zwraca false.
	bool remove(int number);
	//\\ usuwa wszystkie elementy pojemnika
	void clear(void);
	//\\zwraca true je¿eli pojemnik jest pusty, inaczej false
	bool isEmpty(void);
	//\\wyszukuje i zwraca indeks pierwszego elementu o wartoœci _value zaczynaj¹c od elementu _from. Je¿eli takiego elementu nie ma to zwraca -1
	int indexOf(T const& _value, int _from = 0) const;
	//\\ zwraca true je¿eli element o wartoœci _value znajduje siê w pojemniku inaczej zwraca false. Wyszukiwanie rozpoczyna siê od elelmetnu _from
	bool contains(T const& _value, int _from = 0) const;
	//\\ sprawdza czy zawartoœæ pojemników jest taka sama
	bool operator ==(aghContainer<T> const& right);
	//\\ sprawdza czy zawartoœæ pojemników jest ró¿na
	bool operator !=(aghContainer<T> const& right);
	//\\ zwraca element o indeksie n
	T& operator[](int n) const;
	//\\ dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this
	aghContainer<T>& operator+=(aghContainer<T> const& right);
	//\\ dodaje element do pojemnika i zwraca referencje do this
	aghContainer<T>& operator+=(T const& element);
	//\\ dodaje element do pojemnika i zwraca referencje do this
	aghContainer<T>& operator<<(T const& element);
	//\\ dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this
	aghContainer<T>& operator<<(aghContainer<T> const& right);
	//\\ wypisuje zawartoœæ pojemnika na strumieñ
	ostream& operator<<(ostream&, aghContainer<T> const& right);
private:
	//\\size- rozmiar wektora
	int size;
	//\\ wskaznik na tablice przechowujaca elementy wektora
	T *tab;
};
