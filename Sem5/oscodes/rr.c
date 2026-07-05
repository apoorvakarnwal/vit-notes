#include <stdio.h>
#define MAX_PROCESSES 10

struct process {
    char pname[10];
    int bt, rt, wt, tt;
} p[MAX_PROCESSES];

int main() {
    int tq;
    int n;
    int i;
    int count = 0;
    int times = 0;
    int t[15];
    int sq = 0;
    float sum = 0.0, sum1 = 0.0;

    printf("Enter the value for quantum time: ");
    scanf("%d", &tq);

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", p[i].pname);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
    }

    printf("Gantt chart:\n");
    while (1) {
        for (i = 0, count = 0; i < n; i++) {
            int temp = tq;

            if (p[i].rt == 0) {
                count++;
                continue;
            } else if (p[i].rt >= tq) {
                p[i].rt -= tq;
                temp = tq;
            } else {
                temp = p[i].rt;
                p[i].rt = 0;
            }

            t[times++] = sq;
            sq += temp;
            p[i].tt = sq;

            printf("\t %s", p[i].pname);
            t[times] = sq;

            if (count == n) {
                break;
            }
        }
        if (count == n) {
            break;
        }
    }

    for (i = 0; i < n; i++) {
        p[i].wt = p[i].tt - p[i].bt; 
        sum += p[i].wt;
        sum1 += p[i].tt;
    }

    printf("\n");
    for (i = 0; i < times; i++) {
        printf("\t%d", t[i]);
    }
    printf("\n");

    printf("The average waiting time = %f\n", sum / n);
    printf("The average turnaround time = %f\n", sum1 / n);

    return 0;
}
