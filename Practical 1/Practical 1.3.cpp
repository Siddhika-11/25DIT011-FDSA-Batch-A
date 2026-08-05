#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;
    string words[100];
    int count = 0;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    sentence += ' ';

    string temp = "";

    
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ')
        {
            temp += sentence[i];
        }
        else
        {
            words[count] = temp;
            count++;
            temp = "";
        }
    }

    string longest = words[0];

    for (int i = 1; i < count; i++)
    {
        if (words[i].length() > longest.length())
        {
            longest = words[i];
        }
    }

    cout << "Longest Word: " << longest << endl;

    return 0;