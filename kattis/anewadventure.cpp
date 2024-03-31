#include <bits/stdc++.h>



using namespace std;

char Board[100000];
map<pair<int,int>,int> States;
int N,A;

bool is_free(int index, int time){
    if (Board[(index+N*A-time*A)%(N*A)] == 'M' || Board[(index+N*A-(time-1)*A)%(N*A)] == 'M') return false;
    return true;
}

int main(){

    int n,a;
    int start;
    cin >> N >> A;
    n = N, a = A;

    for (int i=0;i<n;i++){
        for (int j=0;j<a;j++){
            cin >> Board[i*n+j];
            if (Board[i*n+j] == 'G') start = i*n+j;
        }
    }

    list<pair<int,int>> queue;
    queue.push_back(make_pair(start,0));


    int result = -1;
    while (queue.size()){
        auto curr = queue.front();
        queue.pop_front();

        int time = curr.second;
        int square = curr.first;

        int left = (square+n*a-a)%(n*a);
        int right = (square+a)%(n*a);
        int down = (square+1)%(n*a);

        if (square/a == n-1) result = time;  

        cout << square << "\n";

        auto it = States.find(make_pair(left,time+1));
        if (is_free(left,time%n) && (it == States.end() || (*it).second > time+1)){
            States[make_pair(left,time%n)] = time+1;
            queue.push_back(make_pair(left,time+1));
        }

        it = States.find(make_pair(right,time+1));
        if (is_free(right,time%n) && (it == States.end() || (*it).second > time+1)){
            States[make_pair(right,time%n)] = time+1;
            queue.push_back(make_pair(right,time+1));
        }

        it = States.find(make_pair(down,time+1));
        if (is_free(down,time%n) && (it == States.end() || (*it).second > time+1)){
            States[make_pair(down,time%n)] = time+1;
            queue.push_back(make_pair(down,time+1));
        }
    }

    cout << result << '\n';




    return 0;
}