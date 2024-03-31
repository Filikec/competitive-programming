#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Mats[500];


int getOpenings(vector<int> f, vector<int> g){
    vector<int> *a = &f, *b=&g;

    if (a->front() > b->front()){
        auto tmp = a;
        a = b;
        b = tmp;
    }


    int iA, iB;
    iA = iB = 0;
    
    for (int iA=0;iA<a->size();iA++){
        for (int iB=0;iB<b->size();iB++){
            
        }
    }
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> Mats[i];
    }


    for (int i=0;i<n;i++){
        for (int j=0;i<=n;i++){
            
        }
    }


    return 0;
}
