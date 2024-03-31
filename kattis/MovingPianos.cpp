#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void work(){
    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> pianos(n);

    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pianos[i]={a,b};
    }

    if (m==1){
        cout << "serious trouble\n";
        return;
    }

    

    sort(pianos.begin(),pianos.end(),[&](auto a, auto b){
        if (a.first < b.first) return true;
        if (a.first == b.first) return a.second < b.second;
        return false;
        });

    int i=0;
    for (int d=1;d<=100&&i<pianos.size();d++){
        int c = 0;
        while (c++<m/2 && i<pianos.size() && pianos[i].first<=d && pianos[i].second>=d){
            i++;
        }
    }

    if (i!=pianos.size()){
        cout << "serious trouble\n";
        return;
    }
    
    i=0;
    for (int d=1;d<=100&&i<pianos.size();d++){
        if (d%7==6 || d%7==0) continue;
        int c = 0;
        while (c++<m/2 && i<pianos.size() && pianos[i].first<=d && pianos[i].second>=d){
            i++;
        }
    }

    if (i!=pianos.size()){
        cout << "weekend work\n";
        return;
    }

    cout << "fine\n";
}

int main(){

    int c;
    cin >> c;

    for (int i=0;i<c;i++){
        work();
    }


    return 0;
}