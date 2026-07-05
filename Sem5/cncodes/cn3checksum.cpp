#include <iostream>
#include <bitset>

using namespace std;

bitset<32> sender(int arr[], int n)
{
    unsigned int sum = 0;
    cout << "\n****SENDER SIDE****\n";
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "SUM IS: " << sum << endl;
    bitset<32> checksum(~sum);
    cout << "CHECKSUM IS: " << checksum << endl;
    return checksum;
}

void receiver(int arr[], int n, bitset<32> sch)
{
    unsigned int sum = 0;
    cout << "\n****RECEIVER SIDE****\n";
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "SUM IS: " << sum << endl;
    sum += sch.to_ulong();
    bitset<32> final_checksum(~sum);
    cout << "CHECKSUM IS: " << final_checksum << endl;
}

int main()
{
    int n;
    cout << "\nENTER SIZE OF THE STRING: ";
    cin >> n;

    if (n <= 0 || n > 10)
    {
        cout << "Invalid size. Please enter a size between 1 and 10.\n";
        return 1;
    }

    int arr[n];
    cout << "ENTER THE ELEMENTS OF THE ARRAY TO CALCULATE CHECKSUM:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bitset<32> sch = sender(arr, n);
    receiver(arr, n, sch);

    return 0;
}
