#include <iostream>
#include <list>

using namespace std;


int main(){


    int n, p;
    int prev = 0, cur=0;
    int sum = 0;
    cin >> n >> p;
    list<int> order;
    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        sum += tmp;
        order.push_front(tmp);
    }

    if (!sum){
        for (int i=0;i<n;i++){
            cout << "0\n";
        }
        return 0;
    }

    list<int> result;

    for (auto s : order){
        if (s > prev){
            cur++;
        }
        result.push_front(cur);
        prev = s;
    }

    if (cur != p){
        cout << "ambiguous\n";
    }else{
        for (auto c:result){
            cout << c << '\n';
        }
    }



    return 0;
}