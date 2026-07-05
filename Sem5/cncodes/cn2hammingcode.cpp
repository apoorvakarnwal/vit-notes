#include <iostream>
#include <cmath>
using namespace std;
int r = 0; // Global variable for number of parity bits
void generateHammingCode(int data[], int m, int r)
{
    int hammingCode[m + r + 1]; // Array to hold data and parity bits
    int k = 0;
    // Initialize hammingCode array with parity bit positions set to 0
    for (int i = 1; i <= m + r; i++)
    {
        if ((i & (i - 1)) == 0)
        {
            hammingCode[i] = 0; // Placeholder for parity bits
        }
        else
        {
            hammingCode[i] = data[k++];
        }
    }
    // Set parity bits
    for (int i = 0; i < r; i++)
    {
        int x = 1 << i;
        int count = 0;
        for (int j = 1; j <= m + r; j++)
        {
            if (j & x)
            {
                count += hammingCode[j];
            }
        }
        hammingCode[x] = count % 2;
    }
    cout << "Generated Hamming Code: ";
    for (int i = 1; i <= m + r; i++)
    {
        cout << hammingCode[i];
    }
    cout << endl;
}
void detectAndCorrect(int received[], int m, int r)
{
    int errorPosition = 0;
    // Check parity bits
    for (int i = 0; i < r; i++)
    {
        int x = 1 << i;
        int count = 0;
        for (int j = 1; j <= m + r; j++)
        {
            if (j & x)
            {
                count += received[j];
            }
        }
        if (count % 2 != 0)
        {
            errorPosition += x;
        }
    }
    if (errorPosition == 0)
    {
        cout << "No error detected in the received Hamming Code." << endl;
    }
    else
    {
        cout << "Error detected at position: " << errorPosition << endl;
        received[errorPosition] = !received[errorPosition]; // Correct the error
        cout << "Corrected Hamming Code: ";
        for (int i = 1; i <= m + r; i++)
        {
            cout << received[i];
        }
        cout << endl;
    }
}

int main()
{
    int m;
    cout << "Enter the number of data bits: ";
    cin >> m;
    int data[m];
    cout << "Enter the data bits (0s and 1s): ";
    for (int i = 0; i < m; i++)
    {
        cin >> data[i];
    }
    // Calculate number of parity bits once in main
    while ((1 << r) < (m + r + 1))
    {
        r++;
    }
    generateHammingCode(data, m, r);
    int received[m + r + 1];
    cout << "Enter the received Hamming Code (with parity bits): ";
    for (int i = 1; i <= m + r; i++)
    {
        cin >> received[i];
    }
    detectAndCorrect(received, m, r);
    return 0;
}
