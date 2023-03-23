#include <iostream>
using namespace std;
void fib(int n,int f,int s){
    cout<<f+s<<" ";
    n--;
    if(n==0){
        return;
    }
    return fib(n,s,f+s);
}
int main() {
	int n;
    cin>>n;
    int f=0,s=1;
    cout<<f<<" "<<s<<" ";
    n=n-2;
    fib(n,f,s);
    return 0;
}
