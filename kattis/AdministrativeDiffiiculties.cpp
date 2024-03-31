#include <iostream>
#include <unordered_map>
#include <list>
#include <cmath>
#include <climits>

using namespace std;



void work(){
    int n,m;

    cin >> n >> m;

    unordered_map<string,long long> Catalog,Pickup,Km,Paid;
    unordered_map<string,string> Status;

    for (int i=0;i<n;i++){
        string s;
        long long c,p,k;
        cin >> s >> c >> p >> k;

        Catalog[s] = c;
        Pickup[s] = p;
        Km[s] = k;
    }

    for (int i=0;i<m;i++){
        string name,e;
        int t;
        cin >> t >> name >> e;


        auto it = Paid.find(name);
        if (it == Paid.end()){
            Paid[name] = 0;
            Status[name] = "";
        }

        if (Paid[name] < 0){
            string skip;
            cin >> skip;
            continue;
        }

        if (e == "p"){
            string car;
            cin >> car;

            if (Status[name] != ""){
                Paid[name] = -1;
            }else{
                Status[name] = car;
                Paid[name] += Pickup[car];
            }
        }else if (e == "r"){
            long long driven;
            cin >> driven;

            if (Status[name] == ""){
                Paid[name] = -1;
            }else{
                Paid[name] += Km[Status[name]]*driven;
                Status[name] = "";
            }
        }else{
            double percentage;
            cin >> percentage;
            percentage /= 100.0;

            if (Status[name] == ""){
                Paid[name] = -1;
            }else{
                Paid[name] += ceil(((double)Catalog[Status[name]])*percentage);
            }
        }
    }

    list<pair<string,long long>> data;
    for (auto n : Status){
        if (n.second != ""){
            Paid[n.first] = -1;
        }
        data.push_back({n.first,Paid[n.first]});
    }
    data.sort([&](pair<string,long long>a, pair<string,long long>b){return a.first<b.first;});
    for (auto d : data){
        cout << d.first << ' ';
        if (d.second < 0){
            cout << "INCONSISTENT\n";
        }else{
            cout << (long long) d.second << '\n';
        }
    }
    cout << '\n';
}


int main(){

    int cases;

    cin >> cases;


    for (int i=0;i<cases;i++){
        work();
    }



    return 0;
}