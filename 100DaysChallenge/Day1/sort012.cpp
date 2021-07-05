/*
    Question: Sort an array containing 0s, 1s, and 2s

*/
#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
    // Count the number of 0s, 1s, and 2s and just iterate over them and convert them.
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        if (arr[i] == 1)
            count1++;
        if (arr[i] == 2)
            count2++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < count0 + count1 + count2)
        {
            arr[i] = 2;
        }
        if (i < count0 + count1)
        {
            arr[i] = 1;
        }
        if (i < count0)
        {
            arr[i] = 0;
        }
    }
}

int main()
{
    int n = 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort012(arr, 5);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}