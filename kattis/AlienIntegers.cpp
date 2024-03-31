#include <iostream>
#include <set>
#include <vector>
#include <algorithm> 
#include <cmath>
#include <list>

using namespace std;


vector<int> number;



long long Num[15],Dynamic[16];

int getDigits(long long n){
    return ((int)(log10(n)));
}

long long eval(long long n){
    return abs(n-Num[getDigits(n)]);
}

bool possible(long long n, set<int> &available){
    while (n){
        int d = n%10;
        n /= 10;
        if (!available.count(d)) return false;
    }
    return true;
}


int main(){
    set<int> available = {0,1,2,3,4,5,6,7,8,9};

    string s;
    cin >> s;
    for (int i=0;i<s.size();i++){
        int c = s[i]-'0';
        available.erase(c);
        if (!i){
            Num[i] = c;
        }else{
            Num[i] = Num[i-1]*10+c;
        }
    }

    for (int i=0;i<16;i++){
        Dynamic[i] = -1;
    }
    Dynamic[0] = 0;

    for (int d=1;d<=s.size();d++){
        for (auto a : available){
            if (!a && d==1) continue;
            long long num = Dynamic[d-1]*10+a;
            if (Dynamic[d]==-1 || eval(Dynamic[d]) > eval(num)){
                Dynamic[d] = num;
            }
        }
    }

    long long best = -1;
    
    for (int i=1;i<=s.size();i++){
        if (abs(Num[s.size()-1]-best) > abs(Num[s.size()-1]-Dynamic[i])){
            best = Dynamic[i];
        }
    }

    if (best == -1 && available.count(0)){
        best = 0;
    }

    if (best == -1){
        cout << "Impossible\n";
    }else{
        list<long long> bests;
        long long diff = abs(Num[s.size()-1]-best);
        bests.push_back(Num[s.size()-1]-diff), bests.push_back(diff+Num[s.size()-1]);
        bests.sort([&](int a,int b){return a<b;});
        while (bests.size()){
            auto cur = bests.front();
            bests.pop_front();
            if (possible(cur,available)){
                cout << cur << ' ';
            }
        }
        cout << '\n';
    }
    

    return 0;
}