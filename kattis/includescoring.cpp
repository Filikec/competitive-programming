#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int Scoring[30] = {100,75,60,50,45,40,36,32,29,26,24,22,20,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

struct Score{
    int p,t,f,o;
    int index,score;

    bool operator==(const Score& other) const {
        // Define your custom equality logic here
        return p == other.p && t==other.t && f==other.f;
    }
};



int main(){
    int n;
    cin >> n;

    vector<Score> ppl(n);

    for (int i=0;i<n;i++){
        int p,t,f,o;
        cin >> p >> t >> f >> o;
        ppl[i] = {p,t,f,o,i,0};
    }

    sort(ppl.begin(),ppl.end(),[&](Score a, Score b){ 
        if (a.p!=b.p) return a.p > b.p;
        if (a.t!=b.t) return a.t < b.t;
        return a.f < b.f;
    });


    for (int i=0;i<ppl.size()&&i<30;i++){
        double total = Scoring[i];
        int j = 1;
        while (i+j < ppl.size() && ppl[i]==ppl[i+j]){
            total += Scoring[i+j];
            j++;
        }
        int points = ceil(total/j);
        for (int k=i;k<i+j;k++) ppl[k].score += points;
        i += j-1;
    }

    sort(ppl.begin(),ppl.end(),[&](Score a, Score b){ 
        return a.index < b.index;
    });

    for (auto c : ppl){
        cout << c.score+c.o << '\n';
    }

    return 0;
}