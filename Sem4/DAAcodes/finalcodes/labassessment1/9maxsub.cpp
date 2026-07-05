#include <iostream>
#include <climits>
using namespace std;
int max(int a, int b) {
    return (a > b) ? a : b; 
}
int max3(int a, int b, int c) { 
    return max(max(a, b), c); 
}
int crossSum(int low,int mid, int high, int arr[]){
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
int maxsum(int low,int high,int arr[]){
    if(low==high){
        return arr[low];
    }
    int mid=(low+high)/2;
    return max3(maxsum(low,mid,arr) , maxsum(mid+1,high, arr), crossSum(low,mid,high,arr));
}
void arrayprint(int arr[],int sum,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=0;
            for(int k=i;k<=j;k++){
                temp+=arr[k];
            }

            if(temp==sum){
                cout<<"Length: "<<j-i+1;
                for(int k=i;k<=j;k++){
                    cout<<arr[k]<<" ";
                }
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int sum=maxsum(0,n-1,arr);
    cout<<sum;
    arrayprint(arr,sum,n);
    return 0;
}