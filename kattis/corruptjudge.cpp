#include <iostream>
#include <list>

using namespace std;

int Times[10000];

int main(){
    int n,p,sum=0;

    cin >> n >> p;

    for (int i=0;i<n;i++){
        cin >> Times[i];
        sum += Times[i];
    }

    if (!sum){
        for (int i=0;i<n;i++){
            cout << "0\n";
        }
        return 0;
    }

    list<int> results;
    int solved, last;
    last = Times[n-1];
    if (!Times[n-1]){
        solved = 0;
    }else{
        solved = 1;
    }

    results.push_front(solved);
    for (int i=n-2;i>=0;i--){
        int curr = Times[i];
        if (curr > last){
            solved++;
        }
        last = curr;
        results.push_front(solved);
    }

    if (solved != p){
        cout << "ambiguous.\n";
    }else{
        for (auto place : results){
            cout << place << '\n';
        }
    }

    return 0;
}