#include <climits>
#include <iostream>
using namespace std;
//step 1 max functions
int max(int a,int b){
    return (a > b) ? a : b;
}
int max_of_three(int a, int b, int c){
    return max(a, max(b, c));
}
//step 2 cross sum
int crossSum(int arr[], int low, int mid, int high){
    int left_sum = INT_MIN;
    int sum = 0;
    for(int i = mid; i >= low; i--){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum;
        }
    }
    sum = 0;
    int right_sum = INT_MIN;
    for(int j = mid+1; j <= high ;j++){
        sum += arr[j];
        if(sum > right_sum){
            right_sum = sum;
        }
    }
    return max_of_three(left_sum, right_sum, (left_sum + right_sum));
}
//step 3 max sum
int maxSum(int arr[], int low, int high){
    if(low == high){
        return arr[low];
    }
    int mid = (low + high) / 2;
    return max_of_three(maxSum(arr, low, mid), maxSum(arr, mid + 1, high), crossSum(arr, low, mid, high));
}
void arrayPrint(int sum,int arr[],int size,int& leftindex, int& rightindex){
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            int temp = 0;
            for (int k = i; k <= j; ++k) {
                temp += arr[k];
            }
            if(temp==sum){
                leftindex=i;
                rightindex=j;
                break;
            }
        }
    }
    cout<<"length"<<rightindex-leftindex+1<<endl;
    cout<<"sum"<<sum<<endl;
    for(int i=leftindex;i<=rightindex;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {-2, 3, 4, -1,-2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSum(arr, 0, size - 1);
    int leftindex, rightindex;
    arrayPrint(max_sum,arr,size,leftindex,rightindex);
}