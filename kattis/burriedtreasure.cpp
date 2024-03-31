#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

#define AMOUNT 100000

unordered_set<int> Rules[2*AMOUNT+1];

int M;

int inputToRule(int n){

    return n+AMOUNT;
}


int ruleToInput(int r){

    return r-AMOUNT;
}

int negateRule(int rule){
    rule = ruleToInput(rule);
    rule *= -1;
    return inputToRule(rule);
}

bool dfs(int d, set<int> &rules){
    bool broke = false;
    for (auto rule : Rules[-d+AMOUNT]){
        if (rules.count(negateRule(rule))){
            broke = true;
            break;
        }
    }
    if (!broke){
        if (d == M) return true;
        rules.insert(-d+AMOUNT);
        if (dfs(d+1,rules)) return true;
        rules.erase(-d+AMOUNT);
    }

    broke = false;
    for (auto rule : Rules[d+AMOUNT]){
        if (rules.count(negateRule(rule))){
            broke = true;
            break;
        }
    }
    if (!broke){
        if (d == M) return true;
        rules.insert(d+AMOUNT);
        if (dfs(d+1,rules)) return true;
        rules.erase(d+AMOUNT);
    }

    return false;
}


int main(){

    int n;

    cin >> n >> M;

    for (int i=0;i<n;i++){
        int m1,m2;

        cin >> m1 >> m2;

        Rules[inputToRule(m1)].insert(inputToRule(m2));
        Rules[inputToRule(m2)].insert(inputToRule(m1));
    }

    set<int> rules;

    if (dfs(1,rules)) cout << "YES\n";
    else cout << "NO\n";


    return 0;
}