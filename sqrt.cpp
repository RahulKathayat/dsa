#include<iostream>
using namespace std;
int squarert(int n){
    //using binary search
    int s=0;
    int e=n;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

double precision(int number,int n,int m){
    double one=1;
    double ans=number;
    while(m--){
        one/=10;
        for(double i=ans;i*i<n;i+=one){
            ans=i;
        }
    }
    return ans;
}
int main(){
    int n,m;
    cout<<"enter number and how many decimal precision:";
    cin>>n>>m;
    int number=squarert(n);
    double precise=precision(number,n,m);
    cout<<precise;
}