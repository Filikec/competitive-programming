#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>


#define INF 100001

using namespace std;

int Distances[100001];


string intToStr(int n){
    string s;
    while (n){
        s += n%10+'0';
        n /= 10;
    }
    reverse(s.begin(),s.end());
    return s;
}

int strToInt(string s){
    int n=0;
    for (int i=0;i<s.size();i++){
        n += (s[i]-'0')*pow(10,s.size()-i-1);
    }
    return n;
}


int main(){
    int n;

    Distances[0] = INF;
    Distances[1] = 1;
    cin >> n;

    for (int i=2;i<=n;i++){
        Distances[i] = INF;
        for (int j=1;j<=i/2;j++){
            Distances[i] = min(Distances[i],Distances[j]+Distances[i-j]);
        }
        for (int j=2;j<sqrt(i+1);j++){
            if (i % j == 0) Distances[i] = min(Distances[i],Distances[j]+Distances[i/j]);
        }
        string s = intToStr(i);
        for (int j=1;j<s.size();j++){
            string l = s.substr(0,j);
            string r = s.substr(j);
            if (r.front() == '0') continue;
            Distances[i] = min(Distances[i],Distances[strToInt(l)]+Distances[strToInt(r)]);
        }   
    }

    
    cout << Distances[n] << '\n';

    return 0;   
}