#include <iostream>

using namespace std;

// Function to update the ready queue when a new process arrives
void queueUpdation(int queue[], int timer, int arrival[], int n, int maxProccessIndex)
{
    int zeroIndex;
    for (int i = 0; i < n; i++)
    {
        if (queue[i] == 0)
        {
            zeroIndex = i;
            break;
        }
    }
    queue[zeroIndex] = maxProccessIndex + 1;
}

// Function to maintain the entries in the ready queue after each preemption
void queueMaintainence(int queue[], int n)
{
    for (int i = 0; (i < n - 1) && (queue[i + 1] != 0); i++)
    {
        int temp = queue[i];
        queue[i] = queue[i + 1];
        queue[i + 1] = temp;
    }
}

// Function to check for new arrivals and update the ready queue
void checkNewArrival(int timer, int arrival[], int n, int maxProccessIndex, int queue[])
{
    if (timer <= arrival[n - 1])
    {
        bool newArrival = false;
        for (int j = (maxProccessIndex + 1); j < n; j++)
        {
            if (arrival[j] <= timer)
            {
                if (maxProccessIndex < j)
                {
                    maxProccessIndex = j;
                    newArrival = true;
                }
            }
        }
        // Add the incoming process to the ready queue if any arrives
        if (newArrival)
            queueUpdation(queue, timer, arrival, n, maxProccessIndex);
    }
}

int main()
{
    int n, tq, timer = 0, maxProccessIndex = 0;
    float avgWait = 0, avgTT = 0;

    // Taking input for time quantum and number of processes
    cout << "\nEnter the time quanta : ";
    cin >> tq;
    cout << "\nEnter the number of processes : ";
    cin >> n;

    int arrival[n], burst[n], wait[n], turn[n], queue[n], temp_burst[n];
    bool complete[n];

    // Taking input for arrival time and burst time of processes
    cout << "\nEnter the arrival time of the processes : ";
    for (int i = 0; i < n; i++)
        cin >> arrival[i];

    cout << "\nEnter the burst time of the processes : ";
    for (int i = 0; i < n; i++)
    {
        cin >> burst[i];
        temp_burst[i] = burst[i]; // Copy the burst times to temp_burst[] for processing
    }

    // Initializing the queue and the 'complete' array
    for (int i = 0; i < n; i++)
    {
        complete[i] = false;
        queue[i] = 0;
    }

    // Incrementing timer until the first process arrives
    while (timer < arrival[0])
        timer++;

    queue[0] = 1; // Add the first process to the ready queue

    // Round Robin Scheduling loop
    while (true)
    {
        bool flag = true;
        // Check if all processes are completed
        for (int i = 0; i < n; i++)
        {
            if (temp_burst[i] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            break; // If all processes are completed, exit the loop

        // Process the ready queue
        for (int i = 0; (i < n) && (queue[i] != 0); i++)
        {
            int ctr = 0;
            while ((ctr < tq) && (temp_burst[queue[0] - 1] > 0))
            {
                temp_burst[queue[0] - 1] -= 1; // Decrease the burst time
                timer += 1;                    // Increment the timer
                ctr++;

                // Checking and updating the ready queue as processes arrive
                checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
            }

            // If a process is completed, record its completion time
            if ((temp_burst[queue[0] - 1] == 0) && (complete[queue[0] - 1] == false))
            {
                turn[queue[0] - 1] = timer;    // Turnaround time (Completion time)
                complete[queue[0] - 1] = true; // Mark the process as completed
            }

            // Check if CPU is idle (i.e., there are no processes in the ready queue)
            bool idle = true;
            if (queue[n - 1] == 0)
            {
                for (int i = 0; i < n && queue[i] != 0; i++)
                {
                    if (complete[queue[i] - 1] == false)
                    {
                        idle = false; // If any process is not completed, CPU is not idle
                    }
                }
            }
            else
            {
                idle = false;
            }

            if (idle)
            {
                timer++;                                                     // Increment timer when CPU is idle
                checkNewArrival(timer, arrival, n, maxProccessIndex, queue); // Check for new arrivals
            }

            // Maintain the ready queue by shifting the completed processes
            queueMaintainence(queue, n);
        }
    }

    // Calculating Turnaround Time and Waiting Time
    for (int i = 0; i < n; i++)
    {
        turn[i] = turn[i] - arrival[i]; // Turnaround Time = Completion Time - Arrival Time
        wait[i] = turn[i] - burst[i];   // Waiting Time = Turnaround Time - Burst Time
    }

    // Displaying results
    cout << "\nProgram No.\tArrival Time\tBurst Time\tWait Time\tTurnAround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << arrival[i] << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << turn[i] << endl;
    }

    // Calculate average waiting time and turnaround time
    for (int i = 0; i < n; i++)
    {
        avgWait += wait[i];
        avgTT += turn[i];
    }

    cout << "\nAverage wait time : " << (avgWait / n) << "\nAverage Turn Around Time : " << (avgTT / n) << endl;

    return 0;
}
