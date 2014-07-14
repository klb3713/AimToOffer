#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX 10


void Swap(char *a, char *b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


//返回 [a, b] 范围内的随机数
int Rand(int a, int b)
{
	return (int)(a + rand() % (b - a + 1));
}


int QuickSortPartition(char *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left >= right)
		return 0;
	int rand_num = Rand(left, right);
	Swap(&arr[rand_num], &arr[right]);

	int small = left;
	for (int i = left; i < right; i++)
	{
		if (arr[i] < arr[right])
		{
			Swap(&arr[small++], &arr[i]);
		}
	}

	Swap(&arr[small], &arr[right]);
	return small;
}



void QuickSort(char *arr, int left, int right)
{
	if (arr == NULL || left < 0 || right < 0 || left >= right)
		return;
	int i = QuickSortPartition(arr, left, right);
	if (i > left)
		QuickSort(arr, left, i - 1);
	if (i < right)
		QuickSort(arr, i + 1, right);
}


bool IsSwap(char *arr, int begin, int end)
{
	for (int k = begin; k < end; k++)
	if (*(arr + k) == *(arr + end))
		return false;
	return true;
}


void FullPermutation(char *arr, int len, int index)
{
	int i;
	if (index == len)
	{
		printf("%s\n", arr);
		return;
	}
	for (i = index; i <= len; i++)
	{
		if (IsSwap(arr, index, i))
		{
			Swap(arr + index, arr + i);
			FullPermutation(arr, len, index + 1);
			Swap(arr + index, arr + i);
		}
	}
}



void sub(char *arr, vector<char> &path, vector<bool> &used)
{
	size_t len = strlen(arr);
	if (path.size() == len)
	{
		for (size_t i = 0; i < len; i++)
			printf("%c", path[i]);
		printf("\n");
		return;
	}

	for (size_t i = 0; i < len; i++)
	{
		if (used[i] || (i != 0 && arr[i] == arr[i - 1] && used[i - 1]))
			continue;
		used[i] = true;
		path.push_back(arr[i]);
		sub(arr, path, used);
		used[i] = false;
		path.pop_back();
	}
}


void PermutationIter(char *arr)
{
	vector<bool> used(strlen(arr), false);
	vector<char> path;
	sub(arr, path, used);
}


void Reverse(char *arr, int start, int end)
{
	while (start < end)
	{
		Swap(&arr[start], &arr[end]);
		start++;
		end--;
	}
}


bool NextPermutation(char *arr)
{
	if (arr == NULL)
		return false;
	int end = strlen(arr) - 1;
	int bigger;
	for (int i = end; i > 0;)
	{
		int j = i;
		i--;
		if (arr[i] < arr[j])
		{
			bigger = end;
			while (bigger > i && arr[bigger] <= arr[i])
				--bigger;
			Swap(&arr[bigger], &arr[i]);
			Reverse(arr, j, end);
			return true;
		}
	}
	Reverse(arr, 0, end);
	return false;
}


void FullPermutation(char *arr)
{
	if (arr == NULL)
		return;
	do
	{
		printf("%s\n", arr);
	} while (NextPermutation(arr));
}


void PermutationRecursive(char *pStr, char *pBegin)
{
	if (*pBegin == '\0')
		printf("%s\n", pStr);
    else {
        for(char *pCh=pBegin; *pCh!='\0'; ++pCh) {
            Swap(pCh, pBegin);
            PermutationRecursive(pStr, pBegin+1);
            Swap(pCh, pBegin);
        }
    }
}


void PermutationRecursive(char *arr)
{
	if (arr == NULL)
		return;
    PermutationRecursive(arr, arr);
}



int main(void)
{
	char arr[MAX];

	while (cin >> arr)
	{
		if (arr == NULL)
			continue;

		QuickSort(arr, 0, strlen(arr) - 1);
		FullPermutation(arr);
		PermutationRecursive(arr);
		PermutationIter(arr);
	}

	return 0;
}

