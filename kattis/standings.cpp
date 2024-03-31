#include <bits/stdc++.h>

using namespace std;


bool cmp(pair<string,int> a, pair<string,int> b){
    return a.second < b.second;
}

void solve(){
    int n;
    cin >> n;
    
    vector<pair<string,int>> Teams;
    Teams.reserve(n);

    for (int i=0;i<n;i++){
        string name;
        int points;
        cin >> name >> points;

        pair<string,int> team = make_pair(name,points); 
        Teams.push_back(team);
    }

    sort(Teams.begin(),Teams.end(),cmp);

    long long sum = 0;
    for (int i=0;i<n;i++){
        sum += abs(Teams[i].second-(i+1));
    }
    cout << sum << "\n";
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++){
        solve();
    }



    return 0;
}