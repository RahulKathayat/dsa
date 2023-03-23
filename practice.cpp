#include <bits/stdc++.h>
using namespace std;

int recursion(int n,vector<int>& dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=recursion(n-1,dp)+recursion(n-2,dp);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(2);
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<recursion(n,dp);
    return 0;
}