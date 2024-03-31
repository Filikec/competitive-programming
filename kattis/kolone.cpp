#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){


    int a,b;

    cin >> a >> b;


    string left,right;


    cin >> left >> right;

    int  t;

    cin >> t;

    vector<char> result(right.size()+left.size());

    for (int i=0;i<left.size();i++){
        result[left.size()-1+t-i] = left[i];
    }

    for (int i=0;i<right.size();i++){
        result[left.size()-t+i] = right[i];
    }    

    for (auto c : result){
        cout << c;
    }
    cout << '\n';

    return 0;
}