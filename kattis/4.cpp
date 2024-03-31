#include <iostream>

using namespace std;

int Segments[100];

int main(){


    int a1,a2,b1,b2;
    int count=0;
    while (cin>>a1){
        cin.get();
        cin>>a2;

        cin.get();

        cin>>b1;
        cin.get();
        cin>>b2;

        int s2 = min(a2,b2), s1 = max(a1,b1);

        count += (s1<=s2);
    }
    cout << count << '\n';

}

