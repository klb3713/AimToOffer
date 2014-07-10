#include <iostream>
#include <algorithm>
using namespace std;

#define MAX  1000


void QuickSort(int data[], int start, int end) {
    if(data == NULL || start < 0 || start >= end)
        return;
    int pos = start;
    for (int i=start+1; i<=end; i++) {
        if (data[i] < data[start])
            swap(data[i], data[++pos]);
    }
    swap(data[start], data[pos]);
    if(pos > start)
        QuickSort(data, start, pos-1);
    if(pos < end)
        QuickSort(data, pos+1, end);
}


int BinarySearch(int data[], int start, int end, int value) {
    if(data == NULL || start < 0 || start >= end)
        return -1;
    int m;
    while(start < end) {
        m = start + (end-start)/2;
        if(data[m] == value)
            return m;
        else if(data[m] > value)
            end = m;
        else
            start = m+1;
    }

    return -1;
}


int main(void)
{
    int numbers[MAX] = {8, 235, 35, 1124, 5352, 1, 3, 7};
    QuickSort(numbers, 0, 7);
    QuickSort(NULL, 7, 0);
    for(int i=0; i<8; i++) {
        cout<<numbers[i]<<endl;
    }

    cout<<BinarySearch(numbers, 0, 8, 35)<<endl;
    cout<<BinarySearch(numbers, 0, 8, 5)<<endl;

    return 0;
}
