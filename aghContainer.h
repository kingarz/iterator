#pragma once

template <class T>
class aghContainer
{
public:
	//\\konstruktor klasy aghContainer
	 aghContainer();

	//\\ destruktor klasy aghContainer
	virtual ~aghContainer() = 0;

	aghContainer(const aghContainer<T>& right);

	//\\dodawanie podanego jako argument obiektu typu T do pojemnika
	virtual void append(T const &value);

	//\\stawia obiekt typu T w wybrane miejsce. Zwraca true je¿eli podane miejsce wstawienia jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool insert(int number, T const &value) = 0;

	//\\ podmienia obiekt typu T z obiektem na wybranym miejscu. Zwraca true je¿eli podane miejsce podmiany jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool replace(int, T const&);

	//\\ zwraca wartoœæ w pojemniku
	virtual T& at(int) const = 0;

	//\\zwraca iloœæ elementów w pojemniku
	virtual int size(void) const = 0;

	//\\ usuwa element na danym miejscu. Zwraca true je¿eli podane miejsce usuniêcia jest prawid³owe, w przeciwnym wypadku zwraca false.
	virtual bool remove(int) = 0;

	//\\ usuwa wszystkie elementy pojemnika
	virtual void clear(void);

	//\\zwraca true je¿eli pojemnik jest pusty, inaczej false
	virtual bool isEmpty(void);

	//\\wyszukuje i zwraca indeks pierwszego elementu o wartoœci _value zaczynaj¹c od elementu _from. Je¿eli takiego elementu nie ma to zwraca -1
	virtual int indexOf(T const& _value, int _from = 0) const;

	//\\ zwraca true je¿eli element o wartoœci _value znajduje siê w pojemniku inaczej zwraca false. Wyszukiwanie rozpoczyna siê od elelmetnu _from
	virtual bool contains(T const& _value, int _from = 0) const;

	//\\ sprawdza czy zawartoœæ pojemników jest taka sama
	virtual bool operator ==(aghContainer<T> const& right);

	//\\ sprawdza czy zawartoœæ pojemników jest ró¿na
	virtual bool operator !=(aghContainer<T> const& right);

	//\\ zwraca element o indeksie n
	virtual T& operator[](int n) const;
	//\\ dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this
	virtual aghContainer<T>& operator+=(aghContainer<T> const& right);

	//\\ dodaje element do pojemnika i zwraca referencje do this
	virtual aghContainer<T>& operator+=(T const& element);

	//\\ dodaje element do pojemnika i zwraca referencje do this
	virtual aghContainer<T>& operator<<(T const& element);

	//\\ dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this
	virtual aghContainer<T>& operator<<(aghContainer<T> const& right);

	virtual aghContainer<T>& operator=(const aghContainer<T>& right);
};

template<class T>
aghContainer<T>::aghContainer()
{

}

template<class T>
aghContainer<T>::aghContainer(const aghContainer<T>& right)
{

}

template<class T>
void aghContainer<T>::append(T const & value)
{
	insert(size() - 1, value);
}

template<class T>
bool aghContainer<T>::replace(int number, T const &value)
{
	if (number <0 || number > size())
	{
		return false;
	}
	else
	{
		remove(number);
		insert(number, value);
		return true;
	}
}

template<class T>
void aghContainer<T>::clear(void)
{
	for (int i = size() - 1; i >= 0; i--)
	{
		remove(i);
	}
}

template<class T>
bool aghContainer<T>::isEmpty(void)
{
	if (size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
int aghContainer<T>::indexOf(T const & _value, int _from) const
{
	for (int i = _from; i < size(); i++)
	{
		if (at(i) == _value)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
bool aghContainer<T>::contains(T const & _value, int _from) const
{
	for (int i = _from; i < size(); i++)
	{
		if (at(i) == _value)
		{
			return true;
		}
	}
	return false;
}

template<class T>
bool aghContainer<T>::operator==(aghContainer<T> const & right)
{
	for (int i = 0; i < size(); i++)
	{
		for (int j = 0; j < right.size(); j++)
		{
			if (this->at(i) != right.at(j))
			{
				return false;
			}
		}
	}
	return true;
}

template<class T>
bool aghContainer<T>::operator!=(aghContainer<T> const & right)
{
	if (*this == right)
	{
		return false;
	}
	return true;
}

template<class T>
T & aghContainer<T>::operator[](int n) const
{
	return at(n);
}

template<class T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const & right)
{
	for (int i = 0; i < right.size(); i++)
	{
		append(at(i));
	}
	return *this;
}

template<class T>
aghContainer<T>& aghContainer<T>::operator+=(T const & element)
{
	append(element);
	return *this;
}

template<class T>
aghContainer<T>& aghContainer<T>::operator<<(T const & element)
{
	append(element);
	return *this;
}

template<class T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const & right)
{
	*this += right;
	return *this;
}

template<class T>
aghContainer<T>& aghContainer<T>::operator=(const aghContainer<T>& right)
{
	return *this;
}

template<class T>
ostream & operator<<(ostream &out, aghContainer<T> const & right)
{
	for (int i = 0; i < right.size(); i++)
	{
		out << right.at(i);
	}
	return out;
}
