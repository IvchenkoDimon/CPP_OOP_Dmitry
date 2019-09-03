#include<iostream>
using namespace std;

#define tab "\t"

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
		
	}

	void print()
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "� ������ " << size << " ���������." << endl;
	}
	void print_reverse()
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "� ������ " << size << " ���������." << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	cout << "������� ������ ������: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.push_front(123);
	list.print();
	list.print_reverse();
}