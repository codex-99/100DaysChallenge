/*
    Question:   Given an unsorted array Arr of size N of positive integers.
                One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array.
                Find these two numbers.

    Input:
    N = 2
    Arr[] = {2, 2}
    Output: 2 1
    Explanation: Repeating number is 2 and smallest positive missing number is 1.

    Basically we can have multiple approaches:
    1.  We can sort the array and then find the missing and repeating number.
        Problem: time complexity will be O(NLogN)
    2.  We can initialize a new array with 0. So when we iterate over the array we can increment the index value of the new array.
        So ultimately the index having 0 as value will be missing and 2 as value will be repeating.
        Problem: time complexity is O(n) but space complexity is also O(n).
    3.  We can iterate over the array and use the absolute value as index and make multiple the value with -1.
        For repeating part, just apply the else statement and check if alreadythe value is negative.
        For missing part, just check if the element is positive. Then just return the index.
*/
#include <bits/stdc++.h>
using namespace std;

int *findTwoElement(int *a, int n)
{
    static int b[2];
    // check for missing number
    for (int i = 0; i < n; i++)
    {
        if (a[abs(a[i]) - 1] > 0)
        {
            a[abs(a[i]) - 1] *= -1;
        }
        else
        {
            b[0] = abs(a[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            b[1] = i + 1;
        }
    }

    return b;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Repeating Number: " << findTwoElement(a, n)[0] << "\nMissing Number: " << findTwoElement(a, n)[1] << endl;
    return 0;
}