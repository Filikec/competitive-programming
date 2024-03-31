#include <iostream>


using namespace std;


int Cars[101];
int P[4];

int main(){
    cin >> P[1] >> P[2] >> P[3];

    int s,t;
    while (cin >> s >> t){
        for (int i=s;i<t;i++) Cars[i]++;
    }

    int total = 0;

    for (int i=0;i<101;i++){
        total += P[Cars[i]]*Cars[i];
    }

    cout << total << '\n';
    return 0;
}