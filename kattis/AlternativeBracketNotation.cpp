#include <iostream>
#include <string>
#include <list>
#include <cmath>

using namespace std;


int getCount(int d){
    return ceil(log10(d))+1;
}

int update(list<int> &l, int u){
    int c = 0;
    for (auto &n : l){
        int d = ceil(log10(n+u))-ceil(log10(n));
        n += u;
        u += d;
        c += d;  
    }
    return c;
}

pair<list<int>,int> makeString(string &s, int i=0){
    if (s.size() == i) return {{},0};

    if (s[i] == '('){
        auto p = makeString(s,i+1);
        int p1 = 4;
        int p2 = p.second;
        int newS = p.second+1;

        int u = 2+getCount(p2);
        while (u){
            newS += u;
            u = update(p.first,u); 
        }

        p.first.push_front(p2);
        p.first.push_front(p1);

        for (auto n : p.first) cout << n << ' ';
        cout << "<\n";
        return {p.first, newS};
    }else{
        cout << 4 << ' ' << 4 << '\n';
        return {{4,4}, 4};
    }
} 


int main(){
    string line;
    getline(cin,line);

    bool f = true;
    for (auto c : makeString(line).first){
        if (f) cout << c << ',';
        else cout << c << ':';
        f = !f;
    }
    cout << '\n';

    return 0;
}