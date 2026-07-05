#include<iostream>
#include<climits>
using namespace std;
int max(int a,int b){
    return (a>b)?a:b;
}
int max3(int a,int b,int c){
    return max(a,max(b,c));
}
int crosssum(int low,int mid,int high,int arr[]){
    int sum=0;
    int leftsum=INT_MIN;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        if(sum>leftsum){
            leftsum=sum;
        }
    }
    sum=0;
    int rightsum=INT_MIN;
    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        if(sum>rightsum){
            rightsum=sum;
        }
    }
    return max3(leftsum,rightsum,leftsum+rightsum);
}
int maxSum(int low,int high,int arr[]){
    if(low==high){
        return arr[low];
    }
    int mid=(high+low)/2;
    return max3( maxSum(low,mid,arr), maxSum(mid+1,high,arr), crosssum(low,mid,high,arr));
}

void arrayPrint(int arr[],int n,int maxsum){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==maxsum){
                cout<<"length: "<<j-i+1;
                for(int k=i;k<=j;k++){
                    cout<<arr[k]<<" ";
                }
                break;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxSum(0,n-1,arr);
    arrayPrint(arr,n,maxSum(0,n-1,arr));

    return 0;
}