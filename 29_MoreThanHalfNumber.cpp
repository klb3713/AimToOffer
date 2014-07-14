#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX 100000


void Swap(unsigned long *a, unsigned long *b)
{
	unsigned long tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


int Rand(int a, int b)
{
	return (int)(a + rand() % (b - a + 1));
}


int QuickSortPartition1(unsigned long *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left > right)
		return 0;
	int rand_num = Rand(left, right);
	Swap(&arr[rand_num], &arr[left]);
	unsigned long ref = arr[left];
	int i, j;
	i = left;
	j = right;
	while (i < j)
	{
		while (i < j && arr[j] >= ref)
			j--;
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}
		while (i < j && arr[i] <= ref)
			i++;
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}
	}

	arr[i] = ref;
	return i;
}


bool CheckMoreThanHalf(unsigned long *numbers, int length, unsigned long result)
{
	int count = 0;
	for (int i = 0;i < length; i++)
	{
		if (numbers[i] == result)
			count ++;
	}
	if (count * 2 <= length)
		return false;
	else
		return true;
}


int MoreThanHalfNum1(unsigned long *numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		printf("-1\n");
		return 0;
	}
	int middle = length >> 1;
	int left = 0, right = length - 1, index;
	index = QuickSortPartition1(numbers, left, right);
	while (index != middle)
	{
		if (index < middle)
		{
			left = index + 1;
			index = QuickSortPartition1(numbers, index + 1, right);
		}
		else if(index > middle)
		{
			right = index - 1;
			index = QuickSortPartition1(numbers, left, right);
		}
	}
	unsigned long result = numbers[middle];

	int count = 0;
	for (int i = 0;i < length; i++)
	{
		if (numbers[i] == result)
			count ++;
	}
	if (count * 2 <= length)
		printf("-1\n");
	else
		printf("%lu\n", result);

	return 0;
}

int MoreThanHalfNum2(unsigned long *numbers, int length)
{
	int i;
	int count = 1;
	unsigned long num = numbers[0];
	for (i = 0; i < length; i++)
	{
		if (count == 0)
		{
			count = 1;
			num = numbers[i];
		}
		else if (numbers[i] != num)
			count --;
		else
			count ++;
	}
	if (!CheckMoreThanHalf(numbers, length, num))
		printf("-1\n");
	else
		printf("%lu\n", num);
	return 0;
}



int main(void)
{
	int  n;

	while (scanf("%d", &n) != EOF)
	{
		unsigned long numbers[MAX];
		for (int i = 0; i < n; i++)
			scanf("%lu", &numbers[i]);
		MoreThanHalfNum1(numbers, n);


	}

	return 0;
}