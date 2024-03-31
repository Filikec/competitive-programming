#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    string n,result;

    cin >> n;

    while (n.size()%3){
        n.insert(n.begin(),'0');
    }

    cout << n << "\n";

    for (int i=0;i<n.size();i+=3){
        string bin;

        bin += n[i];
        bin += n[i+1];
        bin += n[i+2];
        int decimal = 0;

        decimal += (bin[i+2]-'0');
        decimal += (bin[i+1]-'0')+(bin[i+1]-'0');
        decimal += (bin[i]-'0')+(bin[i]-'0')+(bin[i]-'0')+(bin[i]-'0');
        cout << decimal << "<<\n";
        result += decimal+'0';  
    }

    cout << result << '\n';

    return 0;
}