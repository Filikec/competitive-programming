#include <iostream>
#include <list>

using namespace std;


int main(){

    int a,b;

    while (cin >> a >> b){
        if (!(a+b)) break;
        
        if (a<b){
            int tmp = a;
            a = b;
            b = tmp;
        }


        list<int> steps;

        while (a%b){
            int nextB = a%b;
            steps.push_front(a/b);
            a = b;
            b = nextB;
        }
        bool winning = 1;

        for (auto s : steps){
            if (s==1){
                winning = !winning;
            }else{
                winning = 1;
            }
        }

        if (winning){
            cout << "Stan wins\n";
        }else{
            cout << "Ollie wins\n";
        }
    }
    return 0;
}