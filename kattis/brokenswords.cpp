#include <iostream>

using namespace std;



int Sides[2];


int main(){
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin.get();
    for (int i=0;i<n;i++){
        char c;
        int ind = 0;
        while ((c=cin.get())!='\n'){
            Sides[ind++/2] += !(c-'0');
        }
    }

    int maxi = min(Sides[0],Sides[1])/2;
    cout << maxi << " ";
    cout << Sides[0]-maxi*2 << ' ' << Sides[1]-maxi*2 << "\n";

    return 0;
}