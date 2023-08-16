//18.Heap sort(min heap).cpp
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void heapify(int arr[], int n, int root)
{
    int mini = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
    if(left < n && arr[left]<arr[mini])
    {
        mini = left;
    }
    if(right < n && arr[right] < arr[mini])
    {
        mini = right;
    }
    if(root != mini)
    {
        swap(arr[root],arr[mini]);
        heapify(arr,n,mini);
    }
}
void heap_sort(int arr[],int n)
{
    for(int i=0; i<n;i++)
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
    auto start=high_resolution_clock::now();
    cout << "\nBefore heap sort!!\n";
    for(int d:arr)
    {
        cout << d << " ";
    }

    heap_sort(arr,n);

    cout << "\nAfter heap sort!!\n";
    for(int i=n-1; i>=0; i--)
    {
        cout << arr[i] << " ";
    }
    auto stop=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "\nExecutation Time: "<<duration.count() << " microseconds\n";
}
