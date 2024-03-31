#include <iostream>
#include <vector>

using namespace std;

void work(){
    long long n,m;

    cin >> n >> m;

    vector<long long> cs,e;
    
    long long csA=0,eA=0;

    for (int i=0;i<n;i++){
        long long tmp;
        cin>>tmp;
        cs.push_back(tmp);
        csA += tmp;
    }

    for (int i=0;i<m;i++){
        long long tmp;
        cin>>tmp;
        e.push_back(tmp);
        eA += tmp;
    }


    int counter=0;
    for (auto s : cs){
        if (csA > s*n && eA < s*m) counter++;
    }

    cout << counter << '\n';
}


int main(){
    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        work();
    }
}