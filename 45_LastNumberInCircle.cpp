#include <iostream>
#include <cstdio>
#include <list>

using namespace std;


int LastRemaining(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;
	list<int> num;
	for (int i = 0; i < n; i++)
		num.push_back(i);
	list<int>::iterator current = num.begin();
	while(num.size() > 1)
	{
		for (int i = 1; i < m; i++)
		{
			current ++;
			if (current == num.end())
				current = num.begin();
		}
		list<int>::iterator next = ++current;
		if (next == num.end())
			next = num.begin();
		--current;
		num.erase(current);
		current = next;
	}
	return *current;
}

//f(n, m) = 0 , (n = 1)
//f(n, m) = [f(n - 1, m) + m ] % n,  n > 1
int LastRemaining2(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;
	int last_num = 0;
	if (n == 1)
		last_num = 0;
	for (int i = 2; i <= n; i++)
		last_num = (last_num + m) % i;
	return last_num;
}


int main(void)
{
	int n, m;
	cin >> n;
	while (n)
	{
		cin >> m;

		int last_one = LastRemaining2(n, m);
		printf("%d\n", last_one + 1);

		cin >> n;
	}

	return 0;
}

