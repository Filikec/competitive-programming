#include <bits/stdc++.h>

using namespace std;



class Deque{
    public:
    vector<long long> Front, Back;
    long long size;

    Deque(){
        Front.reserve(1000000);
        Back.reserve(1000000);
        size = 0;
    }

    void push_back(long long n){
        Back.push_back(n);
        size++;
    }

    void push_front(long long n){
        Front.push_back(n);
        size++;
    }

    long long get(int index){
        if (index >= Front.size()){
            index -= Front.size();
            if (index >= 0 && index < Back.size()){
                return Back[index];
            }else{
                return 0;
            }
        }else{
            index = Front.size()-1-index;
            if (index >= 0 && index < Front.size()){
                return Front[index];
            }else{
                return 0;
            }
        }
    }
};


Deque deque1, deque2;

int main(){


    string s;
    int n;

    cin >> n;

    for (int i=0;i<n;i++){
        int e;
        cin >> s >> e;

        if (s == "push_back"){
            deque2.push_back(e);
        }else if (s == "push_front"){
            deque1.push_front(e);
        }else if (s == "get"){
            
        }else{
            if (deque1.size < deque2.size){
                deque1.push_back(e);
            }else{
                deque2.push_front(e);
            }
        }
    }



    return 0;
}