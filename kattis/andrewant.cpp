#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct ant{
    int start;
    double pos,time;
    char dir;
} Ant;

typedef struct crash{
    list<int>::iterator a,b;
    long double time;
} Crash;

Ant Ants[100000];

bool cmp(int a, int b){
    return Ants[a].pos < Ants[b].pos;
}

bool heap_cmp(Crash c1, Crash c2){
    return c1.time > c2.time;
}

void solve(int l, int a){
    list<int> ants;
    for (int i=0;i<a;i++){
        cin >> Ants[i].start >> Ants[i].dir;
        Ants[i].pos = Ants[i].start;
        Ants[i].time = 0;
        ants.push_back(i);
    }
    ants.sort(cmp);

    int maxi = -1, max_pos = -1 , scnd_pos = -1;
    
    double time_left = 0;
    vector<Crash> crashes;
    list<int>::iterator prev = ants.end();
    for (auto i = ants.begin(); i!=ants.end(); i++){
        Crash new_crash;
        if (Ants[*i].dir == 'R'){
            prev = i;
            if (next(i) == ants.end()){
                new_crash.a = i;
                new_crash.b = ants.end();
                new_crash.time = l-Ants[*i].pos;
                crashes.push_back(new_crash);
                push_heap(crashes.begin(),crashes.end(),heap_cmp);
            }
        }else if (prev != ants.end()){
            new_crash.a = prev;
            new_crash.b = i;
            new_crash.time = Ants[*i].pos-(Ants[*prev].pos+Ants[*i].pos)/2;
            prev = ants.end();
            crashes.push_back(new_crash);
            push_heap(crashes.begin(),crashes.end(),heap_cmp);
        }else{
            new_crash.a = ants.end();
            new_crash.b = i;
            new_crash.time = Ants[*i].pos;
            crashes.push_back(new_crash);
            push_heap(crashes.begin(),crashes.end(),heap_cmp);
        }
    }

    while (!ants.empty()){
        Crash earliest = crashes.front();
        Crash new_crash;
        int old_a, old_b;
        pop_heap(crashes.begin(),crashes.end(),heap_cmp);
        crashes.pop_back();
        bool f=false;
        list<int>::iterator before,after;
        if (earliest.a != ants.end()){
            old_a = *earliest.a;
            before = prev(earliest.a);
            ants.erase(earliest.a);
        }else if (Ants[ants.front()].dir == 'L'){
            new_crash.a = ants.end();
            new_crash.b = ants.begin();
            new_crash.time = Ants[ants.front()].pos + Ants[ants.front()].time;
            f = true;
        }

        if (earliest.b != ants.end()){
            old_b = *earliest.b;
            after = next(earliest.b);
            ants.erase(earliest.b);
        }else if (Ants[ants.back()].dir == 'R'){
            new_crash.a = ants.rbegin();
            new_crash.b = ants.end();
            new_crash.time = l-Ants[ants.back()].pos+Ants[ants.back()].time;
            f = true;
        }

        if (!f){   
            Ants[old_a].time = earliest.time;
            Ants[old_b].time = earliest.time;
            Ants[old_a].pos += earliest.time;
            Ants[old_b].pos -= earliest.time;
            Ants[old_b].pos = 'R';
            Ants[old_a].pos = 'L';
            if (after == ants.end()){
                Crash new_crash;
                new_crash
            }
        }else{
            crashes.push_back(new_crash);
            push_heap(crashes.begin(),crashes.end(),heap_cmp);
        }
        

    }


    if (scnd_pos != -1){
        cout << maxi << " " << max_pos << " " << scnd_pos << "\n";
    }
    cout << maxi << " " << max_pos << "<\n";
}

int main(){
    int l,a;
    while (cin >> l >> a){
        solve(l,a);
    }
    


    return 0;   
}