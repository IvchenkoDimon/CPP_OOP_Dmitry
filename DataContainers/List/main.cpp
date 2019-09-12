#include "List.h"

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