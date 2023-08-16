//18.Heap sort(max heap).cpp
#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int root)
{
    int maxi = root;
    int left = 2*root+1;
    int right = 2*root + 2;
    if(left < n && arr[maxi] < arr[left])
    {
        maxi = left;
    }
    if(right<n && arr[maxi] < arr[right])
    {
        maxi = right;
    }
    if(root != maxi)
    {
        swap(arr[root],arr[maxi]);
        heapify(arr,n,maxi);
    }
}
void heap_sort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1; i>=0; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main()
{
    cout << "Enter number of element: ";
    int n;
    cin >> n;
    int arr[n];
    for(int &d:arr)
    {
        cin >> d;
    }
    cout << "\nBefore max heap sort!!\n";
    for(int d:arr)
    {
        cout << d << " ";
    }

    heap_sort(arr,n);

    cout << "\nAfter max heap sort!!\n";
    for(int d:arr)
    {
        cout << d << " ";
    }
}
