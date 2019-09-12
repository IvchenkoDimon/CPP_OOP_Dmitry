#include<iostream>
using namespace std;

#define tab "\t"

//#define BASE_CHECK
#define CONSTRUCTORS_CHECK


template<typename T>
class List
{
	template<typename T>
	class Element
	{
		T Data;
		Element<T>* pNext;
		Element<T>* pPrev;
	public:
		Element(T Data, Element<T>* pNext = nullptr, Element<T>* pPrev = nullptr) :
			Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t\t" << this << endl;
		}
		/*const int operator*() const
		{
			return this->Data;
		}
		
		int operator*()
		{
			return this->Data;
		}*/
		operator T&()
		{
			return this->Data;
		}
		friend class List<T>;
	};
	Element<T>* Head;
	Element<T>* Tail;
	int size;
public:
	class Iterator
	{
		Element<T>* Temp;
	public:
		Iterator(Element<T>* Temp = nullptr)
		{
			this->Temp = Temp;
			cout << "ITConstructor:\t\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ITDestructor:\t\t" << this << endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = this;
			Temp = Temp->pNext;
			return old;
		}

		const T& operator*() const
		{
			return Temp->Data;
		}
		T& operator*()
		{
			return Temp->Data;
		}
		bool operator==(const Iterator& other) const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other) const
		{
			return this->Temp != other.Temp;
		}
	};
	int get_size() const
	{
		return this->size;
	}
	const Iterator begin() const
	{
		return this->Head;
	}
	Iterator begin()
	{
		return this->Head;
	}
	const Iterator end() const
	{
		return nullptr;
	}
	Iterator end()
	{
		return nullptr;
	}
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t\t" << this << endl;
	}
	List(initializer_list<int> il) :List()
	{
		for (const int* it = il.begin();it!=il.end();it++)
		{
			push_back(*it);
		}
	}
	~List()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t\t" << this << endl;
	}
	//			Operators:
	T& operator[](int Index)
	{
		Element<T>* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = size - 1; i > Index; i--)Temp = Temp->pPrev;
		}
		return Temp->Data;
	}
	const T& operator[](int Index) const
	{
		Element<T>* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = size - 1; i > Index; i--)Temp = Temp->pPrev;
		}
		return Temp->Data;
	}
	//			Adding elements:
	void push_front(T Data)
	{
		Element<T>* New = new Element<T>(Data);
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = New;
			return;
		}
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
		size++;
	}
	void push_back(T Data)
	{
		Element<T>* New = new Element<T>(Data);
		size++;
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = New;
			return;
		}
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
	}
	void insert(int Index, T Data)
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Index >= size)
		{
			push_back(Data);
			return;
		}
		Element<T>* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - 1 - Index; i++)Temp = Temp->pPrev;
		}
		/*Element* New = new Element(Data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;*/
		Temp->pPrev = Temp->pPrev->pNext = new Element<T>(Data, Temp, Temp->pPrev);
		size++;
	}
	//			Removing elements:
	void pop_front()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == Tail)
		{
			delete Tail;
			Head = Tail = nullptr;
			return;
		}
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	void erase(T Index)
	{
		if (Index == 0)
		{
			pop_front();
			return;
		}
		if (Index >= size - 1)
		{
			pop_back();
			return;
		}
		if (Head == nullptr || Head == Tail)return;
		Element<T>* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - 1 - Index; i++)Temp = Temp->pPrev;
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		size--;
	}

	void print()
	{
		for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "В списке " << size << " элементов." << endl;
	}
	void print_reverse()
	{
		for (Element<T>* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "В списке " << size << " элементов." << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
#ifdef BASE_CHECK
	cout << "Hello Git" << endl;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	cout << "Push_back" << endl;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	cout << "Push_front" << endl;
	list.push_front(123);
	list.print();
	list.print_reverse();
	cout << "Index" << endl;
	int Index;
	int Data;
	cout << "Введите индекс добавляемого элемента: "; cin >> Index;
	cout << "Введите значение добавляемого элемента: "; cin >> Data;
	list.insert(Index, Data);
	cout << "Pop_front" << endl;
	list.pop_front();
	list.print();
	cout << "Pop_back" << endl;
	list.pop_back();
	list.print();
	list.print_reverse();
	cout << "Erase" << endl;
	cout << "Введите индекс удаляемого элемента: "; cin >> Index;
	list.erase(Index);
	list.print();
	list.print_reverse();
#endif // BASE_CHECK
#ifdef CONSTRUCTORS_CHECK
	List<int> lst1 = { 3,5,8,13,21 };
	lst1.print();
	/*for (int i = 0; i < lst1.get_size(); i++)
		cout << lst1[i] << tab;
	cout << endl;*/
	/*for (int i = 0; i < lst1.get_size(); i++)lst1[i] = rand() % 100;*/
	for (int i = 0; i < lst1.get_size(); i++)
		cout << lst1[i] << tab;
	for (int i : lst1)
	{
		cout << i << tab;
	}
	cout << endl;

	/*List lst2 = { 34,55,89 };
	for (int i = 0; i < lst2.get.size(); i++)
		cout << lst2[i] << tab;
	cout << endl;
	List lst3 = lst1 + lst2;
	for (int i : lst3)
	{
		cout << i << tab;
	}
	cout << endl;*/


#endif // CONSTRUCTORS_CHECK

}