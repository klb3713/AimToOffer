#include <iostream>
#include <cstdio>


using namespace std;


class Temp
{
public:
	Temp() { ++N; Sum += N;}

	static void Reset() {N = 0; Sum = 0;}
	static unsigned int GetSum() {return Sum;}
private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int SumSolution1(unsigned int n)
{
	Temp::Reset();
	Temp *a = new Temp[n];
	delete []a;
	return Temp::GetSum();
}


class A;
A *Array[2];

class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};

class B: public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};


int SumSolution2(unsigned int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	unsigned int value = Array[1]->Sum(n);
	return value;
}


typedef unsigned int (*fun)(unsigned int);

unsigned int Solution3Teminator(unsigned int n)
{
	return 0;
}

unsigned int SumSolution3(unsigned int n)
{
	static fun f[2] = {Solution3Teminator, SumSolution3};
	return  n + f[!!n](n - 1);
}


int main(void)
{
	unsigned int n;

	while (cin >> n)
	{
		unsigned int sum = SumSolution3(n);
		cout << sum << endl;
	}

	return 0;
}

