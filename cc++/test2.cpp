#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, char start, char end, char tmp){
   if (n==1){
      cout << start << end << '\n';
      return;
   }
   hanoi(n-1, start, tmp, end);
   cout << start << end << '\n';
   hanoi(n-1, tmp, end, start);
}

int main(){
   int n; cin >> n;
   hanoi(n, 'A', 'C', 'B');
   return 0;
}
