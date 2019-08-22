#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

//#define BASE_CHECK
//#define DESTRUCTOR_CHECK
//#define INDEX_OPERATOR_CHECK
//#define INITIALIZER_LIST_CONSTRUCTOR_CHECK
//#define CONSTRUCTORS_CHECK
#define OPERATORS_CHECK

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
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG


	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element* Head;
	int size;
public:
	const int get_size() const
	{
		return this->size;
	}
	ForwardList()
	{
		this->Head = nullptr;
		this->size = 0;
		//Изначально создаем пустой список.
		cout << "FLConstructor:\t" << this << endl;
	}
	ForwardList(int size):ForwardList()
	{
		/*this->Head = nullptr;
		this->size = 0;*/
		while (size--)push_front(int());
	}
	ForwardList(std::initializer_list<int> il):ForwardList()
	{
		//std::cout << typeid(il.begin()).name() << std::endl;
		for (int const * it = il.begin(); it != il.end(); it++)
		{
			//it - iterator;
			//begin() - возвращает адрес начала контейнера il;
			//end()   - возвращает адрес конца контейнера il;
			push_back(*it);
		}
	}
	~ForwardList()
	{
		while (Head != nullptr)pop_front();
		cout << "FLDestructor:\t" << this << endl;
	}

	//			Operators:
	int& operator[](int Index)
	{
		Element* Temp = Head;
		for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		return Temp->Data;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		////Добавляет значение в начало списка.
		////1)Создаем элемент, в который будет помещено добавляемое значение (Data).
		//Element* New = new Element(Data);
		////2)"Пристыковываем" новый элемент к началу списка:
		//New->pNext = Head;
		//Head = New;

		Head = new Element(Data, Head);
		size++;
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
		size++;
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
		size++;
	}

	//		deleting elements:
	void pop_front()
	{
		Element* Temp = Head;//запоминаем адрес удаляемого элемента.
		Head = Head->pNext;	//исключаем элемент из списка.
		delete Temp;		//удаляем элемент из памяти.
		size--;
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
		size--;
	}

	void erase(int Index)
	{
		if (Index == 0)
		{
			pop_front();
			return;
		}
		if (Index >= Element::count)
		{
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			if (Temp->pNext == nullptr)break;
			Temp = Temp->pNext;
		}
		Element* toDel = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete toDel;
		size--;
	}

	void print()
	{
		//Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это УКАЗАТЕЛЬ, при помощи которого 
		//можно получить доступ к элементам структуры данных.
		/*while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переходим на следующий элемент.
		}*/
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Количество элементов списка: " << size << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;	//Количество элементов списка.
	std::cout << "Введите количество элементов: "; std::cin >> n;
#ifdef BASE_CHECK
	ForwardList fl;	//Создаем пустой список.
	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 100);
	}
	fl.push_back(123);
	fl.print();
	cout << delimiter << endl;
	fl.pop_back();
	fl.print();
	cout << delimiter << endl;
	int Index;
	int Data;
	cout << "Введите индекс добавляемого элемента: "; cin >> Index;
	//cout << "Введите значение добавляемого элемента: "; cin >> Data;
	//fl.insert(Index, Data);
	fl.erase(Index);
	fl.print();
	//delete new Element(666);
	//cout << int() << endl;

	/*ForwardList fl1;
	cout << "Введите количество элементов: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		fl1.push_back(rand() % 100);
	}
	fl1.print();*/
#endif // BASE_CHECK

#ifdef DESTRUCTOR_CHECK
	ForwardList chain;
	for (int i = 0; i < n; i++)
	{
		chain.push_back(rand() % 100);
	}
	//chain.print();
	cout << "List full" << endl;
#endif

#ifdef INDEX_OPERATOR_CHECK
	ForwardList fl(n);
	fl.print();
	for (int i = 0; i < fl.get_size(); i++)
	{
		fl[i] = rand() % 100;
	}
	for (int i = 0; i < fl.get_size(); i++)
	{
		std::cout << fl[i] << "\t";
	}
	std::cout << std::endl;
#endif // INDEX_OPERATOR_CHECK

#ifdef CONSTRUCTORS_CHECK
	ForwardList fl1 = { 3, 5, 8, 13, 21 };	//initializer_list constructor
	for (int i = 0; i < fl1.get_size(); i++)
		cout << fl1[i] << tab;
	cout << endl;
	ForwardList fl2 = fl1;	//Copy constructor
	fl2.print();
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATORS_CHECK
	ForwardList fl1 = { 3, 5, 8, 13, 21 };
	ForwardList fl2 = { 34, 55, 89 };
	for (int i = 0; i < fl1.get_size(); i++)
	{
		cout << fl1[i] << tab;
	}
	cout << endl;
	for (int i = 0; i < fl2.get_size(); i++)
	{
		cout << fl2[i] << tab;
	}
	cout << endl;

	ForwardList fl3;
	fl3 = fl1 + fl2;
	fl3.print();
#endif
}