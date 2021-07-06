/*
    Question:   Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
                1. Each student gets exactly one packet.
                2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.
    
    {
        Input:
        N = 8, M = 5
        A = {3, 4, 1, 9, 56, 7, 9, 12}
        Output: 6
        Explanation: The minimum difference between 
        maximum chocolates and minimum chocolates 
        is 9 - 3 = 6 by choosing following M packets :
        {3, 4, 9, 7, 9}.
    }
*/
#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // First sort the array and then check the difference for the first and last elements. Iterate over a.size()-m+1.
    long long diff, min = -1;
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < a.size() - m + 1; i++)
    {
        diff = a[i] - a[i + m - 1];
        if (min > diff || min < 0)
        {
            min = diff;
        }
    }
    return min;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> a;
    long long x;
    for (long long i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    long long m;
    cin >> m;
    cout << findMinDiff(a, n, m) << endl;
    return 0;
}