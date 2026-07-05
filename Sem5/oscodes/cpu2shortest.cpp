#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Process
{
    int id;
    float arrivalTime, burstTime, completionTime, turnaroundTime, waitingTime;
    int isCompleted;
};
void scheduleProcesses(vector<Process> &processes, int n)
{
    float currentTime = 0;
    float totalTurnaroundTime = 0;
    float totalWaitingTime = 0;
    int completedProcesses = 0;
    while (completedProcesses < n)
    {
        int shortestJobIndex = -1;
        float shortestBurstTime = 1e10;
        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted)
            {
                if (processes[i].burstTime < shortestBurstTime)
                {
                    shortestBurstTime = processes[i].burstTime;
                    shortestJobIndex = i;
                }
            }
        }
        if (shortestJobIndex == -1)
        {
            currentTime++;
            continue;
        }

        Process &p = processes[shortestJobIndex];
        p.completionTime = currentTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime; // cat
        p.waitingTime = p.turnaroundTime - p.burstTime;      // tbw
        p.isCompleted = 1;

        currentTime = p.completionTime;
        totalTurnaroundTime += p.turnaroundTime;
        totalWaitingTime += p.waitingTime;
        completedProcesses++;
    }

    float averageTurnaroundTime = totalTurnaroundTime / n;
    float averageWaitingTime = totalWaitingTime / n;

    // Print the results
    cout << "ProcessID\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t\t" << processes[i].burstTime << "\t\t"
             << processes[i].arrivalTime << "\t\t" << processes[i].completionTime << "\t\t"
             << processes[i].turnaroundTime << "\t\t" << processes[i].waitingTime << "\n";
    }

    cout << "\nAverage Turnaround Time: " << averageTurnaroundTime << "\n";
    cout << "Average Waiting Time: " << averageWaitingTime << "\n";
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes;
    for (int i = 0; i < n; i++)
    {
        float arrivalTime, burstTime;
        cout << "Enter the arrival time for process " << i << ": ";
        cin >> arrivalTime;
        cout << "Enter the burst time for process " << i << ": ";
        cin >> burstTime;

        Process p;
        p.id = i;
        p.arrivalTime = arrivalTime;
        p.burstTime = burstTime;

        processes.push_back(p);
    }

    sort(processes.begin(), processes.end(), [](Process a, Process b)
         { return a.arrivalTime < b.arrivalTime; });

    // Schedule the processes
    scheduleProcesses(processes, n);

    return 0;
}
