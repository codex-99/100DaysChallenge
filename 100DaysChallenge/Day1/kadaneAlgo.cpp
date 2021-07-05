/*
    Question: Given an array arr of N integers. Find the contiguous sub-array with maximum sum.(Kadane's Algorithm)

    Input:
    N = 5
    arr[] = {1,2,3,-2,5}
    Output:
    9

    Input:
    N = 4
    arr[] = {-1,-2,-3,-4}
    Output:
    -1
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    // Modified Kadane's Algo for all negative numbers in an array
    int i = 0;
    int curr = 0, max = 0, ele = arr[0];
    while (i < n)
    {
        curr += arr[i];
        if (curr > max)
        {
            max = curr;
        }
        if (curr < 0)
        {
            curr = 0;
        }
        if (arr[i] > ele)
        {
            ele = arr[i];
        }
        i++;
    }
    // If all the elements are negative then curr and max both will be 0. So the largest element will be the max.
    if (curr == 0 && max == 0)
    {
        max = ele;
    }
    return max;
}

int main()
{
    int n;
    cout << "Enter Size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = maxSubarraySum(arr, n);
    cout << "Maximum Subarray is: " << max << endl;
}