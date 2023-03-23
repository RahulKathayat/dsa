#include<iostream>
using namespace std;
int main(){
    int arr[]={0,1,1,1,1,2,3,3,4,5,5};
    int n=11,j;
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            cout<<arr[i]<<endl;
            for(j=i+1;arr[j]==arr[i];j++){

            }
            i=j-1;
        }
    }
    return 0;
}