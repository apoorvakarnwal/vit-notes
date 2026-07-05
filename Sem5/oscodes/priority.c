#include <stdio.h>
#define MAX_PROCESSES 100

struct Process {
    int priority;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
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
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;
    int completedProcesses = 0;
    
    while (completedProcesses < n) {
        int maxPriorityIndex = -1;
        int maxPriority = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted) {
                if (processes[i].priority > maxPriority) {
                    maxPriority = processes[i].priority;
                    maxPriorityIndex = i;
                }
            }
        }

        if (maxPriorityIndex == -1) {
            currentTime++;
            continue;
        }

        struct Process *p = &processes[maxPriorityIndex];
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

    int averageTurnaroundTime = totalTurnaroundTime / n;
    int averageWaitingTime = totalWaitingTime / n;

    printf("ProcessNo \t Burst Time \t Arrival Time \t Completion Time \t Turnaround Time \t Waiting Time \t Response Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\t\t %d\n",
               i, processes[i].burstTime, processes[i].arrivalTime, processes[i].completionTime,
               processes[i].turnaroundTime, processes[i].waitingTime, processes[i].responseTime);
    }

    printf("\nAverage Turnaround Time: %d\n", averageTurnaroundTime);
    printf("Average Waiting Time: %d\n", averageWaitingTime);
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time for process %d: ", i);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &processes[i].burstTime);
        printf("Enter the priority for process %d: ", i);
        scanf("%d", &processes[i].priority);
        processes[i].isCompleted = 0;
    }
    sortByArrivalTime(processes, n);
    scheduleProcesses(processes, n);
    return 0;
}