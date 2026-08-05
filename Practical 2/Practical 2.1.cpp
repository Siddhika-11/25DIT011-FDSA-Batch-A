#include <iostream>
using namespace std;

int linearSearch(string a[], int n, string key)
{
    for(int i=0; i<n; i++)
    {
        if(a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int recursiveSearch(string a[], int n, string key, int i)
{
    if(i == n)
    {
        return -1;
    }

    if(a[i] == key)
    {
        return i;
    }

    return recursiveSearch(a, n, key, i+1);
}

int main()
{
    int n;
    cout<<"Enter number of vehicles : ";
    cin>>n;

    string a[n];

    cout<<"Enter license plates : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    string key;
    cout<<"Enter target plate : ";
    cin>>key;

    int x = linearSearch(a, n, key);

    if(x == -1)
        cout<<"Linear Search : Not Found"<<endl;
    else
        cout<<"Linear Search : Found at position "<<x+1<<endl;

    int y = recursiveSearch(a, n, key, 0);

    if(y == -1)
        cout<<"Recursive Search : Not Found"<<endl;
    else
        cout<<"Recursive Search : Found at position "<<y+1<<endl;

    return 0;
}