#include <bits/stdc++.h>


using namespace std;


list<int> Nums,Result;

bool cmp(int a, int b){
    return a < b;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        Nums.push_back(tmp);
    }


    Nums.sort(cmp);

    int i=0;
    while (Nums.size()){
        if (i){
            Result.push_front(Nums.front());
            Nums.pop_front();
        }else{
            Result.push_front(Nums.back());
            Nums.pop_back();
        }
        i = !i;
    }

    
    for (auto it = next(Result.begin());next(it) != Result.end();it++){
        if (abs(*it - *(prev(it))) > abs(*it - *(next(it)))){
            cout << "impossible\n";
            return 0;
        }
    }

    for (auto e : Result){
        cout << e << ' ';
    }
    cout << "\n";

}