#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of borrow records: ";
    cin >> n;

    int book[n];

    cout << "Enter Book IDs: ";
    for(int i = 0; i < n; i++)
    {
        cin >> book[i];
    }

    cout << "Books borrowed more than once are:\n";

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(book[i] == book[j])
            {
                count++;
            }
        }

        if(count > 1)
        {
            bool alreadyPrinted = false;

            for(int k = 0; k < i; k++)
            {
                if(book[k] == book[i])
                {
                    alreadyPrinted = true;
                    break;
                }
            }

            if(alreadyPrinted == false)
            {
                cout << "Book ID: " << book[i]
                     << "  Borrowed: " << count << " times" << endl;
            }
        }
    }

    return 0;
}
