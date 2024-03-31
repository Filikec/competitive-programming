#include <iostream>
#include <unordered_map>

using namespace std;


struct Set{
    Set *parent;
    int amount;
    Set *getHead(){
        Set *p = this;
        while (p->parent) p = p->parent;
        return p;
    }
};


void work(){
    int n;

    cin >> n;

    unordered_map<string,Set> map;

    for (int i=0;i<n;i++){
        string s1, s2;
        cin >> s1 >> s2;

        if (!map.count(s1)) map[s1] = {nullptr,1};
        if (!map.count(s2)) map[s2] = {nullptr,1};

        Set *set1 = map[s1].getHead(), *set2 = map[s2].getHead();

        if (set1 != set2){
            if (set1->amount > set2->amount){
                set1->amount += set2->amount;
                set2->parent = set1;
            }else{
                set2->amount += set1->amount;
                set1->parent = set2;
            }
        }

        cout << max(set1->amount,set2->amount) << "\n";
    }

}


int main(){

    int cases;

    cin >> cases;

    for (int c=0;c<cases;c++){
        work();
    }


    return 0;
}