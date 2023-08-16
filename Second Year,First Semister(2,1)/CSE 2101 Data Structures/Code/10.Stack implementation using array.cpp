//10.Stack implementation using array.cpp
#include<bits/stdc++.h>
using namespace std;
int top = 0;
void display(int arr[])
{
    if(top == 0)
    {
        cout << "Stack is empty!!\n";
    }
    else
    {
        cout << "Stack is: ";
        for(int i = top-1; i>=0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    cout << "Enter array size: ";
    int Size;
    cin >> Size;
    int arr[Size];
    while(1)
    {
        system("cls");
        display(arr);
        cout << "\nEnter I for insert element!\n";
        cout << "Enter D for delete element!\n";
        cout << "Enter any for exit!\n";
        cout << "\nEnter your choice: ";
        char ch;
        cin >> ch;
        if(ch == 'i' || ch == 'I')
        {
            if(top > Size-1)
            {
                cout << "Stack Overflow!!\n";
                _sleep(1000);
            }
            else
            {
                cout << "\nEnter element for insert: ";
                int n;
                cin >> n;
                arr[top] = n;
                top++;
            }
        }
        else if(ch == 'd' || ch == 'D')
        {
            if(top <= 0)
            {
                cout << "Stack Underflow!!\n";
                _sleep(1000);
            }
            else
            {
                top--;
            }
        }
        else break;
    }
}
