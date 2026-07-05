#include <stdio.h>
void implementFirstFitMultiProcess(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocate[processes];
    // int occupied[blocks];
    for (int i = 0; i < processes; i++)
    {
        allocate[i] = -1;
    }
    // for (int i = 0; i < blocks; i++)
    // {
    //     occupied[i] = 0;
    // }
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocate[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t%d \t\t", i + 1, processSize[i]);
        if (allocate[i] != -1)
        {
            printf("%d\n", allocate[i] + 1);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }
}

int main()
{
    int blockSize[] = {100, 50, 30, 120, 35};
    int processSize[] = {40, 10, 30, 60, 20, 15};
    int blocks = sizeof(blockSize) / sizeof(blockSize[0]);
    int processes = sizeof(processSize) / sizeof(processSize[0]);
    implementFirstFitMultiProcess(blockSize, blocks, processSize, processes);
    return 0;
}
