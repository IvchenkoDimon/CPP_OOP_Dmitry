#include<iostream>
using namespace std;

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
		{
			this->Data = Data;
			this->pLeft = pLeft;
			this->pRight = pRight;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
	} *Root;
public:
	Element* getRoot()
	{
		return this->Root;
	}

	Tree()
	{
		Root = nullptr;
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
		clear(this->Root);
		cout << "TDestructor:\t" << this << endl;
	}

	void insert(int Data)
	{
		insert(Data, this->Root);
	}

	int getMinValue()
	{
		return getMinValue(this->Root);
	}

	int getMaxValue()
	{
		return getMaxValue(this->Root);
	}

	int count()
	{
		return count(this->Root);
	}

	int count(Element* Root)
	{
		if (Root == nullptr)return 0;
		return count(Root->pLeft) + count(Root->pRight) + 1;
	}

	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}

	void print()
	{
		print(this->Root);
		cout << endl;
	}

	int getMinValue(Element* Root)
	{
		if (Root->pLeft == nullptr)return Root->Data;
		return getMinValue(Root->pLeft);
	}

	int getMaxValue(Element* Root)
	{
		if (Root->pRight == nullptr)return Root->Data;
		return getMaxValue(Root->pRight);
	}

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)
			{
				Root->pLeft = new Element(Data);
			}
			else
			{
				insert(Data, Root->pLeft);
			}
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)
			{
				Root->pRight = new Element(Data);
			}
			else
			{
				insert(Data, Root->pRight);
			}
		}
	}



	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}

	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ ������: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	cout << "����������� �������� � ������: " << tree.getMinValue() << endl;
	cout << "������������ �������� � ������: " << tree.getMaxValue() << endl;
	cout << "���������� ���������� � ������: " << tree.count() << endl;
}