#include <iostream>
#include <algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot_index=low + rand()%(high-low+1);
    swap(arr[pivot_index],arr[high]);
    int pivot=arr[high];
    
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    srand(time(NULL));
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// #include <iostream>
// using namespace std;
// # define max 100

// bool clique(int graph[max][max], int subset[max],int n,int k){
//     int count=0;
//     for(int i=0;i<n;i++){
//         if(subset[i]){
//             count++;
//         }
//     }
//     if(count!=k){
//         return false;
//     }
//     for(int i=0;i<n;i++){
//         if(subset[i]){
//             for(int j=i+1;j<n;j++){
//                 if(subset[j] && !graph[i][j]){
//                     return false;
//                 }
//             }
//         }
//     }
//     return true;
// }
// int main(){
//     int n,k;
//     cin>>n;
//     int graph[max][max];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>graph[i][j];
//         }
//     }
//     cin>>k;
//     int subset[max];
//     for(int j=0;j<k;j++){
//         cin>>subset[j];
//     }
//     if (clique(graph,subset,n,k)){
//         cout<<"True";
//     }
//     else{
//         cout<<"False";
//     }
//     return 0;
// }