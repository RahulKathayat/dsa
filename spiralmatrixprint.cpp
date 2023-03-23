#include<bits/stdc++.h>
using namespace std;
int main() {
    int row=4,col=4;
    int total=row*col,count=0;
    int arr[row][col]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int sr=0,sc=0,er=row-1,ec=col-1;
    while(count<total){
        for(int i=sc;count<total && i<=ec;i++){
            cout<<arr[sr][i]<<" ";
            count++;
        }
        sr++;

        for(int i=sr;count<total && i<=er;i++){
            cout<<arr[i][ec]<<" ";
            count++;
        }
        ec--;

        for(int i=ec;count<total && i>=sc;i--){
            cout<<arr[er][i]<<" ";
            count++;
        }
        er--;

        for(int i=er;count<total && i>=sr;i--){
            cout<<arr[i][sc]<<" ";
            count++;
        }
        sc++;
    }
}