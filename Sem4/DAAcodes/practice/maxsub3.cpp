#include <iostream>
#include <climits>

int crossSum(int arr[],int low,int high){
    int sum=0;
    int left_sum=INT_MIN;
    for(int i=mid;i>=low;i++){
        sum+=arr[i];
        if(sum>left_sum){
            left_sum=sum;
        }
    }
    sum=0;
    int right_sum=INT_MIN;
    for(int i=mid+1;i<high;i++){
        sum+=arr[i];
        if(sum>right_sum){
            right_sum=sum;
        }
    }
    return max3(left_sum,right_sum,left_sum+right_sum);
}
int max_sum{
    if(low==high){
        return arr[low];
    }
    int mid = (low+high)/2;
    return max3(maxSum(arr,low,mid),maxSum(arr,mid+1,high),crossSum(arr,low,mid,high));
}