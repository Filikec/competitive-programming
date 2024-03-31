#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, bool> Mem;


bool work(long long p, long long target){

    if (Mem.count(p)) return Mem[p];

    if (p>=target){
        Mem[p] = false;
        return false;
    }

    bool able = false;
    for (long long i=2;i<10;i++){
        if (!work(p*i,target)){
            able = true;
            break;
        }
    }
    Mem[p] = able;

    return able;


}

int main(){
    long long n;

    while (cin >> n){
        Mem.clear();
        work(1,n);
        if (Mem[1]){
            cout << "Stan wins.\n";
        }else{
            cout << "Ollie wins.\n";
        }
    }

    return 0;
}