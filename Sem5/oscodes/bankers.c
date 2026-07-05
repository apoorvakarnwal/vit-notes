#include <stdio.h>
#define P 5
#define R 4
int isSafeState(int alloc[P][R], int max[P][R], int avail[R], int need[P][R], int safeSeq[P])
{
    int work[R], finish[P] = {0}, count = 0;
    for (int i = 0; i < R; i++)
    {
        work[i] = avail[i];
    }
    while (count < P)
    {
        int found = 0;
        for (int p = 0; p < P; p++)
        {
            if (finish[p] == 0)
            {
                int i;
                for (i = 0; i < R; i++)
                {
                    if (need[p][i] > work[i])
                    {
                        break;
                    }
                }
                if (i == R)
                {
                    for (int i = 0; i < R; i++)
                    {
                        work[i] += alloc[p][i];
                    }
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            return 0;
    }
    return 1;
}
void calculateNeed(int need[P][R], int max[P][R], int alloc[P][R])
{
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}
int requestResources(int process, int request[R], int alloc[P][R], int max[P][R], int avail[R], int need[P][R])
{
    for (int i = 0; i < R; i++)
    {
        if (request[i] > need[process][i])
        {
            printf("Error: Process has exceeded its maximum claim.\n");
            return 0;
        }
    }
    for (int i = 0; i < R; i++)
    {
        if (request[i] > avail[i])
        {
            printf("Error: Not enough resources available.\n");
            return 0;
        }
    }
    for (int i = 0; i < R; i++)
    {
        avail[i] -= request[i];
        alloc[process][i] += request[i];
        need[process][i] -= request[i];
    }
    int safeSeq[P];
    if (isSafeState(alloc, max, avail, need, safeSeq))
    {
        printf("The request can be granted. System is in a safestate.\nSafe sequence: ");
        for (int i = 0; i < P; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
        return 1;
    }
    else
    {
        printf("The request cannot be granted. System would be in an unsafe state.\n");
        for (int i = 0; i < R; i++)
        {
            avail[i] += request[i];
            alloc[process][i] -= request[i];
            need[process][i] += request[i];
        }
        return 0;
    }
}

int main()
{
    int alloc[P][R] = {{0, 1, 0, 3}, {1, 0, 0, 1}, {1, 3, 2, 0}, {1, 2, 1, 2}, {0, 0, 1, 1}};
    int max[P][R] = {{0, 1, 0, 3}, {2, 2, 2, 2}, {3, 3, 2, 1}, {1, 2, 2, 2}, {1, 1, 1, 2}};
    int avail[R] = {2, 3, 1, 2};
    int need[P][R];
    calculateNeed(need, max, alloc);
    int safeSeq[P];
    if (isSafeState(alloc, max, avail, need, safeSeq))
    {
        printf("System is in a safe state.\nSafe sequence: ");
        for (int i = 0; i < P; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    }
    else
    {
        printf("System is not in a safe state.\n");
    }
    int request[R] = {1, 0, 1, 0};
    printf("Processing request from P1: [1, 0, 1, 0]\n");
    requestResources(1, request, alloc, max, avail, need);
    return 0;
}