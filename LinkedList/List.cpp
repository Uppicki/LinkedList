#include "List.h"

#include <iostream>

#include <string>

#define I template <class T> inline
#define L List<T>


I L::List()
{
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

I int L::getSize()
{
	return this->size;
}


//Inserts funcs
I void L::add(T element)
{
	insert(size, element);
}
I void L::add(int index, T element)
{
	insert(index, element);
}
I void L::addFirst(T element)
{
	insert(0, element);
}
I void L::addLast(T element)
{
	insert(size, element);
}


I void L::clear()
{
	_clearAll();
}


I bool L::contains(T value)
{
	element* el = head;
	for (int i = 0; i < size; i++)
	{
		std::cout << "Index: " << i << " Value: " << el->value << " Addr: " << el;
		std::cout << " Xext: " << el->nextElement << " Prev: " << el->prevElement << "\n";
		if (el->value == value)
		{
			return true;
		};
		el = el->nextElement;
	}
	return false;
}


I T L::get(int index)
{
	return _get(index);
}
I T L::getFirst()
{
	return get(0);
}
I T L::getLast()
{
	return get(size-1);
}


I T L::remove(T value)
{
	return _remove(value, true, false);
}
I T L::removeAll(T value)
{
	return _remove(value, true, true);
}
I T L::removeLast(T value)
{
	return _remove(value, false, false);
}
I T L::removeFirst()
{
	return removeIndex(0);
}
I T L::removeLast()
{
	return removeIndex(size-1);
}
I T L::removeIndex(int index)
{
	return _removeIndex(index);
}



//private
I void L::insert(int index, T value)
{
	if (index >= 0 && index <= size)
	{
		if (listIsEmpy())
		{
			element* el = new element(value);
			head = el;
			tail = el;
		}
		else if (index == 0)
		{
			_insertFirst(value);
		}
		else if (index = size) 
		{
			_insertLast(value);
		}
		else
		{
			element* el = head;
			for (int i = 1; i < size; i++)
			{
				el = el->nextElement;
				if (i == index) _insert(el, value);
			}
		}
		size++;

	}
}
I void L::_insert(element* current, T value)
{
	element* el = new element(value);
	current->nextElement->prevElement = el;
	current->prevElement->nextElement = el;
	std::cout <<" Value: " << el->value << " Addr: " << el;
	std::cout << " Xext: " << el->nextElement << " Prev: " << el->prevElement << "\n";
}
I void L::_insertFirst(T value)
{
	element* el = new element(value);
	this->head->prevElement = el;
	el->nextElement = head;
	head = el;
}
I void L::_insertLast(T value)
{
	element* el = new element(value);
	this->tail->nextElement = el;
	el->prevElement = tail;
	tail = el;
}

I void L::_clearAll()
{
	element* el = head;
	element* next = el->nextElement;
	while (next != nullptr)
	{
		next = el->nextElement;
		delete el;
		el = next;
	}
	size = 0;
}

I bool L::listIsEmpy()
{
	return (size == 0);
}

I T L::_get(int index)
{
	T result = 0;
	if (index >= 0 && index < size)
	{
		element* el = head;
		for (int i = 0; i < size; i++)
		{
			if (i == index) return el->value;
			el = el->nextElement;
		}
	}
	return result;
}

I T L::_remove(T value, bool start, bool all)
{
	T result = 0;
	element* el = (start ? head : tail);
	for (int i = (start ? 0 : (size-1)); (start ? (i < size) : (i >=0)); (start ? i++ : i--))
	{ 
		if (value == el->value)
		{
			result = _del(el);
			if (!all) break;
		}

		el = (start ? el->nextElement : el->prevElement);
	}
	return result;
}


I T L::_removeIndex(int index)
{
	T result = 0;
	if ((index >= 0 && index < size))
	{
		element* el = head;
		for (int i = 0; i < size; i++)
		{
			std::cout << "Index: " << i << " Value: " << el->value << " Addr: " << el;
			std::cout << " Xext: " << el->nextElement << " Prev: " << el->prevElement << "\n";
			if (i == index) break;
			el = el->nextElement;
		}

		result = _del(el);
	}

	return result;
}

I T L::_del(element* el)
{
	T result = 0;
	if (size == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else if (el->nextElement == nullptr)
	{
		el->prevElement->nextElement = nullptr;
		tail = el->prevElement;

	}
	else if (el->prevElement == nullptr) {
		el->nextElement->prevElement = nullptr;
		head = el->nextElement;
	}
	else {
		el->nextElement->prevElement = el->prevElement;
		el->prevElement->nextElement = el->nextElement;
	}
	result = el->value;

	std::cout << "RemValue: " << el->value << " Addr: " << el;
	std::cout << " Xext: " << el->nextElement << " Prev: " << el->prevElement << "\n";

	size--;
	return result;
}
