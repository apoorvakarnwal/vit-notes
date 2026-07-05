#include <stdio.h>
#include <string.h>
char number[15];
char remainder[15];
char divisor[15];
int number_length, i, j;
void XOR(int n)
{
    for (j = 0; j < n; j++)
    {
        remainder[j] = (remainder[j] == divisor[j]) ? '0' : '1';
    }
}

void crc(int n)
{
    for (i = 0; i < n; i++)
    {
        remainder[i] = number[i];
    }
    do
    {
        if (remainder[0] == '1')
        {
            XOR(n);
        }
        for (j = 0; j < n - 1; j++)
        {
            remainder[j] = remainder[j + 1];
        }
        remainder[j] = number[i++];
    } while (i <= number_length + n - 1);
}
int main()
{
    printf("\nEnter data to be transmitted: ");
    scanf("%s", number);

    printf("\nEnter the (divisor) code word: ");
    scanf("%s", divisor);
    int n;
    n = strlen(divisor);
    number_length = strlen(number);
    for (i = number_length; i < number_length + n - 1; i++)
    {
        number[i] = '0';
    }
    printf("\nAugmented number: %s\n", number);
    crc(n);
    printf("\nRemainder is: %s", remainder);

    for (i = number_length, j = 0; j < n - 1; i++, j++)
    {
        number[i] = remainder[j];
    }
    printf("\n\nData to be sent: %s", number);
    printf("\n");

    char received_number[15];
    printf("Enter the received data: ");
    scanf("%s", received_number);
    printf("\nData received: %s", received_number);

    strcpy(number, received_number);
    number_length = strlen(number);

    crc(n);
    bool errorFound = false;
    for (i = 0; i < n - 1; i++)
    {
        if (remainder[i] == '1')
        {
            errorFound = true; // Set flag if error is found
            break;
        }
    }

    if (errorFound)
    {
        printf("\nThere is an error in the received data\n\n");
    }
    else
    {
        printf("\nReceived data matches with sender data\n");
    }

    return 0;
}
