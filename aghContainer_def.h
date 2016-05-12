#pragma once


template<class T>
aghContainer<T>::aghContainer()
{

}

template<class T>
aghContainer<T>::~aghContainer()
{

}


template<class T>
void aghContainer<T>::append(T const & value)
{
	insert(size(), value);
}

template<class T>
bool aghContainer<T>::replace(int number, T const &value)
{
	if (number < 0 || number >= size())
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
	if (_from < 0 || _from > size())
	{
		return -1;
	}
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
	bool found;
	for (int i = 0; i < size(); i++)
	{
		found = false;
		for (int j = 0; j < right.size(); j++)
		{
			if (this->at(i) != right.at(j))
			{
				continue;
			}
			else
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			return false;
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
	int _size = size();
	int _rsize = right.size();

	for (int i = 0; i < min(_rsize, _size); i++)
	{
		at(i) = right.at(i);
	}

	if (_rsize > _size)
	{
		for (int i = _size; i < _rsize; i++)
		{
			append(right.at(i));
		}
	}
	else if (_rsize < _size)
	{
		for (int i = _rsize; i < _size; i++)
		{
			remove(i);
		}
	}

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
