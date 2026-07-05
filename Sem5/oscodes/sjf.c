#include <stdio.h>

#define MAX_PROCESSES 100

struct Process {
    int id;
    float arrivalTime;
    float burstTime;
    float completionTime;
    float turnaroundTime;
    float waitingTime;
    float responseTime;
    int isCompleted;
};

void sortByArrivalTime(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void scheduleProcesses(struct Process processes[], int n) {
    float currentTime = 0;
    float totalTurnaroundTime = 0;
    float totalWaitingTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int shortestJobIndex = -1;
        float shortestBurstTime = 1e10;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted) {
                if (processes[i].burstTime < shortestBurstTime) {
                    shortestBurstTime = processes[i].burstTime;
                    shortestJobIndex = i;
                }
            }
        }

        if (shortestJobIndex == -1) {
            currentTime++;
            continue;
        }

        struct Process *p = &processes[shortestJobIndex];
        p->completionTime = currentTime + p->burstTime;
        p->turnaroundTime = p->completionTime - p->arrivalTime;
        p->waitingTime = p->turnaroundTime - p->burstTime;
        p->responseTime = p->waitingTime;
        p->isCompleted = 1;

        currentTime = p->completionTime;
        totalTurnaroundTime += p->turnaroundTime;
        totalWaitingTime += p->waitingTime;
        completedProcesses++;
    }

    float averageTurnaroundTime = totalTurnaroundTime / n;
    float averageWaitingTime = totalWaitingTime / n;

    printf("ProcessID \t Burst Time \t Arrival Time \t Completion Time \t Turnaround Time \t Waiting Time \t Response Time\n");
    for (int i = 0; i < n; i++) {
        printf("%.d\t\t %.2f\t\t %.2f\t\t %.2f \t\t\t %.2f\t\t\t %.2f\t\t %.2f\n",
               processes[i].id, processes[i].burstTime, processes[i].arrivalTime, processes[i].completionTime,
               processes[i].turnaroundTime, processes[i].waitingTime, processes[i].responseTime);
    }

    printf("\nAverage Turnaround Time: %.2f\n", averageTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i;
        printf("Enter the arrival time for process %d: ", i);
        scanf("%f", &processes[i].arrivalTime);
        printf("Enter the burst time for process %d: ", i);
        scanf("%f", &processes[i].burstTime);
        processes[i].isCompleted = 0;
    }

    sortByArrivalTime(processes, n);
    scheduleProcesses(processes, n);

    return 0;
}
