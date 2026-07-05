#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process
{
    int id;
    float arrivalTime, burstTime, completionTime, turnaroundTime, waitingTime;
    int priority; // Priority of the process (higher value means higher priority)
    int isCompleted;
};

void scheduleProcesses(vector<Process> &processes, int n)
{
    float currentTime = 0;
    float totalTurnaroundTime = 0;
    float totalWaitingTime = 0;
    int count = 0;

    while (count < n)
    {
        int highestPriorityIndex = -1;
        int highestPriority = -1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted)
            {
                if (processes[i].priority > highestPriority)
                {
                    highestPriority = processes[i].priority;
                    highestPriorityIndex = i;
                }
            }
        }
        if (highestPriorityIndex == -1)
        {
            currentTime++;
            continue;
        }

        Process &p = processes[highestPriorityIndex];
        p.completionTime = currentTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;
        p.isCompleted = 1;
        currentTime = p.completionTime;

        count++;
        totalTurnaroundTime += p.turnaroundTime;
        totalWaitingTime += p.waitingTime;
    }

    // Calculate average times
    float averageTurnaroundTime = totalTurnaroundTime / n;
    float averageWaitingTime = totalWaitingTime / n;

    // Print the results
    cout << "ProcessID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t"
             << processes[i].burstTime << "\t\t" << processes[i].priority << "\t\t"
             << processes[i].completionTime << "\t\t" << processes[i].turnaroundTime << "\t\t"
             << processes[i].waitingTime << "\n";
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

    // Input process details
    for (int i = 0; i < n; i++)
    {
        Process p;
        p.id = i + 1;
        cout << "Enter the arrival time for process " << p.id << ": ";
        cin >> p.arrivalTime;
        cout << "Enter the burst time for process " << p.id << ": ";
        cin >> p.burstTime;
        cout << "Enter the priority for process " << p.id << ": ";
        cin >> p.priority;

        p.isCompleted = 0; // Initially, no process is completed
        processes.push_back(p);
    }

    // Sort processes by arrival time (and by priority if arrival times are the same)
    sort(processes.begin(), processes.end(), [](Process a, Process b)
         {
             if (a.arrivalTime == b.arrivalTime)
             {
                 return a.priority > b.priority; // Sort by descending priority if arrival time is the same
             }
             return a.arrivalTime < b.arrivalTime; // Sort by arrival time
         });

    // Call the scheduling function
    scheduleProcesses(processes, n);

    return 0;
}
