#include <iostream>
#include <algorithm>
#include <list>
#include <limits>

using namespace std;

typedef struct interval{
    double start, end;
    int index;
} Interval;

Interval Intervals[20000];

bool comp(Interval a, Interval b){
    return a.start < b.start;
}

void solve(double a, double b){
    int n;
    double current = a;
    cin >> n;
    list<int> used;

    for (int i=0;i<n;i++){
        cin >> Intervals[i].start >> Intervals[i].end;
        Intervals[i].index = i;
    }

    sort(Intervals,Intervals+n,comp);

    if (a==b){
        for (int i=0;i<n;i++){
            if (Intervals[i].start<=a && Intervals[i].end>=a){
                cout << 1 << '\n';
                cout << Intervals[i].index << '\n';
                return;
            }
        }
        cout << "impossible\n";
        return;
    }
    
    int i = 0;
    while (current < b){
        double biggest = numeric_limits<double>::lowest();
        int biggest_i = -1;
        while (i < n && Intervals[i].start<=current){
            if (Intervals[i].end > biggest){
                biggest = Intervals[i].end;
                biggest_i = i;
            }
            i++;
        }
        if (biggest_i==-1) break;
        current = biggest;
        used.push_back(biggest_i);
    }

    if (current >= b){
        cout << used.size() << '\n';
        for (auto interval : used){
            cout << Intervals[interval].index << ' ';
        }
        cout << '\n';
    }else{
        cout << "impossible\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a,b;

    while (cin >> a >> b){
        solve(a,b);
    }


    return 0;
}