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
		pair<string, vector<string>>("pain", vector<string>{"боль", "огорчение"}),
		pair<string, vector<string>>("love", vector<string>{"любовь", "влюбленность"}),
		pair<string, vector<string>>("space", vector<string>{"космос", "пространство", "пробел"}),
		pair<string, vector<string>>("void", vector<string>{"пустота", "вакуум"}),
		pair<string, vector<string>>("solitude", vector<string>{"одиночество", "уединение"}),
		pair<string, vector<string>>("money", vector<string>{"деньги", "бабки", "богатство"}),
		pair<string, vector<string>>("winter", vector<string>{"зима"})
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