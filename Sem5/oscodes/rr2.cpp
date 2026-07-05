#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the waiting time and completion time for all processes
void findTimes(int processes[], int n, int bt[], int at[], vector<int>& wt, vector<int>& ct, int quantum)
{
    vector<int> rem_bt(n);   // Using vector for remaining burst times
    queue<int> q;            // Queue for Round Robin scheduling

    // Initialize remaining burst times and arrival times
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }

    vector<int> arrival_time(at, at + n);
    vector<int> first_executed(n, false); // Track if a process has been executed at least once

    int t = 0; // Current time
    int completed = 0;

    // Process execution
    while (completed < n)
    {
        bool process_in_this_round = false;

        // Add processes that have arrived to the queue
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] <= t && rem_bt[i] > 0 && !first_executed[i])
            {
                q.push(i);
                first_executed[i] = true;
            }
        }

        if (!q.empty())
        {
            int idx = q.front();
            q.pop();

            process_in_this_round = true;

            if (rem_bt[idx] > quantum)
            {
                t += quantum;
                rem_bt[idx] -= quantum;
                // Re-add process to the queue if it's not completed
                q.push(idx);
            }
            else
            {
                t += rem_bt[idx];
                ct[idx] = t; // Completion time
                wt[idx] = t - bt[idx] - at[idx];
                rem_bt[idx] = 0;
                completed++;
            }
        }

        // If no process was executed in this round, advance time to the next process arrival
        if (!process_in_this_round)
        {
            int next_arrival_time = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                if (arrival_time[i] < next_arrival_time && rem_bt[i] > 0)
                {
                    next_arrival_time = arrival_time[i];
                }
            }
            if (next_arrival_time < INT_MAX) {
                t = next_arrival_time;
            }
        }
    }
}

// Function to calculate turnaround time
void findTurnAroundTime(int processes[], int n, int bt[], const vector<int>& wt, vector<int>& tat)
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int at[], int quantum)
{
    vector<int> wt(n), tat(n), ct(n);
    int total_wt = 0, total_tat = 0;

    // Function to find waiting time and completion time of all processes
    findTimes(processes, n, bt, at, wt, ct, quantum);

    // Function to find turnaround time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    cout << "Process Id\tExit time\tTurn Around time\tWaiting time\n";

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "P" << processes[i] << "\t\t" << ct[i] << "\t\t" << tat[i] << "\t\t\t" << wt[i] << endl;
    }

    // Display average waiting time and turnaround time with precision
    cout << "Average waiting time = " << fixed << setprecision(4) << (float)total_wt / n << endl;
    cout << "Average turnaround time = " << fixed << setprecision(4) << (float)total_tat / n << endl;
}

// Driver code
int main()
{
    // Process IDs
    int processes[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(processes) / sizeof(processes[0]);

    // Burst times of all processes
    int burst_time[] = {5, 6, 7, 9, 2, 3};

    // Arrival times of all processes
    int arrival_time[] = {5, 4, 3, 1, 2, 6};

    // Time quantum
    int quantum = 3;

    findavgTime(processes, n, burst_time, arrival_time, quantum);

    return 0;
}
