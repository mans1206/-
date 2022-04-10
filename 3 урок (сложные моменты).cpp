#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <fstream>
#include "Timer.h"
using namespace std;

//The first task
//==========================================================================
void AddSred(list <double>& l)
{
	double Sum = 0;
	list <double>::iterator iter;
	for (iter = l.begin(); iter != l.end(); iter++)
	{
		Sum += *iter;
	}
	l.push_back(Sum / l.size());
}

template <typename T>
void printlist(list <T>& l)
{
	for (T i : l)
	{
		cout << i << " ";
	}
}

//The second task
//==========================================================================
class Matrix
{
private:
	vector < vector <int> > v;
public:
	Matrix(int a)
	{
		v.push_back(vector <int> {a});
	}
	Matrix(int a, int b, int c, int d)
	{
		v.push_back(vector<int> {a, b});
		v.push_back(vector<int> {c ,d});
	}
	Matrix (int a, int b, int c, int d, int e, int f, int g, int h, int i)
	{
		v.push_back(vector <int>{ a, b, c });
		v.push_back(vector <int>{ d, e, f });
		v.push_back(vector <int>{ g, h, i });
	};
	void determinator()
	{
		if (v.size() == 1)
		{
			cout << "Your matrix determinator is: " << v[0][0] << endl;
		}
		else if (v.size() == 2)
		{
			cout << "Your matrix determinator is: " << (v[0][0] * v[1][1]) - (v[0][1] * v[1][0]) << endl;
		}
		else if (v.size() == 3)
		cout << "Your matrix determinator is: " << v[0][0] * (v[1][1] * v[2][2]) - v[0][0] * (v[1][2] * v[2][1]) - v[0][1] * (v[1][0] * v[2][2]) + v[0][1] * (v[1][2] * v[2][0]) + v[0][2] * (v[1][0] * v[2][1]) - v[0][2] * (v[1][1] * v[2][0]) << endl;
	}
	void print()
	{
		for (auto i = 0; i < v.size(); i++)
		{
			for (auto j = 0; j < v[i].size(); j++)
			{
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
	}
};

//The third task
//==========================================================================


class Iterator
{
private:
	int* ptr;
public:
	Iterator(int array) : ptr(&array)
	{}
	int operator* () const
	{
		return *ptr;
	}
	int& operator++ () 
	{
		ptr++;
		return *ptr;
	}
	ostream& operator<< (ostream & out)
	{
		out << &ptr;
		return out;
	}
	 bool operator!= (Iterator & it)
	{
		return ptr != it.ptr;
	}
	//friend bool& operator< (Iterator & it, Iterator & it2) 
	//{
	//	return it.ptr < it2.ptr;
	//}
};


int main()
{
	cout << "The first task" << endl;
	cout << "=================================================================" << endl;
	list <double> l1;
	for (double i = 1; i < 11; i++)
	{
		l1.push_back(i);
	}

	printlist(l1);
	cout << endl;
	AddSred(l1);
	printlist(l1);

	cout << endl;
	cout << "=================================================================" << endl;
	cout << "The second task" << endl;
	cout << "=================================================================" << endl;
	
	Matrix mat3(5,7,1,
			  -4,1,0,
			   2,0,3);
	mat3.print();
	mat3.determinator();

	Matrix mat2(1, 0, 1, 0);
	mat2.print();
	mat2.determinator();

	Matrix mat1(56);
	mat1.determinator();
	cout << "=================================================================" << endl;
	cout << "The third task" << endl;
	cout << "=================================================================" << endl;

	vector <int> v = {1, 8, 0, 4, 3,2,};

	for (Iterator iter : v)
	{
		cout << *iter << " ";
	}
	return 0;
}
