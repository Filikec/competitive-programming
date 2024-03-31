#include <bits/stdc++.h>

using namespace std;


void work(int a, int b){
    
    int d; 
    list<int> win;
    while (a && b && a!=b){
        if (a < b){
            int tmp = a;
            a = b;
            b = tmp;
        }

        d = a/b;
        win.push_front(d);
        
        a -= d*b;
        
    }

    int prev = 1; // wins the one who starts here
    while (win.size()){
        int cur = win.front();
        win.pop_front();
        if (cur == 1){
            prev = !prev;
        }else{
            prev = 1;
        }
    }

    if (prev){
        cout << "Stan wins\n";
    }else{
        cout << "Ollie wins\n";
    }
}


int main(){

    int a,b;

    while (cin >> a >> b){
        if (!a && !b) break;
        work(a,b);
    }



    return 0;
}