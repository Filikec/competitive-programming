#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

bool smallerEq(list<char> *l, list<char> *r){
    auto itL = l->begin();
    auto itR = r->begin();

    while (itL != l->end() && itR != r->end()){
        if (*itR < *itL){
            
        }
        else if (*itR > *itL) return true;
        itL++;
        itR++;
    }

    if (itL != l->end() && itR == r->end()) return false;

    return true;
}

int main(){


    int n;
    cin >> n;

    list<char> ls[2];

    list<char> *p = &ls[0];
    list<char> *s = &ls[1];

    char c;
    
    cin.get();
    while ((c = cin.get())){
        if ((c >= 'a' && c <= 'z') == false) break;
        p->push_back(c);
    } 

    bool good = 1;
    for (int i=1;i<n;i++){
        s->clear();
        
        while ((c = cin.get())){
            if ((c >= 'a' && c <= 'z') == false) break;
            s->push_back(c);
        } 
        for (auto c : *s) cout << c;
        cout << "<<\n";
        list<char>::reverse_iterator last = s->rend();
        while (!smallerEq(p,s) && good){
            for (auto c : *s) cout << c;
            cout << "<\n";
            if (!updtStr(s,last)) good = 0;
            for (auto c : *s) cout << c;
            cout << "<\n";
        }

        if (!good) break;

        swap(p,s);
    }

    if (good){
        cout << "yes\n";
    }else{
        cout << "no\n";
    }

    return 0;
}