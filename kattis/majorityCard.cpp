#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

string getString(){
    char c;
    string s;
    c = getchar();
    while (c != ' ' && c != '\n' && c){
        s += c;
        c = getchar();
    }
    return s;
}

int getInt(){
    char c;
    int n=0;
    c = getchar();
    while (c != ' ' && c != '\n' && c){
        n = n*10+c-'0';
        c = getchar();
    }
    return n;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    n = getInt();

    unordered_map<int,int> count;
    auto cmp = [&](const pii &a, const pii &b) {return a.first==b.first?a.second<b.second:a.first>b.first;};
    set<pii,decltype(cmp)> heap(cmp);
    list<pii> q;

    while (n--){
        string s;
        int a,b;
        s = getString();

        if (s[0] == 'P' && s[4] == 'T'){
            a = getInt(), b = getInt();
            if (count.find(b) != count.end()) heap.erase({count[b],b});
            count[b] += a, heap.insert({count[b],b}); 
            q.push_front({a,b});
        }else if (s[0] == 'P' && s[4] == 'B'){
            a = getInt(), b = getInt();
            if (count.find(b) != count.end()) heap.erase({count[b],b});
            count[b] += a, heap.insert({count[b],b}); 
            q.push_back({a,b});
        }else if (s[0] == 'R' && s[7] == 'T'){
            a = getInt();
            while (a){
                int r = min(q.front().first,a);
                heap.erase({count[q.front().second],q.front().second});
                count[q.front().second] -= r;
                heap.insert({count[q.front().second],q.front().second});
                q.front().first -= r;
                if (!q.front().first) q.pop_front();
                a -= r;
            }
        }else{
            a = getInt();
            while (a){
                int r = min(q.back().first,a);
                heap.erase({count[q.back().second],q.back().second});
                count[q.back().second] -= r;
                heap.insert({count[q.back().second],q.back().second});
                q.back().first -= r;
                if (!q.back().first) q.pop_back();
                a -= r;
            }
        }
        cout << heap.begin()->second << '\n';
    }

    return 0;
}