#include <bits/stdc++.h>

using namespace std;

template<class A, class B>
struct MyMultiset{
    multiset<A,B> s;
    long long sum;
    MyMultiset(B cmp) : s(cmp), sum(0) {}
    void add(A v){
        s.insert(v);
        sum += v;
    }
    void remove(A v){
        s.erase(s.find(v));
        sum -= v;
    }
};

int main(){

    int n,k;
    cin >> n >> k;

    list<long long> q;
    auto cmp1 = [](auto a,auto b){ return a<b;};
    MyMultiset<long long,decltype(cmp1)> r(cmp1);
    auto cmp2 = [](auto a,auto b){ return a>b;};
    MyMultiset<long long,decltype(cmp2)> l(cmp2);

    for (int i=0;i<k;i++){
        long long c;
        cin >> c;
        q.push_back(c);
        r.add(c);
    }

    while (r.s.size() > l.s.size()) l.add(*r.s.begin()), r.remove(*r.s.begin());

    for (int i=0;i<n-k;i++){
        long long c;
        cin >> c;

        cout << ((long long)l.s.size()-1)**l.s.begin() - l.sum+*l.s.begin() - (long long)r.s.size()**l.s.begin() + r.sum<< ' ';

        if (l.s.contains(q.front())) l.remove(q.front());
        else r.remove(q.front());
        q.pop_front();

        if (*l.s.begin() >= c) l.add(c);
        else r.add(c);
        q.push_back(c);

        while (l.s.size() > r.s.size()+1) r.add(*l.s.begin()), l.remove(*l.s.begin());
        while (r.s.size() > l.s.size()) l.add(*r.s.begin()), r.remove(*r.s.begin());
    }

    cout << ((long long)l.s.size()-1)**l.s.begin() - l.sum+*l.s.begin() - (long long)r.s.size()**l.s.begin() + r.sum<< ' ';

    return 0;
}