/*
    Question: Given an integer N, find its factorial.

    Input: N = 5
    Output: 120
    Explanation : 5! = 1*2*3*4*5 = 120

    Even if we use long long data type then too after a number we cannot find the factorial as it will out of bounds.
    So we use vector/array to store the data.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void multiple(vector<int> &a, int i); // adjust the number accordingly.

    vector<int> factorial(int N); // calculate the factorial
};

void Solution::multiple(vector<int> &a, int i)
{
    int carry = 0;
    vector<int>::iterator x;

    for (x = a.begin(); x != a.end(); x++)
    {
        int product = i * (*x) + carry;
        (*x) = product % 10;
        carry = product / 10;
    }
    while (carry)
    {
        a.push_back(carry % 10);
        carry = carry / 10;
    }
}
vector<int> Solution::factorial(int N)
{
    vector<int> a;
    a.push_back(1);
    for (int i = 2; i <= N; i++)
    {
        multiple(a, i);
    }
    reverse(a.begin(), a.end());
    return a;
}

int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<int> res = s.factorial(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    return 0;
}