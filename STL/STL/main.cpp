#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
using namespace std;

#define tab "\t"
//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
#define STL_FORWARD_LIST
void main()
{
	setlocale(LC_ALL, " ");

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
	for (int i : fl) cout << i << tab; cout << endl;



#endif // STL_FORWARD_LIST

}