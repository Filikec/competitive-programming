#include <iostream>
#include <cmath>
#include <list>
#include <set>
#include <unordered_set>

using namespace std;


typedef long double ld;

list<ld> Distances;

ld getDist(ld e1, ld e2, ld s, ld d, ld t, bool big){
    d *= abs(e1-e2);
    if (big) return 2*sqrt(d*d+s*s)+2*t;
    else return 2*d+2*t;
}

void process(int n, ld d, ld s, ld t, list<int> &used, set<int> &av, ld total){
    if (used.back() == n-1){
        Distances.push_back(total);
        return;
    }

    for (auto it=av.begin();it!=av.end();it++){
        int cur = *it;
        int prev = used.back();

        av.erase(it);
        used.push_back(cur);
        
        for (int b=0;b<2;b++){
            if (!b && abs(prev-cur)!=1) continue;
            ld newD = getDist(prev,cur,s,d,t,b);
            process(n,d,s,t,used,av,total+newD);
        }

        used.pop_back();
        it = av.insert(cur).first;
    }
}

int main(){
    ld n,d,s,t,fs,ft;
    cin >> n >> d >> s >> t >> fs >> ft;
    
    list<int> used;
    set<int> av;

    for (int i=1;i<n;i++) av.insert(i);

    used = {0};
    process(n,d,s,t,used,av,s+2*t);
 
    ld l;
    while (cin >> l){
        int count = 0;
        for (auto v : Distances){
            ld f = (l-v)/2.0;
            if ( f >= fs && f <= ft){
                count++;
            }
        }
        cout << count << '\n';
    }
    
    return 0;
}





