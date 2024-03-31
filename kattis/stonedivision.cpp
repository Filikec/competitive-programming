#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

long long Possible[10];
vector<long long> Dividers;
unordered_map<long long, int> Visited;
long long N,M;


int divide(long long stones, int player, long long piles){
    int opponent, flag = 0;

    if (Visited.count(stones)){
        return Visited[stones];
    }

    opponent = player==1?0:1;

    for (auto n : Dividers){
        if (stones % n == 0 && divide(stones/n,opponent,n) == player){
            flag = 1;
            break;
        }
    }

    if (flag){
        if (piles%2){
            Visited.emplace(stones,player);
            return player;
        }
        Visited.emplace(stones,opponent);
        return opponent;
    }
    Visited.emplace(stones,opponent);
    return opponent;
}

int main(){
    long long s;

    Dividers.reserve(10);
    
    cin >> N >> M;

    for (int i=0;i<M;i++){
        cin >> s;
        if (N%s == 0){
            Dividers.push_back(s);
        }
    }

    if (divide(N,0,1)){
        cout << "Second\n";
    }else{
        cout << "First\n";
    } 

    return 0;
}