#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

long long A[10], B[10];
long long Visited[1000001], N,M,S;

long long bfs(){
    queue<long long> numbers;
    long long steps = 0, last;
    numbers.push(S);
    last = S;
    Visited[S] = 1;

    while (!numbers.empty()){
        long long num = numbers.front();
        numbers.pop();
        
        for (int i=0;i<N;i++){
            long long next = (((num%M)*(A[i]%M))%M+(B[i]%M))%M;
            if (next == 0){
                return steps+1;
            }
            if (!Visited[next]){
                Visited[next] = 1;
                numbers.push(next);
            }
        }
        
        if (num==last){
            last = numbers.back();
            steps++;
        }
    }

    return -1;

}

int main(){
    cin >> M >> N >> S;
    for (int i=0;i<N;i++){
        cin >> A[i] >> B[i];
    }

    if (S==0){
        cout << "0\n";
        return 0;
    }

    cout << bfs() << "\n";

    return 0;
}