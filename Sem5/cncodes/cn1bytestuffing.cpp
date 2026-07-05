#include <iostream>
#include <string>
using namespace std;
int main()
{
    string inp;
    cout << "Enter the string: ";
    cin >> inp;

    char afterstuffing[1000];
    int len = 0;
    afterstuffing[len++] = '$';

    for (int i = 0; i < inp.length(); i++)
    {
        if (inp[i] == '@' || inp[i] == '$')
        {
            afterstuffing[len++] = inp[i];
            afterstuffing[len++] = '@';
        }
        else
        {
            afterstuffing[len++] = inp[i];
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
    for (int i = len2 - 1; i >= 0; i--)
    {
        cout << unstuffing[i];
    }
    cout << "\n";
    return 0;
}
