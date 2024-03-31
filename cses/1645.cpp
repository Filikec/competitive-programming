#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int>v(n);
    for (auto &c:v)cin >> c;

    list<int> q;

    for (int i=0;i<n;i++){
        while (q.size() && v[q.front()] >= v[i]) q.pop_front();
        if (q.size()) cout << q.front()+1 << ' ';
        else cout << "0 ";
        q.push_front(i);
    }
    cout << '\n';


    return 0;
}