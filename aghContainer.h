#pragma once

template <class T>
class aghContainer
{
	void append(T const&);
	bool insert(int, T const&);
	bool replace(int, T const&);
	T& at(int) const;
	int size(void) const;
	bool remove(int);
	void clear(void);
	bool isEmpty(void);
	int indexOf(T const& _value, int _from = 0) const;
	bool contains(T const& _value, int _from = 0) const;
	bool operator ==(aghContainer<T> const& right);
	bool operator !=(aghContainer<T> const& right);
	T& operator[](int n) const;
	aghContainer<T>& operator+=(aghContainer<T> const& right);
	aghContainer<T>& operator+=(T const& element);
	aghContainer<T>& operator<<(T const& element);
	aghContainer<T>& operator<<(aghContainer<T> const& right);
	ostream& operator<<(ostream&,aghContainer<T> const& right);


};