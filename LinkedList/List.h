#pragma once


template<class T>
class List
{
public:
	struct element
	{
		friend List;
	public:
		T value;
		element* nextElement;
		element* prevElement;
	public:
		element(T val)
		{
			value = val;
			nextElement = nullptr;
			prevElement = nullptr;
		}
		~element()
		{
			nextElement = nullptr;
			prevElement = nullptr;
		}
		
		bool operator== (const element& rhs)
		{
			return (this->value == rhs.value) ;
		}
		bool operator!= (const element& rhs)
		{
			return !(operator==(rhs));
		}
	};
	
	int size;

	element* head;
	element* tail;
public:
	List();

	int getSize();

	void add(T);
	void add(int, T);
	void addFirst(T);
	void addLast(T);

	void clear();

	bool contains(T);

	T get(int);
	T getFirst();
	T getLast();

	T remove(T);
	T removeAll(T);
	T removeLast(T);
	T removeFirst();
	T removeLast();
	T removeIndex(int);

private:
	void insert(int, T);
	void _insert(element*, T);
	void _insertFirst(T);
	void _insertLast(T);
	void _clearAll();
	bool listIsEmpy();
	T _get(int);
	T _remove(T, bool, bool);
	T _removeIndex(int);
	T _del(element*);
	
};




