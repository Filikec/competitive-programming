#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


string toBin(int n){
    if (!n) return "0";
    string result;
    while (n){
        result += n%2 + '0';
        n /= 2;
    }
    reverse(result.begin(),result.end());
    return result;
}

string binToHex(string bin){
    int result = 0;
    int pow = 1;
    for (int i=bin.size()-1;i>=0;i--){
        result += (bin[i]-'0')*pow;
        pow *= 2;
    }
    string r;
    if (result >= 10){
        r += (char)('A'+result-10);
        return r;
    }
    r += (char)(result+'0');
    return r;
}

int main(){
    
    string line;
    string bin, r;

    getline(cin,line);

    for (auto c : line){
       string g = toBin(c-'0');
       bin += g;
    }
    cout << bin << "\n";
    for (int i=bin.size()-1;i>=0;i-=4){
        string b;
        for (int j=0;j<4&&i-j>=0;j++){
            b += bin[i-j];
        }
        reverse(b.begin(),b.end());
        r +=  binToHex(b);
    }
    reverse(r.begin(),r.end());
    cout <<r << '\n';

    return 0;
}