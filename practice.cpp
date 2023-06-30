#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int s,int e){
    int pivot=s,cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=arr[pivot]) cnt++;
    }
    pivot+=cnt;
    swap(arr[s],arr[pivot]);
    int i=s,j=e;
    while(i<pivot && j>pivot){
        while(arr[i] <= arr[pivot]) i++;
        while(arr[j] > arr[pivot]) j--;
        if(i<pivot && j>pivot){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivot;   
}
void quicksort(int arr[],int s,int e){
    if(s>=e) return;
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main() {
    int arr[]={8,4,3,71,8,3,1,9,9,9,9,8,0,7,88};
    int n=sizeof(arr)/sizeof(int);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}