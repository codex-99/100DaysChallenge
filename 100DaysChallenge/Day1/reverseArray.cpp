/*
    Question: Write a program to reverse an array or string (Difficulty: Basic)

    Expected I/O:
    Input  : arr[] = {1, 2, 3}
    Output : arr[] = {3, 2, 1}

    Input :  arr[] = {4, 5, 1, 2}
    Output : arr[] = {2, 1, 5, 4}

    Explaination:   Create an array and just traverse the first value of the old to new.(Basic Approach)
                    Swap the first and last elements of the array(Optimal Approach)
*/
#include <bits/stdc++.h>
using namespace std;

void reverseArray(int *arr, int size)
{
    int i, temp;
    for (i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void display(int *arr, int size)
{
    cout << endl << "Elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int s;
    cout << "Enter the size of the array" << endl;
    cin >> s;
    cout << "Enter Element" << endl;
    int arr[s];
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    display(arr, s);
    reverseArray(arr, s);
    display(arr, s);
    return 0;
}