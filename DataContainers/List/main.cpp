#include<iostream>
using namespace std;

#define tab "\t"

//#define BASE_CHECK
#define CONSTRUCTORS_CHECK

class List
{
	class Element
	{
		int Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :
			Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t\t" << this << endl;
		}
		friend class List;
	};
	Element* Head;
	Element* Tail;
	int size;
public:
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t\t" << this << endl;
	}
	~List()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t\t" << this << endl;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		Element* New = new Element(Data);
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
	void push_back(int Data)
	{
		Element* New = new Element(Data);
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

	void insert(int Index, int Data)
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
		Element* Temp;
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
		Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
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
	void erase(int Index)
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
		Element* Temp;
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
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "В списке " << size << " элементов." << endl;
	}
	void print_reverse()
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
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
	List lst1 = { 3,5,8,13,21 };
	for (int i = 0; i < lst1.get.size(); i++)
		cout << lst1[i] << tab;
	cout << endl;
	List lst2 = { 34,55,89 };
	for (int i = 0; i < lst2.get.size(); i++)
		cout << lst2[i] << tab;
	cout << endl;
	List lst3 = lst1 + lst2;
	for (int i : lst3)
	{
		cout << i << tab;
	}
	cout << endl;


#endif // CONSTRUCTORS_CHECK

}