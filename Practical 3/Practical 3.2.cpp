#include <iostream>
using namespace std;

int main()
{
    int n, a[50];

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter colours: ";
    for(int i=0; i<n; i++)
        cin >> a[i];

    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high)
    {
        if(a[mid] == 0)
        {
            int t = a[low];
            a[low] = a[mid];
            a[mid] = t;

            low++;
            mid++;
        }

        else if(a[mid] == 1)
        {
            mid++;
        }

        else
        {
            int t = a[mid];
            a[mid] = a[high];
            a[high] = t;

            high--;
        }
    }

    cout << "Sorted colours: ";

    for(int i=0; i<n; i++)
        cout << a[i] << " ";

    return 0;
}