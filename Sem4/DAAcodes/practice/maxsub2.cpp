#include<iostream>
#include<climits>

using namespace std;

int max(int a,int b){
    return (a > b) ? a : b;
}
int max3(int a,int b,int c){
    return max(a,max(b,c));
}
int crossSum(int arr[],int low,int mid,int high){
    int sum=0;
    int left_sum=INT_MIN;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        if(sum>left_sum){
            left_sum=sum;
        }
    }
    sum=0;
    int right_sum=INT_MIN;
    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        if(sum>right_sum){
            right_sum=sum;
        }
    }
    return max3(left_sum,right_sum,left_sum+right_sum);
}
int maxSum(int arr[],int low,int high){
    if(low==high){
        return arr[low];
    }
    int mid = (low+high)/2;
    return max3(maxSum(arr,low,mid),maxSum(arr,mid+1,high),crossSum(arr,low,mid,high));
}
void arrayPrint(int sum,int arr[],int size){
    int leftindex,rightindex;
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
    arrayPrint(max_sum,arr,size);
}