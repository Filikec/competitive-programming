#include <iostream>
#include <algorithm>

using namespace std;


struct Snowball{
    int num,f;
};

Snowball Nums[200000];

int main(){


    int f,s;

    cin >> f >> s;

    for (int i=0;i<f;i++){
        cin >> Nums[i].num;
        Nums[i].f=1;
    }

    for (int i=0;i<s;i++){
        cin >> Nums[i+f].num;
    }

    sort(Nums,Nums+f+s,[&](Snowball a, Snowball b){return a.num<b.num;});

    Snowball prev = {-1,-1};

    int impossible = 1;
    for (int i=0;i<f+s;i++){
        if (Nums[i].num == prev.num || Nums[i].f == prev.f){
            impossible++;
        }
        prev = Nums[i];
    }
    
    cout << f+s-impossible << '\n';

    return 0;
}