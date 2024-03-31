#include <bits/stdc++.h>

using namespace std;
int derangements(int N){
   if (N == 0)
      return 1;
   if (N == 1)
      return 0;
   if (N == 2)
      return 1;
   return (N - 1) * (derangements(N - 1) + derangements(N - 2));
}
int main(){
   int Numbers;
   cin >> Numbers;
   cout<<"Number of Derangements :"<<derangements(Numbers);
}