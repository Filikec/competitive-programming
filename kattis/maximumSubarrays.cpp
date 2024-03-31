#include <iostream>
#include <list>
#include <climits>

using namespace std;

typedef long long ld;

list<pair<pair<ld,ld>,ld>> Sequences;
ld Sums[50001];

int main(){
    ld n,k;

    ld sum = 0;

    cin >> n >> k;

    for (ld i=0;i<n;i++){
        ld num;
        cin >> num;

        sum += num;

        if (!i){
            Sums[i] = num;
        }else{
            Sums[i] = Sums[i-1]+num;
        }

        Sequences.push_back({{i,i},num});
    }

    while (Sequences.size() > k){
         
        auto it1 = Sequences.begin(), it2 = Sequences.begin(), smallest = Sequences.begin();
        ld best = LLONG_MIN;
        for (auto it = Sequences.begin(); next(it)!= Sequences.end();it++){
            auto s = next(it);
            ld start = it->first.second,end=s->first.first;

            if (s->second < smallest->second) smallest = s;

            ld dif = Sums[end-1]-Sums[start];

            if (dif > best){
                best = dif;
                it1 = it;
                it2 = s;
            }
        }

        if (sum - smallest->second > sum + best ){
            Sequences.erase(smallest);
            sum -= smallest->second;
        }else{
            it1->second += best+it2->second;
            it1->first.second = it2->first.second;
            sum += best;
            Sequences.erase(it2);
        }
    }

    cout << sum << "\n";

    
       

    return 0;
}