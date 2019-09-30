#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	map<string, vector<string>> dictionary =
	{
		pair<string, vector<string>>("pain", vector<string>{"����", "���������"}),
		pair<string, vector<string>>("love", vector<string>{"������", "������������"}),
		pair<string, vector<string>>("space", vector<string>{"������", "������������", "������"}),
		pair<string, vector<string>>("void", vector<string>{"�������", "������"}),
		pair<string, vector<string>>("solitude", vector<string>{"�����������", "���������"}),
		pair<string, vector<string>>("money", vector<string>{"������", "�����", "���������"}),
		pair<string, vector<string>>("winter", vector<string>{"����"})
	};
	//Short output
	for (pair<string, vector<string>> i : dictionary)
	{
		cout << i.first << tab;

		for (string j : i.second)
		{
			cout << j << ", ";
		}
		cout << "\b\b;\n";
	}
	//Standert output
	/*for (map<string, vector<string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << tab << tab;
		for (vector<string>::iterator jt = it->second.begin(); jt!=it->second.end();jt++)
		{
			cout << *jt << ", ";
		}
		cout << "\b;\n";
	}*/
	vector<int> numbers = { 3,5,8,13,21 };
	for (int i : numbers)
	{
		cout << i << tab;
	}
	cout << endl;
}