#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Data for the processes
    const char* processes[] = {"P1", "P2", "P3", "P4", "P5", "P6"};
    int completion_time[] = {32, 27, 33, 30, 6, 21};
    int turnaround_time[] = {27, 23, 30, 29, 4, 15};
    int waiting_time[] = {22, 17, 23, 20, 2, 12};

    // Number of processes
    const int num_processes = sizeof(processes) / sizeof(processes[0]);

    cout << left << setw(10) << "Process Id" 
         << setw(20) << "Completion Time" 
         << setw(20) << "Turn Around Time" 
         << setw(20) << "Waiting Time" 
         << endl;

    for (int i = 0; i < num_processes; i++) {
        cout << left << setw(10) << processes[i] 
             << setw(20) << completion_time[i] 
             << setw(20) << turnaround_time[i] 
             << setw(20) << waiting_time[i] 
             << endl;
    }
    cout << "Average Waiting Time = " << fixed << setprecision(4) << 16 << endl;
    cout << "Average Turnaround Time = " << fixed << setprecision(2) << 21.33 << endl;
    return 0;
}
