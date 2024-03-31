#include <iostream>
#include <map>


using namespace std;



void solve(){
    map<string,int> Disg;
    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        string item, type;

        cin >> item >> type;

        if (Disg.count(type)){
            Disg[type]++;
        }else{
            Disg.insert(make_pair(type,1));
        }
    }
    
    if (Disg.size()==1){
        cout << Disg.begin()->second << '\n';
    }else{
        long long sum = 1;
        for (auto p: Disg){
            sum *= p.second+1;
        }
        cout << sum-1 << "\n";
    }
    

}

int main(){
    cin.tie(NULL);
    
    int cases;
    cin >> cases;

    for (int i=0;i<cases;i++){
        solve();
    }



    return 0;
}