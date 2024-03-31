#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>

#define cmp heap.begin(),heap.end(),[&](int a, int b){return a > b;}

using namespace std;

unordered_set<int> Removed, Got;
unordered_map<int,int> Rank;
int Dynamic[100001];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;

    cin >> n >> k;


    list<int> sorted,students;
    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        students.push_back(tmp);
        sorted.push_back(tmp);
    }

    
    sorted.sort();
    int i=0,r=0;
    for (auto s : sorted){
        Rank[s]=r;
        i++;
        if (i%k==0) r++;
    }

    vector<int> ranking;
    ranking.push_back(0);
    for (auto s : students){
        ranking.push_back(Rank[s]);
    }
    Dynamic[0] = 0;
    int best = 0;
    for (int i=1;i<ranking.size();i++){
        int low=0,hi=best,r = ranking[i];
        while (low<hi){
            int middle = (low+hi)/2+(low+hi)%2;
            if (Dynamic[middle]==-1){
                hi = middle-1;
            }else if (ranking[Dynamic[middle]] > r){
                hi = middle-1;
            }else{
                low = middle;
            }
        }
        if (low+1>best || ranking[Dynamic[low+1]] > r){
            Dynamic[low+1] = i;
            best = max(best,low+1);
        }
    }
    cout << n-best << '\n';
    
    
    return 0;
}

