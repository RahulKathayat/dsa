#include <bits/stdc++.h>
using namespace std;
void tower_of_hanoi(int num, string source, string dest, string helper) {
  if (num == 1) {
    cout << " Move disk 1 from tower " << source << " to tower " << dest << endl;
    return;
  }
  tower_of_hanoi(num - 1, source, helper, dest);
  cout << " Move disk " << num << " from tower " << source << " to tower " << dest << endl;
  tower_of_hanoi(num - 1, helper, dest, source);
}
int main() {
  int num;
  cin >> num;
  printf("The sequence of moves :\n");
  tower_of_hanoi(num, "I", "III", "II");
  return 0;
}