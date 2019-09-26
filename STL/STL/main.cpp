#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
using namespace std;



#define tab "\t"
//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
//#define STL_FORWARD_LIST
#define STL_LIST
void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	int Arr[] = { 3,5,8,13,21 };
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	for (int i : Arr)
	{
		cout << i << "\t";
	}
	cout << endl;

	/*int* d_arr = new int[5]{ 34,88,123 };
	for (int i : d_arr)cout << i << "\t";
	delete d_arr;*/
	for (int i : arr)cout << i << "\t"; cout << endl;
#endif // STL_ARRAY
#ifdef STL_VECTOR
	vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;

	vec.push_back(55);
	vec.push_back(89);
	//Вывод с начала массива
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	//Var2 Вывод с конца массива - Вариант класса.
	for (vector<int>::iterator it = vec.end() - 1;/* it != vec.begin()*/; it--)
	{
		cout << *it << tab;
		if (it == vec.begin())break;
	}
	cout << endl;
	vec.resize(8); // Урезает размер массива до нужного.
	//Вывод с конца массива - Вариант Олега Анатолича.
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	vec.shrink_to_fit(); //Урезает вектор(емкость) до минимально необходимой;
	vec.reserve(20); //Задаем значение capacity(емкости);
	cout << "size:\t\t" << vec.size() << endl;
	cout << "capacity:\t" << vec.capacity() << endl;
	cout << "max_size:\t" << vec.max_size() << endl;
	cout << vec.empty() << endl; //Проверка пустой или полный массив.
	cout << vec.front() << endl; //Возвращает первое значение.
	cout << vec.back() << endl; //Возвращает последнее значение.
	cout << vec.data() << endl;
	int* vec_arr = vec.data();

	int index;
	int data;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> data;
	//Вариант 1
	vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, 5, data);
	for (int i : vec)cout << i << tab; cout << endl;
	////Вариант 2
	//vec.insert(vec.begin() + index, data);
	//for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	//{
	//	cout << *it << tab;
	//}
	//cout << endl;

#endif // STL_VECTOR
#ifdef STL_DEQUE
	deque<int> dq = { 3,5,8,13,21 };
	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i] << tab;
	}
	cout << endl;

	dq.insert(dq.begin(), { 0,1,1 });
	dq.insert(dq.end(), { 34,55,89 });
	for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
	{
		cout << *it << tab;
	}
#endif // STL_DEQUE
#ifdef STL_FORWARD_LIST
	//forward_list - это контейнер, который хранит данные в виде односвязного списка.
	forward_list<int> fl(5);
	fl.push_front(123);
	for (int i : fl) cout << i << tab; cout << endl;
	//fl.insert_after(fl.before_begin(), { 0,1,1,2 });
	//for (int i : fl) cout << i << tab; cout << endl;
	int index;
	int data;
	cout << "Введите индекс добавляемого елемента: "; cin >> index;
	cout << "Введите значение добавляемого елемента: "; cin >> data;
	forward_list<int>::iterator position = fl.before_begin();
	for (int i = 0; i < index; i++)position++;
	fl.insert_after(position, data);
	for (int i : fl) cout << i << tab; cout << endl;
#endif // STL_FORWARD_LIST
#ifdef STL_LIST
	//list<int> my_list{ 3,5,8,13,21 };
	//my_list.resize(8); // Изменение размера списка.
	//for (int i : my_list)cout << i << tab; cout << endl; // Вывод списка на экран.
	//cout << my_list.size() << endl; // Размер текущего списка.
	//cout << my_list.max_size() << endl; // Максимальный размер двухсвязного списка
	//cout << forward_list<int>().max_size() << endl; // // Максимальный размер односвязного списка

	//list<int> list1 = { 3,5,8,13,21 };
	//list<int> list2 = { 34,55,89 };
	//for (int i : list1)cout << i << tab; cout << endl;
	//for (int i : list2)cout << i << tab; cout << endl;
	//// splice
	//list<int>::iterator position = list2.begin();
	//position++;

	//list1.splice(list1.end(), list2, position);
	//for (int i : list1)cout << i << tab; cout << endl;
	//for (int i : list2)cout << i << tab; cout << endl;

	list<int> my_list(10);
	for (list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)*it = rand() % 10;
	for (int i : my_list)
	{

		cout << i << tab;
	}
	cout << endl;
	cout << "size:\t" << my_list.size() << endl;
	//my_list.remove(4); //Удаление всех значений 4;
	//Лямбда выражение__________________________________________________________
	for (list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
	{
		//*it = rand() % 10;
		my_list.remove_if([it](int num)->bool {return num % 2 == 0; });
	}
	for (int i : my_list)
	{
		cout << i << tab;
	}
	cout << endl;
	cout << "size:\t" << my_list.size() << endl;

#endif // STL_LIST

}