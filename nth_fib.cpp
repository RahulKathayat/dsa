#include <iostream>
#include <vector>
using namespace std;
int fib(int x,int n,int f,int s){
    vector<int> v;
    v.push_back(f+s);
    if(x==n){
        return v[v.size()-1];
    }
    x++;
    return fib(x,n,s,f+s);
}
int main() {
	int n;
    cin>>n;
    int f=0,s=1;
    if(n<=0){
        cout<<"not possible";
    }
    else if(n==1){
        cout<<n<<" number is = "<<f<<" ";
    }
    else if(n==2){
        cout<<n<<" number is = "<<s<<" ";
    }
    else{
        int ans = fib(3,n,f,s);
        cout<<n<<" number is = "<<ans;
    }
    return 0;
}
