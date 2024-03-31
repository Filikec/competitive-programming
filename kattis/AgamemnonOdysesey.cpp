#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

list<int> Graph[200001];
unordered_map<long long,long long> Res;

long long getIndex(long long n1, long long n2){
    return n1*1000000+n2;
}

long long Best = 0;
long long Count = 0;

long long find(int node,long long got=0,int prev=-1){
    Count++;
    long long bestOne = 0, bestSnd = 0;

    for (auto neigh : Graph[node]){
        if (neigh != prev){
            
            long long newRoute = Res[getIndex(node,neigh)]+find(neigh,got+Res[getIndex(node,neigh)],node);
            
            if (newRoute > bestOne){
                bestSnd = bestOne;
                bestOne = newRoute;
            }else if (newRoute > bestSnd){
                bestSnd = newRoute;
            }

        }
    }
    
    Best = max(max(Best,bestOne+got),bestOne+bestSnd);
    
    return bestOne;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,k;

    cin >> n >> k;


    long long sum = 0;
    for (int i=0;i<n-1;i++){
        long long a,b,c;

        cin >> a >> b >> c;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        Res[getIndex(a,b)] = c;
        Res[getIndex(b,a)] = c;
        sum += c;
    }

    if (k>1){
        cout << sum << '\n';
        return 0;
    }

    find(1);
    
    cout << Best << ' ' << Count << '\n';


    return 0;
}