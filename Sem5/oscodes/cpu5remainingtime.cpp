#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Process
{
    int id;
    float arrivalTime, burstTime, remainingTime, completionTime, turnaroundTime, waitingTime;
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
        int shortestJobIndex = -1;
        float shortestRemainingTime = 1e10;
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted)
            {
                if (processes[i].remainingTime < shortestRemainingTime)
                {
                    shortestRemainingTime = processes[i].remainingTime;
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
        p.remainingTime -= 1;
        currentTime++;
        // If process is completed after this execution slice
        if (p.remainingTime == 0)
        {
            p.completionTime = currentTime;
            p.turnaroundTime = p.completionTime - p.arrivalTime;
            p.waitingTime = p.turnaroundTime - p.burstTime;
            p.isCompleted = 1;
            count++;
            totalTurnaroundTime += p.turnaroundTime;
            totalWaitingTime += p.waitingTime;
        }
    }
    float averageTurnaroundTime = totalTurnaroundTime / n;
    float averageWaitingTime = totalWaitingTime / n;

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
        Process p;
        p.id = i;
        float arrivalTime, burstTime;
        cout << "Enter the arrival time for process " << i << ": ";
        cin >> p.arrivalTime;
        cout << "Enter the burst time for process " << i << ": ";
        cin >> p.burstTime;

        p.remainingTime = p.burstTime;
        p.isCompleted = 0;

        processes.push_back(p);
    }

    sort(processes.begin(), processes.end(), [](Process a, Process b)
         { return a.arrivalTime < b.arrivalTime; });

    scheduleProcesses(processes, n);

    return 0;
}
