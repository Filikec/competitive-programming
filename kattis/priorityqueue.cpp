#include <iostream>
#include <vector>

using namespace std;


vector<int> Priority_queue;

void init(){
    Priority_queue.reserve(100000000);
}

void add_priority(int n){
    int low, high;
    low = 0;
    high = Priority_queue.size()-1;

    while (low<high){
        int tmp = (high-low)/2;
        if (Priority_queue[tmp] > n){
            low = n;
        }else{
            high = n;
        }
    }
    Priority_queue
}

int main(){
    init();
    return 0;
}