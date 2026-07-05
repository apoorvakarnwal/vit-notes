#include <iostream>
using namespace std;
int main()
{
    string inp;
    cout << "Enter the string: ";
    cin >> inp;
    char afterstuffing[1000];
    int len = 0;
    afterstuffing[len++] = '$';
    for (char c : inp)
    {
        if (c == '@' || c == '$')
        {
            afterstuffing[len++] = c;
            afterstuffing[len++] = '@';
        }
        else
        {
            afterstuffing[len++] = c;
        }
    }
    afterstuffing[len++] = '$';
    cout << "After Stuffing: ";
    for (int i = 0; i < len; i++)
    {
        cout << afterstuffing[i];
    }
    char unstuffing[1000];
    int len2 = 0;
    for (int i = len - 2; i > 0; i--)
    {
        if (afterstuffing[i] == '@')
        {
            i--;
        }
        unstuffing[len2++] = afterstuffing[i];
    }
    cout << "\nAfter Unstuffing: ";
    for (int i = 0; i < len; i++)
    {
        cout << unstuffing[i];
    }
    cout << endl;
    return 0;
}