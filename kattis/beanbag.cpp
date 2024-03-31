#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

typedef struct merchant{
    int beas[20];
} Merchant;

typedef struct type{
    int req, ind;
} Type;

list<Type> Beans;
list<Merchant> Merchants;

Merchant Merchs[100];
Type Types[20];

int main(){
    int b,r,s;

    cin >> b;

    for (int i=0;i<b;i++){
        cin >> Types[i].req;
        Types[i].ind = i;
        Beans.push_back(Types[i]);
    }

    int m;

    cin >> m;

    for (int i=0;i<m;i++){
        int t;
        cin >> t;
        for (int j=0;j<t;j++){
            int type;
            cin >> type;
            Merchs[i].beas[type-1] = 1;
        }
        Merchants.push_back(Merchs[i]);
    }
    bool f = true;
    while (!Beans.empty() && !Merchants.empty() && f){
        auto least = Beans.end();
        double least_value = 200;
        for (auto it=Beans.begin();it!=Beans.end();it++){
            double cost = it->req,amount=0;
            for (auto merch : Merchants){
                if (merch.beas[it->ind]) amount++;
            }
            if (amount && cost/amount < least_value){
                least_value = cost/amount;
                least = it;
            }
        }
        
        if (least == Beans.end()) break;
        
        list<list<Merchant>::iterator> del;
        for (auto it=Merchants.begin();it!=Merchants.end();it++){
            if (it->beas[least->ind]) del.push_back(it);
        }
        for (auto it : del){
            Merchants.erase(it);
        }
        Beans.erase(least);
    }
    int result = 0;
    for (auto b : Beans){
        result += b.req;
    }
    cout << result << "\n";
    

    return 0;
}

/*
4
6 5 4 1
3   
3 1 3 4
2 1 2
1 3

*/