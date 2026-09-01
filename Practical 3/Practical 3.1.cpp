#include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

void selectionSort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min = i;

        for(int j = i+1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }

        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
}

void insertionSort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i-1;

        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
    }
}

void print(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of sheets: ";
    cin >> n;

    int a[50], b[50], c[50];

    cout << "Enter marks: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        c[i] = a[i];
    }

    bubbleSort(a, n);
    selectionSort(b, n);
    insertionSort(c, n);

    cout << "\nBubble Sort: ";
    print(a, n);

    cout << "Selection Sort: ";
    print(b, n);

    cout << "Insertion Sort: ";
    print(c, n);

    return 0;
}