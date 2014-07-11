#include <iostream>
#include <vector>
using namespace std;

bool isOdd(const int& n)
{
	return (n & 0x1) == 1;
}

bool isNeg(const int& n)
{
	return n < 0;
}

bool isDiviableByThree(const int& n)
{
    return n%3 == 0;
}

template <typename T>
void Reorder(vector<T> &arr, bool (*func)(const T&))
{
	if (arr.empty())
		return;
	typename vector<T>::iterator iterbeg = arr.begin(), iterend = arr.end() - 1;
	T tmp;
	while (iterbeg < iterend)
	{
		while (iterbeg < iterend && func(*iterbeg))
			iterbeg ++;
		while (iterbeg < iterend && !func(*iterend))
			iterend --;
		if (iterbeg < iterend)
		{
			tmp = *iterbeg;
			*iterbeg = *iterend;
			*iterend = tmp;
		}
	}

	return;
}


int main()
{
	int n, tmp;
	vector<int> arr;
	cin >> n;
	int i = n;
	while (n --)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	Reorder(arr, isOdd);
	Reorder(arr, isDiviableByThree);

	for (int j = 0; j < i; j ++)
		cout << arr[j] << " ";
	cout<<endl;

    return 0;
}
