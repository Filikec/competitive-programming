#include <iostream>
#include <limits>
#include <forward_list>
#include <queue>
#include <set>

using namespace std;

typedef struct line{
    long long start;
    long long end;
    long long dep;
    long long delta;
    long long duration;
} Line;

Line Lines[200000];
forward_list<Line*> Stops[100000];
queue<long long> Children;
long long Max_times[100000];

long long get_max_time(Line *line, long long max_time){
    if (max_time-line->duration-line->dep < 0){
        return -2;
    }
    return ((max_time-line->duration-line->dep)/line->delta)*line->delta + line->dep; //if negative, cannot make it
}

void to_children(long long stop){
    forward_list<Line*>::iterator ptr;
    for (ptr=Stops[stop].begin();ptr!=Stops[stop].end();ptr++){
        
        long long max_time = get_max_time(*ptr,Max_times[stop]);
        
        if (max_time > Max_times[(*ptr)->start] && max_time >= 0){
            Children.push((*ptr)->start);
            Max_times[(*ptr)->start] = max_time;
        }
    }
}

void solve(){
    long long next;

    while (!Children.empty()){
        next = Children.front();
        Children.pop();
        to_children(next);
    }
}  

int main(){
    long long n, m, s;

    cin >> n >> m >> s;

    for (long long i=0;i<n;i++){
        Max_times[i] = -1;
    }

    for (long long i=0;i<m;i++){
        cin >> Lines[i].start >> Lines[i].end >> Lines[i].dep >> Lines[i].delta >> Lines[i].duration;
        Stops[Lines[i].end].push_front(&Lines[i]);
    }

    Max_times[n-1] = s;
    Children.push(n-1);

    solve();
    
    if (Max_times[0] < 0){
        cout << "impossible\n";
    }else{
        cout << Max_times[0] << "\n";
    }

    return 0;
}