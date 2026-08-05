#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(a[mid] == key)
        {
            return mid;
        }
        else if(a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int recursiveSearch(int a[], int low, int high, int key)
{
    if(low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if(a[mid] == key)
    {
        return mid;
    }

    if(a[mid] < key)
    {
        return recursiveSearch(a, mid + 1, high, key);
    }

    return recursiveSearch(a, low, mid - 1, key);
}

int main()
{
    int n;

    cout<<"Enter number of book codes : ";
    cin>>n;

    int a[n];

    cout<<"Enter sorted book codes : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    int key;
    cout<<"Enter target code : ";
    cin>>key;

    int x = binarySearch(a, n, key);

    if(x == -1)
        cout<<"Binary Search : Not Found"<<endl;
    else
        cout<<"Binary Search : Found at position "<<x+1<<endl;

    int y = recursiveSearch(a, 0, n-1, key);

    if(y == -1)
        cout<<"Recursive Binary Search : Not Found"<<endl;
    else
        cout<<"Recursive Binary Search : Found at position "<<y+1<<endl;

    return 0;
}