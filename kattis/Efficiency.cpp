#include <iostream>

using namespace std;

int main(){

    int p, m;

    cin >> p >> m;


    int n = 1;
    int count = 0;

    int next;

    while ((count + 4*n) < m){
        count += 4*n;
        n++;
    }

    next = count + 4*n-1;

    for (int i=0;i<n;i++){
        count++;
        if (count == m){
            cout << "Efficiency\n";
            cout << (next%p)+1 << "\n";
            return 0;
        }
        
    }

    for (int i=0;i<n;i++){
        count++;
        if (count == m){
            cout << "Unbreaking\n";
            cout << (next%p)+1 << "\n";
            return 0;
        }
    }

    for (int i=0;i<2*n;i++){
        count++;
        if (count == m){
            if (i%2){
                cout << "Touch\n";
            }else{
                cout << "Silk\n";
            }
            cout << (next%p)+1 << "\n";
            return 0;
        }
    }


    return 0;
}