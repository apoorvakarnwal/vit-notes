#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Process
{
    int arrivalTime, burstTime, waitingTime, turnaroundTime, processId, completionTime;
};

void FCFS(vector<Process> &processes)
{
    int n = processes.size();

    processes[0].waitingTime = 0;
    processes[0].completionTime = processes[0].arrivalTime + processes[0].burstTime;

    for (int i = 1; i < n; i++)
    {
        processes[i].waitingTime = processes[i - 1].completionTime - processes[i].arrivalTime;
        if (processes[i].waitingTime < 0)
        {
            processes[i].waitingTime = 0;
        }
        processes[i].completionTime = processes[i].arrivalTime + processes[i].waitingTime + processes[i].burstTime;
    }
    for (int i = 0; i < n; i++)
    {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void displayResults(const vector<Process> &processes)
{
    float totalWaitTime = 0, totalTurnaroundTime = 0;
    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for (const auto &p : processes)
    {
        cout << "P" << p.processId << "\t" << p.arrivalTime << "\t\t" << p.burstTime
             << "\t\t" << p.waitingTime << "\t\t" << p.turnaroundTime << "\t\t" << p.completionTime << endl;
        totalWaitTime += p.waitingTime;
        totalTurnaroundTime += p.turnaroundTime;
    }

    cout << "Average Waiting Time: " << totalWaitTime / processes.size() << endl;
    cout << "Average Turnaround Time: " << totalTurnaroundTime / processes.size() << endl;
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++)
    {
        processes[i].processId = i + 1;
        cout << "Enter arrival time for Process P" << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for Process P" << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), [](Process a, Process b)
         { return a.arrivalTime < b.arrivalTime; });

    FCFS(processes);

    displayResults(processes);

    return 0;
}
