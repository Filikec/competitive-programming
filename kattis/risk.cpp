#include <iostream>
#include <list>

using namespace std;



list<int> Graph[100];
int Armies[100];

void solve(){
    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Armies[i];
        Graph[i].clear();
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char tmp;
            cin >> tmp;
            if (tmp == 'Y'){
                Graph[i].push_back(j);
            }
        }
    }
    
    
    
}

int main(){
    int cases;
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> cases;


    for (int c=0;c<cases;c++){
        solve();
    }





    return 0;
}