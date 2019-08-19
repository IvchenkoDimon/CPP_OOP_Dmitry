#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

#define BASE_CHECK
#define INDEX_OPERATOR_CHECK
#define INITIALIZER_LIST_CONSTRUCTOR_CHECK

class Element
{
	int Data;
	Element* pNext;
	static int count;
public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{
		this->Head = nullptr;
		//���������� ������� ������ ������.
		cout << "FLConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "FLDestructor:\t" << this << endl;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		////��������� �������� � ������ ������.
		////1)������� �������, � ������� ����� �������� ����������� �������� (Data).
		//Element* New = new Element(Data);
		////2)"��������������" ����� ������� � ������ ������:
		//New->pNext = Head;
		//Head = New;

		Head = new Element(Data, Head);
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
	}

	void insert(int Index, int Data)
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			if (Temp->pNext == nullptr)break;
			Temp = Temp->pNext;
		}
		/*Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element(Data, Temp->pNext);
	}

	//		deleting elements:
	void pop_front()
	{
		Element* Temp = Head;//���������� ����� ���������� ��������.
		Head = Head->pNext;	//��������� ������� �� ������.
		delete Temp;		//������� ������� �� ������.
	}

	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)
		{
			pop_front();
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
	}

	void erase(int Index)
	{
		
	}

	void print()
	{
		//Element* Temp = Head;	//Temp - ��� ��������.
		//�������� - ��� ���������, ��� ������ �������� 
		//����� �������� ������ � ��������� ��������� ������.
		/*while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//��������� �� ��������� �������.
		}*/
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "���������� ��������� ������: " << Element::count << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;	//���������� ��������� ������.
	cout << "������� ���������� ���������: "; cin >> n;
#ifdef BASE_CHECK
	ForwardList fl;	//������� ������ ������.
	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 100);
	}
	fl.push_back(123);
	fl.print();
	/*cout << delimiter << endl;
	fl.pop_back();
	fl.print();
	cout << delimiter << endl;
	int Index;
	int Data;
	cout << "������� ������ ������������ ��������: "; cin >> Index;
	cout << "������� �������� ������������ ��������: "; cin >> Data;
	fl.insert(Index, Data);
	fl.print();*/
	//delete new Element(666);
	cout << int() << endl;
#endif // BASE_CHECK

#ifdef INDEX_OPERATOR_CHECK
	ForwardList fl(n);
	for (int i = 0; i < n; i++)
	{
		cout << fl[i] << tab;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		fl[i] = rand()%100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << fl[i] << tab;
	}
	cout << endl;
#endif // INDEX_OPERATOR_CHECK

}