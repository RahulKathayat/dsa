#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& ans,vector<int>& op,vector<int>& c,int target,int index,int sum){
        if(index==c.size()){
            if(sum==target){
                sort(op.begin(),op.end());
                ans.push_back(op);
                return;
            }
            return;
        }
        sum+=c[index];
        op.push_back(c[index]);
        solve(ans,op,c,target,index+1,sum);
        op.pop_back();
        sum-=c[index];
        solve(ans,op,c,target,index+1,sum);
    }

vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(ans,op,c,target,0,0);
        //set<vector<int>> a(ans.begin(),ans.end());
        //vector<vector<int>> a2(a.begin(),a.end());
        return ans;
}

int main(){
    
    return 0;
}