#include <stdio.h>
#define NUM_FRAMES 3

// FIFO Page Replacement Algorithm
int fifo(int pages[], int total_pages)
{
    int frames[NUM_FRAMES] = {-1};
    int page_fault = 0;
    int next_frame = 0;

    for (int i = 0; i < total_pages; i++)
    {
        printf("%d: ", pages[i]);
        int page_found = 0;
        for (int j = 0; j < NUM_FRAMES; j++)
        {
            if (frames[j] == pages[i])
            {
                page_found = 1;
                break;
            }
        }
        if (!page_found)
        {
            frames[next_frame % NUM_FRAMES] = pages[i];
            next_frame++;
            page_fault++;
        }

        for (int j = 0; j < NUM_FRAMES; j++)
        {
            printf("%d\t", frames[j]);
        }
        printf("\n");
    }

    return page_fault;
}

int lru(int pages[], int n)
{
    int frames[NUM_FRAMES] = {-1};
    int page_faults = 0;
    int last_used[NUM_FRAMES] = {0};

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < NUM_FRAMES; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                last_used[j] = i;
                break;
            }
        }
        if (!found)
        {
            int lru_index = 0;
            for (int j = 1; j < NUM_FRAMES; j++)
            {
                if (last_used[j] < last_used[lru_index])
                {
                    lru_index = j;
                }
            }
            frames[lru_index] = pages[i];
            last_used[lru_index] = i;
            page_faults++;
        }
        // Print current state of frames
        for (int j = 0; j < NUM_FRAMES; j++)
        {
            printf("%d\t", frames[j]);
        }
        printf("\n");
    }
    return page_faults;
}
// Optimal Page Replacement Algorithm
int optimal(int pages[], int total_pages)
{
    int frames[NUM_FRAMES] = {-1};
    int page_fault = 0;
    for (int i = 0; i < total_pages; i++)
    {
        printf("%d: ", pages[i]);
        int found = 0;
        for (int j = 0; j < NUM_FRAMES; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int optimal_idx = -1;
            int farthest = i + 1;
            for (int j = 0; j < NUM_FRAMES; j++)
            {
                int k;
                for (k = i + 1; k < total_pages; k++)
                {
                    if (frames[j] == pages[k])
                        break;
                }
                if (k == total_pages)
                {
                    optimal_idx = j;
                    break;
                }
                else if (k > farthest)
                {
                    farthest = k;
                    optimal_idx = j;
                }
            }

            frames[optimal_idx] = pages[i];
            page_fault++;
        }

        for (int j = 0; j < NUM_FRAMES; j++)
        {
            printf("%d\t", frames[j]);
        }
        printf("\n");
    }

    return page_fault;
}

int main()
{
    int n;
    printf("Enter number of page references: ");
    scanf("%d", &n);

    int pages[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter page reference %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    int total_pages = n;
    printf("FIFO Page Replacement Algorithm:\n");
    int fifo_faults = fifo(pages, total_pages);
    printf("Total Number of Page Faults (FIFO): %d\n\n", fifo_faults);

    printf("LRU Page Replacement Algorithm:\n");
    int lru_faults = lru(pages, total_pages);
    printf("Total Number of Page Faults (LRU): %d\n\n", lru_faults);

    printf("Optimal Page Replacement Algorithm:\n");
    int optimal_faults = optimal(pages, total_pages);
    printf("Total Number of Page Faults (Optimal): %d\n", optimal_faults);

    return 0;
}