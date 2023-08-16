// 6.Selection Sort.cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter array size: ";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nBefore sort!!\n";
    for (int d : arr)
        cout << d << " ";

    int min, index = -1;
    for (int i = 0; i < n - 1; i++)
    {
        min = arr[i];
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
    cout << "\nAfter sort!!\n";
    for (int d : arr)
        cout << d << " ";
}