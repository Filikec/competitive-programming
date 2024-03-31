#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>

using namespace std;

struct block{
    string type;
    long double size;

};


bool cmp(block a, block b){
    if (a.type == "cube" && b.type == "cube"){
        return a.size >= b.size;
    }else if (a.type == "cube" && b.type != "cube"){
        return a.size >= b.size*2;
    }else if (a.type != "cube" && b.type != "cube"){
        return a.size >= b.size;
    }else if (a.type != "cube" && b.type == "cube"){
        return a.size*2 >= sqrt(b.size*b.size*2);
    }
    return false;
}

list<block> blocks,sorted;

int main(){

    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        string type;
        long double size;

        cin >> type >> size;

        block newBlock = {type,size};

        blocks.push_back(newBlock);
    }

    sorted.push_back({"cube",1000000});

    while (blocks.size()){
        bool in = false;

        for (auto it = blocks.begin();it!=blocks.end();){
            auto it3= next(it);
            for (auto it2=sorted.begin();it2!=sorted.end();it2++){
                if (cmp(*it,*it2)){
                    if (it2 == sorted.begin() || cmp(*prev(it2),*it)){
                        sorted.insert(it2,*it);
                        blocks.erase(it);
                        in = true;
                        break;
                    }
                }
            }
            
            if (!in && cmp(sorted.back(),*it)){
                sorted.push_back(*it);
                blocks.erase(it);
                in = true;
            }
            it = it3;
            if (in) break;
        }


        if (!in){
            cout << "impossible\n";
            return 0;
        }
    }

    for (auto it=sorted.rbegin();it!=sorted.rend();it++){
        if (it->size != 1000000)cout << it->type << ' ' << (int)(it->size) << '\n';
    }

    return 0;
}