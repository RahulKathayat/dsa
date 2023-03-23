#include <bits/stdc++.h>
using namespace std;
    
class disjointset{
    vector<int> rank,parent,size;
    public:
        disjointset(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++) parent[i]=i;
        }
        int findultparent(int node){
            if(parent[node]==node) return node;
            else return parent[node]=findultparent(parent[node]);
        }
        void unionbyrank(int u,int v){
            int ultu=findultparent(u);
            int ultv=findultparent(v);
            if(ultu==ultv) return;
            if(rank[ultu] < rank[ultv]){
                parent[ultu]=ultv;
            }
            else if(rank[ultu] > rank[ultv]){
                parent[ultv]=ultu;
            }
            else{
                parent[ultv]=ultu;
                rank[ultu]++;
            }
        }
        void unionbysize(int u,int v){
            int ultu=findultparent(u);
            int ultv=findultparent(v);
            if(ultu==ultv) return;
            if(size[ultu] < size[ultv]){
                parent[ultu]=ultv;
                size[ultv]+=size[ultu];
            }
            else{
                parent[ultv]=ultu;
                size[ultu]+=size[ultv];
            }
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(2);
    disjointset ds(7);
    ds.unionbysize(1,2);
    ds.unionbysize(2,3);
    ds.unionbysize(4,5);
    ds.unionbysize(6,7);
    ds.unionbysize(5,6);
    if(ds.findultparent(3)==ds.findultparent(7)) cout<< "same\n";
    else cout<<"not same\n";
    ds.unionbysize(3,7);
    if(ds.findultparent(3)==ds.findultparent(7)) cout<< "same\n";
    else cout<<"not same\n";
    return 0;
}